#ifndef PAIR_HPP
#define PAIR_HPP

template<class A, class B>
struct Pair {
    Pair(A first, B second): first(first), second(second) {}
    A first;
    B second;
};

#endif
