// Same bug as c01, but the hierarchy has no virtual functions (no vtable to check).
#include "common.h"
int main() {
    PlainBase* p = new PlainBase;
    PlainDerived* bad = static_cast<PlainDerived*>(p);
    sink(bad->y[3]);                                // reads past a 4-byte object
    delete p;
    UNDETECTED();
}
