// Object passes through void* (callback / C API style) and comes back as an unrelated type.
#include "common.h"
static void* to_handle(DerivedA* p) { return p; }
int main() {
    void* h = to_handle(new DerivedA);
    Unrelated* u = static_cast<Unrelated*>(h);      // unrelated-type cast from void*
    sink(u->tag());                                 // virtual call through the wrong vtable
    UNDETECTED();
}
