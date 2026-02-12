#!/usr/bin/env python

env = SConscript("modules/godot-cpp/SConstruct")

env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

env.Append(CPPDEFINES=["GDEXTENSION"])

bin_path = "bin/"
extension_name = "kaboom"
debug_or_release = "release" if env["target"] == "template_release" else "debug"

if not "arch_suffix" in env:
    env["arch_suffix"] = env["arch"]

if env["target"] in ["editor", "template_debug"]:
    doc_data = env.GodotCPPDocData("src/gen/doc_data.gen.cpp", source=Glob("doc_classes/*.xml"))
    sources.append(doc_data)

library = env.SharedLibrary(
    "{}/{}{}.{}.{}.{}{}".format(
        bin_path,
        env.subst('$SHLIBPREFIX'),
        extension_name,
        env["platform"],
        debug_or_release,
        env["arch_suffix"],
        env["SHLIBSUFFIX"],
    ),
    source=sources,
)

Default(library)
