#include "kaboom.h"

Kaboom *Kaboom::singleton = nullptr;

void Kaboom::crash() {
	char *ptr = (char *)1;
	print_line("Kaboom! Crashing...");
	print_line(ptr);
}

void Kaboom::_bind_methods() {
	ClassDB::bind_method(D_METHOD("crash"), &Kaboom::crash);
}
