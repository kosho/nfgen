//
// Created by Kosho Owa on 2019-07-25.
//

#ifndef NETFLOW_TRAFFIC_GENERATOR_TIMER_H
#define NETFLOW_TRAFFIC_GENERATOR_TIMER_H

#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

class Timer {
public:
    Timer();

    Timer(std::atomic_ulong *requests);

    void Start();

private:
    std::atomic_ulong *requests_;

};

#endif //NETFLOW_TRAFFIC_GENERATOR_TIMER_H
