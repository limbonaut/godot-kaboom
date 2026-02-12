# godot-kaboom

> Hasta la vista, baby.

A GDExtension library that triggers controlled native crashes in Godot. Used to test crash reporting in Sentry SDK.

> [!TIP]
> Catch those nasty crashes with the official [Sentry for Godot Engine](https://github.com/getsentry/sentry-godot) addon.

Exposes a `Kaboom` singleton with the following methods:

- `Kaboom.crash_with_null_dereference()`
- `Kaboom.crash_with_stack_overflow()`
- `Kaboom.crash_with_abort()`
- `Kaboom.crash_with_division_by_zero()`

Supports Linux, Windows, macOS, Android, iOS, and Web.

## Usage

Download the latest release and extract it into your Godot project's `addons/` directory. Then call any of the crash methods from GDScript:

```gdscript
Kaboom.crash_with_null_dereference()
```
