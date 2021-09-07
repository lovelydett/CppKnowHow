//
// Created by tt on 2021/9/8.
// E-Mail: xyt@bupt.cn
//

#include <cstdio>
#include <icecream.hpp>
#include <atomic>
#include <thread>
#include <vector>

// not protect critical area
int nVar1;

// atomic protects critical area
std::atomic<int> nVar2;

void worker(int no) {
    while (nVar1 < 100) {
        if (++nVar1 == 100) {
            printf("worker %d wins\n", no);
        }
    }
}

void worker2(int no) {
    while (nVar2 < 100000) {
        if (++nVar2 == 100000) {
            printf("worker %d wins\n", no);
        }
    }
}

int main() {
    nVar1 = 0;
    nVar2.store(0);

    std::vector<std::thread> threads;
    threads.reserve(20);
    printf("not protect critical area:\n");
    for (int i = 0; i < 10; i++) {
        threads.emplace_back(std::thread(worker, i));
    }

    printf("atomic protects critical area:\n");
    for (int i = 0; i < 10; i++) {
        threads.emplace_back(std::thread(worker2, i));
    }

    for(auto& t : threads) {
        t.join();
    }

    return 0;
}

