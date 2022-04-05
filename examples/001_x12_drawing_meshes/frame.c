#include "frame.h"

#include <stdlib.h> // For calloc, free, strtoul

#include "depthpass.hlsl.vs.h"

#include "scenepass.hlsl.vs.h"
#include "scenepass.hlsl.ps.h"

int fileMap   (const wchar_t * filepath, void ** outFileDescriptorHandle, void ** outFileMappingHandle, uint64_t * outFileDataBytesCount, void ** outFileData);
int fileUnmap (void * fileDescriptorHandle, void * fileMappingHandle);

#ifdef __cplusplus
extern "C"
#endif
__declspec(dllexport) int frame(int recompileRequested, void * dataFromMain) {
  int recompile = recompileRequested;
  
  X12Factory4 * factory = globalCacheGetAsP(L"", L"X12Factory4", L"factory");
  if (factory == 0) {
    x12CreateFactory2(DXGI_CREATE_FACTORY_FLAG_DEBUG, &factory, __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12Factory4", L"factory", factory);
  }
  
  X12Adapter3 * adapter = globalCacheGetAsP(L"", L"X12Adapter3", L"adapter");
  if (adapter == 0) {
    x12FactoryEnumAdapters1(factory, 0, &adapter, __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12Adapter3", L"adapter", adapter);
  }
  
  X12Device3 * device = globalCacheGetAsP(L"", L"X12Device3", L"device");
  if (device == 0) {
    x12CreateDevice(adapter, D3D_FEATURE_LEVEL_12_0, &device, __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12Device3", L"device", device);
  }
  
  X12CommandQueue * queue = globalCacheGetAsP(L"", L"X12CommandQueue", L"queue");
  if (queue == 0) {
    D3D12_COMMAND_QUEUE_DESC queueDescription = {};
    queueDescription.Type     = D3D12_COMMAND_LIST_TYPE_DIRECT;
    queueDescription.Priority = D3D12_COMMAND_QUEUE_PRIORITY_HIGH;
    queueDescription.Flags    = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queueDescription.NodeMask = 0;
    x12DeviceCreateCommandQueue(device, &queueDescription, &queue, __FILE__, __LINE__);
    x12ObjectSetName(queue, L"queue", __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12CommandQueue", L"queue", queue);
  }
  
  X12SwapChain3 * swapchain = globalCacheGetAsP(L"", L"X12SwapChain3", L"swapchain");
  if (swapchain == 0) {
    DXGI_SWAP_CHAIN_DESC1 swapchainDesc = {};
    swapchainDesc.Width              = 1800; // NOTE(Constantine): Hardcoded.
    swapchainDesc.Height             = 900;  // NOTE(Constantine): Hardcoded.
    swapchainDesc.Format             = DXGI_FORMAT_B8G8R8A8_UNORM;
    swapchainDesc.Stereo             = 0;
    swapchainDesc.SampleDesc.Count   = 1;
    swapchainDesc.SampleDesc.Quality = 0;
    swapchainDesc.BufferUsage        = DXGI_USAGE_FLAG_RENDER_TARGET_OUTPUT;
    swapchainDesc.BufferCount        = 2;
    swapchainDesc.Scaling            = DXGI_SCALING_STRETCH;
    swapchainDesc.SwapEffect         = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    swapchainDesc.AlphaMode          = DXGI_ALPHA_MODE_IGNORE;
    swapchainDesc.Flags              = 0;
    x12FactoryCreateSwapChainForHwnd(factory, queue, glfwGetWin32Window((GLFWwindow *)dataFromMain), &swapchainDesc, 0, 0, &swapchain, __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12SwapChain3", L"swapchain", swapchain);
  }
  
  X12Resource * swapchainResources[2] = {};
  swapchainResources[0] = globalCacheGetAsP(L"", L"X12Resource", L"swapchainResources[0]");
  swapchainResources[1] = globalCacheGetAsP(L"", L"X12Resource", L"swapchainResources[1]");
  if (swapchainResources[0] == 0) {
    x12SwapChainGetBuffer(swapchain, 0, &swapchainResources[0], __FILE__, __LINE__);
    x12ObjectSetName(swapchainResources[0], L"swapchainResources[0]", __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12Resource", L"swapchainResources[0]", swapchainResources[0]);
  }
  if (swapchainResources[1] == 0) {
    x12SwapChainGetBuffer(swapchain, 1, &swapchainResources[1], __FILE__, __LINE__);
    x12ObjectSetName(swapchainResources[1], L"swapchainResources[1]", __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12Resource", L"swapchainResources[1]", swapchainResources[1]);
  }
  
  X12DescriptorHeap * swapchainDescriptorsCpuHeapRTV[2] = {};
  swapchainDescriptorsCpuHeapRTV[0] = globalCacheGetAsP(L"", L"X12DescriptorHeap", L"swapchainDescriptorsCpuHeapRTV[0]");
  swapchainDescriptorsCpuHeapRTV[1] = globalCacheGetAsP(L"", L"X12DescriptorHeap", L"swapchainDescriptorsCpuHeapRTV[1]");
  D3D12_CPU_DESCRIPTOR_HANDLE swapchainDescriptorsCpuDescriptorRTV[2] = {};
  swapchainDescriptorsCpuDescriptorRTV[0].ptr = (size_t)globalCacheGetAsP(L"", L"", L"swapchainDescriptorsCpuDescriptorRTV[0].ptr");
  swapchainDescriptorsCpuDescriptorRTV[1].ptr = (size_t)globalCacheGetAsP(L"", L"", L"swapchainDescriptorsCpuDescriptorRTV[1].ptr");
  if (swapchainDescriptorsCpuHeapRTV[0] == 0) {
    D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDesc = {};
    descriptorHeapDesc.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
    descriptorHeapDesc.NumDescriptors = 1;
    descriptorHeapDesc.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
    descriptorHeapDesc.NodeMask       = 0;
    x12DeviceCreateDescriptorHeap(device, &descriptorHeapDesc, &swapchainDescriptorsCpuHeapRTV[0], __FILE__, __LINE__);
    x12ObjectSetName(swapchainDescriptorsCpuHeapRTV[0], L"swapchainDescriptorsCpuHeapRTV[0]", __FILE__, __LINE__);
    x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(swapchainDescriptorsCpuHeapRTV[0], &swapchainDescriptorsCpuDescriptorRTV[0]);
    D3D12_RENDER_TARGET_VIEW_DESC rtvDescription = {};
    rtvDescription.Format               = DXGI_FORMAT_B8G8R8A8_UNORM_SRGB;
    rtvDescription.ViewDimension        = D3D12_RTV_DIMENSION_TEXTURE2D;
    rtvDescription.Texture2D.MipSlice   = 0;
    rtvDescription.Texture2D.PlaneSlice = 0;
    x12DeviceCreateRenderTargetView(device, swapchainResources[0], &rtvDescription, swapchainDescriptorsCpuDescriptorRTV[0], __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12DescriptorHeap", L"swapchainDescriptorsCpuHeapRTV[0]", swapchainDescriptorsCpuHeapRTV[0]);
    globalCacheSetAsP(L"", L"", L"swapchainDescriptorsCpuDescriptorRTV[0].ptr", (void *)swapchainDescriptorsCpuDescriptorRTV[0].ptr);
  }
  if (swapchainDescriptorsCpuHeapRTV[1] == 0) {
    D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDesc = {};
    descriptorHeapDesc.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
    descriptorHeapDesc.NumDescriptors = 1;
    descriptorHeapDesc.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
    descriptorHeapDesc.NodeMask       = 0;
    x12DeviceCreateDescriptorHeap(device, &descriptorHeapDesc, &swapchainDescriptorsCpuHeapRTV[1], __FILE__, __LINE__);
    x12ObjectSetName(swapchainDescriptorsCpuHeapRTV[1], L"swapchainDescriptorsCpuHeapRTV[1]", __FILE__, __LINE__);
    x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(swapchainDescriptorsCpuHeapRTV[1], &swapchainDescriptorsCpuDescriptorRTV[1]);
    D3D12_RENDER_TARGET_VIEW_DESC rtvDescription = {};
    rtvDescription.Format               = DXGI_FORMAT_B8G8R8A8_UNORM_SRGB;
    rtvDescription.ViewDimension        = D3D12_RTV_DIMENSION_TEXTURE2D;
    rtvDescription.Texture2D.MipSlice   = 0;
    rtvDescription.Texture2D.PlaneSlice = 0;
    x12DeviceCreateRenderTargetView(device, swapchainResources[1], &rtvDescription, swapchainDescriptorsCpuDescriptorRTV[1], __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12DescriptorHeap", L"swapchainDescriptorsCpuHeapRTV[1]", swapchainDescriptorsCpuHeapRTV[1]);
    globalCacheSetAsP(L"", L"", L"swapchainDescriptorsCpuDescriptorRTV[1].ptr", (void *)swapchainDescriptorsCpuDescriptorRTV[1].ptr);
  }
  
  X12Resource * arrayConstantBufferCameraMatrices              = globalCacheGetAsP(L"", L"X12Resource", L"arrayConstantBufferCameraMatrices");
  void *        arrayConstantBufferCameraMatricesMemoryPointer = globalCacheGetAsP(L"", L"", L"arrayConstantBufferCameraMatricesMemoryPointer");
  if (arrayConstantBufferCameraMatrices == 0) {
    D3D12_HEAP_PROPERTIES props = {};
    props.Type                 = D3D12_HEAP_TYPE_UPLOAD;
    props.CPUPageProperty      = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    props.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
    props.CreationNodeMask     = 0;
    props.VisibleNodeMask      = 0;
    D3D12_RESOURCE_DESC desc = {};
    desc.Dimension          = D3D12_RESOURCE_DIMENSION_BUFFER;
    desc.Alignment          = 0;
    desc.Width              = 128;
    desc.Height             = 1;
    desc.DepthOrArraySize   = 1;
    desc.MipLevels          = 1;
    desc.Format             = DXGI_FORMAT_UNKNOWN;
    desc.SampleDesc.Count   = 1;
    desc.SampleDesc.Quality = 0;
    desc.Layout             = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
    desc.Flags              = D3D12_RESOURCE_FLAG_NONE;
    x12DeviceCreateCommittedResource(device, &props, D3D12_HEAP_FLAG_ALLOW_ALL_BUFFERS_AND_TEXTURES, &desc, D3D12_RESOURCE_STATE_GENERIC_READ, 0, &arrayConstantBufferCameraMatrices, __FILE__, __LINE__);
    x12ObjectSetName(arrayConstantBufferCameraMatrices, L"arrayConstantBufferCameraMatrices", __FILE__, __LINE__);
    D3D12_RANGE range = {};
    range.Begin = 0;
    range.End   = 128;
    x12ResourceMap(arrayConstantBufferCameraMatrices, 0, &range, &arrayConstantBufferCameraMatricesMemoryPointer, __FILE__, __LINE__);
    const float arrayConstantBufferCameraMatricesData[] = {
      1.0978291,   0.219721511,-0.599208534, -0.596811712,
      0,          -1.69420147, -0.208746701, -0.207911715,
     -0.84544158,  0.285314411,-0.778088748, -0.774976432,
      0,           0,           2.97696114,   3.06505346,
      0.571785212,-0,          -0.440334648, -4.94717995e-007,
      0.073240526,-0.564733446, 0.0951047391, 0,
      -18.2194118,-6.34710836, -23.6584053,  -9.9599905,
      17.6957684,  6.16468668,  22.9784412,   9.99998951
    };
    float * p = (float *)arrayConstantBufferCameraMatricesMemoryPointer;
    for (unsigned i = 0; i < _countof(arrayConstantBufferCameraMatricesData); i += 1) {
      p[i] = arrayConstantBufferCameraMatricesData[i];
    }
    globalCacheSetAsP(L"", L"X12Resource", L"arrayConstantBufferCameraMatrices", arrayConstantBufferCameraMatrices);
    globalCacheSetAsP(L"", L"", L"arrayConstantBufferCameraMatricesMemoryPointer", arrayConstantBufferCameraMatricesMemoryPointer);
  }
  
  X12Resource * arrayConstantBufferLightMatrices              = globalCacheGetAsP(L"", L"X12Resource", L"arrayConstantBufferLightMatrices");
  void *        arrayConstantBufferLightMatricesMemoryPointer = globalCacheGetAsP(L"", L"", L"arrayConstantBufferLightMatricesMemoryPointer");
  if (arrayConstantBufferLightMatrices == 0) {
    D3D12_HEAP_PROPERTIES props = {};
    props.Type                 = D3D12_HEAP_TYPE_UPLOAD;
    props.CPUPageProperty      = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    props.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
    props.CreationNodeMask     = 0;
    props.VisibleNodeMask      = 0;
    D3D12_RESOURCE_DESC desc = {};
    desc.Dimension          = D3D12_RESOURCE_DIMENSION_BUFFER;
    desc.Alignment          = 0;
    desc.Width              = 128;
    desc.Height             = 1;
    desc.DepthOrArraySize   = 1;
    desc.MipLevels          = 1;
    desc.Format             = DXGI_FORMAT_UNKNOWN;
    desc.SampleDesc.Count   = 1;
    desc.SampleDesc.Quality = 0;
    desc.Layout             = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
    desc.Flags              = D3D12_RESOURCE_FLAG_NONE;
    x12DeviceCreateCommittedResource(device, &props, D3D12_HEAP_FLAG_ALLOW_ALL_BUFFERS_AND_TEXTURES, &desc, D3D12_RESOURCE_STATE_GENERIC_READ, 0, &arrayConstantBufferLightMatrices, __FILE__, __LINE__);
    x12ObjectSetName(arrayConstantBufferLightMatrices, L"arrayConstantBufferLightMatrices", __FILE__, __LINE__);
    D3D12_RANGE range = {};
    range.Begin = 0;
    range.End   = 128;
    x12ResourceMap(arrayConstantBufferLightMatrices, 0, &range, &arrayConstantBufferLightMatricesMemoryPointer, __FILE__, __LINE__);
    float arrayConstantBufferLightMatricesData[] = {
      0.137147039, -1.54432929,     0.447599858,  0.445809454,
      0,           -0.774596691,   -0.898019314, -0.89442724,
      1.72661245,   0.122668043,   -0.0355534293,-0.0354112163,
      0,            0.0881770551,   11.227067,    11.2821589,
      0.0457157306,-1.9788817e-007, 0.575539529, -0,
     -0.514775217, -0.258198142,    0.0408894382, 0,
      49.6438293,  -100.734207,    -3.94327331,  -9.96003819,
     -49.3973885,   100.244331,     3.92369819,   10.0000391
    };
    float * p = (float *)arrayConstantBufferLightMatricesMemoryPointer;
    for (unsigned i = 0; i < _countof(arrayConstantBufferLightMatricesData); i += 1) {
      p[i] = arrayConstantBufferLightMatricesData[i];
    }
    globalCacheSetAsP(L"", L"X12Resource", L"arrayConstantBufferLightMatrices", arrayConstantBufferLightMatrices);
    globalCacheSetAsP(L"", L"", L"arrayConstantBufferLightMatricesMemoryPointer", arrayConstantBufferLightMatricesMemoryPointer);
  }
  
  X12Resource * arrayVertices              = globalCacheGetAsP(L"", L"X12Resource", L"arrayVertices");
  void *        arrayVerticesMemoryPointer = globalCacheGetAsP(L"", L"", L"arrayVerticesMemoryPointer");
  if (arrayVertices == 0) {
    D3D12_HEAP_PROPERTIES props = {};
    props.Type                 = D3D12_HEAP_TYPE_UPLOAD;
    props.CPUPageProperty      = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    props.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
    props.CreationNodeMask     = 0;
    props.VisibleNodeMask      = 0;
    D3D12_RESOURCE_DESC desc = {};
    desc.Dimension          = D3D12_RESOURCE_DIMENSION_BUFFER;
    desc.Alignment          = 0;
    desc.Width              = 3857976;
    desc.Height             = 1;
    desc.DepthOrArraySize   = 1;
    desc.MipLevels          = 1;
    desc.Format             = DXGI_FORMAT_UNKNOWN;
    desc.SampleDesc.Count   = 1;
    desc.SampleDesc.Quality = 0;
    desc.Layout             = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
    desc.Flags              = D3D12_RESOURCE_FLAG_NONE;
    x12DeviceCreateCommittedResource(device, &props, D3D12_HEAP_FLAG_ALLOW_ALL_BUFFERS_AND_TEXTURES, &desc, D3D12_RESOURCE_STATE_GENERIC_READ, 0, &arrayVertices, __FILE__, __LINE__);
    x12ObjectSetName(arrayVertices, L"arrayVertices", __FILE__, __LINE__);
    D3D12_RANGE range = {};
    range.Begin = 0;
    range.End   = 3857976;
    x12ResourceMap(arrayVertices, 0, &range, &arrayVerticesMemoryPointer, __FILE__, __LINE__);
    {
      void *   fh    = 0;
      void *   fm    = 0;
      uint64_t fsize = 0;
      void *   fdata = 0;
      fileMap(L"vertices_3857976.h", &fh, &fm, &fsize, &fdata);
      char * data = (char *)fdata;

      // assert(fsize == 11570588);

      unsigned * arrayDataVertices = (unsigned *)calloc(1, 964494 * sizeof(unsigned));

      size_t j = 0;
      size_t k = 0;
      char   printValue[512] = {};
      int    endOfValue = 0;
      for (size_t i = 0; i < fsize; i += 1) {
        if (endOfValue == 1) {
          endOfValue = 0;
          j = 0;
        }
        if (data[i] == '0' || data[i] == '1' || data[i] == '2' || data[i] == '3' || data[i] == '4' ||
            data[i] == '5' || data[i] == '6' || data[i] == '7' || data[i] == '8' || data[i] == '9')
        {
          printValue[j] = data[i];
          j += 1;
        } else {
          endOfValue = 1;
        }
        if (endOfValue == 1 && j > 0) {
          unsigned value = (unsigned)strtoul(printValue, 0, 0);
          arrayDataVertices[k] = value;
          k += 1;
          for (unsigned l = 0; l < 512; l += 1) {
            printValue[l] = 0;
          }
        }
      }
      // assert(k == 964494);
      // assert(arrayDataVertices[964494-1] == 3211563010);

      unsigned * p = (unsigned *)arrayVerticesMemoryPointer;
      for (unsigned i = 0; i < 964494; i += 1) {
        p[i] = arrayDataVertices[i];
      }

      free(arrayDataVertices);
      fileUnmap(fh, fm);
    }
    globalCacheSetAsP(L"", L"X12Resource", L"arrayVertices", arrayVertices);
    globalCacheSetAsP(L"", L"", L"arrayVerticesMemoryPointer", arrayVerticesMemoryPointer);
  }
  
  X12Resource * arrayIndices              = globalCacheGetAsP(L"", L"X12Resource", L"arrayIndices");
  void *        arrayIndicesMemoryPointer = globalCacheGetAsP(L"", L"", L"arrayIndicesMemoryPointer");
  if (arrayIndices == 0) {
    D3D12_HEAP_PROPERTIES props = {};
    props.Type                 = D3D12_HEAP_TYPE_UPLOAD;
    props.CPUPageProperty      = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    props.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
    props.CreationNodeMask     = 0;
    props.VisibleNodeMask      = 0;
    D3D12_RESOURCE_DESC desc = {};
    desc.Dimension          = D3D12_RESOURCE_DIMENSION_BUFFER;
    desc.Alignment          = 0;
    desc.Width              = 642996;
    desc.Height             = 1;
    desc.DepthOrArraySize   = 1;
    desc.MipLevels          = 1;
    desc.Format             = DXGI_FORMAT_UNKNOWN;
    desc.SampleDesc.Count   = 1;
    desc.SampleDesc.Quality = 0;
    desc.Layout             = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
    desc.Flags              = D3D12_RESOURCE_FLAG_NONE;
    x12DeviceCreateCommittedResource(device, &props, D3D12_HEAP_FLAG_ALLOW_ALL_BUFFERS_AND_TEXTURES, &desc, D3D12_RESOURCE_STATE_GENERIC_READ, 0, &arrayIndices, __FILE__, __LINE__);
    x12ObjectSetName(arrayIndices, L"arrayIndices", __FILE__, __LINE__);
    D3D12_RANGE range = {};
    range.Begin = 0;
    range.End   = 642996;
    x12ResourceMap(arrayIndices, 0, &range, &arrayIndicesMemoryPointer, __FILE__, __LINE__);
    {
      void *   fh    = 0;
      void *   fm    = 0;
      uint64_t fsize = 0;
      void *   fdata = 0;
      fileMap(L"indices_642996.h", &fh, &fm, &fsize, &fdata);
      char * data = (char *)fdata;

      // assert(fsize == 1174881);

      unsigned * arrayDataIndices = (unsigned *)calloc(1, 160749 * sizeof(unsigned));

      size_t j = 0;
      size_t k = 0;
      char   printValue[512] = {};
      int    endOfValue = 0;
      for (size_t i = 0; i < fsize; i += 1) {
        if (endOfValue == 1) {
          endOfValue = 0;
          j = 0;
        }
        if (data[i] == '0' || data[i] == '1' || data[i] == '2' || data[i] == '3' || data[i] == '4' ||
            data[i] == '5' || data[i] == '6' || data[i] == '7' || data[i] == '8' || data[i] == '9')
        {
          printValue[j] = data[i];
          j += 1;
        } else {
          endOfValue = 1;
        }
        if (endOfValue == 1 && j > 0) {
          unsigned value = (unsigned)strtoul(printValue, 0, 0);
          arrayDataIndices[k] = value;
          k += 1;
          for (unsigned l = 0; l < 512; l += 1) {
            printValue[l] = 0;
          }
        }
      }
      // assert(k == 160749);
      // assert(arrayDataIndices[160749-1] == 160746);

      unsigned * p = (unsigned *)arrayIndicesMemoryPointer;
      for (unsigned i = 0; i < 160749; i += 1) {
        p[i] = arrayDataIndices[i];
      }

      free(arrayDataIndices);
      fileUnmap(fh, fm);
    }
    globalCacheSetAsP(L"", L"X12Resource", L"arrayIndices", arrayIndices);
    globalCacheSetAsP(L"", L"", L"arrayIndicesMemoryPointer", arrayIndicesMemoryPointer);
  }
  
  X12Resource * imageDepth = globalCacheGetAsP(L"", L"X12Resource", L"imageDepth");
  if (imageDepth == 0) {
    D3D12_HEAP_PROPERTIES props = {};
    props.Type                 = D3D12_HEAP_TYPE_DEFAULT;
    props.CPUPageProperty      = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    props.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
    props.CreationNodeMask     = 0;
    props.VisibleNodeMask      = 0;
    D3D12_RESOURCE_DESC desc = {};
    desc.Dimension          = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
    desc.Alignment          = 0;
    desc.Width              = 1800; // NOTE(Constantine): Hardcoded.
    desc.Height             = 900;  // NOTE(Constantine): Hardcoded.
    desc.DepthOrArraySize   = 1;
    desc.MipLevels          = 1;
    desc.Format             = DXGI_FORMAT_D32_FLOAT;
    desc.SampleDesc.Count   = 1;
    desc.SampleDesc.Quality = 0;
    desc.Layout             = D3D12_TEXTURE_LAYOUT_UNKNOWN;
    desc.Flags              = D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL;
    D3D12_CLEAR_VALUE clearValue = {};
    clearValue.Format               = DXGI_FORMAT_D32_FLOAT;
    clearValue.DepthStencil.Depth   = 1.f;
    clearValue.DepthStencil.Stencil = 0;
    x12DeviceCreateCommittedResource(device, &props, D3D12_HEAP_FLAG_ALLOW_ALL_BUFFERS_AND_TEXTURES, &desc, D3D12_RESOURCE_STATE_GENERIC_READ, &clearValue, &imageDepth, __FILE__, __LINE__);
    x12ObjectSetName(imageDepth, L"imageDepth", __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12Resource", L"imageDepth", imageDepth);
  }
  
  X12Resource * imageShadow = globalCacheGetAsP(L"", L"X12Resource", L"imageShadow");
  if (imageShadow == 0) {
    D3D12_HEAP_PROPERTIES props = {};
    props.Type                 = D3D12_HEAP_TYPE_DEFAULT;
    props.CPUPageProperty      = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
    props.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
    props.CreationNodeMask     = 0;
    props.VisibleNodeMask      = 0;
    D3D12_RESOURCE_DESC desc = {};
    desc.Dimension          = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
    desc.Alignment          = 0;
    desc.Width              = 2048;
    desc.Height             = 2048;
    desc.DepthOrArraySize   = 1;
    desc.MipLevels          = 1;
    desc.Format             = DXGI_FORMAT_R32_TYPELESS;
    desc.SampleDesc.Count   = 1;
    desc.SampleDesc.Quality = 0;
    desc.Layout             = D3D12_TEXTURE_LAYOUT_UNKNOWN;
    desc.Flags              = D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL;
    D3D12_CLEAR_VALUE clearValue = {};
    clearValue.Format               = DXGI_FORMAT_D32_FLOAT;
    clearValue.DepthStencil.Depth   = 1.f;
    clearValue.DepthStencil.Stencil = 0;
    x12DeviceCreateCommittedResource(device, &props, D3D12_HEAP_FLAG_ALLOW_ALL_BUFFERS_AND_TEXTURES, &desc, D3D12_RESOURCE_STATE_GENERIC_READ, &clearValue, &imageShadow, __FILE__, __LINE__);
    x12ObjectSetName(imageShadow, L"imageShadow", __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12Resource", L"imageShadow", imageShadow);
  }
  
  X12DescriptorHeap *         arrayConstantBufferCameraMatricesSrvCpuHeapCBVSRVUAV       = globalCacheGetAsP(L"", L"X12DescriptorHeap", L"arrayConstantBufferCameraMatricesSrvCpuHeapCBVSRVUAV");
  D3D12_CPU_DESCRIPTOR_HANDLE arrayConstantBufferCameraMatricesSrvCpuDescriptorCBVSRVUAV = {};
  arrayConstantBufferCameraMatricesSrvCpuDescriptorCBVSRVUAV.ptr = (size_t)globalCacheGetAsP(L"", L"", L"arrayConstantBufferCameraMatricesSrvCpuDescriptorCBVSRVUAV");
  if (arrayConstantBufferCameraMatricesSrvCpuHeapCBVSRVUAV == 0) {
    D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDesc = {};
    descriptorHeapDesc.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    descriptorHeapDesc.NumDescriptors = 1;
    descriptorHeapDesc.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
    descriptorHeapDesc.NodeMask       = 0;
    x12DeviceCreateDescriptorHeap(device, &descriptorHeapDesc, &arrayConstantBufferCameraMatricesSrvCpuHeapCBVSRVUAV, __FILE__, __LINE__);
    x12ObjectSetName(arrayConstantBufferCameraMatricesSrvCpuHeapCBVSRVUAV, L"arrayConstantBufferCameraMatricesSrvCpuHeapCBVSRVUAV", __FILE__, __LINE__);
    x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(arrayConstantBufferCameraMatricesSrvCpuHeapCBVSRVUAV, &arrayConstantBufferCameraMatricesSrvCpuDescriptorCBVSRVUAV);
    D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
    srvDesc.Format                     = DXGI_FORMAT_UNKNOWN;
    srvDesc.ViewDimension              = D3D12_SRV_DIMENSION_BUFFER;
    srvDesc.Shader4ComponentMapping    = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
    srvDesc.Buffer.FirstElement        = 0;
    srvDesc.Buffer.NumElements         = 1;
    srvDesc.Buffer.StructureByteStride = 128;
    srvDesc.Buffer.Flags               = D3D12_BUFFER_SRV_FLAG_NONE;
    x12DeviceCreateShaderResourceView(device, arrayConstantBufferCameraMatrices, &srvDesc, arrayConstantBufferCameraMatricesSrvCpuDescriptorCBVSRVUAV, __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12DescriptorHeap", L"arrayConstantBufferCameraMatricesSrvCpuHeapCBVSRVUAV", arrayConstantBufferCameraMatricesSrvCpuHeapCBVSRVUAV);
    globalCacheSetAsP(L"", L"", L"arrayConstantBufferCameraMatricesSrvCpuDescriptorCBVSRVUAV", (void *)arrayConstantBufferCameraMatricesSrvCpuDescriptorCBVSRVUAV.ptr);
  }
  
  X12DescriptorHeap *         arrayConstantBufferLightMatricesSrvCpuHeapCBVSRVUAV       = globalCacheGetAsP(L"", L"X12DescriptorHeap", L"arrayConstantBufferLightMatricesSrvCpuHeapCBVSRVUAV");
  D3D12_CPU_DESCRIPTOR_HANDLE arrayConstantBufferLightMatricesSrvCpuDescriptorCBVSRVUAV = {};
  arrayConstantBufferLightMatricesSrvCpuDescriptorCBVSRVUAV.ptr = (size_t)globalCacheGetAsP(L"", L"", L"arrayConstantBufferLightMatricesSrvCpuDescriptorCBVSRVUAV");
  if (arrayConstantBufferLightMatricesSrvCpuHeapCBVSRVUAV == 0) {
    D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDesc = {};
    descriptorHeapDesc.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    descriptorHeapDesc.NumDescriptors = 1;
    descriptorHeapDesc.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
    descriptorHeapDesc.NodeMask       = 0;
    x12DeviceCreateDescriptorHeap(device, &descriptorHeapDesc, &arrayConstantBufferLightMatricesSrvCpuHeapCBVSRVUAV, __FILE__, __LINE__);
    x12ObjectSetName(arrayConstantBufferLightMatricesSrvCpuHeapCBVSRVUAV, L"arrayConstantBufferLightMatricesSrvCpuHeapCBVSRVUAV", __FILE__, __LINE__);
    x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(arrayConstantBufferLightMatricesSrvCpuHeapCBVSRVUAV, &arrayConstantBufferLightMatricesSrvCpuDescriptorCBVSRVUAV);
    D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
    srvDesc.Format                     = DXGI_FORMAT_UNKNOWN;
    srvDesc.ViewDimension              = D3D12_SRV_DIMENSION_BUFFER;
    srvDesc.Shader4ComponentMapping    = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
    srvDesc.Buffer.FirstElement        = 0;
    srvDesc.Buffer.NumElements         = 1;
    srvDesc.Buffer.StructureByteStride = 128;
    srvDesc.Buffer.Flags               = D3D12_BUFFER_SRV_FLAG_NONE;
    x12DeviceCreateShaderResourceView(device, arrayConstantBufferLightMatrices, &srvDesc, arrayConstantBufferLightMatricesSrvCpuDescriptorCBVSRVUAV, __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12DescriptorHeap", L"arrayConstantBufferLightMatricesSrvCpuHeapCBVSRVUAV", arrayConstantBufferLightMatricesSrvCpuHeapCBVSRVUAV);
    globalCacheSetAsP(L"", L"", L"arrayConstantBufferLightMatricesSrvCpuDescriptorCBVSRVUAV", (void *)arrayConstantBufferLightMatricesSrvCpuDescriptorCBVSRVUAV.ptr);
  }
  
  X12DescriptorHeap *         arrayVerticesSrvCpuHeapCBVSRVUAV       = globalCacheGetAsP(L"", L"X12DescriptorHeap", L"arrayVerticesSrvCpuHeapCBVSRVUAV");
  D3D12_CPU_DESCRIPTOR_HANDLE arrayVerticesSrvCpuDescriptorCBVSRVUAV = {};
  arrayVerticesSrvCpuDescriptorCBVSRVUAV.ptr = (size_t)globalCacheGetAsP(L"", L"", L"arrayVerticesSrvCpuDescriptorCBVSRVUAV");
  if (arrayVerticesSrvCpuHeapCBVSRVUAV == 0) {
    D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDesc = {};
    descriptorHeapDesc.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    descriptorHeapDesc.NumDescriptors = 1;
    descriptorHeapDesc.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
    descriptorHeapDesc.NodeMask       = 0;
    x12DeviceCreateDescriptorHeap(device, &descriptorHeapDesc, &arrayVerticesSrvCpuHeapCBVSRVUAV, __FILE__, __LINE__);
    x12ObjectSetName(arrayVerticesSrvCpuHeapCBVSRVUAV, L"arrayVerticesSrvCpuHeapCBVSRVUAV", __FILE__, __LINE__);
    x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(arrayVerticesSrvCpuHeapCBVSRVUAV, &arrayVerticesSrvCpuDescriptorCBVSRVUAV);
    D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
    srvDesc.Format                     = DXGI_FORMAT_R32_TYPELESS;
    srvDesc.ViewDimension              = D3D12_SRV_DIMENSION_BUFFER;
    srvDesc.Shader4ComponentMapping    = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
    srvDesc.Buffer.FirstElement        = 0;
    srvDesc.Buffer.NumElements         = 3857976 / 4;
    srvDesc.Buffer.StructureByteStride = 0;
    srvDesc.Buffer.Flags               = D3D12_BUFFER_SRV_FLAG_RAW;
    x12DeviceCreateShaderResourceView(device, arrayVertices, &srvDesc, arrayVerticesSrvCpuDescriptorCBVSRVUAV, __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12DescriptorHeap", L"arrayVerticesSrvCpuHeapCBVSRVUAV", arrayVerticesSrvCpuHeapCBVSRVUAV);
    globalCacheSetAsP(L"", L"", L"arrayVerticesSrvCpuDescriptorCBVSRVUAV", (void *)arrayVerticesSrvCpuDescriptorCBVSRVUAV.ptr);
  }
  
  X12DescriptorHeap *         imageDepthDsvCpuHeapDSV       = globalCacheGetAsP(L"", L"X12DescriptorHeap", L"imageDepthDsvCpuHeapDSV");
  D3D12_CPU_DESCRIPTOR_HANDLE imageDepthDsvCpuDescriptorDSV = {};
  imageDepthDsvCpuDescriptorDSV.ptr = (size_t)globalCacheGetAsP(L"", L"", L"imageDepthDsvCpuDescriptorDSV");
  if (imageDepthDsvCpuHeapDSV == 0) {
    D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDesc = {};
    descriptorHeapDesc.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
    descriptorHeapDesc.NumDescriptors = 1;
    descriptorHeapDesc.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
    descriptorHeapDesc.NodeMask       = 0;
    x12DeviceCreateDescriptorHeap(device, &descriptorHeapDesc, &imageDepthDsvCpuHeapDSV, __FILE__, __LINE__);
    x12ObjectSetName(imageDepthDsvCpuHeapDSV, L"imageDepthDsvCpuHeapDSV", __FILE__, __LINE__);
    x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(imageDepthDsvCpuHeapDSV, &imageDepthDsvCpuDescriptorDSV);
    D3D12_DEPTH_STENCIL_VIEW_DESC dsvDesc = {};
    dsvDesc.Format             = DXGI_FORMAT_D32_FLOAT;
    dsvDesc.ViewDimension      = D3D12_DSV_DIMENSION_TEXTURE2D;
    dsvDesc.Flags              = D3D12_DSV_FLAG_NONE;
    dsvDesc.Texture2D.MipSlice = 0;
    x12DeviceCreateDepthStencilView(device, imageDepth, &dsvDesc, imageDepthDsvCpuDescriptorDSV, __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12DescriptorHeap", L"imageDepthDsvCpuHeapDSV", imageDepthDsvCpuHeapDSV);
    globalCacheSetAsP(L"", L"", L"imageDepthDsvCpuDescriptorDSV", (void *)imageDepthDsvCpuDescriptorDSV.ptr);
  }
  
  X12DescriptorHeap *         imageShadowSrvCpuHeapCBVSRVUAV       = globalCacheGetAsP(L"", L"X12DescriptorHeap", L"imageShadowSrvCpuHeapCBVSRVUAV");
  D3D12_CPU_DESCRIPTOR_HANDLE imageShadowSrvCpuDescriptorCBVSRVUAV = {};
  imageShadowSrvCpuDescriptorCBVSRVUAV.ptr = (size_t)globalCacheGetAsP(L"", L"", L"imageShadowSrvCpuDescriptorCBVSRVUAV");
  if (imageShadowSrvCpuHeapCBVSRVUAV == 0) {
    D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDescSRV = {};
    descriptorHeapDescSRV.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    descriptorHeapDescSRV.NumDescriptors = 1;
    descriptorHeapDescSRV.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
    descriptorHeapDescSRV.NodeMask       = 0;
    x12DeviceCreateDescriptorHeap(device, &descriptorHeapDescSRV, &imageShadowSrvCpuHeapCBVSRVUAV, __FILE__, __LINE__);
    x12ObjectSetName(imageShadowSrvCpuHeapCBVSRVUAV, L"imageShadowSrvCpuHeapCBVSRVUAV", __FILE__, __LINE__);
    x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(imageShadowSrvCpuHeapCBVSRVUAV, &imageShadowSrvCpuDescriptorCBVSRVUAV);
    D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
    srvDesc.Format                        = DXGI_FORMAT_R32_FLOAT;                    // D3D12 ERROR: X12Device::CreateShaderResourceView: The format (0x28, D32_FLOAT) cannot be used with a ShaderResource view. [ STATE_CREATION ERROR #28: CREATESHADERRESOURCEVIEW_INVALIDFORMAT]
    srvDesc.ViewDimension                 = D3D12_SRV_DIMENSION_TEXTURE2D;
    srvDesc.Shader4ComponentMapping       = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
    srvDesc.Texture2D.MostDetailedMip     = 0;
    srvDesc.Texture2D.MipLevels           =-1;
    srvDesc.Texture2D.PlaneSlice          = 0;
    srvDesc.Texture2D.ResourceMinLODClamp = 0;
    x12DeviceCreateShaderResourceView(device, imageShadow, &srvDesc, imageShadowSrvCpuDescriptorCBVSRVUAV, __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12DescriptorHeap", L"imageShadowSrvCpuHeapCBVSRVUAV", imageShadowSrvCpuHeapCBVSRVUAV);
    globalCacheSetAsP(L"", L"", L"imageShadowSrvCpuDescriptorCBVSRVUAV", (void *)imageShadowSrvCpuDescriptorCBVSRVUAV.ptr);
  }
  
  X12DescriptorHeap *         imageShadowDsvCpuHeapDSV       = globalCacheGetAsP(L"", L"X12DescriptorHeap", L"imageShadowDsvCpuHeapDSV");
  D3D12_CPU_DESCRIPTOR_HANDLE imageShadowDsvCpuDescriptorDSV = {};
  imageShadowDsvCpuDescriptorDSV.ptr = (size_t)globalCacheGetAsP(L"", L"", L"imageShadowDsvCpuDescriptorDSV");
  if (imageShadowDsvCpuHeapDSV == 0) {
    D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDescDSV = {};
    descriptorHeapDescDSV.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
    descriptorHeapDescDSV.NumDescriptors = 1;
    descriptorHeapDescDSV.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
    descriptorHeapDescDSV.NodeMask       = 0;
    x12DeviceCreateDescriptorHeap(device, &descriptorHeapDescDSV, &imageShadowDsvCpuHeapDSV, __FILE__, __LINE__);
    x12ObjectSetName(imageShadowDsvCpuHeapDSV, L"imageShadowDsvCpuHeapDSV", __FILE__, __LINE__);
    x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(imageShadowDsvCpuHeapDSV, &imageShadowDsvCpuDescriptorDSV);
    D3D12_DEPTH_STENCIL_VIEW_DESC dsvDesc = {};
    dsvDesc.Format                        = DXGI_FORMAT_D32_FLOAT;
    dsvDesc.ViewDimension                 = D3D12_DSV_DIMENSION_TEXTURE2D;
    dsvDesc.Flags                         = D3D12_DSV_FLAG_NONE;
    dsvDesc.Texture2D.MipSlice            = 0;
    x12DeviceCreateDepthStencilView(device, imageShadow, &dsvDesc, imageShadowDsvCpuDescriptorDSV, __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12DescriptorHeap", L"imageShadowDsvCpuHeapDSV", imageShadowDsvCpuHeapDSV);
    globalCacheSetAsP(L"", L"", L"imageShadowDsvCpuDescriptorDSV", (void *)imageShadowDsvCpuDescriptorDSV.ptr);
  }
  
  X12DescriptorHeap *         samplerCpuHeapSampler       = globalCacheGetAsP(L"", L"X12DescriptorHeap", L"samplerCpuHeapSampler");
  D3D12_CPU_DESCRIPTOR_HANDLE samplerCpuDescriptorSampler = {};
  samplerCpuDescriptorSampler.ptr = (size_t)globalCacheGetAsP(L"", L"", L"samplerCpuDescriptorSampler");
  if (samplerCpuHeapSampler == 0) {
    D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDesc = {};
    descriptorHeapDesc.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER;
    descriptorHeapDesc.NumDescriptors = 1;
    descriptorHeapDesc.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
    descriptorHeapDesc.NodeMask       = 0;
    x12DeviceCreateDescriptorHeap(device, &descriptorHeapDesc, &samplerCpuHeapSampler, __FILE__, __LINE__);
    x12ObjectSetName(samplerCpuHeapSampler, L"samplerCpuHeapSampler", __FILE__, __LINE__);
    x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(samplerCpuHeapSampler, &samplerCpuDescriptorSampler);
    D3D12_SAMPLER_DESC samplerDesc = {};
    samplerDesc.Filter         = D3D12_FILTER_MIN_MAG_MIP_LINEAR;
    samplerDesc.AddressU       = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
    samplerDesc.AddressV       = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
    samplerDesc.AddressW       = D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
    samplerDesc.MipLODBias     = 0;
    samplerDesc.MaxAnisotropy  = 1;
    samplerDesc.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
    samplerDesc.BorderColor[0] = 0;
    samplerDesc.BorderColor[1] = 0;
    samplerDesc.BorderColor[2] = 0;
    samplerDesc.BorderColor[3] = 0;
    samplerDesc.MinLOD         = 0;
    samplerDesc.MaxLOD         = 1;
    x12DeviceCreateSampler(device, &samplerDesc, samplerCpuDescriptorSampler, __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12DescriptorHeap", L"samplerCpuHeapSampler", samplerCpuHeapSampler);
    globalCacheSetAsP(L"", L"", L"samplerCpuDescriptorSampler", (void *)samplerCpuDescriptorSampler.ptr);
  }
  
  X12DescriptorHeap * descriptorHeapDepthPass = globalCacheGetAsP(L"", L"X12DescriptorHeap", L"descriptorHeapDepthPass");
  if (descriptorHeapDepthPass == 0) {
    // Create GPU descriptor heap (D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE):
    D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDescDepthPass = {};
    descriptorHeapDescDepthPass.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    descriptorHeapDescDepthPass.NumDescriptors = 2;
    descriptorHeapDescDepthPass.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
    descriptorHeapDescDepthPass.NodeMask       = 0;
    x12DeviceCreateDescriptorHeap(device, &descriptorHeapDescDepthPass, &descriptorHeapDepthPass, __FILE__, __LINE__);
    x12ObjectSetName(descriptorHeapDepthPass, L"descriptorHeapDepthPass", __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12DescriptorHeap", L"descriptorHeapDepthPass", descriptorHeapDepthPass);
  }
  
  X12DescriptorHeap * descriptorHeapScenePass = globalCacheGetAsP(L"", L"X12DescriptorHeap", L"descriptorHeapScenePass");
  if (descriptorHeapScenePass == 0) {
    // Create GPU descriptor heap (D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE):
    D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapDescScenePass = {};
    descriptorHeapDescScenePass.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    descriptorHeapDescScenePass.NumDescriptors = 4;
    descriptorHeapDescScenePass.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
    descriptorHeapDescScenePass.NodeMask       = 0;
    x12DeviceCreateDescriptorHeap(device, &descriptorHeapDescScenePass, &descriptorHeapScenePass, __FILE__, __LINE__);
    x12ObjectSetName(descriptorHeapScenePass, L"descriptorHeapScenePass", __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12DescriptorHeap", L"descriptorHeapScenePass", descriptorHeapScenePass);
  }
  
  X12DescriptorHeap * descriptorHeapSamplerScenePass = globalCacheGetAsP(L"", L"X12DescriptorHeap", L"descriptorHeapSamplerScenePass");
  if (descriptorHeapSamplerScenePass == 0) {
    // Create GPU descriptor heap (D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE):
    D3D12_DESCRIPTOR_HEAP_DESC descriptorHeapSamplersDescScenePass = {};
    descriptorHeapSamplersDescScenePass.Type           = D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER;
    descriptorHeapSamplersDescScenePass.NumDescriptors = 1;
    descriptorHeapSamplersDescScenePass.Flags          = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
    descriptorHeapSamplersDescScenePass.NodeMask       = 0;
    x12DeviceCreateDescriptorHeap(device, &descriptorHeapSamplersDescScenePass, &descriptorHeapSamplerScenePass, __FILE__, __LINE__);
    x12ObjectSetName(descriptorHeapSamplerScenePass, L"descriptorHeapSamplerScenePass", __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12DescriptorHeap", L"descriptorHeapSamplerScenePass", descriptorHeapSamplerScenePass);
  }
  
  {
    // Copy CPU descriptors to GPU descriptor heaps:
    unsigned size = 1;
    unsigned descriptorSizeCbvSrvUav = x12DeviceGetDescriptorHandleIncrementSize(device, D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, __FILE__, __LINE__);
    unsigned descriptorSizeSampler   = x12DeviceGetDescriptorHandleIncrementSize(device, D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER, __FILE__, __LINE__);
    D3D12_CPU_DESCRIPTOR_HANDLE dst = {};
    D3D12_CPU_DESCRIPTOR_HANDLE src = {};
    {
      x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(descriptorHeapDepthPass, &dst);
      dst.ptr += 0 * descriptorSizeCbvSrvUav;
      src = arrayConstantBufferLightMatricesSrvCpuDescriptorCBVSRVUAV;
      x12DeviceCopyDescriptors(device, 1, &dst, &size, 1, &src, &size, D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, __FILE__, __LINE__);
    }
    {
      x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(descriptorHeapDepthPass, &dst);
      dst.ptr += 1 * descriptorSizeCbvSrvUav;
      src = arrayVerticesSrvCpuDescriptorCBVSRVUAV;
      x12DeviceCopyDescriptors(device, 1, &dst, &size, 1, &src, &size, D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, __FILE__, __LINE__);
    }
    {
      x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(descriptorHeapScenePass, &dst);
      dst.ptr += 0 * descriptorSizeCbvSrvUav;
      src = arrayConstantBufferCameraMatricesSrvCpuDescriptorCBVSRVUAV;
      x12DeviceCopyDescriptors(device, 1, &dst, &size, 1, &src, &size, D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, __FILE__, __LINE__);
    }
    {
      x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(descriptorHeapScenePass, &dst);
      dst.ptr += 1 * descriptorSizeCbvSrvUav;
      src = arrayConstantBufferLightMatricesSrvCpuDescriptorCBVSRVUAV;
      x12DeviceCopyDescriptors(device, 1, &dst, &size, 1, &src, &size, D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, __FILE__, __LINE__);
    }
    {
      x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(descriptorHeapScenePass, &dst);
      dst.ptr += 2 * descriptorSizeCbvSrvUav;
      src = imageShadowSrvCpuDescriptorCBVSRVUAV;
      x12DeviceCopyDescriptors(device, 1, &dst, &size, 1, &src, &size, D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, __FILE__, __LINE__);
    }
    {
      x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(descriptorHeapScenePass, &dst);
      dst.ptr += 3 * descriptorSizeCbvSrvUav;
      src = arrayVerticesSrvCpuDescriptorCBVSRVUAV;
      x12DeviceCopyDescriptors(device, 1, &dst, &size, 1, &src, &size, D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, __FILE__, __LINE__);
    }
    {
      x12DescriptorHeapGetCPUDescriptorHandleForHeapStart(descriptorHeapSamplerScenePass, &dst);
      dst.ptr += 0 * descriptorSizeSampler;
      src = samplerCpuDescriptorSampler;
      x12DeviceCopyDescriptors(device, 1, &dst, &size, 1, &src, &size, D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER, __FILE__, __LINE__);
    }
  }
  
  X12RootSignature * parametersDepthPassRootSignature = globalCacheGetAsP(L"", L"X12RootSignature", L"parametersDepthPassRootSignature");
  X12Blob *          parametersDepthPassBlob          = globalCacheGetAsP(L"", L"X12Blob", L"parametersDepthPassBlob");
  X12Blob *          parametersDepthPassBlobError     = globalCacheGetAsP(L"", L"X12Blob", L"parametersDepthPassBlobError");
  if (parametersDepthPassRootSignature == 0) {
    D3D12_DESCRIPTOR_RANGE tableRanges[2] = {};
    tableRanges[0].RangeType                         = D3D12_DESCRIPTOR_RANGE_TYPE_SRV; // NOTE: is it tho??
    tableRanges[0].NumDescriptors                    = 1;
    tableRanges[0].BaseShaderRegister                = 0;
    tableRanges[0].RegisterSpace                     = 1; // HLSL: light
    tableRanges[0].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND; // https://microsoft.github.io/DirectX-Specs/d3d/ResourceBinding.html#descriptor-range
    tableRanges[1].RangeType                         = D3D12_DESCRIPTOR_RANGE_TYPE_SRV; // NOTE: is it tho??
    tableRanges[1].NumDescriptors                    = 1;
    tableRanges[1].BaseShaderRegister                = 0;
    tableRanges[1].RegisterSpace                     = 4; // HLSL: vertices
    tableRanges[1].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
    D3D12_ROOT_PARAMETER parameters[1] = {};
    parameters[0].ParameterType                       = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    parameters[0].DescriptorTable.NumDescriptorRanges = _countof(tableRanges);
    parameters[0].DescriptorTable.pDescriptorRanges   = tableRanges;
    parameters[0].ShaderVisibility                    = D3D12_SHADER_VISIBILITY_ALL;
    D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc = {};
    rootSignatureDesc.NumParameters     = _countof(parameters);
    rootSignatureDesc.pParameters       = parameters;
    rootSignatureDesc.NumStaticSamplers = 0;
    rootSignatureDesc.pStaticSamplers   = 0;
    rootSignatureDesc.Flags             = D3D12_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS | D3D12_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS | D3D12_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS;
    x12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &parametersDepthPassBlob, &parametersDepthPassBlobError, __FILE__, __LINE__);
    // NOTE: Check parametersDepthPassBlobError on errors here.
    x12DeviceCreateRootSignature(device, 0, x12BlobGetBufferPointer(parametersDepthPassBlob), x12BlobGetBufferSize(parametersDepthPassBlob), &parametersDepthPassRootSignature, __FILE__, __LINE__);
    x12ObjectSetName(parametersDepthPassRootSignature, L"parametersDepthPassRootSignature", __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12RootSignature", L"parametersDepthPassRootSignature", parametersDepthPassRootSignature);
    globalCacheSetAsP(L"", L"X12Blob", L"parametersDepthPassBlob", parametersDepthPassBlob);
    globalCacheSetAsP(L"", L"X12Blob", L"parametersDepthPassBlobError", parametersDepthPassBlobError);
  }
  
  X12RootSignature * parametersScenePassRootSignature = globalCacheGetAsP(L"", L"X12RootSignature", L"parametersScenePassRootSignature");
  X12Blob *          parametersScenePassBlob          = globalCacheGetAsP(L"", L"X12Blob", L"parametersScenePassBlob");
  X12Blob *          parametersScenePassBlobError     = globalCacheGetAsP(L"", L"X12Blob", L"parametersScenePassBlobError");
  if (parametersScenePassRootSignature == 0) {
    D3D12_DESCRIPTOR_RANGE tableRanges[4] = {};
    tableRanges[0].RangeType                         = D3D12_DESCRIPTOR_RANGE_TYPE_SRV; // NOTE: is it tho??
    tableRanges[0].NumDescriptors                    = 1;
    tableRanges[0].BaseShaderRegister                = 0;
    tableRanges[0].RegisterSpace                     = 0; // HLSL: camera
    tableRanges[0].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
    tableRanges[1].RangeType                         = D3D12_DESCRIPTOR_RANGE_TYPE_SRV; // NOTE: is it tho??
    tableRanges[1].NumDescriptors                    = 1;
    tableRanges[1].BaseShaderRegister                = 0;
    tableRanges[1].RegisterSpace                     = 1; // HLSL: light
    tableRanges[1].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
    tableRanges[2].RangeType                         = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
    tableRanges[2].NumDescriptors                    = 1;
    tableRanges[2].BaseShaderRegister                = 0;
    tableRanges[2].RegisterSpace                     = 2; // HLSL: shadowMap
    tableRanges[2].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
    tableRanges[3].RangeType                         = D3D12_DESCRIPTOR_RANGE_TYPE_SRV; // NOTE: is it tho??
    tableRanges[3].NumDescriptors                    = 1;
    tableRanges[3].BaseShaderRegister                = 0;
    tableRanges[3].RegisterSpace                     = 4; // HLSL: vertices
    tableRanges[3].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
    D3D12_DESCRIPTOR_RANGE tableRangesSamplers[1] = {}; // "Samplers are not allowed in the same descriptor table as constant-buffer views (CBVs), unordered-access views (UAVs), and shader-resource views (SRVs)." https://docs.microsoft.com/en-us/windows/win32/api/d3d12/ns-d3d12-d3d12_root_descriptor_table#remarks
    tableRangesSamplers[0].RangeType                         = D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER;
    tableRangesSamplers[0].NumDescriptors                    = 1;
    tableRangesSamplers[0].BaseShaderRegister                = 0;
    tableRangesSamplers[0].RegisterSpace                     = 3; // HLSL: shadowMapSampler
    tableRangesSamplers[0].OffsetInDescriptorsFromTableStart = D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND;
    D3D12_ROOT_PARAMETER parameters[2] = {};
    parameters[0].ParameterType                       = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    parameters[0].DescriptorTable.NumDescriptorRanges = _countof(tableRanges);
    parameters[0].DescriptorTable.pDescriptorRanges   = tableRanges;
    parameters[0].ShaderVisibility                    = D3D12_SHADER_VISIBILITY_ALL;
    parameters[1].ParameterType                       = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE;
    parameters[1].DescriptorTable.NumDescriptorRanges = _countof(tableRangesSamplers);
    parameters[1].DescriptorTable.pDescriptorRanges   = tableRangesSamplers;
    parameters[1].ShaderVisibility                    = D3D12_SHADER_VISIBILITY_ALL;
    D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc = {};
    rootSignatureDesc.NumParameters     = _countof(parameters);
    rootSignatureDesc.pParameters       = parameters;
    rootSignatureDesc.NumStaticSamplers = 0;
    rootSignatureDesc.pStaticSamplers   = 0;
    rootSignatureDesc.Flags             = D3D12_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS | D3D12_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS | D3D12_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS;
    x12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &parametersScenePassBlob, &parametersScenePassBlobError, __FILE__, __LINE__);
    // NOTE: Check parametersScenePassBlobError on errors here.
    x12DeviceCreateRootSignature(device, 0, x12BlobGetBufferPointer(parametersScenePassBlob), x12BlobGetBufferSize(parametersScenePassBlob), &parametersScenePassRootSignature, __FILE__, __LINE__);
    x12ObjectSetName(parametersScenePassRootSignature, L"parametersScenePassRootSignature", __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12RootSignature", L"parametersScenePassRootSignature", parametersScenePassRootSignature);
    globalCacheSetAsP(L"", L"X12Blob", L"parametersScenePassBlob", parametersScenePassBlob);
    globalCacheSetAsP(L"", L"X12Blob", L"parametersScenePassBlobError", parametersScenePassBlobError);
  }
  
  X12PipelineState * pipelineDepthPass = globalCacheGetAsP(L"", L"X12PipelineState", L"pipelineDepthPass");
  if (pipelineDepthPass == 0) {
    D3D12_GRAPHICS_PIPELINE_STATE_DESC state = {};
    state.pRootSignature                                   = parametersDepthPassRootSignature;
    state.VS.pShaderBytecode                               = g_DepthPassVSMain;
    state.VS.BytecodeLength                                = sizeof(g_DepthPassVSMain);
    state.PS.pShaderBytecode                               = 0;
    state.PS.BytecodeLength                                = 0;
    state.BlendState.AlphaToCoverageEnable                 = 0;
    state.BlendState.IndependentBlendEnable                = 0;
    for (unsigned i = 0; i < 8; i += 1) {
    state.BlendState.RenderTarget[i].BlendEnable           = 0;
    state.BlendState.RenderTarget[i].LogicOpEnable         = 0;
    state.BlendState.RenderTarget[i].SrcBlend              = D3D12_BLEND_ONE;
    state.BlendState.RenderTarget[i].DestBlend             = D3D12_BLEND_ZERO;
    state.BlendState.RenderTarget[i].BlendOp               = D3D12_BLEND_OP_ADD;
    state.BlendState.RenderTarget[i].SrcBlendAlpha         = D3D12_BLEND_ONE;
    state.BlendState.RenderTarget[i].DestBlendAlpha        = D3D12_BLEND_ZERO;
    state.BlendState.RenderTarget[i].BlendOpAlpha          = D3D12_BLEND_OP_ADD;
    state.BlendState.RenderTarget[i].LogicOp               = D3D12_LOGIC_OP_NOOP;
    state.BlendState.RenderTarget[i].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
    }
    state.SampleMask                                       = UINT_MAX;
    state.RasterizerState.FillMode                         = D3D12_FILL_MODE_SOLID;
    state.RasterizerState.CullMode                         = D3D12_CULL_MODE_BACK;
    state.RasterizerState.FrontCounterClockwise            = 0;
    state.RasterizerState.DepthBias                        = (int)1.25f;
    state.RasterizerState.DepthBiasClamp                   = 0.f;
    state.RasterizerState.SlopeScaledDepthBias             = 1.75f;
    state.RasterizerState.DepthClipEnable                  = 1;
    state.RasterizerState.MultisampleEnable                = 0;
    state.RasterizerState.AntialiasedLineEnable            = 0;
    state.RasterizerState.ForcedSampleCount                = 0;
    state.RasterizerState.ConservativeRaster               = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;
    state.DepthStencilState.DepthEnable                    = 1;
    state.DepthStencilState.DepthWriteMask                 = D3D12_DEPTH_WRITE_MASK_ALL;
    state.DepthStencilState.DepthFunc                      = D3D12_COMPARISON_FUNC_LESS_EQUAL;
    state.DepthStencilState.StencilEnable                  = 0;
    state.DepthStencilState.StencilReadMask                = D3D12_DEFAULT_STENCIL_READ_MASK;
    state.DepthStencilState.StencilWriteMask               = D3D12_DEFAULT_STENCIL_WRITE_MASK;
    state.DepthStencilState.FrontFace.StencilFailOp        = D3D12_STENCIL_OP_KEEP;
    state.DepthStencilState.FrontFace.StencilDepthFailOp   = D3D12_STENCIL_OP_KEEP;
    state.DepthStencilState.FrontFace.StencilPassOp        = D3D12_STENCIL_OP_KEEP;
    state.DepthStencilState.FrontFace.StencilFunc          = D3D12_COMPARISON_FUNC_ALWAYS;
    state.DepthStencilState.BackFace.StencilFailOp         = D3D12_STENCIL_OP_KEEP;
    state.DepthStencilState.BackFace.StencilDepthFailOp    = D3D12_STENCIL_OP_KEEP;
    state.DepthStencilState.BackFace.StencilPassOp         = D3D12_STENCIL_OP_KEEP;
    state.DepthStencilState.BackFace.StencilFunc           = D3D12_COMPARISON_FUNC_ALWAYS;
    state.IBStripCutValue                                  = D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_DISABLED;
    state.PrimitiveTopologyType                            = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
    state.NumRenderTargets                                 = 0;
    state.RTVFormats[0]                                    = DXGI_FORMAT_UNKNOWN;
    state.RTVFormats[1]                                    = DXGI_FORMAT_UNKNOWN;
    state.RTVFormats[2]                                    = DXGI_FORMAT_UNKNOWN;
    state.RTVFormats[3]                                    = DXGI_FORMAT_UNKNOWN;
    state.RTVFormats[4]                                    = DXGI_FORMAT_UNKNOWN;
    state.RTVFormats[5]                                    = DXGI_FORMAT_UNKNOWN;
    state.RTVFormats[6]                                    = DXGI_FORMAT_UNKNOWN;
    state.RTVFormats[7]                                    = DXGI_FORMAT_UNKNOWN;
    state.DSVFormat                                        = DXGI_FORMAT_D32_FLOAT;
    state.SampleDesc.Count                                 = 1;
    state.SampleDesc.Quality                               = 0;
    state.NodeMask                                         = 0;
    state.CachedPSO.pCachedBlob                            = 0;
    state.CachedPSO.CachedBlobSizeInBytes                  = 0;
    state.Flags                                            = D3D12_PIPELINE_STATE_FLAG_NONE;
    x12DeviceCreateGraphicsPipelineState(device, &state, &pipelineDepthPass, __FILE__, __LINE__);
    x12ObjectSetName(pipelineDepthPass, L"pipelineDepthPass", __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12PipelineState", L"pipelineDepthPass", pipelineDepthPass);
  }
  
  X12PipelineState * pipelineScenePass = globalCacheGetAsP(L"", L"X12PipelineState", L"pipelineScenePass");
  if (pipelineScenePass == 0) {
    D3D12_GRAPHICS_PIPELINE_STATE_DESC stateScenePass = {};
    stateScenePass.pRootSignature                                   = parametersScenePassRootSignature;
    stateScenePass.VS.pShaderBytecode                               = g_ScenePassVSMain;
    stateScenePass.VS.BytecodeLength                                = sizeof(g_ScenePassVSMain);
    stateScenePass.PS.pShaderBytecode                               = g_ScenePassPSMain;
    stateScenePass.PS.BytecodeLength                                = sizeof(g_ScenePassPSMain);
    stateScenePass.BlendState.AlphaToCoverageEnable                 = 0;
    stateScenePass.BlendState.IndependentBlendEnable                = 0;
    for (unsigned i = 0; i < 8; i += 1) {
    stateScenePass.BlendState.RenderTarget[i].BlendEnable           = 0;
    stateScenePass.BlendState.RenderTarget[i].LogicOpEnable         = 0;
    stateScenePass.BlendState.RenderTarget[i].SrcBlend              = D3D12_BLEND_ONE;
    stateScenePass.BlendState.RenderTarget[i].DestBlend             = D3D12_BLEND_ZERO;
    stateScenePass.BlendState.RenderTarget[i].BlendOp               = D3D12_BLEND_OP_ADD;
    stateScenePass.BlendState.RenderTarget[i].SrcBlendAlpha         = D3D12_BLEND_ONE;
    stateScenePass.BlendState.RenderTarget[i].DestBlendAlpha        = D3D12_BLEND_ZERO;
    stateScenePass.BlendState.RenderTarget[i].BlendOpAlpha          = D3D12_BLEND_OP_ADD;
    stateScenePass.BlendState.RenderTarget[i].LogicOp               = D3D12_LOGIC_OP_NOOP;
    stateScenePass.BlendState.RenderTarget[i].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
    }
    stateScenePass.SampleMask                                       = UINT_MAX;
    stateScenePass.RasterizerState.FillMode                         = D3D12_FILL_MODE_SOLID;
    stateScenePass.RasterizerState.CullMode                         = D3D12_CULL_MODE_BACK;
    stateScenePass.RasterizerState.FrontCounterClockwise            = 0;
    stateScenePass.RasterizerState.DepthBias                        = D3D12_DEFAULT_DEPTH_BIAS;
    stateScenePass.RasterizerState.DepthBiasClamp                   = D3D12_DEFAULT_DEPTH_BIAS_CLAMP;
    stateScenePass.RasterizerState.SlopeScaledDepthBias             = D3D12_DEFAULT_SLOPE_SCALED_DEPTH_BIAS;
    stateScenePass.RasterizerState.DepthClipEnable                  = 1;
    stateScenePass.RasterizerState.MultisampleEnable                = 0;
    stateScenePass.RasterizerState.AntialiasedLineEnable            = 0;
    stateScenePass.RasterizerState.ForcedSampleCount                = 0;
    stateScenePass.RasterizerState.ConservativeRaster               = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;
    stateScenePass.DepthStencilState.DepthEnable                    = 1;
    stateScenePass.DepthStencilState.DepthWriteMask                 = D3D12_DEPTH_WRITE_MASK_ALL;
    stateScenePass.DepthStencilState.DepthFunc                      = D3D12_COMPARISON_FUNC_LESS_EQUAL;
    stateScenePass.DepthStencilState.StencilEnable                  = 0;
    stateScenePass.DepthStencilState.StencilReadMask                = D3D12_DEFAULT_STENCIL_READ_MASK;
    stateScenePass.DepthStencilState.StencilWriteMask               = D3D12_DEFAULT_STENCIL_WRITE_MASK;
    stateScenePass.DepthStencilState.FrontFace.StencilFailOp        = D3D12_STENCIL_OP_KEEP;
    stateScenePass.DepthStencilState.FrontFace.StencilDepthFailOp   = D3D12_STENCIL_OP_KEEP;
    stateScenePass.DepthStencilState.FrontFace.StencilPassOp        = D3D12_STENCIL_OP_KEEP;
    stateScenePass.DepthStencilState.FrontFace.StencilFunc          = D3D12_COMPARISON_FUNC_ALWAYS;
    stateScenePass.DepthStencilState.BackFace.StencilFailOp         = D3D12_STENCIL_OP_KEEP;
    stateScenePass.DepthStencilState.BackFace.StencilDepthFailOp    = D3D12_STENCIL_OP_KEEP;
    stateScenePass.DepthStencilState.BackFace.StencilPassOp         = D3D12_STENCIL_OP_KEEP;
    stateScenePass.DepthStencilState.BackFace.StencilFunc           = D3D12_COMPARISON_FUNC_ALWAYS;
    stateScenePass.IBStripCutValue                                  = D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_DISABLED;
    stateScenePass.PrimitiveTopologyType                            = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
    stateScenePass.NumRenderTargets                                 = 1;
    stateScenePass.RTVFormats[0]                                    = DXGI_FORMAT_B8G8R8A8_UNORM_SRGB;
    stateScenePass.RTVFormats[1]                                    = DXGI_FORMAT_UNKNOWN;
    stateScenePass.RTVFormats[2]                                    = DXGI_FORMAT_UNKNOWN;
    stateScenePass.RTVFormats[3]                                    = DXGI_FORMAT_UNKNOWN;
    stateScenePass.RTVFormats[4]                                    = DXGI_FORMAT_UNKNOWN;
    stateScenePass.RTVFormats[5]                                    = DXGI_FORMAT_UNKNOWN;
    stateScenePass.RTVFormats[6]                                    = DXGI_FORMAT_UNKNOWN;
    stateScenePass.RTVFormats[7]                                    = DXGI_FORMAT_UNKNOWN;
    stateScenePass.DSVFormat                                        = DXGI_FORMAT_D32_FLOAT;
    stateScenePass.SampleDesc.Count                                 = 1;
    stateScenePass.SampleDesc.Quality                               = 0;
    stateScenePass.NodeMask                                         = 0;
    stateScenePass.CachedPSO.pCachedBlob                            = 0;
    stateScenePass.CachedPSO.CachedBlobSizeInBytes                  = 0;
    stateScenePass.Flags                                            = D3D12_PIPELINE_STATE_FLAG_NONE;
    x12DeviceCreateGraphicsPipelineState(device, &stateScenePass, &pipelineScenePass, __FILE__, __LINE__);
    x12ObjectSetName(pipelineScenePass, L"pipelineScenePass", __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12PipelineState", L"pipelineScenePass", pipelineScenePass);
  }
  
  X12CommandAllocator * commandListsAllocator[2] = {};
  commandListsAllocator[0] = globalCacheGetAsP(L"", L"X12CommandAllocator", L"commandListsAllocator[0]");
  commandListsAllocator[1] = globalCacheGetAsP(L"", L"X12CommandAllocator", L"commandListsAllocator[1]");
  X12CommandList * commandLists[2] = {};
  commandLists[0] = globalCacheGetAsP(L"", L"X12CommandList", L"commandLists[0]");
  commandLists[1] = globalCacheGetAsP(L"", L"X12CommandList", L"commandLists[1]");
  if (commandListsAllocator[0] == 0) {
    D3D12_COMMAND_LIST_TYPE commandListType = D3D12_COMMAND_LIST_TYPE_DIRECT;
    x12DeviceCreateCommandAllocator(device, commandListType, &commandListsAllocator[0], __FILE__, __LINE__);
    x12DeviceCreateCommandList(device, 0, commandListType, commandListsAllocator[0], 0, &commandLists[0], __FILE__, __LINE__);
    x12CommandListClose(commandLists[0], __FILE__, __LINE__);
    x12ObjectSetName(commandListsAllocator[0], L"commandListsAllocator[0]", __FILE__, __LINE__);
    x12ObjectSetName(commandLists[0], L"commandLists[0]", __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12CommandAllocator", L"commandListsAllocator[0]", commandListsAllocator[0]);
    globalCacheSetAsP(L"", L"X12CommandList", L"commandLists[0]", commandLists[0]);
  }
  if (commandListsAllocator[1] == 0) {
    D3D12_COMMAND_LIST_TYPE commandListType = D3D12_COMMAND_LIST_TYPE_DIRECT;
    x12DeviceCreateCommandAllocator(device, commandListType, &commandListsAllocator[1], __FILE__, __LINE__);
    x12DeviceCreateCommandList(device, 0, commandListType, commandListsAllocator[1], 0, &commandLists[1], __FILE__, __LINE__);
    x12CommandListClose(commandLists[1], __FILE__, __LINE__);
    x12ObjectSetName(commandListsAllocator[1], L"commandListsAllocator[1]", __FILE__, __LINE__);
    x12ObjectSetName(commandLists[1], L"commandLists[1]", __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12CommandAllocator", L"commandListsAllocator[1]", commandListsAllocator[1]);
    globalCacheSetAsP(L"", L"X12CommandList", L"commandLists[1]", commandLists[1]);
  }
  
  X12Fence * fence[2] = {};
  fence[0] = globalCacheGetAsP(L"", L"X12Fence", L"fence[0]");
  fence[1] = globalCacheGetAsP(L"", L"X12Fence", L"fence[1]");
  if (fence[0] == 0) {
    x12DeviceCreateFence(device, 1, D3D12_FENCE_FLAG_NONE, &fence[0], __FILE__, __LINE__);
    x12ObjectSetName(fence[0], L"fence[0]", __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12Fence", L"fence[0]", fence[0]);
  }
  if (fence[1] == 0) {
    x12DeviceCreateFence(device, 1, D3D12_FENCE_FLAG_NONE, &fence[1], __FILE__, __LINE__);
    x12ObjectSetName(fence[1], L"fence[1]", __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12Fence", L"fence[1]", fence[1]);
  }
  
  uint64_t f = globalCacheGetAsU(L"", L"", L"frame");
  
  x12FenceSetEventOnCompletion(fence[f], 1, 0, __FILE__, __LINE__);
  x12FenceSignal(fence[f], 0, __FILE__, __LINE__);
  
  {
    x12CommandAllocatorReset(commandListsAllocator[f], __FILE__, __LINE__);
    x12CommandListReset(commandLists[f], commandListsAllocator[f], 0, __FILE__, __LINE__);
    D3D12_VIEWPORT viewport = {};
    viewport.TopLeftX = 0.f;
    viewport.TopLeftY = 0.f;
    viewport.Width    = 2048.f;
    viewport.Height   = 2048.f;
    viewport.MinDepth = 0.f;
    viewport.MaxDepth = 1.f;
    D3D12_RECT scissor = {};
    scissor.left   = 0;
    scissor.top    = 0;
    scissor.right  = 2048;
    scissor.bottom = 2048;
    x12CommandListRSSetViewports(commandLists[f], 1, &viewport);
    x12CommandListRSSetScissorRects(commandLists[f], 1, &scissor);
    D3D12_RESOURCE_BARRIER _0[1] = {};
    _0[0].Type                   = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    _0[0].Flags                  = D3D12_RESOURCE_BARRIER_FLAG_NONE;
    _0[0].Transition.pResource   = imageShadow;
    _0[0].Transition.StateBefore = D3D12_RESOURCE_STATE_GENERIC_READ;
    _0[0].Transition.StateAfter  = D3D12_RESOURCE_STATE_DEPTH_WRITE;
    _0[0].Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    x12CommandListResourceBarrier(commandLists[f], 1, _0);
    x12CommandListOMSetRenderTargets(commandLists[f], 0, 0, 0, &imageShadowDsvCpuDescriptorDSV);
    x12CommandListClearDepthStencilView(commandLists[f], imageShadowDsvCpuDescriptorDSV, D3D12_CLEAR_FLAG_DEPTH, 1.f, 0, 0, 0);
    x12CommandListSetGraphicsRootSignature(commandLists[f], parametersDepthPassRootSignature);
   {X12DescriptorHeap * setHeaps[1];
    setHeaps[0] = descriptorHeapDepthPass;
    x12CommandListSetDescriptorHeaps(commandLists[f], _countof(setHeaps), (const X12DescriptorHeap **)setHeaps);}
    D3D12_GPU_DESCRIPTOR_HANDLE descriptorHeap_DepthPass_gpuDescriptorHandle = {};
    x12DescriptorHeapGetGPUDescriptorHandleForHeapStart(descriptorHeapDepthPass, &descriptorHeap_DepthPass_gpuDescriptorHandle);
    x12CommandListSetGraphicsRootDescriptorTable(commandLists[f], 0, descriptorHeap_DepthPass_gpuDescriptorHandle);
    x12CommandListSetPipelineState(commandLists[f], pipelineDepthPass);
    x12CommandListIASetPrimitiveTopology(commandLists[f], D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    D3D12_INDEX_BUFFER_VIEW ibv = {};
    ibv.BufferLocation = x12ResourceGetGPUVirtualAddress(arrayIndices);
    ibv.SizeInBytes    = 642996;
    ibv.Format         = DXGI_FORMAT_R32_UINT;
    x12CommandListIASetIndexBuffer(commandLists[f], &ibv);
    x12CommandListDrawIndexedInstanced(commandLists[f], 160749, 1, 0, 0, 0);
    viewport.TopLeftX = 0.f;
    viewport.TopLeftY = 0.f;
    viewport.Width    = (float)1900; // NOTE(Constantine): Hardcoded.
    viewport.Height   = (float)800;  // NOTE(Constantine): Hardcoded.
    viewport.MinDepth = 0.f;
    viewport.MaxDepth = 1.f;
    scissor.left   = 0;
    scissor.top    = 0;
    scissor.right  = 1900; // NOTE(Constantine): Hardcoded.
    scissor.bottom = 800;  // NOTE(Constantine): Hardcoded.
    x12CommandListRSSetViewports(commandLists[f], 1, &viewport);
    x12CommandListRSSetScissorRects(commandLists[f], 1, &scissor);
     D3D12_RESOURCE_BARRIER _1[1] = {};
    _1[0].Type                   = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    _1[0].Flags                  = D3D12_RESOURCE_BARRIER_FLAG_NONE;
    _1[0].Transition.pResource   = swapchainResources[f];
    _1[0].Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
    _1[0].Transition.StateAfter  = D3D12_RESOURCE_STATE_RENDER_TARGET;
    _1[0].Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    x12CommandListResourceBarrier(commandLists[f], 1, _1);
    D3D12_RESOURCE_BARRIER _2[1] = {};
    _2[0].Type                   = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    _2[0].Flags                  = D3D12_RESOURCE_BARRIER_FLAG_NONE;
    _2[0].Transition.pResource   = imageShadow;
    _2[0].Transition.StateBefore = D3D12_RESOURCE_STATE_DEPTH_WRITE;
    _2[0].Transition.StateAfter  = D3D12_RESOURCE_STATE_GENERIC_READ;
    _2[0].Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    x12CommandListResourceBarrier(commandLists[f], 1, _2);
    D3D12_RESOURCE_BARRIER _3[1] = {};
    _3[0].Type                   = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    _3[0].Flags                  = D3D12_RESOURCE_BARRIER_FLAG_NONE;
    _3[0].Transition.pResource   = imageDepth;
    _3[0].Transition.StateBefore = D3D12_RESOURCE_STATE_GENERIC_READ;
    _3[0].Transition.StateAfter  = D3D12_RESOURCE_STATE_DEPTH_WRITE;
    _3[0].Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    x12CommandListResourceBarrier(commandLists[f], 1, _3);
    x12CommandListOMSetRenderTargets(commandLists[f], 1, &swapchainDescriptorsCpuDescriptorRTV[f], 0, &imageDepthDsvCpuDescriptorDSV);
    const float clearColor[] = {0.3f, 0.3f, 0.3f, 1.f};
    x12CommandListClearRenderTargetView(commandLists[f], swapchainDescriptorsCpuDescriptorRTV[f], clearColor, 0, 0);
    x12CommandListClearDepthStencilView(commandLists[f], imageDepthDsvCpuDescriptorDSV, D3D12_CLEAR_FLAG_DEPTH, 1.f, 0, 0, 0);
    x12CommandListSetGraphicsRootSignature(commandLists[f], parametersScenePassRootSignature);
   {X12DescriptorHeap * setHeaps[2];
    setHeaps[0] = descriptorHeapScenePass;
    setHeaps[1] = descriptorHeapSamplerScenePass;
    x12CommandListSetDescriptorHeaps(commandLists[f], _countof(setHeaps), (const X12DescriptorHeap **)setHeaps);}
    D3D12_GPU_DESCRIPTOR_HANDLE descriptorHeap_ScenePass_gpuDescriptorHandle        = {};
    D3D12_GPU_DESCRIPTOR_HANDLE descriptorHeapSampler_ScenePass_gpuDescriptorHandle = {};
    x12DescriptorHeapGetGPUDescriptorHandleForHeapStart(descriptorHeapScenePass, &descriptorHeap_ScenePass_gpuDescriptorHandle);
    x12DescriptorHeapGetGPUDescriptorHandleForHeapStart(descriptorHeapSamplerScenePass, &descriptorHeapSampler_ScenePass_gpuDescriptorHandle);
    x12CommandListSetGraphicsRootDescriptorTable(commandLists[f], 0, descriptorHeap_ScenePass_gpuDescriptorHandle);
    x12CommandListSetGraphicsRootDescriptorTable(commandLists[f], 1, descriptorHeapSampler_ScenePass_gpuDescriptorHandle);
    x12CommandListSetPipelineState(commandLists[f], pipelineScenePass);
    x12CommandListIASetPrimitiveTopology(commandLists[f], D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    x12CommandListIASetIndexBuffer(commandLists[f], &ibv);
    x12CommandListDrawIndexedInstanced(commandLists[f], 160749, 1, 0, 0, 0);
    D3D12_RESOURCE_BARRIER _4[1] = {};
    _4[0].Type                   = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    _4[0].Flags                  = D3D12_RESOURCE_BARRIER_FLAG_NONE;
    _4[0].Transition.pResource   = imageDepth;
    _4[0].Transition.StateBefore = D3D12_RESOURCE_STATE_DEPTH_WRITE;
    _4[0].Transition.StateAfter  = D3D12_RESOURCE_STATE_GENERIC_READ;
    _4[0].Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    x12CommandListResourceBarrier(commandLists[f], 1, _4);
    D3D12_RESOURCE_BARRIER _5[1] = {};
    _5[0].Type                   = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    _5[0].Flags                  = D3D12_RESOURCE_BARRIER_FLAG_NONE;
    _5[0].Transition.pResource   = swapchainResources[f];
    _5[0].Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
    _5[0].Transition.StateAfter  = D3D12_RESOURCE_STATE_PRESENT;
    _5[0].Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    x12CommandListResourceBarrier(commandLists[f], 1, _5);
    x12CommandListClose(commandLists[f], __FILE__, __LINE__);
  }

  x12SwapChainGetCurrentBackBufferIndex(swapchain, __FILE__, __LINE__); // Assumes currentBackBufferIndex == f
  X12CommandList * execute[] = {
    commandLists[f],
  };
  x12CommandQueueExecuteCommandLists(queue, _countof(execute), (const X12CommandList **)execute, __FILE__, __LINE__);
  DXGI_PRESENT_PARAMETERS presentParameters = {};
  x12SwapChainPresent1(swapchain, 1, 0, &presentParameters, __FILE__, __LINE__);
  x12CommandQueueSignal(queue, fence[f], 1, __FILE__, __LINE__);

  {
    // Just a test.
    float * p = (float *)arrayConstantBufferCameraMatricesMemoryPointer;
    p[8] += 0.001f;
  }
  
  f += 1;
  f %= 2;
  
  globalCacheSetAsU(L"", L"", L"frame", f);
  
  if (recompile == 1) {
    x12FenceSetEventOnCompletion(fence[0], 1, 0, __FILE__, __LINE__);
    x12FenceSignal(fence[0], 0, __FILE__, __LINE__);
    x12FenceSetEventOnCompletion(fence[1], 1, 0, __FILE__, __LINE__);
    x12FenceSignal(fence[1], 0, __FILE__, __LINE__);
  }
  return recompile;
}

#if defined(__clang__) || defined(_MSC_VER)
#include "Windows.h"
#else
typedef struct _CREATEFILE2_EXTENDED_PARAMETERS {
  DWORD dwSize;   
  DWORD dwFileAttributes;
  DWORD dwFileFlags;   
  DWORD dwSecurityQosFlags;	
  LPSECURITY_ATTRIBUTES lpSecurityAttributes; 
  HANDLE hTemplateFile;      
} CREATEFILE2_EXTENDED_PARAMETERS, * PCREATEFILE2_EXTENDED_PARAMETERS, * LPCREATEFILE2_EXTENDED_PARAMETERS;
#endif

int fileMap(const wchar_t * filepath, void ** outFileDescriptorHandle, void ** outFileMappingHandle, uint64_t * outFileDataBytesCount, void ** outFileData) {
  HANDLE (*tccCreateFile2)              (LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, DWORD dwCreationDisposition, LPCREATEFILE2_EXTENDED_PARAMETERS pCreateExParams);
  BOOL   (*tccGetFileSizeEx)            (HANDLE hFile, PLARGE_INTEGER lpFileSize);
  HANDLE (*tccCreateFileMappingFromApp) (HANDLE hFile, PSECURITY_ATTRIBUTES SecurityAttributes, ULONG PageProtection, ULONG64 MaximumSize, PCWSTR Name);
  PVOID  (*tccMapViewOfFileFromApp)     (HANDLE hFileMappingObject, ULONG DesiredAccess, ULONG64 FileOffset, SIZE_T NumberOfBytesToMap);
  tccCreateFile2              = GetProcAddress(GetModuleHandleA("kernel32.dll"), "CreateFile2");
  tccGetFileSizeEx            = GetProcAddress(GetModuleHandleA("kernel32.dll"), "GetFileSizeEx");
  tccCreateFileMappingFromApp = GetProcAddress(GetModuleHandleA("kernel32.dll"), "CreateFileMappingFromApp");
  tccMapViewOfFileFromApp     = GetProcAddress(GetModuleHandleA("kernel32.dll"), "MapViewOfFileFromApp");

  HANDLE fd = tccCreateFile2(filepath, FILE_READ_DATA, FILE_SHARE_READ | FILE_SHARE_WRITE, OPEN_EXISTING, 0);
  if (fd == INVALID_HANDLE_VALUE) {
    return -1;
  }
  if (outFileDescriptorHandle != NULL) {
    outFileDescriptorHandle[0] = fd;
  }
  size_t fsize = 0;
  tccGetFileSizeEx(fd, (PLARGE_INTEGER)&fsize);
  if (outFileDataBytesCount != NULL) {
    outFileDataBytesCount[0] = fsize;
  }
  HANDLE fm = tccCreateFileMappingFromApp(fd, 0, PAGE_READONLY, fsize, 0);
  if (fm == INVALID_HANDLE_VALUE) {
    return -2;
  }
  if (outFileMappingHandle != NULL) {
    outFileMappingHandle[0] = fm;
  }
  void * fdata = tccMapViewOfFileFromApp(fm, FILE_MAP_READ, 0, 0);
  if (outFileData != NULL) {
    outFileData[0] = fdata;
  }
  return 0;
}

int fileUnmap(void * fileDescriptorHandle, void * fileMappingHandle) {
  int out = 0;
  if (fileDescriptorHandle != INVALID_HANDLE_VALUE) {
    int closeHandleSuccess = CloseHandle(fileDescriptorHandle);
    if (closeHandleSuccess == 0) {     // "If the function fails, the return value is zero." https://docs.microsoft.com/en-us/windows/win32/api/handleapi/nf-handleapi-closehandle
      out = -1;
    }
  }
  if (fileMappingHandle != INVALID_HANDLE_VALUE) {
    int unmapViewOfFileSuccess = UnmapViewOfFile(fileMappingHandle);
    if (unmapViewOfFileSuccess == 0) { // "If the function fails, the return value is zero." https://docs.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-unmapviewoffile
      out = -2;
    }
  }
  return out;
}
