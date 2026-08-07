

#include <iostream>
#include "FileSearch.h"
#include <filesystem>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>


int TargetCount;
std::vector<std::string> resultTargetList;

bool isSystemPath(const fs::path& path)
{
    std::string SystemFileName = path.filename().string();
    return SystemFileName == "Recovery"||
           SystemFileName [0] == '$';

}

bool FindTarget(const fs::path& path, const std::string& target)
{
    std::string FileName = path.filename().string();
    if (target == FileName)
    {
        TargetCount++;
        resultTargetList.push_back(FileName);
        return true;
    }
    return false;
}



void DirectoryIteration(const fs::path& path, const std::string& target)
{
    auto options = fs::directory_options::skip_permission_denied;

    std::error_code ErrorCode;

    auto FileIterator = fs::recursive_directory_iterator(path,options, ErrorCode);

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

        if (FindTarget(FileIterator->path() ,target))
        {
            std::cout<<"[target find]"<<FileIterator->path().string()<<"\n";
           system("pause");
        }

        FileIterator.increment(ErrorCode);

        if (ErrorCode)
        {
            std::cout<<"[error: skip ]" << FileIterator->path().string() <<"\n";
            ErrorCode.clear();

        }



    }
}