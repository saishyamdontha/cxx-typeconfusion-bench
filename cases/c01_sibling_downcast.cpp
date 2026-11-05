// static_cast a Base* that holds a DerivedA down to its sibling DerivedB, then read a DerivedB field.
#include "common.h"
int main() {
    Base* b = new DerivedA;
    DerivedB* bad = static_cast<DerivedB*>(b);      // type confusion at the cast
    sink(bad->b_extra);                             // reads past the end of a DerivedA
    delete b;
    UNDETECTED();
}
