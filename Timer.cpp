//
// Created by Kosho Owa on 2019-07-25.
//

#include <iomanip>
#include <sstream>
#include "Timer.h"

void Timer::Start() {
    while (true) {
        this_thread::sleep_for(chrono::seconds(1));
        cout << get_iso8601_timestamp() << ", " << requests_->exchange(0) << endl;
    }
}

Timer::Timer(std::atomic_ulong *requests) : requests_(requests) {}

string Timer::get_iso8601_timestamp() {
    auto now_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::ostringstream ss;
    ss << std::put_time(localtime(&now_t), "%FT%T%z");
    return ss.str();
}