/**
 * Copyright (C) 2020 Xilinx, Inc
 * Author(s): Himanshu Choudhary <hchoudha@xilinx.com>
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

#ifndef AIE_D_H
#define AIE_D_H

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <thread>
#include <pthread.h> 
#include "core/common/device.h"
#include "graph_object.h"

/*
 * It receives commands from zocl and dispatches back the output.
 * One typical command is get graph status.
 */
namespace zynqaie {

class aied
{
public:
  aied(xrt_core::device* device);
  ~aied();
  void register_graph(const graph_object *graph);
  void deregister_graph(const graph_object *graph);

private:
  bool done;
  static void* poll_aie(void *arg);
  xrt_core::device *m_device;
  std::vector<const graph_object*> m_graphs;
  pthread_t ptid;
};
} // end namespace

#endif
