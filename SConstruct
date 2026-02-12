#!/usr/bin/env python

env = SConscript("modules/godot-cpp/SConstruct")

platform = env["platform"]

env.Tool("separate_debug_symbols")
if platform == "web":
    env.Tool("wasm_split", properties_file="deps/wasm-split.properties")

env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

env.Append(CPPDEFINES=["GDEXTENSION"])

bin_path = "project/addons/kaboom/bin/"
extension_name = "kaboom"
debug_or_release = "release" if env["target"] == "template_release" else "debug"

if not "arch_suffix" in env:
    env["arch_suffix"] = env["arch"]

extra = ""
if env["threads"] is False:
    extra += ".nothreads"

if env["target"] in ["editor", "template_debug"]:
    doc_data = env.GodotCPPDocData("src/gen/doc_data.gen.cpp", source=Glob("doc_classes/*.xml"))
    sources.append(doc_data)

lib_name = "{}{}.{}.{}.{}{}{}".format(
    env.subst('$SHLIBPREFIX'),
    extension_name,
    platform,
    debug_or_release,
    env["arch_suffix"],
    extra,
    env["SHLIBSUFFIX"],
)
lib_path = f"{bin_path}{lib_name}"

library = env.SharedLibrary(lib_path, source=sources)
Default(library)


# *** Separate debug symbols.

if env["debug_symbols"]:
    # Note: Windows/MSVC separates debug symbols by default (.pdb).
    if platform in ["macos", "ios"]:
        dsym_path = f"{bin_path}dSYMs/{lib_name}.dSYM"
        env.SeparateDebugSymbols(Dir(dsym_path), library)
    elif platform in ["linux", "android"]:
        symbols_path = f"{bin_path}{lib_name}.debug"
        env.SeparateDebugSymbols(File(symbols_path), library)
    elif platform == "web":
        debug_name = lib_name.removesuffix(".wasm") + ".debug"
        symbols_path = f"{bin_path}{debug_name}"
        env.SeparateDebugSymbols(File(symbols_path), library)
