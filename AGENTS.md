# Agent Instructions

## Overview
GDExtension library that triggers controlled native crashes for testing Sentry crash reporting in Godot Engine.

## Build System
- **SCons** with godot-cpp submodule
- Initialize submodules: `git submodule sync --recursive && git submodule update --init --recursive`
- **Always** specify `target=`, `api_version=`, and `debug_symbols=yes`
- `target=` must be `template_debug` or `template_release` (never `editor`)

```bash
# Build (current platform)
scons target=template_debug api_version=4.5 debug_symbols=yes

# Platform-specific
scons platform=linux target=template_release api_version=4.5 debug_symbols=yes arch=x86_64
scons platform=windows target=template_release api_version=4.5 debug_symbols=yes arch=x86_64
scons platform=macos target=template_release api_version=4.5 debug_symbols=yes arch=universal
scons platform=android target=template_release api_version=4.5 debug_symbols=yes arch=arm64
scons platform=ios target=template_debug api_version=4.5 debug_symbols=yes arch=arm64 ios_simulator=no
scons platform=web target=template_release api_version=4.5 debug_symbols=yes arch=wasm32 threads=no
```

- Build output: `project/addons/kaboom/bin/{platform}/`
- Environment: `SCONSFLAGS="verbose=yes api_version=4.5 debug_symbols=yes"`

## Commit Attribution
AI commits MUST include:
```
Co-Authored-By: <model_name> <noreply@anthropic.com>
```

## Key Conventions
- **Language**: C++ (godot-cpp GDExtension)
- **API version**: Godot 4.5+
- **Public API**: `Kaboom` singleton with crash methods (`crash_with_null_dereference`, `crash_with_stack_overflow`, `crash_with_abort`, `crash_with_division_by_zero`)
- **Source**: `src/` — ~130 lines total
- **GDExtension manifest**: `project/addons/kaboom/kaboom.gdextension` (uses `res://` paths)
- **Debug symbols**: Separated per platform via custom SCons tools in `site_scons/`
- **Python linting**: `ruff check .` and `mypy .`

## Project Structure
```
src/                    # C++ source
  kaboom.h/cpp          # Crash implementations
  register_types.h/cpp  # Module registration
  initialize_gdextension.cpp
modules/godot-cpp/      # Git submodule
project/addons/kaboom/  # Built extension + manifest
site_scons/             # Custom SCons tools (debug symbols, wasm-split)
```
