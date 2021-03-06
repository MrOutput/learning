#include <iostream>
#include <thread>

#define TPOOL_SIZE 2
#define TOTAL_ITERATIONS 10000

using namespace std;

void loop(void) {
    for (int j = 0; j < TOTAL_ITERATIONS / TPOOL_SIZE; j++) {
        for (int i = 1; i < 1000; i*=2) {
            cout << i << endl;
        }
    }

    cout << "thread finished." << endl;
}

int main(int argc, char const* argv[])
{
    thread tpool[TPOOL_SIZE];

    for (int i = 0; i < TPOOL_SIZE; i++) {
        tpool[i] = thread(loop);
    }

    for (int i = 0; i < TPOOL_SIZE; i++) {
        tpool[i].join();
    }

    cout << "Rafael says: Done." << endl;

    return 0;
}
