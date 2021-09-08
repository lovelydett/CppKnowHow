//
// Created by tt on 2021/9/8.
// E-Mail: xyt@bupt.cn
//

#include <vector>
#include <cstdio>
#include <icecream.hpp>

// vector capacity: 1, 2, 4, 8, 16, 32...
void dynamic_alloc() {
    std::vector<int> vec;
    for (int i = 0; i < 100; i++) {
        vec.push_back(1);
        IC(vec.size(), vec.capacity());
        IC((float)vec.size() / vec.capacity());
    }
}

class A {
public:
    int n = 0;
    A() {
        printf("default ctr called\n");
    }
    A(const A& a) {
        printf("copy ctr called\n");
        n = a.n;
    }
    // Move ctr must noexcept! If failed, we don't handle it, just std::terminate!
    A(const A&& a) noexcept {
        printf("move ctr called\n");
        n = a.n;
    }
    ~A() {
        printf("dtr called\n");
    }
    void func() {
        printf("A::func() called\n");
    }
};

// emplace_back
void vector_emplace_back() {
    std::vector<A> vec;
    vec.reserve(5);

    printf("----now create an A object and push_back it----\n");
    vec.push_back(A());

    printf("----now emplace_back it----\n");
    vec.emplace_back(A());

    printf("----leaving----\n");
}


int main() {
    // dynamic_alloc();
    vector_emplace_back();
    return 0;
}