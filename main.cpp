#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;
 bool isSystemPath(const fs::path& path)
    {
    std::string SystemFileName = path.filename().string();
        return SystemFileName == "Recovery"||
               SystemFileName [0] == '$';

    }
int main() {
    fs::path temp = "D:/";

    auto options = fs::directory_options::skip_permission_denied;

    std::error_code ErrorCode;

     auto FileIterator = fs::recursive_directory_iterator(temp,options, ErrorCode);

    while (FileIterator != fs::recursive_directory_iterator())
    {


        if (isSystemPath(FileIterator->path()))
        {
            FileIterator.disable_recursion_pending();
            std::cout<<"[system file: skip]"<<FileIterator->path().string()<<"\n";

        }

        if (FileIterator->is_regular_file())
        {
            std::cout<<"[file] "
                                <<FileIterator->path().string()<<"\t"
                                <<FileIterator->file_size() << "[bytes]";



        } else if (FileIterator->is_directory())
        {
            std::cout<<"[directory]";
        }
            std::cout<<"\n";

          FileIterator.increment(ErrorCode);

            if (ErrorCode)
            {
                std::cout<<"[error: skip ]" << FileIterator->path().string() <<"\n";
                ErrorCode.clear();

            }

    }


 

   }


//X:/TEST/hello_world.txt