#include <iostream>
#include <filesystem>
#include <string>
#include "FileSearch.h"

namespace fs = std::filesystem;

std::string target;

std::string DiskName;

int main() {
    std::cout<<"pls enter ur disk Name"<<std::endl;
    std::cin>>DiskName;
    fs::path const Dir = DiskName + ":/";
    std::cout << "Pls enter the target: ";
    std::cin>>target;

    DirectoryIteration(Dir, target);
    return 0;
}


