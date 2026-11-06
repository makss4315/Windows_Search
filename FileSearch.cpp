

#include <iostream>
#include "FileSearch.h"
#include <filesystem>
#include <string>

#include <vector>

#include <fstream>


int TargetCount;
std::vector<std::string> resultTargetList;
std::vector<std::string> LoadFromIndexPoolVector;

void LoadFromIndexPool()
{
    std::ifstream IndexPool("indexPool.txt");
    std::string line;
    if (IndexPool.is_open())
    {
        LoadFromIndexPoolVector.clear();
        while (std::getline(IndexPool, line))
        {
            std::cout<<line<<"\n";
            LoadFromIndexPoolVector.push_back(line);

        }
       
    } else
    {
        std::cerr <<"Cant open [IndexPool.txt]"<<"\n" ;
    }


}

void AddToIndexPoolPath(const fs::path& path, std::vector<std::string>& Paths)
{
    Paths.push_back(path.string());
}

void SaveToIndexPool(std::vector<std::string>& Paths)
{
    std::ofstream IndexPool;
    IndexPool.open("indexPool.txt");
    if (!IndexPool.is_open())
    {
        std::cout<<"Can't open [IndexPool.txt]"<<std::endl;

    }

    for(const auto& a: Paths)
    {
        IndexPool << a <<'\n';
    }

}


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
    std::vector<std::string> Paths;
    auto options = fs::directory_options::skip_permission_denied;

    std::error_code ErrorCode;

    auto FileIterator = fs::recursive_directory_iterator(path,options, ErrorCode);
     if (ErrorCode)
    {
       std::cerr<<"[error:]"
         << ErrorCode.message() <<"\n";

         return;

    }

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
            AddToIndexPoolPath(FileIterator->path(), Paths);



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





    }

SaveToIndexPool(Paths);
}