#ifndef HELPERS_H
#define HELPERS_H

#include <filesystem>
#include "buffer.h"

namespace fs = std::filesystem;

void recursiveSearch(std::unique_ptr<Buffer>& buf, const fs::path& rootDir);
void loadAndProcessFile(const fs::directory_entry&& entry, const std::string& pattern);

#endif