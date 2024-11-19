#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <thread>
#include "helpers.h"

int main(const int argc, const char *argv[]) {

    unsigned int available_threads = std::thread::hardware_concurrency();

    //ingest args
    if(argc < 3){
        std::cout << "Error please provide arguments. Arg1: pattern, Arg2: Directory path"  << std::endl;
        std::exit(1);
    }

    const std::string pattern = argv[1];
    const std::string searchDir = argv[2];
    std::unique_ptr<Buffer> buf = std::make_unique<Buffer>();

    //Spin up threads
    std::vector<std::jthread> threads;
    int i = 0;

    auto work = [&buf, &pattern](){ 
        while(!buf->isDone()){
            loadAndProcessFile(buf->consume(), pattern);
        }
    };

    for(int i=0; i < available_threads; i++){
        threads.push_back(std::jthread(work));
    }

    //Get list of all dirs
    recursiveSearch(buf, searchDir);

    return 0;
}
