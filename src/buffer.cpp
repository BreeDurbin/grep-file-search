#include "buffer.h"

namespace fs = std::filesystem;

void Buffer::produce(const fs::directory_entry& value) {
    std::unique_lock<std::mutex> lock(mtx);
    data.push(value);
    cond.notify_one();
}

const fs::directory_entry Buffer::consume() {
    std::unique_lock<std::mutex> lock(mtx);
    cond.wait(lock, [this] { return !data.empty(); });
    const fs::directory_entry value = data.front();
    data.pop();
    return value;
}
