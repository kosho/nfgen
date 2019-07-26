#include <iostream>
#include <thread>

#include "Worker.h"
#include "Timer.h"

using namespace std;

u_int _NUM_THREADS = 3;
u_int _NF_PORT = 9995;

int main(int argc, char *argv[]) {

    u_int num_threads_ = _NUM_THREADS;
    unsigned short port_ = _NF_PORT;
    char *dest_;

    mutex mtx_;
    atomic_ulong requests_(0);

    // handle options
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " [-t num_threads (" << _NUM_THREADS << ")] [-p port (" << _NF_PORT
             << ")] target_ip" << endl;
        return -1;
    }

    int opt;
    char *endptr;

    while ((opt = getopt(argc, argv, "t:p:")) != EOF) {
        switch (opt) {
            case 't':
                num_threads_ = (u_int) strtol(optarg, &endptr, 0);
                if (num_threads_ == 0) {
                    cout << "Invalid num_threads: " << endptr << endl;
                    return EXIT_FAILURE;
                }
                break;
            case 'p':
                port_ = (u_int) strtol(optarg, &endptr, 0);
                if (port_ == 0) {
                    cout << "Invalid port: " << endptr << endl;
                    return EXIT_FAILURE;
                }
                break;
            default:
                cout << "Usage: " << argv[0] << " [-t num_threads (" << _NUM_THREADS << ")] [-p port (" << _NF_PORT
                     << ")] target_ip" << endl;
                return EXIT_FAILURE;
        }
    }

    if (!argv[optind]) {
        cout << "Error: destination missing" << endl;
        return EXIT_FAILURE;
    } else {
        dest_ = argv[optind];
    }

    // create worker threads
    thread *thWorker;
    thWorker = new thread[num_threads_];

    for (u_int i = 0; i < num_threads_; i++) {
        thWorker[i] = thread(&Worker::Run, Worker(dest_, &port_, &mtx_, &requests_));
    }

    // timer thread
    thread th_timer(&Timer::Start, Timer(&requests_));

    // run workers
    for (u_int i = 0; i < num_threads_; i++) {
        thWorker[i].join();
    }

    return EXIT_SUCCESS;
}