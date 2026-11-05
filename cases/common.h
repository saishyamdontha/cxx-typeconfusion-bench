// Shared class hierarchy for every case. Kept tiny on purpose so each bug is obvious.
#pragma once
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Base {
    virtual ~Base() = default;
    virtual int id() const { return 0; }
    int base_field = 1;
};
struct DerivedA : Base {
    int id() const override { return 1; }
    int a_field = 0xA;
};
struct DerivedB : Base {
    int id() const override { return 2; }
    long b_field = 0xB;
    long b_extra = 0xBB;            // DerivedB is larger than DerivedA
};
struct Unrelated {                   // polymorphic, but not in Base's hierarchy
    virtual ~Unrelated() = default;
    virtual int tag() const { return 99; }
    long u_field = 7;
};

// Second hierarchy for multiple inheritance.
struct Left  { virtual ~Left() = default;  virtual int l() const { return 10; } int lf = 10; };
struct Right { virtual ~Right() = default; virtual int r() const { return 20; } int rf = 20; };
struct Both  : Left, Right { int bf = 30; };
struct OnlyRight : Right { int of = 40; };

// Non-polymorphic hierarchy: no vtable, so vtable-based checkers have nothing to inspect.
struct PlainBase { int x = 1; };
struct PlainDerived : PlainBase { int y[4] = {2, 2, 2, 2}; };

// Keep the compiler from optimising the bug away.
template <class T> inline void sink(T v) { asm volatile("" : : "g"(v) : "memory"); }

// A case that reaches this line was NOT stopped by the active checker.
#define UNDETECTED() do { std::puts("UNDETECTED"); return 0; } while (0)
