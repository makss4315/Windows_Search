#include <iostream>
#include <filesystem>
#include <string>
#include "FileSearch.h"

namespace fs = std::filesystem;

std::string target;


int main() {
    fs::path const Dir = "D:/";
    std::cin>>target;

    DirectoryIteration(Dir);
    return 0;
}


