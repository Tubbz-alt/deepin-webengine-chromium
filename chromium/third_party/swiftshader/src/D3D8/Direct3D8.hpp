// Copyright 2016 The SwiftShader Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef D3D8_Direct3D8_hpp
#define D3D8_Direct3D8_hpp

#include "Unknown.hpp"

#include <stdio.h>
#include <initguid.h>
#include <d3d8.h>

namespace D3D8
{
	class Direct3DDevice8;

	class Direct3D8 : public IDirect3D8, protected Unknown
	{
	public:
		Direct3D8(int version, const HINSTANCE instance);

		virtual ~Direct3D8();

		// IUnknown methods
		long __stdcall QueryInterface(const IID &iid, void **object);
		unsigned long __stdcall AddRef();
		unsigned long __stdcall Release();

		// IDirect3D8 methods
		long __stdcall CheckDepthStencilMatch(unsigned int adapter, D3DDEVTYPE deviceType, D3DFORMAT adapterFormat, D3DFORMAT renderTargetFormat, D3DFORMAT depthStencilFormat);
		long __stdcall CheckDeviceFormat(unsigned int adapter, D3DDEVTYPE deviceType, D3DFORMAT adapaterFormat, unsigned long usage, D3DRESOURCETYPE type, D3DFORMAT checkFormat);
		long __stdcall CheckDeviceMultiSampleType(unsigned int adapter, D3DDEVTYPE deviceType, D3DFORMAT surfaceFormat, int windowed, D3DMULTISAMPLE_TYPE multiSampleType);
		long __stdcall CheckDeviceType(unsigned int adapter, D3DDEVTYPE checkType, D3DFORMAT displayFormat, D3DFORMAT backBufferFormat, int windowed);
		long __stdcall CreateDevice(unsigned int adapter, D3DDEVTYPE deviceType, HWND focusWindow, unsigned long behaviorFlags, D3DPRESENT_PARAMETERS *presentParameters, IDirect3DDevice8 **returnedDeviceInterface);
		long __stdcall EnumAdapterModes(unsigned int adapter, unsigned int index, D3DDISPLAYMODE *mode);
		unsigned int __stdcall GetAdapterCount();
		long __stdcall GetAdapterDisplayMode(unsigned int adapter, D3DDISPLAYMODE *mode);
		long __stdcall GetAdapterIdentifier(unsigned int adapter, unsigned long flags, D3DADAPTER_IDENTIFIER8 *identifier);
		unsigned int __stdcall GetAdapterModeCount(unsigned int adapter);
		HMONITOR __stdcall GetAdapterMonitor(unsigned int adapter);
		long __stdcall GetDeviceCaps(unsigned int adapter, D3DDEVTYPE deviceType, D3DCAPS8 *caps);
		long __stdcall RegisterSoftwareDevice(void *initializeFunction);

	private:
		void loadSystemD3D8();

		// Creation parameters
		const int version;
		const HINSTANCE instance;

		DEVMODE *displayMode;
		int numDisplayModes;

		// Real D3D8 library and IDirect3D8 object
		HMODULE d3d8Lib;
		IDirect3D8 *d3d8;
	};
}

#endif   // D3D8_Direct3D8_hpp
