// dynamic_cast is safe, but its nullptr result is ignored: a logic bug, not type confusion.
// Included to show where type checkers stop and ordinary null checks take over.
#include "common.h"
int main() {
    Base* b = new DerivedA;
    DerivedB* d = dynamic_cast<DerivedB*>(b);       // correctly returns nullptr
    if (!d) { std::puts("CAUGHT_BY_DYNAMIC_CAST"); delete b; return 0; }
    sink(d->b_field);
    UNDETECTED();
}
