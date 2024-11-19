#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <thread>
#include "helpers.h"

namespace fs = std::filesystem;

void recursiveSearch(std::unique_ptr<Buffer>& buf, const fs::path& rootDir) {
    
    for (const auto& entry : fs::recursive_directory_iterator(rootDir, fs::directory_options::skip_permission_denied)) {
        if (entry.is_regular_file()) {
            buf->produce(entry);
        }
    }

    buf->setPopulated();
}

void loadAndProcessFile(const fs::directory_entry&& entry, const std::string& pattern){

    std::ifstream inputFile(entry.path());
    std::string line;
    unsigned long long i = 0;

    while (std::getline(inputFile, line)) {
        if (std::string::npos != line.find(pattern)){
            std::cout << entry.path().filename().string() << ":" << "Line " << i << ": " << line << std::endl;
        }
        i++;
    }

    inputFile.close();

}