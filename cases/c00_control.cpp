// Control: correct casts only. Any report here is a false positive.
#include "common.h"
int main() {
    Base* b = new DerivedB;
    auto* d = static_cast<DerivedB*>(b);            // correct downcast
    sink(d->b_field + b->id());
    Both both; Right* r = &both;
    sink(static_cast<Both*>(r)->bf);                // correct cross-hierarchy downcast
    delete b;
    std::puts("OK");
    return 0;
}
