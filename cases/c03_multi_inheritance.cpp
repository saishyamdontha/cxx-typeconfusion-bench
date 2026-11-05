// Multiple inheritance: a Right* that is really OnlyRight gets downcast to Both.
// The cast also applies a this-pointer adjustment, so the result points before the object.
#include "common.h"
int main() {
    Right* r = new OnlyRight;
    Both* bad = static_cast<Both*>(r);              // wrong: r is not inside a Both
    sink(bad->lf);
    delete r;
    UNDETECTED();
}
