//
// Created by Kosho Owa on 2019-07-25.
//

#ifndef NFGEN_TIMER_H
#define NFGEN_TIMER_H

#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

class Timer {
public:

    explicit Timer(std::atomic_ulong *requests);

    void Start();

private:
    std::atomic_ulong *requests_;

};

#endif //NFGEN_TIMER_H
