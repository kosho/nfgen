//
// Created by Kosho Owa on 2019-07-25.
//

#include "Timer.h"

void Timer::Start() {
    while (true) {
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Sent: " << requests_->exchange(0) << " requests/sec" << endl;
    }
}

Timer::Timer(std::atomic_ulong *requests) : requests_(requests) {}
