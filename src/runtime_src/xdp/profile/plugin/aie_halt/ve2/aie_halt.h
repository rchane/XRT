/**
 * Copyright (C) 2025 Advanced Micro Devices, Inc. - All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You may
 * not use this file except in compliance with the License. A copy of the
 * License is located at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#ifndef XDP_PLUGIN_AIE_HALT_VE2_IMPL_H
#define XDP_PLUGIN_AIE_HALT_VE2_IMPL_H

#include "xdp/config.h"
#include "xdp/profile/plugin/aie_halt/aie_halt_impl.h"

namespace xdp {

  class AIEHaltVE2Impl : public AIEHaltImpl
  {

    public :
      explicit AIEHaltVE2Impl(VPDatabase* dB);

      ~AIEHaltVE2Impl() override = default;

      AIEHaltVE2Impl(const AIEHaltVE2Impl&) = delete;
      AIEHaltVE2Impl(AIEHaltVE2Impl&&)      = delete;

      AIEHaltVE2Impl& operator=(const AIEHaltVE2Impl&) = delete;
      AIEHaltVE2Impl& operator=(AIEHaltVE2Impl&&)      = delete;

      void updateDevice(void* hwCtxImpl) override;
      void finishflushDevice(void* hwCtxImpl) override;
  };

}

#endif