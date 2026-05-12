// SPDX-License-Identifier: Apache-2.0
// Copyright (C) 2023 Advanced Micro Devices, Inc. All rights reserved.
#define XRT_CORE_COMMON_SOURCE
#include "sysinfo.h"
#include "detail/sysinfo.h"
#include "system.h"

#include "xrt/detail/version-git.h"

#include <boost/algorithm/string/predicate.hpp>

#include <cstdlib>
#ifdef _WIN32
# include <windows.h>
#endif

namespace xrt_core::sysinfo {

void
get_xrt_info(boost::property_tree::ptree& pt)
{
  pt.put("version",         xrt_build_version);
  pt.put("branch",          xrt_build_version_branch);
  pt.put("hash",            xrt_build_version_hash);
  pt.put("build_hash_date", xrt_build_version_hash_date);
  xrt_core::get_driver_info(pt);
}

void
get_xrt_build_info(boost::property_tree::ptree& pt)
{
  pt.put("version",         xrt_build_version);
  pt.put("branch",          xrt_build_version_branch);
  pt.put("hash",            xrt_build_version_hash);
  pt.put("build_hash_date", xrt_build_version_hash_date);
}

void
get_os_info(boost::property_tree::ptree& pt)
{
  xrt_core::sysinfo::detail::get_os_info(pt);
}

boost::property_tree::ptree
get_os_info()
{
  boost::property_tree::ptree pt;
  get_os_info(pt);
  return pt;
}

bool
is_advanced()
{
  const char* v = std::getenv("XRTSMIAdvanced"); // NOLINT(concurrency-mt-unsafe)
  if (v && boost::iequals(v, "1"))
    return true;

  // TODO: Remove when phasing out reg check for Windows
#ifdef _WIN32
  DWORD value = 0;
  DWORD valueSize = sizeof(value);
  DWORD valueType;
  LONG result = RegGetValueA(HKEY_LOCAL_MACHINE, "SYSTEM\\ControlSet001\\Services\\IpuMcdmDriver", "XRTSMIAdvanced", RRF_RT_REG_DWORD, &valueType, &value, &valueSize);
  if ((result == ERROR_SUCCESS) && (valueType == REG_DWORD) && (value == 1))
    return true;

  result = RegGetValueA(HKEY_LOCAL_MACHINE, "SYSTEM\\ControlSet001\\Services\\Npu2McdmDriver", "XRTSMIAdvanced", RRF_RT_REG_DWORD, &valueType, &value, &valueSize);
  if ((result == ERROR_SUCCESS) && (valueType == REG_DWORD) && (value == 1))
    return true;
#endif

  return false;
}

} //xrt_core::sysinfo
