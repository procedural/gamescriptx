#include "frame.h"

#include "program.hlsl.vs.h"
#include "program.hlsl.ps.h"

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
  
  X12RootSignature * parametersRootSignature = globalCacheGetAsP(L"", L"X12RootSignature", L"parametersRootSignature");
  X12Blob *          parametersBlob          = globalCacheGetAsP(L"", L"X12Blob", L"parametersBlob");
  X12Blob *          parametersBlobError     = globalCacheGetAsP(L"", L"X12Blob", L"parametersBlobError");
  if (parametersRootSignature == 0) {
    D3D12_ROOT_SIGNATURE_DESC rootSignatureDesc = {};
    rootSignatureDesc.NumParameters     = 0;
    rootSignatureDesc.pParameters       = 0;
    rootSignatureDesc.NumStaticSamplers = 0;
    rootSignatureDesc.pStaticSamplers   = 0;
    rootSignatureDesc.Flags             = D3D12_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS | D3D12_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS | D3D12_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS;
    x12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &parametersBlob, &parametersBlobError, __FILE__, __LINE__);
    // NOTE: Check parametersBlobError on errors here.
    x12DeviceCreateRootSignature(device, 0, x12BlobGetBufferPointer(parametersBlob), x12BlobGetBufferSize(parametersBlob), &parametersRootSignature, __FILE__, __LINE__);
    x12ObjectSetName(parametersRootSignature, L"parametersRootSignature", __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12RootSignature", L"parametersRootSignature", parametersRootSignature);
    globalCacheSetAsP(L"", L"X12Blob", L"parametersBlob", parametersBlob);
    globalCacheSetAsP(L"", L"X12Blob", L"parametersBlobError", parametersBlobError);
  }
  
  X12PipelineState * pipeline = globalCacheGetAsP(L"", L"X12PipelineState", L"pipeline");
  if (pipeline == 0) {
    D3D12_GRAPHICS_PIPELINE_STATE_DESC pipelineState = {};
    pipelineState.pRootSignature                                   = parametersRootSignature;
    pipelineState.VS.pShaderBytecode                               = g_VSMain;
    pipelineState.VS.BytecodeLength                                = sizeof(g_VSMain);
    pipelineState.PS.pShaderBytecode                               = g_PSMain;
    pipelineState.PS.BytecodeLength                                = sizeof(g_PSMain);
    pipelineState.BlendState.AlphaToCoverageEnable                 = 0;
    pipelineState.BlendState.IndependentBlendEnable                = 0;
    for (unsigned i = 0; i < 8; i += 1) {
    pipelineState.BlendState.RenderTarget[i].BlendEnable           = 0;
    pipelineState.BlendState.RenderTarget[i].LogicOpEnable         = 0;
    pipelineState.BlendState.RenderTarget[i].SrcBlend              = D3D12_BLEND_ONE;
    pipelineState.BlendState.RenderTarget[i].DestBlend             = D3D12_BLEND_ZERO;
    pipelineState.BlendState.RenderTarget[i].BlendOp               = D3D12_BLEND_OP_ADD;
    pipelineState.BlendState.RenderTarget[i].SrcBlendAlpha         = D3D12_BLEND_ONE;
    pipelineState.BlendState.RenderTarget[i].DestBlendAlpha        = D3D12_BLEND_ZERO;
    pipelineState.BlendState.RenderTarget[i].BlendOpAlpha          = D3D12_BLEND_OP_ADD;
    pipelineState.BlendState.RenderTarget[i].LogicOp               = D3D12_LOGIC_OP_NOOP;
    pipelineState.BlendState.RenderTarget[i].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
    }
    pipelineState.SampleMask                                       = 0xffffffff;
    pipelineState.RasterizerState.FillMode                         = D3D12_FILL_MODE_SOLID;
    pipelineState.RasterizerState.CullMode                         = D3D12_CULL_MODE_NONE;
    pipelineState.RasterizerState.FrontCounterClockwise            = 1;
    pipelineState.RasterizerState.DepthBias                        = D3D12_DEFAULT_DEPTH_BIAS;
    pipelineState.RasterizerState.DepthBiasClamp                   = D3D12_DEFAULT_DEPTH_BIAS_CLAMP;
    pipelineState.RasterizerState.SlopeScaledDepthBias             = D3D12_DEFAULT_SLOPE_SCALED_DEPTH_BIAS;
    pipelineState.RasterizerState.DepthClipEnable                  = 1;
    pipelineState.RasterizerState.MultisampleEnable                = 0;
    pipelineState.RasterizerState.AntialiasedLineEnable            = 0;
    pipelineState.RasterizerState.ForcedSampleCount                = 0;
    pipelineState.RasterizerState.ConservativeRaster               = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;
    pipelineState.DepthStencilState.DepthEnable                    = 0;
    pipelineState.DepthStencilState.DepthWriteMask                 = D3D12_DEPTH_WRITE_MASK_ALL;
    pipelineState.DepthStencilState.DepthFunc                      = D3D12_COMPARISON_FUNC_LESS;
    pipelineState.DepthStencilState.StencilEnable                  = 0;
    pipelineState.DepthStencilState.StencilReadMask                = D3D12_DEFAULT_STENCIL_READ_MASK;
    pipelineState.DepthStencilState.StencilWriteMask               = D3D12_DEFAULT_STENCIL_WRITE_MASK;
    pipelineState.DepthStencilState.FrontFace.StencilFailOp        = D3D12_STENCIL_OP_KEEP;
    pipelineState.DepthStencilState.FrontFace.StencilDepthFailOp   = D3D12_STENCIL_OP_KEEP;
    pipelineState.DepthStencilState.FrontFace.StencilPassOp        = D3D12_STENCIL_OP_KEEP;
    pipelineState.DepthStencilState.FrontFace.StencilFunc          = D3D12_COMPARISON_FUNC_ALWAYS;
    pipelineState.DepthStencilState.BackFace.StencilFailOp         = D3D12_STENCIL_OP_KEEP;
    pipelineState.DepthStencilState.BackFace.StencilDepthFailOp    = D3D12_STENCIL_OP_KEEP;
    pipelineState.DepthStencilState.BackFace.StencilPassOp         = D3D12_STENCIL_OP_KEEP;
    pipelineState.DepthStencilState.BackFace.StencilFunc           = D3D12_COMPARISON_FUNC_ALWAYS;
    pipelineState.IBStripCutValue                                  = D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_DISABLED;
    pipelineState.PrimitiveTopologyType                            = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
    pipelineState.NumRenderTargets                                 = 1;
    pipelineState.RTVFormats[0]                                    = DXGI_FORMAT_B8G8R8A8_UNORM_SRGB;
    pipelineState.RTVFormats[1]                                    = DXGI_FORMAT_UNKNOWN;
    pipelineState.RTVFormats[2]                                    = DXGI_FORMAT_UNKNOWN;
    pipelineState.RTVFormats[3]                                    = DXGI_FORMAT_UNKNOWN;
    pipelineState.RTVFormats[4]                                    = DXGI_FORMAT_UNKNOWN;
    pipelineState.RTVFormats[5]                                    = DXGI_FORMAT_UNKNOWN;
    pipelineState.RTVFormats[6]                                    = DXGI_FORMAT_UNKNOWN;
    pipelineState.RTVFormats[7]                                    = DXGI_FORMAT_UNKNOWN;
    pipelineState.DSVFormat                                        = DXGI_FORMAT_UNKNOWN;
    pipelineState.SampleDesc.Count                                 = 1;
    pipelineState.SampleDesc.Quality                               = 0;
    pipelineState.NodeMask                                         = 0;
    pipelineState.CachedPSO.pCachedBlob                            = 0;
    pipelineState.CachedPSO.CachedBlobSizeInBytes                  = 0;
    pipelineState.Flags                                            = D3D12_PIPELINE_STATE_FLAG_NONE;
    x12DeviceCreateGraphicsPipelineState(device, &pipelineState, &pipeline, __FILE__, __LINE__);
    x12ObjectSetName(pipeline, L"pipeline", __FILE__, __LINE__);
    globalCacheSetAsP(L"", L"X12PipelineState", L"pipeline", pipeline);
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
    viewport.Width    = 1800.f;
    viewport.Height   = 900.f;
    viewport.MinDepth = 0.f;
    viewport.MaxDepth = 1.f;
    D3D12_RECT scissor = {};
    scissor.left   = 0;
    scissor.top    = 0;
    scissor.right  = 1800;
    scissor.bottom = 900;
    x12CommandListRSSetViewports(commandLists[f], 1, &viewport);
    x12CommandListRSSetScissorRects(commandLists[f], 1, &scissor);
    D3D12_RESOURCE_BARRIER _0[1] = {};
    _0[0].Type                   = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    _0[0].Flags                  = D3D12_RESOURCE_BARRIER_FLAG_NONE;
    _0[0].Transition.pResource   = swapchainResources[f];
    _0[0].Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
    _0[0].Transition.StateAfter  = D3D12_RESOURCE_STATE_RENDER_TARGET;
    _0[0].Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    x12CommandListResourceBarrier(commandLists[f], 1, _0);
    x12CommandListOMSetRenderTargets(commandLists[f], 1, &swapchainDescriptorsCpuDescriptorRTV[f], 0, 0);
    const float clearColor[] = {0.f, 0.f, 0.f, 1.f};
    x12CommandListClearRenderTargetView(commandLists[f], swapchainDescriptorsCpuDescriptorRTV[f], clearColor, 0, 0);
    x12CommandListSetGraphicsRootSignature(commandLists[f], parametersRootSignature);
    x12CommandListSetPipelineState(commandLists[f], pipeline);
    x12CommandListIASetPrimitiveTopology(commandLists[f], D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    x12CommandListDrawInstanced(commandLists[f], 3, 1, 0, 0);
    D3D12_RESOURCE_BARRIER _1[1] = {};
    _1[0].Type                   = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
    _1[0].Flags                  = D3D12_RESOURCE_BARRIER_FLAG_NONE;
    _1[0].Transition.pResource   = swapchainResources[f];
    _1[0].Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
    _1[0].Transition.StateAfter  = D3D12_RESOURCE_STATE_PRESENT;
    _1[0].Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
    x12CommandListResourceBarrier(commandLists[f], 1, _1);
    
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
