// reinterpret_cast between polymorphic types: the programmer explicitly opts out of type rules.
#include "common.h"
int main() {
    DerivedA* a = new DerivedA;
    Unrelated* u = reinterpret_cast<Unrelated*>(a);
    sink(u->u_field);                               // field read through the wrong type
    delete a;
    UNDETECTED();
}
