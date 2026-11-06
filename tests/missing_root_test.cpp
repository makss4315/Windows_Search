
#include "FileSearch.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

int main()
{
    const fs::path missingRoot = "missing-root";
    if (fs::exists(missingRoot)) {
        std::cerr << "SETUP ERROR: missing-root must not exist\n";
        return 2;
    }

    {
        std::ofstream output("indexPool.txt");
        if (!(output << "previous-index\n")) {
            std::cerr << "SETUP ERROR: cannot create fixture index\n";
            return 2;
        }
    }

    // Act: use the real application function, without console input.
    DirectoryIteration(missingRoot, "anything.txt");

    // Assert: a failed scan must not erase the existing index.
    std::ifstream input("indexPool.txt");
    std::string line;
    if (!std::getline(input, line) || line != "previous-index") {
        std::cerr << "FAIL: failed scan changed the previous index\n";
        return 1;
    }

    std::cout << "PASS: failed scan preserved the previous index\n";
    return 0;


}
