#include "register_types.h"

#include <godot_cpp/classes/engine.hpp>

#include "kaboom.h"

inline void add_godot_singleton(const StringName &p_singleton_name,
		Object *p_object) {
	Engine::get_singleton()->register_singleton(p_singleton_name, p_object);
}

inline void remove_godot_singleton(const StringName &p_singleton_name) {
	Engine::get_singleton()->unregister_singleton(p_singleton_name);
}

void initialize_kaboom_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
		GDREGISTER_CLASS(Kaboom);
		Kaboom::create_singleton();
		add_godot_singleton("Kaboom", Kaboom::get_singleton());
	}
}

void uninitialize_kaboom_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
		remove_godot_singleton("Kaboom");
		Kaboom::destroy_singleton();
	}
}
