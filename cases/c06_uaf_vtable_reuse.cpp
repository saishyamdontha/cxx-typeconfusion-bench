// Use-after-free where the memory is reused by an object of another type, then called through the stale pointer.
#include "common.h"
#include <new>
alignas(16) static unsigned char arena[64];         // fixed slot, so reuse is guaranteed without relying on malloc
int main() {
    Base* stale = new (arena) DerivedA;
    stale->~Base();                                 // "free"
    new (arena) Unrelated;                          // slot reused by an unrelated type
    sink(stale->id());                              // virtual call through the stale Base*
    UNDETECTED();
}
