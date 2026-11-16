// SPDX-License-Identifier: GPL-3.0-only
// Copyright (C) 2026 Maksym Shevchenko
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

     LoadFromIndexPool(target);
    
auto start = std::chrono::steady_clock::now();
    DirectoryIteration(Dir, target);

    auto finish = std::chrono::steady_clock::now();
    
    auto elapsed = finish - start;

    std::cout << "Time: "
              << std::chrono::duration<double, std::milli>(elapsed).count()
              << " ms\n";
    system("pause");
    return 0;
}


