//
// Created by tt on 2021/9/7.
// E-Mail: xyt@bupt.cn
//

#include <cstdio>
#include <memory>

#include <icecream.hpp>

class A {
public:
    A() {
        printf("A object created\n");
    }
    virtual void func() {
        printf("A::func() called\n");
    }
};

class B : public A{
public:
    B() {
        printf("B object created\n");
    }
    virtual void func() {
        printf("B::func() called\n");
    }
};

void shared_pointer() {
    // create a B object and ptr1 points to it
    auto ptr1 = std::make_shared<B>();
    // son's pointer points to father's pointer
    std::shared_ptr<A> ptr2 = ptr1;

    // calls B::func()
    ptr1->func();
    // calls A::func()
    ptr2->func();

    // compare two pointers, they are the same
    IC(ptr1.get() == ptr2.get());
}

void unique_pointer() {
    auto ptr1 = std::make_unique<B>();
    ptr1->func();

    auto temp = ptr1.get();
    // unique_pointer cannot be copied but only moved
    // auto ptr2 = ptr1;
    auto ptr2 = std::move(ptr1);
    printf("ptr1 moved to ptr2\n");

    // will incur signal 11: SIGSEGV
    // ptr1->func();
    ptr2->func();

    // validate that ptr2 now takes over the original ptr1's memory
    IC(temp == ptr2.get());
}

int main() {
    unique_pointer();
}
