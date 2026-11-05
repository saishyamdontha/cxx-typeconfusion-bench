// Non-polymorphic downcast where the wrong-type read stays INSIDE a valid allocation.
// No vtable (so vptr/CFI cannot check) and no out-of-bounds access (so ASan cannot either).
#include "common.h"
struct Packet { PlainBase header; int payload[4] = {5, 5, 5, 5}; };
int main() {
    Packet* pkt = new Packet;
    PlainDerived* bad = static_cast<PlainDerived*>(&pkt->header);   // header is not a PlainDerived
    sink(bad->y[3]);                                                 // silently reads payload[3]
    delete pkt;
    UNDETECTED();
}
