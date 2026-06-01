#pragma once

#include <filesystem>

namespace fs = std::filesystem;


bool isSystemPath(const fs::path& path);

void DirectoryIteration(const fs::path& path);

void FindTarget(const fs::path& path);

void ShowTargetList(const fs::path& path);