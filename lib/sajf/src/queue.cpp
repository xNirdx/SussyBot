#include <queue.h>

void sajf::queue::add(sajf::song song) {
    this->queue.push_back(song);
}

void sajf::queue::clear() {
    this->queue.clear();
}