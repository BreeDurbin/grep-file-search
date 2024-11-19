#ifndef BUFFER_H
#define BUFFER_H

#include <filesystem>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <iostream>

namespace fs = std::filesystem;

class Buffer {
private:

    std::queue<fs::directory_entry> data;
    std::mutex mtx;
    std::condition_variable cond;
    bool finishedPopulating;

public:

    bool isDone(){ return finishedPopulating && data.size() == 0; }
    void setPopulated(){ finishedPopulating = true; }
    bool isPopulated(){ return finishedPopulating; }
    int size(){ return data.size(); }

    void produce(const fs::directory_entry& value);

    const fs::directory_entry consume();
};

#endif