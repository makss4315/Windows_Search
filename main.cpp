#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main() {
    fs::path temp = "D:/TEST";

    for (auto& entry : fs::recursive_directory_iterator(temp))
    {
        std::cout<<entry.path().string()<<" ";

        if (entry.is_regular_file())
        {
            std::cout<<"[file]"
                                <<entry.file_size() << "[baits]";


        } else if (entry.is_directory())
        {
            std::cout<<"[directory]";
        }
            std::cout<<"\n";
    }


 

   }


//X:/TEST/hello_world.txt