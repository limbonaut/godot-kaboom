#pragma once

#include "kaboom_defines.h"

#include <godot_cpp/classes/object.hpp>

class Kaboom : public Object {
	GDCLASS(Kaboom, Object);

public:
	static Kaboom *singleton;

	static Kaboom *get_singleton() { return singleton; }
	static void create_singleton() { singleton = memnew(Kaboom); }
	static void destroy_singleton() {
		memdelete(singleton);
		singleton = nullptr;
	}

protected:
	static void _bind_methods();

public:
	void crash();
};
