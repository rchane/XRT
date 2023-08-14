// SPDX-License-Identifier: Apache-2.0
// Copyright (C) 2021-2022 Xilinx, Inc
// Copyright (C) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.

#include "NodeParser.h"
#include <iostream>
#include <filesystem>
#include <map>
#include <vector>

#include "tools/common/OptionOptions.h"

namespace fs = std::filesystem;

std::map<std::string, std::vector<std::string>> listDirectoryContents(const fs::path& directoryPath) {
  std::map<std::string, std::vector<std::string>> directoryContents;

  for (const auto& entry : fs::directory_iterator(directoryPath)) {
    if (entry.is_directory())
      directoryContents["subdirectories"].push_back(entry.path().filename().string());
    else if (entry.is_regular_file())
      directoryContents["files"].push_back(entry.path().filename().string());
  }
  
  return directoryContents;
}
