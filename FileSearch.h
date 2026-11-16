// SPDX-License-Identifier: GPL-3.0-only
// Copyright (C) 2026 Maksym Shevchenko
#pragma once

#include <filesystem>

namespace fs = std::filesystem;


bool isSystemPath(const fs::path& path);

void DirectoryIteration(const fs::path& path, const std::string& target);

bool FindTarget(const fs::path& path, const std::string& target);

void ShowTargetList(const fs::path& path);

void LoadFromIndexPool(const std::string& target);