#include "kaboom.h"

#include <cstdlib>

Kaboom *Kaboom::singleton = nullptr;

void Kaboom::crash_with_null_dereference() {
	volatile int *ptr = nullptr;
	*ptr = 0;
}

void Kaboom::crash_with_stack_overflow() {
	volatile int arr[1024];
	crash_with_stack_overflow();
	arr[0] = 0;
}

void Kaboom::crash_with_abort() {
	abort();
}

void Kaboom::crash_with_division_by_zero() {
	volatile int a = 1;
	volatile int b = 0;
	volatile int c = a / b;
	(void)c;
}

void Kaboom::_bind_methods() {
	ClassDB::bind_method(D_METHOD("crash_with_null_dereference"), &Kaboom::crash_with_null_dereference);
	ClassDB::bind_method(D_METHOD("crash_with_stack_overflow"), &Kaboom::crash_with_stack_overflow);
	ClassDB::bind_method(D_METHOD("crash_with_abort"), &Kaboom::crash_with_abort);
	ClassDB::bind_method(D_METHOD("crash_with_division_by_zero"), &Kaboom::crash_with_division_by_zero);
}
