#include <queue>
#include <thread>
#include <iostream>
#include <condition_variable>

int counter = 0;
bool done = false;

std::queue<int> goods;

std::condition_variable flag;
std::mutex mutex;

void producer() {
    std::cout << "Starting producer..." << std::endl;

    for (int i = 0; i < 500; ++i) {
        goods.push(i);
        counter++;
    }

    flag.notify_one();
    done = true;

    std::cout << "Finished producer..." << std::endl;
}

void consumer() {
    std::cout << "Starting consumer..." << std::endl;

    std::unique_lock<std::mutex> lock(mutex);

    while (!done) {

        flag.wait(lock);

        while (!goods.empty()) {
            goods.pop();
            counter--;
        }
    }

    std::cout << "Finished consumer..." << std::endl;
}

int main() {
    counter = 0;
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    std::cout << "Net: " << counter << " " << goods.size() << std::endl;
}
