// Polymorphic array decay: indexing DerivedB[] through Base* uses sizeof(Base) as the stride.
#include "common.h"
static int sum_ids(Base* arr, int n) { int s = 0; for (int i = 0; i < n; ++i) s += arr[i].id(); return s; }
int main() {
    DerivedB* arr = new DerivedB[4];
    sink(sum_ids(arr, 4));                          // arr[1] is not at the start of any object
    delete[] arr;
    UNDETECTED();
}
