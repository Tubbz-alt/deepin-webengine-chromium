// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_MUS_SURFACES_DIRECT_OUTPUT_SURFACES_OZONE_H_
#define COMPONENTS_MUS_SURFACES_DIRECT_OUTPUT_SURFACES_OZONE_H_

#include "base/macros.h"
#include "gpu/command_buffer/client/gpu_memory_buffer_manager.h"

namespace mus {

class OzoneGpuMemoryBufferManager : public gpu::GpuMemoryBufferManager {
 public:
  OzoneGpuMemoryBufferManager();
  ~OzoneGpuMemoryBufferManager() override;

  // gpu::GpuMemoryBufferManager:
  std::unique_ptr<gfx::GpuMemoryBuffer> AllocateGpuMemoryBuffer(
      const gfx::Size& size,
      gfx::BufferFormat format,
      gfx::BufferUsage usage,
      gpu::SurfaceHandle surface_handle) override;
  std::unique_ptr<gfx::GpuMemoryBuffer> CreateGpuMemoryBufferFromHandle(
      const gfx::GpuMemoryBufferHandle& handle,
      const gfx::Size& size,
      gfx::BufferFormat format) override;
  gfx::GpuMemoryBuffer* GpuMemoryBufferFromClientBuffer(
      ClientBuffer buffer) override;
  void SetDestructionSyncToken(gfx::GpuMemoryBuffer* buffer,
                               const gpu::SyncToken& sync_token) override;

 private:
  DISALLOW_COPY_AND_ASSIGN(OzoneGpuMemoryBufferManager);
};

}  // namespace mus

#endif  // COMPONENTS_MUS_SURFACES_DIRECT_OUTPUT_SURFACES_OZONE_H_
