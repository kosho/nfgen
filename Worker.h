//
// Created by Kosho Owa on 2019-07-25.
//

#ifndef NETFLOW_TRAFFIC_GENERATOR_WORKER_H
#define NETFLOW_TRAFFIC_GENERATOR_WORKER_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <mutex>

#ifdef __linux__
#include <atomic>
#endif

using namespace std;

class Worker {
public:
    Worker();

    Worker(char *dest, u_int *port, mutex *mtx, atomic_ulong *requests);

    Worker(char *dest, unsigned short *port, mutex *mtx, atomic_ulong *requests);

    void Run();

private:
    char *dest_;
    unsigned short *port_;
    std::mutex *mtx_;
    std::atomic_ulong *requests_;

    void safe_cout(const string &msg);
};

#endif //NETFLOW_TRAFFIC_GENERATOR_WORKER_H
