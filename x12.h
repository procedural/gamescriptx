#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define HRESULT long
typedef int X12Bool;
#ifdef _WIN64
typedef struct X12TypeGpuVirtualAddress * D3D12_GPU_VIRTUAL_ADDRESS;
#else
typedef uint64_t D3D12_GPU_VIRTUAL_ADDRESS;
#endif

typedef struct X12TypeFactory4                  * X12Factory4;
typedef struct X12TypeAdapter3                  * X12Adapter3;
typedef struct X12TypeDevice3                   * X12Device3;
typedef struct X12TypeHeap                      * X12Heap;                      // X12Pageable
typedef struct X12TypeResource                  * X12Resource;                  // X12Pageable (committed X12Resource only)
typedef struct X12TypeDescriptorHeap            * X12DescriptorHeap;            // X12Pageable
typedef struct X12TypePageable                  * X12Pageable;
typedef struct X12TypeBlob                      * X12Blob;
typedef struct X12TypeRootSignature             * X12RootSignature;
typedef struct X12TypeRootSignatureDeserializer * X12RootSignatureDeserializer;
typedef struct X12TypePipelineState             * X12PipelineState;
typedef struct X12TypeFence                     * X12Fence;
typedef struct X12TypeCommandQueue              * X12CommandQueue;
typedef struct X12TypeCommandAllocator          * X12CommandAllocator;
typedef struct X12TypeCommandList               * X12CommandList;
typedef struct X12TypeSwapChain3                * X12SwapChain3;
typedef struct X12TypeOutput4                   * X12Output4;

#define D3D12_16BIT_INDEX_STRIP_CUT_VALUE                                        (0xffff)
#define D3D12_32BIT_INDEX_STRIP_CUT_VALUE                                        (0xffffffff)
#define D3D12_8BIT_INDEX_STRIP_CUT_VALUE                                         (0xff)
#define D3D12_APPEND_ALIGNED_ELEMENT                                             (0xffffffff)
#define D3D12_ARRAY_AXIS_ADDRESS_RANGE_BIT_COUNT                                 (9)
#define D3D12_CLIP_OR_CULL_DISTANCE_COUNT                                        (8)
#define D3D12_CLIP_OR_CULL_DISTANCE_ELEMENT_COUNT                                (2)
#define D3D12_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT                        (14)
#define D3D12_COMMONSHADER_CONSTANT_BUFFER_COMPONENTS                            (4)
#define D3D12_COMMONSHADER_CONSTANT_BUFFER_COMPONENT_BIT_COUNT                   (32)
#define D3D12_COMMONSHADER_CONSTANT_BUFFER_HW_SLOT_COUNT                         (15)
#define D3D12_COMMONSHADER_CONSTANT_BUFFER_PARTIAL_UPDATE_EXTENTS_BYTE_ALIGNMENT (16)
#define D3D12_COMMONSHADER_CONSTANT_BUFFER_REGISTER_COMPONENTS                   (4)
#define D3D12_COMMONSHADER_CONSTANT_BUFFER_REGISTER_COUNT                        (15)
#define D3D12_COMMONSHADER_CONSTANT_BUFFER_REGISTER_READS_PER_INST               (1)
#define D3D12_COMMONSHADER_CONSTANT_BUFFER_REGISTER_READ_PORTS                   (1)
#define D3D12_COMMONSHADER_FLOWCONTROL_NESTING_LIMIT                             (64)
#define D3D12_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_COMPONENTS         (4)
#define D3D12_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_COUNT              (1)
#define D3D12_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_READS_PER_INST     (1)
#define D3D12_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_READ_PORTS         (1)
#define D3D12_COMMONSHADER_IMMEDIATE_VALUE_COMPONENT_BIT_COUNT                   (32)
#define D3D12_COMMONSHADER_INPUT_RESOURCE_REGISTER_COMPONENTS                    (1)
#define D3D12_COMMONSHADER_INPUT_RESOURCE_REGISTER_COUNT                         (128)
#define D3D12_COMMONSHADER_INPUT_RESOURCE_REGISTER_READS_PER_INST                (1)
#define D3D12_COMMONSHADER_INPUT_RESOURCE_REGISTER_READ_PORTS                    (1)
#define D3D12_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT                             (128)
#define D3D12_COMMONSHADER_SAMPLER_REGISTER_COMPONENTS                           (1)
#define D3D12_COMMONSHADER_SAMPLER_REGISTER_COUNT                                (16)
#define D3D12_COMMONSHADER_SAMPLER_REGISTER_READS_PER_INST                       (1)
#define D3D12_COMMONSHADER_SAMPLER_REGISTER_READ_PORTS                           (1)
#define D3D12_COMMONSHADER_SAMPLER_SLOT_COUNT                                    (16)
#define D3D12_COMMONSHADER_SUBROUTINE_NESTING_LIMIT                              (32)
#define D3D12_COMMONSHADER_TEMP_REGISTER_COMPONENTS                              (4)
#define D3D12_COMMONSHADER_TEMP_REGISTER_COMPONENT_BIT_COUNT                     (32)
#define D3D12_COMMONSHADER_TEMP_REGISTER_COUNT                                   (4096)
#define D3D12_COMMONSHADER_TEMP_REGISTER_READS_PER_INST                          (3)
#define D3D12_COMMONSHADER_TEMP_REGISTER_READ_PORTS                              (3)
#define D3D12_COMMONSHADER_TEXCOORD_RANGE_REDUCTION_MAX                          (10)
#define D3D12_COMMONSHADER_TEXCOORD_RANGE_REDUCTION_MIN                          (-10)
#define D3D12_COMMONSHADER_TEXEL_OFFSET_MAX_NEGATIVE                             (-8)
#define D3D12_COMMONSHADER_TEXEL_OFFSET_MAX_POSITIVE                             (7)
#define D3D12_CONSTANT_BUFFER_DATA_PLACEMENT_ALIGNMENT                           (256)
#define D3D12_CS_4_X_BUCKET00_MAX_BYTES_TGSM_WRITABLE_PER_THREAD                 (256)
#define D3D12_CS_4_X_BUCKET00_MAX_NUM_THREADS_PER_GROUP                          (64)
#define D3D12_CS_4_X_BUCKET01_MAX_BYTES_TGSM_WRITABLE_PER_THREAD                 (240)
#define D3D12_CS_4_X_BUCKET01_MAX_NUM_THREADS_PER_GROUP                          (68)
#define D3D12_CS_4_X_BUCKET02_MAX_BYTES_TGSM_WRITABLE_PER_THREAD                 (224)
#define D3D12_CS_4_X_BUCKET02_MAX_NUM_THREADS_PER_GROUP                          (72)
#define D3D12_CS_4_X_BUCKET03_MAX_BYTES_TGSM_WRITABLE_PER_THREAD                 (208)
#define D3D12_CS_4_X_BUCKET03_MAX_NUM_THREADS_PER_GROUP                          (76)
#define D3D12_CS_4_X_BUCKET04_MAX_BYTES_TGSM_WRITABLE_PER_THREAD                 (192)
#define D3D12_CS_4_X_BUCKET04_MAX_NUM_THREADS_PER_GROUP                          (84)
#define D3D12_CS_4_X_BUCKET05_MAX_BYTES_TGSM_WRITABLE_PER_THREAD                 (176)
#define D3D12_CS_4_X_BUCKET05_MAX_NUM_THREADS_PER_GROUP                          (92)
#define D3D12_CS_4_X_BUCKET06_MAX_BYTES_TGSM_WRITABLE_PER_THREAD                 (160)
#define D3D12_CS_4_X_BUCKET06_MAX_NUM_THREADS_PER_GROUP                          (100)
#define D3D12_CS_4_X_BUCKET07_MAX_BYTES_TGSM_WRITABLE_PER_THREAD                 (144)
#define D3D12_CS_4_X_BUCKET07_MAX_NUM_THREADS_PER_GROUP                          (112)
#define D3D12_CS_4_X_BUCKET08_MAX_BYTES_TGSM_WRITABLE_PER_THREAD                 (128)
#define D3D12_CS_4_X_BUCKET08_MAX_NUM_THREADS_PER_GROUP                          (128)
#define D3D12_CS_4_X_BUCKET09_MAX_BYTES_TGSM_WRITABLE_PER_THREAD                 (112)
#define D3D12_CS_4_X_BUCKET09_MAX_NUM_THREADS_PER_GROUP                          (144)
#define D3D12_CS_4_X_BUCKET10_MAX_BYTES_TGSM_WRITABLE_PER_THREAD                 (96)
#define D3D12_CS_4_X_BUCKET10_MAX_NUM_THREADS_PER_GROUP                          (168)
#define D3D12_CS_4_X_BUCKET11_MAX_BYTES_TGSM_WRITABLE_PER_THREAD                 (80)
#define D3D12_CS_4_X_BUCKET11_MAX_NUM_THREADS_PER_GROUP                          (204)
#define D3D12_CS_4_X_BUCKET12_MAX_BYTES_TGSM_WRITABLE_PER_THREAD                 (64)
#define D3D12_CS_4_X_BUCKET12_MAX_NUM_THREADS_PER_GROUP                          (256)
#define D3D12_CS_4_X_BUCKET13_MAX_BYTES_TGSM_WRITABLE_PER_THREAD                 (48)
#define D3D12_CS_4_X_BUCKET13_MAX_NUM_THREADS_PER_GROUP                          (340)
#define D3D12_CS_4_X_BUCKET14_MAX_BYTES_TGSM_WRITABLE_PER_THREAD                 (32)
#define D3D12_CS_4_X_BUCKET14_MAX_NUM_THREADS_PER_GROUP                          (512)
#define D3D12_CS_4_X_BUCKET15_MAX_BYTES_TGSM_WRITABLE_PER_THREAD                 (16)
#define D3D12_CS_4_X_BUCKET15_MAX_NUM_THREADS_PER_GROUP                          (768)
#define D3D12_CS_4_X_DISPATCH_MAX_THREAD_GROUPS_IN_Z_DIMENSION                   (1)
#define D3D12_CS_4_X_RAW_UAV_BYTE_ALIGNMENT                                      (256)
#define D3D12_CS_4_X_THREAD_GROUP_MAX_THREADS_PER_GROUP                          (768)
#define D3D12_CS_4_X_THREAD_GROUP_MAX_X                                          (768)
#define D3D12_CS_4_X_THREAD_GROUP_MAX_Y                                          (768)
#define D3D12_CS_4_X_UAV_REGISTER_COUNT                                          (1)
#define D3D12_CS_DISPATCH_MAX_THREAD_GROUPS_PER_DIMENSION                        (65535)
#define D3D12_CS_TGSM_REGISTER_COUNT                                             (8192)
#define D3D12_CS_TGSM_REGISTER_READS_PER_INST                                    (1)
#define D3D12_CS_TGSM_RESOURCE_REGISTER_COMPONENTS                               (1)
#define D3D12_CS_TGSM_RESOURCE_REGISTER_READ_PORTS                               (1)
#define D3D12_CS_THREADGROUPID_REGISTER_COMPONENTS                               (3)
#define D3D12_CS_THREADGROUPID_REGISTER_COUNT                                    (1)
#define D3D12_CS_THREADIDINGROUPFLATTENED_REGISTER_COMPONENTS                    (1)
#define D3D12_CS_THREADIDINGROUPFLATTENED_REGISTER_COUNT                         (1)
#define D3D12_CS_THREADIDINGROUP_REGISTER_COMPONENTS                             (3)
#define D3D12_CS_THREADIDINGROUP_REGISTER_COUNT                                  (1)
#define D3D12_CS_THREADID_REGISTER_COMPONENTS                                    (3)
#define D3D12_CS_THREADID_REGISTER_COUNT                                         (1)
#define D3D12_CS_THREAD_GROUP_MAX_THREADS_PER_GROUP                              (1024)
#define D3D12_CS_THREAD_GROUP_MAX_X                                              (1024)
#define D3D12_CS_THREAD_GROUP_MAX_Y                                              (1024)
#define D3D12_CS_THREAD_GROUP_MAX_Z                                              (64)
#define D3D12_CS_THREAD_GROUP_MIN_X                                              (1)
#define D3D12_CS_THREAD_GROUP_MIN_Y                                              (1)
#define D3D12_CS_THREAD_GROUP_MIN_Z                                              (1)
#define D3D12_CS_THREAD_LOCAL_TEMP_REGISTER_POOL                                 (16384)
#define D3D12_DEFAULT_BLEND_FACTOR_ALPHA                                         (1.0f)
#define D3D12_DEFAULT_BLEND_FACTOR_BLUE                                          (1.0f)
#define D3D12_DEFAULT_BLEND_FACTOR_GREEN                                         (1.0f)
#define D3D12_DEFAULT_BLEND_FACTOR_RED                                           (1.0f)
#define D3D12_DEFAULT_BORDER_COLOR_COMPONENT                                     (0.0f)
#define D3D12_DEFAULT_DEPTH_BIAS                                                 (0)
#define D3D12_DEFAULT_DEPTH_BIAS_CLAMP                                           (0.0f)
#define D3D12_DEFAULT_MAX_ANISOTROPY                                             (16)
#define D3D12_DEFAULT_MIP_LOD_BIAS                                               (0.0f)
#define D3D12_DEFAULT_MSAA_RESOURCE_PLACEMENT_ALIGNMENT                          (4194304)
#define D3D12_DEFAULT_RENDER_TARGET_ARRAY_INDEX                                  (0)
#define D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT                               (65536)
#define D3D12_DEFAULT_SAMPLE_MASK                                                (0xffffffff)
#define D3D12_DEFAULT_SCISSOR_ENDX                                               (0)
#define D3D12_DEFAULT_SCISSOR_ENDY                                               (0)
#define D3D12_DEFAULT_SCISSOR_STARTX                                             (0)
#define D3D12_DEFAULT_SCISSOR_STARTY                                             (0)
#define D3D12_DEFAULT_SLOPE_SCALED_DEPTH_BIAS                                    (0.0f)
#define D3D12_DEFAULT_STENCIL_READ_MASK                                          (0xff)
#define D3D12_DEFAULT_STENCIL_REFERENCE                                          (0)
#define D3D12_DEFAULT_STENCIL_WRITE_MASK                                         (0xff)
#define D3D12_DEFAULT_VIEWPORT_AND_SCISSORRECT_INDEX                             (0)
#define D3D12_DEFAULT_VIEWPORT_HEIGHT                                            (0)
#define D3D12_DEFAULT_VIEWPORT_MAX_DEPTH                                         (0.0f)
#define D3D12_DEFAULT_VIEWPORT_MIN_DEPTH                                         (0.0f)
#define D3D12_DEFAULT_VIEWPORT_TOPLEFTX                                          (0)
#define D3D12_DEFAULT_VIEWPORT_TOPLEFTY                                          (0)
#define D3D12_DEFAULT_VIEWPORT_WIDTH                                             (0)
#define D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND                                     (0xffffffff)
#define D3D12_DRIVER_RESERVED_REGISTER_SPACE_VALUES_END                          (0xfffffff7)
#define D3D12_DRIVER_RESERVED_REGISTER_SPACE_VALUES_START                        (0xfffffff0)
#define D3D12_FLOAT16_FUSED_TOLERANCE_IN_ULP                                     (0.6)
#define D3D12_FLOAT32_MAX                                                        (3.402823466e+38f)
#define D3D12_FLOAT32_TO_INTEGER_TOLERANCE_IN_ULP                                (0.6f)
#define D3D12_FLOAT_TO_SRGB_EXPONENT_DENOMINATOR                                 (2.4f)
#define D3D12_FLOAT_TO_SRGB_EXPONENT_NUMERATOR                                   (1.0f)
#define D3D12_FLOAT_TO_SRGB_OFFSET                                               (0.055f)
#define D3D12_FLOAT_TO_SRGB_SCALE_1                                              (12.92f)
#define D3D12_FLOAT_TO_SRGB_SCALE_2                                              (1.055f)
#define D3D12_FLOAT_TO_SRGB_THRESHOLD                                            (0.0031308f)
#define D3D12_FTOI_INSTRUCTION_MAX_INPUT                                         (2147483647.999f)
#define D3D12_FTOI_INSTRUCTION_MIN_INPUT                                         (-2147483648.999f)
#define D3D12_FTOU_INSTRUCTION_MAX_INPUT                                         (4294967295.999f)
#define D3D12_FTOU_INSTRUCTION_MIN_INPUT                                         (0.0f)
#define D3D12_IA_DEFAULT_INDEX_BUFFER_OFFSET_IN_BYTES                            (0)
#define D3D12_IA_DEFAULT_PRIMITIVE_TOPOLOGY                                      (0)
#define D3D12_IA_DEFAULT_VERTEX_BUFFER_OFFSET_IN_BYTES                           (0)
#define D3D12_IA_INDEX_INPUT_RESOURCE_SLOT_COUNT                                 (1)
#define D3D12_IA_INSTANCE_ID_BIT_COUNT                                           (32)
#define D3D12_IA_INTEGER_ARITHMETIC_BIT_COUNT                                    (32)
#define D3D12_IA_PATCH_MAX_CONTROL_POINT_COUNT                                   (32)
#define D3D12_IA_PRIMITIVE_ID_BIT_COUNT                                          (32)
#define D3D12_IA_VERTEX_ID_BIT_COUNT                                             (32)
#define D3D12_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT                                (32)
#define D3D12_IA_VERTEX_INPUT_STRUCTURE_ELEMENTS_COMPONENTS                      (128)
#define D3D12_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT                            (32)
#define D3D12_INTEGER_DIVIDE_BY_ZERO_QUOTIENT                                    (0xffffffff)
#define D3D12_INTEGER_DIVIDE_BY_ZERO_REMAINDER                                   (0xffffffff)
#define D3D12_KEEP_RENDER_TARGETS_AND_DEPTH_STENCIL                              (0xffffffff)
#define D3D12_KEEP_UNORDERED_ACCESS_VIEWS                                        (0xffffffff)
#define D3D12_LINEAR_GAMMA                                                       (1.0f)
#define D3D12_MAJOR_VERSION                                                      (12)
#define D3D12_MAX_BORDER_COLOR_COMPONENT                                         (1.0f)
#define D3D12_MAX_DEPTH                                                          (1.0f)
#define D3D12_MAX_LIVE_STATIC_SAMPLERS                                           (2032)
#define D3D12_MAX_MAXANISOTROPY                                                  (16)
#define D3D12_MAX_MULTISAMPLE_SAMPLE_COUNT                                       (32)
#define D3D12_MAX_POSITION_VALUE                                                 (3.402823466e+34f)
#define D3D12_MAX_ROOT_COST                                                      (64)
#define D3D12_MAX_SHADER_VISIBLE_DESCRIPTOR_HEAP_SIZE_TIER_1                     (1000000)
#define D3D12_MAX_SHADER_VISIBLE_DESCRIPTOR_HEAP_SIZE_TIER_2                     (1000000)
#define D3D12_MAX_SHADER_VISIBLE_SAMPLER_HEAP_SIZE                               (2048)
#define D3D12_MAX_TEXTURE_DIMENSION_2_TO_EXP                                     (17)
#define D3D12_MINOR_VERSION                                                      (0)
#define D3D12_MIN_BORDER_COLOR_COMPONENT                                         (0.0f)
#define D3D12_MIN_DEPTH                                                          (0.0f)
#define D3D12_MIN_MAXANISOTROPY                                                  (0)
#define D3D12_MIP_LOD_BIAS_MAX                                                   (15.99f)
#define D3D12_MIP_LOD_BIAS_MIN                                                   (-16.0f)
#define D3D12_MIP_LOD_FRACTIONAL_BIT_COUNT                                       (8)
#define D3D12_MIP_LOD_RANGE_BIT_COUNT                                            (8)
#define D3D12_MULTISAMPLE_ANTIALIAS_LINE_WIDTH                                   (1.4f)
#define D3D12_NONSAMPLE_FETCH_OUT_OF_RANGE_ACCESS_RESULT                         (0)
#define D3D12_OS_RESERVED_REGISTER_SPACE_VALUES_END                              (0xffffffff)
#define D3D12_OS_RESERVED_REGISTER_SPACE_VALUES_START                            (0xfffffff8)
#define D3D12_PACKED_TILE                                                        (0xffffffff)
#define D3D12_PIXEL_ADDRESS_RANGE_BIT_COUNT                                      (15)
#define D3D12_PRE_SCISSOR_PIXEL_ADDRESS_RANGE_BIT_COUNT                          (16)
#define D3D12_PS_CS_UAV_REGISTER_COMPONENTS                                      (1)
#define D3D12_PS_CS_UAV_REGISTER_COUNT                                           (8)
#define D3D12_PS_CS_UAV_REGISTER_READS_PER_INST                                  (1)
#define D3D12_PS_CS_UAV_REGISTER_READ_PORTS                                      (1)
#define D3D12_PS_FRONTFACING_DEFAULT_VALUE                                       (0xffffffff)
#define D3D12_PS_FRONTFACING_FALSE_VALUE                                         (0)
#define D3D12_PS_FRONTFACING_TRUE_VALUE                                          (0xffffffff)
#define D3D12_PS_INPUT_REGISTER_COMPONENTS                                       (4)
#define D3D12_PS_INPUT_REGISTER_COMPONENT_BIT_COUNT                              (32)
#define D3D12_PS_INPUT_REGISTER_COUNT                                            (32)
#define D3D12_PS_INPUT_REGISTER_READS_PER_INST                                   (2)
#define D3D12_PS_INPUT_REGISTER_READ_PORTS                                       (1)
#define D3D12_PS_LEGACY_PIXEL_CENTER_FRACTIONAL_COMPONENT                        (0.0f)
#define D3D12_PS_OUTPUT_DEPTH_REGISTER_COMPONENTS                                (1)
#define D3D12_PS_OUTPUT_DEPTH_REGISTER_COMPONENT_BIT_COUNT                       (32)
#define D3D12_PS_OUTPUT_DEPTH_REGISTER_COUNT                                     (1)
#define D3D12_PS_OUTPUT_MASK_REGISTER_COMPONENTS                                 (1)
#define D3D12_PS_OUTPUT_MASK_REGISTER_COMPONENT_BIT_COUNT                        (32)
#define D3D12_PS_OUTPUT_MASK_REGISTER_COUNT                                      (1)
#define D3D12_PS_OUTPUT_REGISTER_COMPONENTS                                      (4)
#define D3D12_PS_OUTPUT_REGISTER_COMPONENT_BIT_COUNT                             (32)
#define D3D12_PS_OUTPUT_REGISTER_COUNT                                           (8)
#define D3D12_PS_PIXEL_CENTER_FRACTIONAL_COMPONENT                               (0.5f)
#define D3D12_RAW_UAV_SRV_BYTE_ALIGNMENT                                         (16)
#define D3D12_REQ_BLEND_OBJECT_COUNT_PER_DEVICE                                  (4096)
#define D3D12_REQ_BUFFER_RESOURCE_TEXEL_COUNT_2_TO_EXP                           (27)
#define D3D12_REQ_CONSTANT_BUFFER_ELEMENT_COUNT                                  (4096)
#define D3D12_REQ_DEPTH_STENCIL_OBJECT_COUNT_PER_DEVICE                          (4096)
#define D3D12_REQ_DRAWINDEXED_INDEX_COUNT_2_TO_EXP                               (32)
#define D3D12_REQ_DRAW_VERTEX_COUNT_2_TO_EXP                                     (32)
#define D3D12_REQ_FILTERING_HW_ADDRESSABLE_RESOURCE_DIMENSION                    (16384)
#define D3D12_REQ_GS_INVOCATION_32BIT_OUTPUT_COMPONENT_LIMIT                     (1024)
#define D3D12_REQ_IMMEDIATE_CONSTANT_BUFFER_ELEMENT_COUNT                        (4096)
#define D3D12_REQ_MAXANISOTROPY                                                  (16)
#define D3D12_REQ_MIP_LEVELS                                                     (15)
#define D3D12_REQ_MULTI_ELEMENT_STRUCTURE_SIZE_IN_BYTES                          (2048)
#define D3D12_REQ_RASTERIZER_OBJECT_COUNT_PER_DEVICE                             (4096)
#define D3D12_REQ_RENDER_TO_BUFFER_WINDOW_WIDTH                                  (16384)
#define D3D12_REQ_RESOURCE_SIZE_IN_MEGABYTES_EXPRESSION_A_TERM                   (128)
#define D3D12_REQ_RESOURCE_SIZE_IN_MEGABYTES_EXPRESSION_B_TERM                   (0.25f)
#define D3D12_REQ_RESOURCE_SIZE_IN_MEGABYTES_EXPRESSION_C_TERM                   (2048)
#define D3D12_REQ_RESOURCE_VIEW_COUNT_PER_DEVICE_2_TO_EXP                        (20)
#define D3D12_REQ_SAMPLER_OBJECT_COUNT_PER_DEVICE                                (4096)
#define D3D12_REQ_SUBRESOURCES                                                   (30720)
#define D3D12_REQ_TEXTURE1D_ARRAY_AXIS_DIMENSION                                 (2048)
#define D3D12_REQ_TEXTURE1D_U_DIMENSION                                          (16384)
#define D3D12_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION                                 (2048)
#define D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION                                     (16384)
#define D3D12_REQ_TEXTURE3D_U_V_OR_W_DIMENSION                                   (2048)
#define D3D12_REQ_TEXTURECUBE_DIMENSION                                          (16384)
#define D3D12_RESINFO_INSTRUCTION_MISSING_COMPONENT_RETVAL                       (0)
#define D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES                                  (0xffffffff)
#define D3D12_SHADER_MAJOR_VERSION                                               (5)
#define D3D12_SHADER_MAX_INSTANCES                                               (65535)
#define D3D12_SHADER_MAX_INTERFACES                                              (253)
#define D3D12_SHADER_MAX_INTERFACE_CALL_SITES                                    (4096)
#define D3D12_SHADER_MAX_TYPES                                                   (65535)
#define D3D12_SHADER_MINOR_VERSION                                               (1)
#define D3D12_SHIFT_INSTRUCTION_PAD_VALUE                                        (0)
#define D3D12_SHIFT_INSTRUCTION_SHIFT_VALUE_BIT_COUNT                            (5)
#define D3D12_SIMULTANEOUS_RENDER_TARGET_COUNT                                   (8)
#define D3D12_SMALL_MSAA_RESOURCE_PLACEMENT_ALIGNMENT                            (65536)
#define D3D12_SMALL_RESOURCE_PLACEMENT_ALIGNMENT                                 (4096)
#define D3D12_SPEC_DATE_DAY                                                      (14)
#define D3D12_SPEC_DATE_MONTH                                                    (11)
#define D3D12_SPEC_DATE_YEAR                                                     (2014)
#define D3D12_SPEC_VERSION                                                       (1.16)
#define D3D12_SRGB_GAMMA                                                         (2.2f)
#define D3D12_SRGB_TO_FLOAT_DENOMINATOR_1                                        (12.92f)
#define D3D12_SRGB_TO_FLOAT_DENOMINATOR_2                                        (1.055f)
#define D3D12_SRGB_TO_FLOAT_EXPONENT                                             (2.4f)
#define D3D12_SRGB_TO_FLOAT_OFFSET                                               (0.055f)
#define D3D12_SRGB_TO_FLOAT_THRESHOLD                                            (0.04045f)
#define D3D12_SRGB_TO_FLOAT_TOLERANCE_IN_ULP                                     (0.5f)
#define D3D12_STANDARD_COMPONENT_BIT_COUNT                                       (32)
#define D3D12_STANDARD_COMPONENT_BIT_COUNT_DOUBLED                               (64)
#define D3D12_STANDARD_MAXIMUM_ELEMENT_ALIGNMENT_BYTE_MULTIPLE                   (4)
#define D3D12_STANDARD_PIXEL_COMPONENT_COUNT                                     (128)
#define D3D12_STANDARD_PIXEL_ELEMENT_COUNT                                       (32)
#define D3D12_STANDARD_VECTOR_SIZE                                               (4)
#define D3D12_STANDARD_VERTEX_ELEMENT_COUNT                                      (32)
#define D3D12_STANDARD_VERTEX_TOTAL_COMPONENT_COUNT                              (64)
#define D3D12_SUBPIXEL_FRACTIONAL_BIT_COUNT                                      (8)
#define D3D12_SUBTEXEL_FRACTIONAL_BIT_COUNT                                      (8)
#define D3D12_SYSTEM_RESERVED_REGISTER_SPACE_VALUES_END                          (0xffffffff)
#define D3D12_SYSTEM_RESERVED_REGISTER_SPACE_VALUES_START                        (0xfffffff0)
#define D3D12_TEXEL_ADDRESS_RANGE_BIT_COUNT                                      (16)
#define D3D12_TEXTURE_DATA_PITCH_ALIGNMENT                                       (256)
#define D3D12_TEXTURE_DATA_PLACEMENT_ALIGNMENT                                   (512)
#define D3D12_TILED_RESOURCE_TILE_SIZE_IN_BYTES                                  (65536)
#define D3D12_UAV_COUNTER_PLACEMENT_ALIGNMENT                                    (4096)
#define D3D12_UAV_SLOT_COUNT                                                     (64)
#define D3D12_UNBOUND_MEMORY_ACCESS_RESULT                                       (0)
#define D3D12_VIEWPORT_AND_SCISSORRECT_MAX_INDEX                                 (15)
#define D3D12_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE                 (16)
#define D3D12_VIEWPORT_BOUNDS_MAX                                                (32767)
#define D3D12_VIEWPORT_BOUNDS_MIN                                                (-32768)
#define D3D12_VS_INPUT_REGISTER_COMPONENTS                                       (4)
#define D3D12_VS_INPUT_REGISTER_COMPONENT_BIT_COUNT                              (32)
#define D3D12_VS_INPUT_REGISTER_COUNT                                            (32)
#define D3D12_VS_INPUT_REGISTER_READS_PER_INST                                   (2)
#define D3D12_VS_INPUT_REGISTER_READ_PORTS                                       (1)
#define D3D12_VS_OUTPUT_REGISTER_COMPONENTS                                      (4)
#define D3D12_VS_OUTPUT_REGISTER_COMPONENT_BIT_COUNT                             (32)
#define D3D12_VS_OUTPUT_REGISTER_COUNT                                           (32)
#define D3D12_WHQL_CONTEXT_COUNT_FOR_RESOURCE_LIMIT                              (10)
#define D3D12_WHQL_DRAWINDEXED_INDEX_COUNT_2_TO_EXP                              (25)
#define D3D12_WHQL_DRAW_VERTEX_COUNT_2_TO_EXP                                    (25)
#define DXGI_MAX_SWAP_CHAIN_BUFFERS                                              (16)

// x12AdapterQueryVideoMemoryInfo
// x12AdapterSetVideoMemoryReservation

typedef enum DXGI_MEMORY_SEGMENT_GROUP {
  DXGI_MEMORY_SEGMENT_GROUP_LOCAL     = 0,
  DXGI_MEMORY_SEGMENT_GROUP_NON_LOCAL = 1,
} DXGI_MEMORY_SEGMENT_GROUP;

typedef struct DXGI_QUERY_VIDEO_MEMORY_INFO {
  uint64_t Budget;
  uint64_t CurrentUsage;
  uint64_t AvailableForReservation;
  uint64_t CurrentReservation;
} DXGI_QUERY_VIDEO_MEMORY_INFO;

// x12DeviceCreateHeap

typedef enum D3D12_HEAP_TYPE {
  D3D12_HEAP_TYPE_DEFAULT  = 1,
  D3D12_HEAP_TYPE_UPLOAD   = 2,
  D3D12_HEAP_TYPE_READBACK = 3,
  D3D12_HEAP_TYPE_CUSTOM   = 4,
} D3D12_HEAP_TYPE;

typedef enum D3D12_CPU_PAGE_PROPERTY {
  D3D12_CPU_PAGE_PROPERTY_UNKNOWN       = 0,
  D3D12_CPU_PAGE_PROPERTY_NOT_AVAILABLE = 1,
  D3D12_CPU_PAGE_PROPERTY_WRITE_COMBINE = 2,
  D3D12_CPU_PAGE_PROPERTY_WRITE_BACK    = 3,
} D3D12_CPU_PAGE_PROPERTY;

typedef enum D3D12_MEMORY_POOL {
  D3D12_MEMORY_POOL_UNKNOWN = 0,
  D3D12_MEMORY_POOL_L0      = 1,
  D3D12_MEMORY_POOL_L1      = 2,
} D3D12_MEMORY_POOL;

typedef unsigned D3D12_HEAP_FLAGS;
typedef enum D3D12_HEAP_FLAG {
  D3D12_HEAP_FLAG_NONE                           = 0,
  D3D12_HEAP_FLAG_ALLOW_ALL_BUFFERS_AND_TEXTURES = 0,
  D3D12_HEAP_FLAG_ALLOW_ONLY_BUFFERS             = 0xc0,
  D3D12_HEAP_FLAG_ALLOW_ONLY_NON_RT_DS_TEXTURES  = 0x44,
  D3D12_HEAP_FLAG_ALLOW_ONLY_RT_DS_TEXTURES      = 0x84,
  D3D12_HEAP_FLAG_DENY_BUFFERS                   = 0x4,
  D3D12_HEAP_FLAG_DENY_NON_RT_DS_TEXTURES        = 0x80,
  D3D12_HEAP_FLAG_DENY_RT_DS_TEXTURES            = 0x40,
  D3D12_HEAP_FLAG_CREATE_NOT_RESIDENT            = 0x800,
  D3D12_HEAP_FLAG_CREATE_NOT_ZEROED              = 0x1000,
  D3D12_HEAP_FLAG_ALLOW_DISPLAY                  = 0x8,
  D3D12_HEAP_FLAG_ALLOW_SHADER_ATOMICS           = 0x400,
  D3D12_HEAP_FLAG_SHARED                         = 0x1,
  D3D12_HEAP_FLAG_SHARED_CROSS_ADAPTER           = 0x20,
} D3D12_HEAP_FLAG;

typedef struct D3D12_HEAP_PROPERTIES {
  D3D12_HEAP_TYPE         Type;
  D3D12_CPU_PAGE_PROPERTY CPUPageProperty;
  D3D12_MEMORY_POOL       MemoryPoolPreference;
  unsigned                CreationNodeMask;
  unsigned                VisibleNodeMask;
} D3D12_HEAP_PROPERTIES;

typedef struct D3D12_HEAP_DESC {
  uint64_t              SizeInBytes;
  D3D12_HEAP_PROPERTIES Properties;
  uint64_t              Alignment;
  D3D12_HEAP_FLAGS      Flags;
} D3D12_HEAP_DESC;

// x12DeviceGetResourceAllocationInfo
// x12DeviceCreatePlacedResource
// x12DeviceCreateCommittedResource

typedef enum D3D12_RESOURCE_DIMENSION {
  D3D12_RESOURCE_DIMENSION_UNKNOWN   = 0,
  D3D12_RESOURCE_DIMENSION_BUFFER    = 1,
  D3D12_RESOURCE_DIMENSION_TEXTURE1D = 2,
  D3D12_RESOURCE_DIMENSION_TEXTURE2D = 3,
  D3D12_RESOURCE_DIMENSION_TEXTURE3D = 4,
} D3D12_RESOURCE_DIMENSION;

typedef enum DXGI_FORMAT {
  DXGI_FORMAT_UNKNOWN                    = 0,
  DXGI_FORMAT_R32G32B32A32_TYPELESS      = 1,
  DXGI_FORMAT_R32G32B32A32_FLOAT         = 2,
  DXGI_FORMAT_R32G32B32A32_UINT          = 3,
  DXGI_FORMAT_R32G32B32A32_SINT          = 4,
  DXGI_FORMAT_R32G32B32_TYPELESS         = 5,
  DXGI_FORMAT_R32G32B32_FLOAT            = 6,
  DXGI_FORMAT_R32G32B32_UINT             = 7,
  DXGI_FORMAT_R32G32B32_SINT             = 8,
  DXGI_FORMAT_R16G16B16A16_TYPELESS      = 9,
  DXGI_FORMAT_R16G16B16A16_FLOAT         = 10,
  DXGI_FORMAT_R16G16B16A16_UNORM         = 11,
  DXGI_FORMAT_R16G16B16A16_UINT          = 12,
  DXGI_FORMAT_R16G16B16A16_SNORM         = 13,
  DXGI_FORMAT_R16G16B16A16_SINT          = 14,
  DXGI_FORMAT_R32G32_TYPELESS            = 15,
  DXGI_FORMAT_R32G32_FLOAT               = 16,
  DXGI_FORMAT_R32G32_UINT                = 17,
  DXGI_FORMAT_R32G32_SINT                = 18,
  DXGI_FORMAT_R32G8X24_TYPELESS          = 19,
  DXGI_FORMAT_D32_FLOAT_S8X24_UINT       = 20,
  DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS   = 21,
  DXGI_FORMAT_X32_TYPELESS_G8X24_UINT    = 22,
  DXGI_FORMAT_R10G10B10A2_TYPELESS       = 23,
  DXGI_FORMAT_R10G10B10A2_UNORM          = 24,
  DXGI_FORMAT_R10G10B10A2_UINT           = 25,
  DXGI_FORMAT_R11G11B10_FLOAT            = 26,
  DXGI_FORMAT_R8G8B8A8_TYPELESS          = 27,
  DXGI_FORMAT_R8G8B8A8_UNORM             = 28,
  DXGI_FORMAT_R8G8B8A8_UNORM_SRGB        = 29,
  DXGI_FORMAT_R8G8B8A8_UINT              = 30,
  DXGI_FORMAT_R8G8B8A8_SNORM             = 31,
  DXGI_FORMAT_R8G8B8A8_SINT              = 32,
  DXGI_FORMAT_R16G16_TYPELESS            = 33,
  DXGI_FORMAT_R16G16_FLOAT               = 34,
  DXGI_FORMAT_R16G16_UNORM               = 35,
  DXGI_FORMAT_R16G16_UINT                = 36,
  DXGI_FORMAT_R16G16_SNORM               = 37,
  DXGI_FORMAT_R16G16_SINT                = 38,
  DXGI_FORMAT_R32_TYPELESS               = 39,
  DXGI_FORMAT_D32_FLOAT                  = 40,
  DXGI_FORMAT_R32_FLOAT                  = 41,
  DXGI_FORMAT_R32_UINT                   = 42,
  DXGI_FORMAT_R32_SINT                   = 43,
  DXGI_FORMAT_R24G8_TYPELESS             = 44,
  DXGI_FORMAT_D24_UNORM_S8_UINT          = 45,
  DXGI_FORMAT_R24_UNORM_X8_TYPELESS      = 46,
  DXGI_FORMAT_X24_TYPELESS_G8_UINT       = 47,
  DXGI_FORMAT_R8G8_TYPELESS              = 48,
  DXGI_FORMAT_R8G8_UNORM                 = 49,
  DXGI_FORMAT_R8G8_UINT                  = 50,
  DXGI_FORMAT_R8G8_SNORM                 = 51,
  DXGI_FORMAT_R8G8_SINT                  = 52,
  DXGI_FORMAT_R16_TYPELESS               = 53,
  DXGI_FORMAT_R16_FLOAT                  = 54,
  DXGI_FORMAT_D16_UNORM                  = 55,
  DXGI_FORMAT_R16_UNORM                  = 56,
  DXGI_FORMAT_R16_UINT                   = 57,
  DXGI_FORMAT_R16_SNORM                  = 58,
  DXGI_FORMAT_R16_SINT                   = 59,
  DXGI_FORMAT_R8_TYPELESS                = 60,
  DXGI_FORMAT_R8_UNORM                   = 61,
  DXGI_FORMAT_R8_UINT                    = 62,
  DXGI_FORMAT_R8_SNORM                   = 63,
  DXGI_FORMAT_R8_SINT                    = 64,
  DXGI_FORMAT_A8_UNORM                   = 65,
  DXGI_FORMAT_R1_UNORM                   = 66,
  DXGI_FORMAT_R9G9B9E5_SHAREDEXP         = 67,
  DXGI_FORMAT_R8G8_B8G8_UNORM            = 68,
  DXGI_FORMAT_G8R8_G8B8_UNORM            = 69,
  DXGI_FORMAT_BC1_TYPELESS               = 70,
  DXGI_FORMAT_BC1_UNORM                  = 71,
  DXGI_FORMAT_BC1_UNORM_SRGB             = 72,
  DXGI_FORMAT_BC2_TYPELESS               = 73,
  DXGI_FORMAT_BC2_UNORM                  = 74,
  DXGI_FORMAT_BC2_UNORM_SRGB             = 75,
  DXGI_FORMAT_BC3_TYPELESS               = 76,
  DXGI_FORMAT_BC3_UNORM                  = 77,
  DXGI_FORMAT_BC3_UNORM_SRGB             = 78,
  DXGI_FORMAT_BC4_TYPELESS               = 79,
  DXGI_FORMAT_BC4_UNORM                  = 80,
  DXGI_FORMAT_BC4_SNORM                  = 81,
  DXGI_FORMAT_BC5_TYPELESS               = 82,
  DXGI_FORMAT_BC5_UNORM                  = 83,
  DXGI_FORMAT_BC5_SNORM                  = 84,
  DXGI_FORMAT_B5G6R5_UNORM               = 85,
  DXGI_FORMAT_B5G5R5A1_UNORM             = 86,
  DXGI_FORMAT_B8G8R8A8_UNORM             = 87,
  DXGI_FORMAT_B8G8R8X8_UNORM             = 88,
  DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM = 89,
  DXGI_FORMAT_B8G8R8A8_TYPELESS          = 90,
  DXGI_FORMAT_B8G8R8A8_UNORM_SRGB        = 91,
  DXGI_FORMAT_B8G8R8X8_TYPELESS          = 92,
  DXGI_FORMAT_B8G8R8X8_UNORM_SRGB        = 93,
  DXGI_FORMAT_BC6H_TYPELESS              = 94,
  DXGI_FORMAT_BC6H_UF16                  = 95,
  DXGI_FORMAT_BC6H_SF16                  = 96,
  DXGI_FORMAT_BC7_TYPELESS               = 97,
  DXGI_FORMAT_BC7_UNORM                  = 98,
  DXGI_FORMAT_BC7_UNORM_SRGB             = 99,
  DXGI_FORMAT_AYUV                       = 100,
  DXGI_FORMAT_Y410                       = 101,
  DXGI_FORMAT_Y416                       = 102,
  DXGI_FORMAT_NV12                       = 103,
  DXGI_FORMAT_P010                       = 104,
  DXGI_FORMAT_P016                       = 105,
  DXGI_FORMAT_420_OPAQUE                 = 106,
  DXGI_FORMAT_YUY2                       = 107,
  DXGI_FORMAT_Y210                       = 108,
  DXGI_FORMAT_Y216                       = 109,
  DXGI_FORMAT_NV11                       = 110,
  DXGI_FORMAT_AI44                       = 111,
  DXGI_FORMAT_IA44                       = 112,
  DXGI_FORMAT_P8                         = 113,
  DXGI_FORMAT_A8P8                       = 114,
  DXGI_FORMAT_B4G4R4A4_UNORM             = 115,
  DXGI_FORMAT_P208                       = 130,
  DXGI_FORMAT_V208                       = 131,
  DXGI_FORMAT_V408                       = 132,
} DXGI_FORMAT;

typedef enum D3D12_TEXTURE_LAYOUT {
  D3D12_TEXTURE_LAYOUT_UNKNOWN                = 0,
  D3D12_TEXTURE_LAYOUT_ROW_MAJOR              = 1,
  D3D12_TEXTURE_LAYOUT_64KB_UNDEFINED_SWIZZLE = 2,
  D3D12_TEXTURE_LAYOUT_64KB_STANDARD_SWIZZLE  = 3,
} D3D12_TEXTURE_LAYOUT;

typedef unsigned D3D12_RESOURCE_FLAGS;
typedef enum D3D12_RESOURCE_FLAG {
  D3D12_RESOURCE_FLAG_NONE                      = 0,
  D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET       = 0x1,
  D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL       = 0x2,
  D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS    = 0x4,
  D3D12_RESOURCE_FLAG_DENY_SHADER_RESOURCE      = 0x8,
  D3D12_RESOURCE_FLAG_ALLOW_CROSS_ADAPTER       = 0x10,
  D3D12_RESOURCE_FLAG_ALLOW_SIMULTANEOUS_ACCESS = 0x20,
} D3D12_RESOURCE_FLAG;

typedef struct DXGI_SAMPLE_DESC {
  unsigned Count;
  unsigned Quality;
} DXGI_SAMPLE_DESC;

typedef struct D3D12_RESOURCE_DESC {
  D3D12_RESOURCE_DIMENSION Dimension;
  uint64_t                 Alignment;
  uint64_t                 Width;
  unsigned                 Height;
  unsigned short           DepthOrArraySize;
  unsigned short           MipLevels;
  DXGI_FORMAT              Format;
  DXGI_SAMPLE_DESC         SampleDesc;
  D3D12_TEXTURE_LAYOUT     Layout;
  D3D12_RESOURCE_FLAGS     Flags;
} D3D12_RESOURCE_DESC;

typedef struct D3D12_RESOURCE_ALLOCATION_INFO {
  uint64_t SizeInBytes;
  uint64_t Alignment;
} D3D12_RESOURCE_ALLOCATION_INFO;

typedef unsigned D3D12_RESOURCE_STATES;
typedef enum D3D12_RESOURCE_STATE {
  D3D12_RESOURCE_STATE_COMMON                     = 0,
  D3D12_RESOURCE_STATE_PRESENT                    = 0,
  D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER = 0x1,
  D3D12_RESOURCE_STATE_INDEX_BUFFER               = 0x2,
  D3D12_RESOURCE_STATE_RENDER_TARGET              = 0x4,
  D3D12_RESOURCE_STATE_UNORDERED_ACCESS           = 0x8,
  D3D12_RESOURCE_STATE_DEPTH_WRITE                = 0x10,
  D3D12_RESOURCE_STATE_DEPTH_READ                 = 0x20,
  D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE  = 0x40,
  D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE      = 0x80,
  D3D12_RESOURCE_STATE_STREAM_OUT                 = 0x100,
  D3D12_RESOURCE_STATE_INDIRECT_ARGUMENT          = 0x200,
  D3D12_RESOURCE_STATE_COPY_DEST                  = 0x400,
  D3D12_RESOURCE_STATE_COPY_SOURCE                = 0x800,
  D3D12_RESOURCE_STATE_RESOLVE_DEST               = 0x1000,
  D3D12_RESOURCE_STATE_RESOLVE_SOURCE             = 0x2000,
  D3D12_RESOURCE_STATE_GENERIC_READ               = (((((D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER | D3D12_RESOURCE_STATE_INDEX_BUFFER) | D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE) | D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE) | D3D12_RESOURCE_STATE_INDIRECT_ARGUMENT) | D3D12_RESOURCE_STATE_COPY_SOURCE),
  D3D12_RESOURCE_STATE_PREDICATION                = 0x200,
} D3D12_RESOURCE_STATE;

typedef struct D3D12_DEPTH_STENCIL_VALUE {
  float         Depth;
  unsigned char Stencil;
} D3D12_DEPTH_STENCIL_VALUE;

typedef struct D3D12_CLEAR_VALUE {
  DXGI_FORMAT                 Format;
  union {
    float                     Color[4];
    D3D12_DEPTH_STENCIL_VALUE DepthStencil;
  };
} D3D12_CLEAR_VALUE;

// x12ResourceMap
// x12ResourceUnmap

typedef struct D3D12_RANGE {
  size_t Begin;
  size_t End;
} D3D12_RANGE;

// x12DeviceCreateDescriptorHeap

typedef enum D3D12_DESCRIPTOR_HEAP_TYPE {
  D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV = 0,
  D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER     = 1,
  D3D12_DESCRIPTOR_HEAP_TYPE_RTV         = 2,
  D3D12_DESCRIPTOR_HEAP_TYPE_DSV         = 3,
  D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES   = 4,
} D3D12_DESCRIPTOR_HEAP_TYPE;

typedef unsigned D3D12_DESCRIPTOR_HEAP_FLAGS;
typedef enum D3D12_DESCRIPTOR_HEAP_FLAG {
  D3D12_DESCRIPTOR_HEAP_FLAG_NONE           = 0,
  D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE = 0x1,
} D3D12_DESCRIPTOR_HEAP_FLAG;

typedef struct D3D12_DESCRIPTOR_HEAP_DESC {
  D3D12_DESCRIPTOR_HEAP_TYPE  Type;
  unsigned                    NumDescriptors;
  D3D12_DESCRIPTOR_HEAP_FLAGS Flags;
  unsigned                    NodeMask;
} D3D12_DESCRIPTOR_HEAP_DESC;

// x12DescriptorHeapGetCPUDescriptorHandleForHeapStart
// x12DeviceCopyDescriptors

typedef struct D3D12_CPU_DESCRIPTOR_HANDLE {
  size_t ptr;
} D3D12_CPU_DESCRIPTOR_HANDLE;

// x12DescriptorHeapGetGPUDescriptorHandleForHeapStart

typedef struct D3D12_GPU_DESCRIPTOR_HANDLE {
  uint64_t ptr;
} D3D12_GPU_DESCRIPTOR_HANDLE;

// x12DeviceSetResidencyPriority

// Applications may use the whole value range of UINT for a priority.
// These names are merely semantic suggestions.
#define D3D12_RESIDENCY_PRIORITY_MINIMUM (0x28000000)
#define D3D12_RESIDENCY_PRIORITY_LOW     (0x50000000)
#define D3D12_RESIDENCY_PRIORITY_NORMAL  (0x78000000)
#define D3D12_RESIDENCY_PRIORITY_HIGH    (0xa0000000)
#define D3D12_RESIDENCY_PRIORITY_MAXIMUM (0xc8000000)

// x12DeviceEnqueueMakeResident

typedef unsigned D3D12_RESIDENCY_FLAGS;
typedef enum D3D12_RESIDENCY_FLAG {
  D3D12_RESIDENCY_FLAG_NONE            = 0,
  D3D12_RESIDENCY_FLAG_DENY_OVERBUDGET = 0x1,
} D3D12_RESIDENCY_FLAG;

// x12CreateFactory2

typedef unsigned DXGI_CREATE_FACTORY_FLAGS;
typedef enum DXGI_CREATE_FACTORY_FLAG {
  DXGI_CREATE_FACTORY_FLAG_NONE  = 0,
  DXGI_CREATE_FACTORY_FLAG_DEBUG = 0x1,
} DXGI_CREATE_FACTORY_FLAG;

// x12CreateDevice

typedef enum D3D_FEATURE_LEVEL {
  D3D_FEATURE_LEVEL_1_0_CORE = 0x1000,
  D3D_FEATURE_LEVEL_9_1      = 0x9100,
  D3D_FEATURE_LEVEL_9_2      = 0x9200,
  D3D_FEATURE_LEVEL_9_3      = 0x9300,
  D3D_FEATURE_LEVEL_10_0     = 0xa000,
  D3D_FEATURE_LEVEL_10_1     = 0xa100,
  D3D_FEATURE_LEVEL_11_0     = 0xb000,
  D3D_FEATURE_LEVEL_11_1     = 0xb100,
  D3D_FEATURE_LEVEL_12_0     = 0xc000,
  D3D_FEATURE_LEVEL_12_1     = 0xc100,
} D3D_FEATURE_LEVEL;

// x12DeviceCreateUnorderedAccessView

typedef enum D3D12_UAV_DIMENSION {
  D3D12_UAV_DIMENSION_UNKNOWN        = 0,
  D3D12_UAV_DIMENSION_BUFFER         = 1,
  D3D12_UAV_DIMENSION_TEXTURE1D      = 2,
  D3D12_UAV_DIMENSION_TEXTURE1DARRAY = 3,
  D3D12_UAV_DIMENSION_TEXTURE2D      = 4,
  D3D12_UAV_DIMENSION_TEXTURE2DARRAY = 5,
  D3D12_UAV_DIMENSION_TEXTURE3D      = 8,
} D3D12_UAV_DIMENSION;

typedef unsigned D3D12_BUFFER_UAV_FLAGS;
typedef enum D3D12_BUFFER_UAV_FLAG {
  D3D12_BUFFER_UAV_FLAG_NONE = 0,
  D3D12_BUFFER_UAV_FLAG_RAW  = 0x1,
} D3D12_BUFFER_UAV_FLAG;

typedef struct D3D12_BUFFER_UAV {
  uint64_t               FirstElement;
  unsigned               NumElements;
  unsigned               StructureByteStride;
  uint64_t               CounterOffsetInBytes;
  D3D12_BUFFER_UAV_FLAGS Flags;
} D3D12_BUFFER_UAV;

typedef struct D3D12_TEX1D_UAV {
  unsigned MipSlice;
} D3D12_TEX1D_UAV;

typedef struct D3D12_TEX1D_ARRAY_UAV {
  unsigned MipSlice;
  unsigned FirstArraySlice;
  unsigned ArraySize;
} D3D12_TEX1D_ARRAY_UAV;

typedef struct D3D12_TEX2D_UAV {
  unsigned MipSlice;
  unsigned PlaneSlice;
} D3D12_TEX2D_UAV;

typedef struct D3D12_TEX2D_ARRAY_UAV {
  unsigned MipSlice;
  unsigned FirstArraySlice;
  unsigned ArraySize;
  unsigned PlaneSlice;
} D3D12_TEX2D_ARRAY_UAV;

typedef struct D3D12_TEX3D_UAV {
  unsigned MipSlice;
  unsigned FirstWSlice;
  unsigned WSize;
} D3D12_TEX3D_UAV;

typedef struct D3D12_UNORDERED_ACCESS_VIEW_DESC {
  DXGI_FORMAT             Format;
  D3D12_UAV_DIMENSION     ViewDimension;
  union {
    D3D12_BUFFER_UAV      Buffer;
    D3D12_TEX1D_UAV       Texture1D;
    D3D12_TEX1D_ARRAY_UAV Texture1DArray;
    D3D12_TEX2D_UAV       Texture2D;
    D3D12_TEX2D_ARRAY_UAV Texture2DArray;
    D3D12_TEX3D_UAV       Texture3D;
  };
} D3D12_UNORDERED_ACCESS_VIEW_DESC;

// x12DeviceCreateShaderResourceView

typedef enum D3D12_SRV_DIMENSION {
  D3D12_SRV_DIMENSION_UNKNOWN          = 0,
  D3D12_SRV_DIMENSION_BUFFER           = 1,
  D3D12_SRV_DIMENSION_TEXTURE1D        = 2,
  D3D12_SRV_DIMENSION_TEXTURE1DARRAY   = 3,
  D3D12_SRV_DIMENSION_TEXTURE2D        = 4,
  D3D12_SRV_DIMENSION_TEXTURE2DARRAY   = 5,
  D3D12_SRV_DIMENSION_TEXTURE2DMS      = 6,
  D3D12_SRV_DIMENSION_TEXTURE2DMSARRAY = 7,
  D3D12_SRV_DIMENSION_TEXTURE3D        = 8,
  D3D12_SRV_DIMENSION_TEXTURECUBE      = 9,
  D3D12_SRV_DIMENSION_TEXTURECUBEARRAY = 10,
} D3D12_SRV_DIMENSION;

typedef enum D3D12_SHADER_COMPONENT_MAPPING {
  D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_0 = 0,
  D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_1 = 1,
  D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_2 = 2,
  D3D12_SHADER_COMPONENT_MAPPING_FROM_MEMORY_COMPONENT_3 = 3,
  D3D12_SHADER_COMPONENT_MAPPING_FORCE_VALUE_0           = 4,
  D3D12_SHADER_COMPONENT_MAPPING_FORCE_VALUE_1           = 5,
} D3D12_SHADER_COMPONENT_MAPPING;

#define D3D12_SHADER_COMPONENT_MAPPING_MASK                                     0x7
#define D3D12_SHADER_COMPONENT_MAPPING_SHIFT                                    3
#define D3D12_SHADER_COMPONENT_MAPPING_ALWAYS_SET_BIT_AVOIDING_ZEROMEM_MISTAKES (1 << (D3D12_SHADER_COMPONENT_MAPPING_SHIFT * 4))
#define D3D12_ENCODE_SHADER_4_COMPONENT_MAPPING(Src0, Src1, Src2, Src3)         ((((Src0)&D3D12_SHADER_COMPONENT_MAPPING_MASK) | (((Src1)&D3D12_SHADER_COMPONENT_MAPPING_MASK) << D3D12_SHADER_COMPONENT_MAPPING_SHIFT) | (((Src2)&D3D12_SHADER_COMPONENT_MAPPING_MASK) << (D3D12_SHADER_COMPONENT_MAPPING_SHIFT * 2)) | (((Src3)&D3D12_SHADER_COMPONENT_MAPPING_MASK) << (D3D12_SHADER_COMPONENT_MAPPING_SHIFT * 3)) | D3D12_SHADER_COMPONENT_MAPPING_ALWAYS_SET_BIT_AVOIDING_ZEROMEM_MISTAKES))
#define D3D12_DECODE_SHADER_4_COMPONENT_MAPPING(ComponentToExtract, Mapping)    ((D3D12_SHADER_COMPONENT_MAPPING)(Mapping >> (D3D12_SHADER_COMPONENT_MAPPING_SHIFT * ComponentToExtract) & D3D12_SHADER_COMPONENT_MAPPING_MASK))
#define D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING                                D3D12_ENCODE_SHADER_4_COMPONENT_MAPPING(0, 1, 2, 3)

typedef unsigned D3D12_BUFFER_SRV_FLAGS;
typedef enum D3D12_BUFFER_SRV_FLAG {
  D3D12_BUFFER_SRV_FLAG_NONE = 0,
  D3D12_BUFFER_SRV_FLAG_RAW  = 0x1,
} D3D12_BUFFER_SRV_FLAG;

typedef struct D3D12_BUFFER_SRV {
  uint64_t               FirstElement;
  unsigned               NumElements;
  unsigned               StructureByteStride;
  D3D12_BUFFER_SRV_FLAGS Flags;
} D3D12_BUFFER_SRV;

typedef struct D3D12_TEX1D_SRV {
  unsigned MostDetailedMip;
  unsigned MipLevels;
  float    ResourceMinLODClamp;
} D3D12_TEX1D_SRV;

typedef struct D3D12_TEX1D_ARRAY_SRV {
  unsigned MostDetailedMip;
  unsigned MipLevels;
  unsigned FirstArraySlice;
  unsigned ArraySize;
  float    ResourceMinLODClamp;
} D3D12_TEX1D_ARRAY_SRV;

typedef struct D3D12_TEX2D_SRV {
  unsigned MostDetailedMip;
  unsigned MipLevels;
  unsigned PlaneSlice;
  float    ResourceMinLODClamp;
} D3D12_TEX2D_SRV;

typedef struct D3D12_TEX2D_ARRAY_SRV {
  unsigned MostDetailedMip;
  unsigned MipLevels;
  unsigned FirstArraySlice;
  unsigned ArraySize;
  unsigned PlaneSlice;
  float    ResourceMinLODClamp;
} D3D12_TEX2D_ARRAY_SRV;

typedef struct D3D12_TEX2DMS_SRV {
  unsigned UnusedField_NothingToDefine;
} D3D12_TEX2DMS_SRV;

typedef struct D3D12_TEX2DMS_ARRAY_SRV {
  unsigned FirstArraySlice;
  unsigned ArraySize;
} D3D12_TEX2DMS_ARRAY_SRV;

typedef struct D3D12_TEX3D_SRV {
  unsigned MostDetailedMip;
  unsigned MipLevels;
  float    ResourceMinLODClamp;
} D3D12_TEX3D_SRV;

typedef struct D3D12_TEXCUBE_SRV {
  unsigned MostDetailedMip;
  unsigned MipLevels;
  float    ResourceMinLODClamp;
} D3D12_TEXCUBE_SRV;

typedef struct D3D12_TEXCUBE_ARRAY_SRV {
  unsigned MostDetailedMip;
  unsigned MipLevels;
  unsigned First2DArrayFace;
  unsigned NumCubes;
  float    ResourceMinLODClamp;
} D3D12_TEXCUBE_ARRAY_SRV;

typedef struct D3D12_SHADER_RESOURCE_VIEW_DESC {
  DXGI_FORMAT               Format;
  D3D12_SRV_DIMENSION       ViewDimension;
  unsigned                  Shader4ComponentMapping; // D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING
  union {
    D3D12_BUFFER_SRV        Buffer;
    D3D12_TEX1D_SRV         Texture1D;
    D3D12_TEX1D_ARRAY_SRV   Texture1DArray;
    D3D12_TEX2D_SRV         Texture2D;
    D3D12_TEX2D_ARRAY_SRV   Texture2DArray;
    D3D12_TEX2DMS_SRV       Texture2DMS;
    D3D12_TEX2DMS_ARRAY_SRV Texture2DMSArray;
    D3D12_TEX3D_SRV         Texture3D;
    D3D12_TEXCUBE_SRV       TextureCube;
    D3D12_TEXCUBE_ARRAY_SRV TextureCubeArray;
  };
} D3D12_SHADER_RESOURCE_VIEW_DESC;

// x12DeviceCreateConstantBufferView

typedef struct D3D12_CONSTANT_BUFFER_VIEW_DESC {
  D3D12_GPU_VIRTUAL_ADDRESS BufferLocation;
  unsigned                  SizeInBytes;
} D3D12_CONSTANT_BUFFER_VIEW_DESC;

// x12DeviceCreateSampler

typedef enum D3D12_FILTER {
  D3D12_FILTER_MIN_MAG_MIP_POINT                          = 0,
  D3D12_FILTER_MIN_MAG_POINT_MIP_LINEAR                   = 0x1,
  D3D12_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT             = 0x4,
  D3D12_FILTER_MIN_POINT_MAG_MIP_LINEAR                   = 0x5,
  D3D12_FILTER_MIN_LINEAR_MAG_MIP_POINT                   = 0x10,
  D3D12_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR            = 0x11,
  D3D12_FILTER_MIN_MAG_LINEAR_MIP_POINT                   = 0x14,
  D3D12_FILTER_MIN_MAG_MIP_LINEAR                         = 0x15,
  D3D12_FILTER_ANISOTROPIC                                = 0x55,
  D3D12_FILTER_COMPARISON_MIN_MAG_MIP_POINT               = 0x80,
  D3D12_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR        = 0x81,
  D3D12_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT  = 0x84,
  D3D12_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR        = 0x85,
  D3D12_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT        = 0x90,
  D3D12_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x91,
  D3D12_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT        = 0x94,
  D3D12_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR              = 0x95,
  D3D12_FILTER_COMPARISON_ANISOTROPIC                     = 0xd5,
  D3D12_FILTER_MINIMUM_MIN_MAG_MIP_POINT                  = 0x100,
  D3D12_FILTER_MINIMUM_MIN_MAG_POINT_MIP_LINEAR           = 0x101,
  D3D12_FILTER_MINIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT     = 0x104,
  D3D12_FILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR           = 0x105,
  D3D12_FILTER_MINIMUM_MIN_LINEAR_MAG_MIP_POINT           = 0x110,
  D3D12_FILTER_MINIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR    = 0x111,
  D3D12_FILTER_MINIMUM_MIN_MAG_LINEAR_MIP_POINT           = 0x114,
  D3D12_FILTER_MINIMUM_MIN_MAG_MIP_LINEAR                 = 0x115,
  D3D12_FILTER_MINIMUM_ANISOTROPIC                        = 0x155,
  D3D12_FILTER_MAXIMUM_MIN_MAG_MIP_POINT                  = 0x180,
  D3D12_FILTER_MAXIMUM_MIN_MAG_POINT_MIP_LINEAR           = 0x181,
  D3D12_FILTER_MAXIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT     = 0x184,
  D3D12_FILTER_MAXIMUM_MIN_POINT_MAG_MIP_LINEAR           = 0x185,
  D3D12_FILTER_MAXIMUM_MIN_LINEAR_MAG_MIP_POINT           = 0x190,
  D3D12_FILTER_MAXIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR    = 0x191,
  D3D12_FILTER_MAXIMUM_MIN_MAG_LINEAR_MIP_POINT           = 0x194,
  D3D12_FILTER_MAXIMUM_MIN_MAG_MIP_LINEAR                 = 0x195,
  D3D12_FILTER_MAXIMUM_ANISOTROPIC                        = 0x1d5,
} D3D12_FILTER;

typedef enum D3D12_FILTER_TYPE {
  D3D12_FILTER_TYPE_POINT  = 0,
  D3D12_FILTER_TYPE_LINEAR = 1,
} D3D12_FILTER_TYPE;

typedef enum D3D12_FILTER_REDUCTION_TYPE {
  D3D12_FILTER_REDUCTION_TYPE_STANDARD   = 0,
  D3D12_FILTER_REDUCTION_TYPE_COMPARISON = 1,
  D3D12_FILTER_REDUCTION_TYPE_MINIMUM    = 2,
  D3D12_FILTER_REDUCTION_TYPE_MAXIMUM    = 3,
} D3D12_FILTER_REDUCTION_TYPE;

#define D3D12_FILTER_TYPE_MASK                              (0x3)
#define D3D12_MIN_FILTER_SHIFT                              (4)
#define D3D12_MAG_FILTER_SHIFT                              (2)
#define D3D12_MIP_FILTER_SHIFT                              (0)
#define D3D12_FILTER_REDUCTION_TYPE_MASK                    (0x3)
#define D3D12_FILTER_REDUCTION_TYPE_SHIFT                   (7)
#define D3D12_ANISOTROPIC_FILTERING_BIT                     (0x40)
#define D3D12_ENCODE_BASIC_FILTER(min, mag, mip, reduction) ((D3D12_FILTER)((((min)&D3D12_FILTER_TYPE_MASK) << D3D12_MIN_FILTER_SHIFT) | (((mag)&D3D12_FILTER_TYPE_MASK) << D3D12_MAG_FILTER_SHIFT) | (((mip)&D3D12_FILTER_TYPE_MASK) << D3D12_MIP_FILTER_SHIFT) | (((reduction)&D3D12_FILTER_REDUCTION_TYPE_MASK) << D3D12_FILTER_REDUCTION_TYPE_SHIFT)))
#define D3D12_ENCODE_ANISOTROPIC_FILTER(reduction)          ((D3D12_FILTER)(D3D12_ANISOTROPIC_FILTERING_BIT | D3D12_ENCODE_BASIC_FILTER(D3D12_FILTER_TYPE_LINEAR, D3D12_FILTER_TYPE_LINEAR, D3D12_FILTER_TYPE_LINEAR, reduction)))
#define D3D12_DECODE_MIN_FILTER(D3D12Filter)                ((D3D12_FILTER_TYPE)(((D3D12Filter) >> D3D12_MIN_FILTER_SHIFT) & D3D12_FILTER_TYPE_MASK))
#define D3D12_DECODE_MAG_FILTER(D3D12Filter)                ((D3D12_FILTER_TYPE)(((D3D12Filter) >> D3D12_MAG_FILTER_SHIFT) & D3D12_FILTER_TYPE_MASK))
#define D3D12_DECODE_MIP_FILTER(D3D12Filter)                ((D3D12_FILTER_TYPE)(((D3D12Filter) >> D3D12_MIP_FILTER_SHIFT) & D3D12_FILTER_TYPE_MASK))
#define D3D12_DECODE_FILTER_REDUCTION(D3D12Filter)          ((D3D12_FILTER_REDUCTION_TYPE)(((D3D12Filter) >> D3D12_FILTER_REDUCTION_TYPE_SHIFT) & D3D12_FILTER_REDUCTION_TYPE_MASK))
#define D3D12_DECODE_IS_COMPARISON_FILTER(D3D12Filter)      (D3D12_DECODE_FILTER_REDUCTION(D3D12Filter) == D3D12_FILTER_REDUCTION_TYPE_COMPARISON)
#define D3D12_DECODE_IS_ANISOTROPIC_FILTER(D3D12Filter)     (((D3D12Filter)&D3D12_ANISOTROPIC_FILTERING_BIT) && (D3D12_FILTER_TYPE_LINEAR == D3D12_DECODE_MIN_FILTER(D3D12Filter)) && (D3D12_FILTER_TYPE_LINEAR == D3D12_DECODE_MAG_FILTER(D3D12Filter)) && (D3D12_FILTER_TYPE_LINEAR == D3D12_DECODE_MIP_FILTER(D3D12Filter)))

typedef enum D3D12_TEXTURE_ADDRESS_MODE {
  D3D12_TEXTURE_ADDRESS_MODE_WRAP        = 1,
  D3D12_TEXTURE_ADDRESS_MODE_MIRROR      = 2,
  D3D12_TEXTURE_ADDRESS_MODE_CLAMP       = 3,
  D3D12_TEXTURE_ADDRESS_MODE_BORDER      = 4,
  D3D12_TEXTURE_ADDRESS_MODE_MIRROR_ONCE = 5,
} D3D12_TEXTURE_ADDRESS_MODE;

typedef enum D3D12_COMPARISON_FUNC {
  D3D12_COMPARISON_FUNC_NEVER         = 1,
  D3D12_COMPARISON_FUNC_LESS          = 2,
  D3D12_COMPARISON_FUNC_EQUAL         = 3,
  D3D12_COMPARISON_FUNC_LESS_EQUAL    = 4,
  D3D12_COMPARISON_FUNC_GREATER       = 5,
  D3D12_COMPARISON_FUNC_NOT_EQUAL     = 6,
  D3D12_COMPARISON_FUNC_GREATER_EQUAL = 7,
  D3D12_COMPARISON_FUNC_ALWAYS        = 8,
} D3D12_COMPARISON_FUNC;

typedef struct D3D12_SAMPLER_DESC {
  D3D12_FILTER               Filter;         // D3D12_ENCODE_BASIC_FILTER(D3D12_FILTER_TYPE min, D3D12_FILTER_TYPE mag, D3D12_FILTER_TYPE mip, D3D12_FILTER_REDUCTION_TYPE reduction), D3D12_ENCODE_ANISOTROPIC_FILTER(D3D12_FILTER_REDUCTION_TYPE reduction)
  D3D12_TEXTURE_ADDRESS_MODE AddressU;
  D3D12_TEXTURE_ADDRESS_MODE AddressV;
  D3D12_TEXTURE_ADDRESS_MODE AddressW;
  float                      MipLODBias;
  unsigned                   MaxAnisotropy;
  D3D12_COMPARISON_FUNC      ComparisonFunc;
  float                      BorderColor[4];
  float                      MinLOD;
  float                      MaxLOD;
} D3D12_SAMPLER_DESC;

// x12DeviceCreateRenderTargetView

typedef enum D3D12_RTV_DIMENSION {
  D3D12_RTV_DIMENSION_UNKNOWN          = 0,
  D3D12_RTV_DIMENSION_BUFFER           = 1,
  D3D12_RTV_DIMENSION_TEXTURE1D        = 2,
  D3D12_RTV_DIMENSION_TEXTURE1DARRAY   = 3,
  D3D12_RTV_DIMENSION_TEXTURE2D        = 4,
  D3D12_RTV_DIMENSION_TEXTURE2DARRAY   = 5,
  D3D12_RTV_DIMENSION_TEXTURE2DMS      = 6,
  D3D12_RTV_DIMENSION_TEXTURE2DMSARRAY = 7,
  D3D12_RTV_DIMENSION_TEXTURE3D        = 8,
} D3D12_RTV_DIMENSION;

typedef struct D3D12_BUFFER_RTV {
  uint64_t FirstElement;
  unsigned NumElements;
} D3D12_BUFFER_RTV;

typedef struct D3D12_TEX1D_RTV {
  unsigned MipSlice;
} D3D12_TEX1D_RTV;

typedef struct D3D12_TEX1D_ARRAY_RTV {
  unsigned MipSlice;
  unsigned FirstArraySlice;
  unsigned ArraySize;
} D3D12_TEX1D_ARRAY_RTV;

typedef struct D3D12_TEX2D_RTV {
  unsigned MipSlice;
  unsigned PlaneSlice;
} D3D12_TEX2D_RTV;

typedef struct D3D12_TEX2D_ARRAY_RTV {
  unsigned MipSlice;
  unsigned FirstArraySlice;
  unsigned ArraySize;
  unsigned PlaneSlice;
} D3D12_TEX2D_ARRAY_RTV;

typedef struct D3D12_TEX2DMS_RTV {
  unsigned UnusedField_NothingToDefine;
} D3D12_TEX2DMS_RTV;

typedef struct D3D12_TEX2DMS_ARRAY_RTV {
  unsigned FirstArraySlice;
  unsigned ArraySize;
} D3D12_TEX2DMS_ARRAY_RTV;

typedef struct D3D12_TEX3D_RTV {
  unsigned MipSlice;
  unsigned FirstWSlice;
  unsigned WSize;
} D3D12_TEX3D_RTV;

typedef struct D3D12_RENDER_TARGET_VIEW_DESC {
  DXGI_FORMAT               Format;
  D3D12_RTV_DIMENSION       ViewDimension;
  union {
    D3D12_BUFFER_RTV        Buffer;
    D3D12_TEX1D_RTV         Texture1D;
    D3D12_TEX1D_ARRAY_RTV   Texture1DArray;
    D3D12_TEX2D_RTV         Texture2D;
    D3D12_TEX2D_ARRAY_RTV   Texture2DArray;
    D3D12_TEX2DMS_RTV       Texture2DMS;
    D3D12_TEX2DMS_ARRAY_RTV Texture2DMSArray;
    D3D12_TEX3D_RTV         Texture3D;
  };
} D3D12_RENDER_TARGET_VIEW_DESC;

// x12DeviceCreateDepthStencilView

typedef enum D3D12_DSV_DIMENSION {
  D3D12_DSV_DIMENSION_UNKNOWN          = 0,
  D3D12_DSV_DIMENSION_TEXTURE1D        = 1,
  D3D12_DSV_DIMENSION_TEXTURE1DARRAY   = 2,
  D3D12_DSV_DIMENSION_TEXTURE2D        = 3,
  D3D12_DSV_DIMENSION_TEXTURE2DARRAY   = 4,
  D3D12_DSV_DIMENSION_TEXTURE2DMS      = 5,
  D3D12_DSV_DIMENSION_TEXTURE2DMSARRAY = 6,
} D3D12_DSV_DIMENSION;

typedef unsigned D3D12_DSV_FLAGS;
typedef enum D3D12_DSV_FLAG {
  D3D12_DSV_FLAG_NONE              = 0,
  D3D12_DSV_FLAG_READ_ONLY_DEPTH   = 0x1,
  D3D12_DSV_FLAG_READ_ONLY_STENCIL = 0x2,
} D3D12_DSV_FLAG;

typedef struct D3D12_TEX1D_DSV {
  unsigned MipSlice;
} D3D12_TEX1D_DSV;

typedef struct D3D12_TEX1D_ARRAY_DSV {
  unsigned MipSlice;
  unsigned FirstArraySlice;
  unsigned ArraySize;
} D3D12_TEX1D_ARRAY_DSV;

typedef struct D3D12_TEX2D_DSV {
  unsigned MipSlice;
} D3D12_TEX2D_DSV;

typedef struct D3D12_TEX2D_ARRAY_DSV {
  unsigned MipSlice;
  unsigned FirstArraySlice;
  unsigned ArraySize;
} D3D12_TEX2D_ARRAY_DSV;

typedef struct D3D12_TEX2DMS_DSV {
  unsigned UnusedField_NothingToDefine;
} D3D12_TEX2DMS_DSV;

typedef struct D3D12_TEX2DMS_ARRAY_DSV {
  unsigned FirstArraySlice;
  unsigned ArraySize;
} D3D12_TEX2DMS_ARRAY_DSV;

typedef struct D3D12_DEPTH_STENCIL_VIEW_DESC {
  DXGI_FORMAT               Format;
  D3D12_DSV_DIMENSION       ViewDimension;
  D3D12_DSV_FLAGS           Flags;
  union {
    D3D12_TEX1D_DSV         Texture1D;
    D3D12_TEX1D_ARRAY_DSV   Texture1DArray;
    D3D12_TEX2D_DSV         Texture2D;
    D3D12_TEX2D_ARRAY_DSV   Texture2DArray;
    D3D12_TEX2DMS_DSV       Texture2DMS;
    D3D12_TEX2DMS_ARRAY_DSV Texture2DMSArray;
  };
} D3D12_DEPTH_STENCIL_VIEW_DESC;

// x12SerializeRootSignature
// x12RootSignatureDeserializerGetRootSignatureDesc

typedef enum D3D12_ROOT_PARAMETER_TYPE {
  D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE = 0,
  D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS  = 1,
  D3D12_ROOT_PARAMETER_TYPE_CBV              = 2,
  D3D12_ROOT_PARAMETER_TYPE_SRV              = 3,
  D3D12_ROOT_PARAMETER_TYPE_UAV              = 4,
} D3D12_ROOT_PARAMETER_TYPE;

typedef enum D3D12_DESCRIPTOR_RANGE_TYPE {
  D3D12_DESCRIPTOR_RANGE_TYPE_SRV     = 0,
  D3D12_DESCRIPTOR_RANGE_TYPE_UAV     = 1,
  D3D12_DESCRIPTOR_RANGE_TYPE_CBV     = 2,
  D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER = 3,
} D3D12_DESCRIPTOR_RANGE_TYPE;

typedef enum D3D12_SHADER_VISIBILITY {
  D3D12_SHADER_VISIBILITY_ALL      = 0,
  D3D12_SHADER_VISIBILITY_VERTEX   = 1,
  D3D12_SHADER_VISIBILITY_HULL     = 2,
  D3D12_SHADER_VISIBILITY_DOMAIN   = 3,
  D3D12_SHADER_VISIBILITY_GEOMETRY = 4,
  D3D12_SHADER_VISIBILITY_PIXEL    = 5,
} D3D12_SHADER_VISIBILITY;

typedef enum D3D12_STATIC_BORDER_COLOR {
  D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK = 0,
  D3D12_STATIC_BORDER_COLOR_OPAQUE_BLACK      = 1,
  D3D12_STATIC_BORDER_COLOR_OPAQUE_WHITE      = 2,
} D3D12_STATIC_BORDER_COLOR;

typedef unsigned D3D12_ROOT_SIGNATURE_FLAGS;
typedef enum D3D12_ROOT_SIGNATURE_FLAG {
  D3D12_ROOT_SIGNATURE_FLAG_NONE                               = 0,
  D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT = 0x1,
  D3D12_ROOT_SIGNATURE_FLAG_DENY_VERTEX_SHADER_ROOT_ACCESS     = 0x2,
  D3D12_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS       = 0x4,
  D3D12_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS     = 0x8,
  D3D12_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS   = 0x10,
  D3D12_ROOT_SIGNATURE_FLAG_DENY_PIXEL_SHADER_ROOT_ACCESS      = 0x20,
  D3D12_ROOT_SIGNATURE_FLAG_ALLOW_STREAM_OUTPUT                = 0x40,
} D3D12_ROOT_SIGNATURE_FLAG;

typedef struct D3D12_DESCRIPTOR_RANGE {
  D3D12_DESCRIPTOR_RANGE_TYPE RangeType;
  unsigned                    NumDescriptors;
  unsigned                    BaseShaderRegister;
  unsigned                    RegisterSpace;
  unsigned                    OffsetInDescriptorsFromTableStart;
} D3D12_DESCRIPTOR_RANGE;

typedef struct D3D12_ROOT_DESCRIPTOR_TABLE {
  unsigned                       NumDescriptorRanges;
  const D3D12_DESCRIPTOR_RANGE * pDescriptorRanges;   // _Field_size_full_(NumDescriptorRanges)
} D3D12_ROOT_DESCRIPTOR_TABLE;

typedef struct D3D12_ROOT_CONSTANTS {
  unsigned ShaderRegister;
  unsigned RegisterSpace;
  unsigned Num32BitValues;
} D3D12_ROOT_CONSTANTS;

typedef struct D3D12_ROOT_DESCRIPTOR {
  unsigned ShaderRegister;
  unsigned RegisterSpace;
} D3D12_ROOT_DESCRIPTOR;

typedef struct D3D12_ROOT_PARAMETER {
  D3D12_ROOT_PARAMETER_TYPE     ParameterType;
  union {
    D3D12_ROOT_DESCRIPTOR_TABLE DescriptorTable;
    D3D12_ROOT_CONSTANTS        Constants;
    D3D12_ROOT_DESCRIPTOR       Descriptor;
  };
  D3D12_SHADER_VISIBILITY       ShaderVisibility;
} D3D12_ROOT_PARAMETER;

typedef struct D3D12_STATIC_SAMPLER_DESC {
  D3D12_FILTER               Filter;
  D3D12_TEXTURE_ADDRESS_MODE AddressU;
  D3D12_TEXTURE_ADDRESS_MODE AddressV;
  D3D12_TEXTURE_ADDRESS_MODE AddressW;
  float                      MipLODBias;
  unsigned                   MaxAnisotropy;
  D3D12_COMPARISON_FUNC      ComparisonFunc;
  D3D12_STATIC_BORDER_COLOR  BorderColor;
  float                      MinLOD;
  float                      MaxLOD;
  unsigned                   ShaderRegister;
  unsigned                   RegisterSpace;
  D3D12_SHADER_VISIBILITY    ShaderVisibility;
} D3D12_STATIC_SAMPLER_DESC;

typedef struct D3D12_ROOT_SIGNATURE_DESC {
  unsigned                          NumParameters;
  const D3D12_ROOT_PARAMETER *      pParameters;       // _Field_size_full_(NumParameters)
  unsigned                          NumStaticSamplers;
  const D3D12_STATIC_SAMPLER_DESC * pStaticSamplers;   // _Field_size_full_(NumStaticSamplers)
  D3D12_ROOT_SIGNATURE_FLAGS        Flags;
} D3D12_ROOT_SIGNATURE_DESC;

typedef enum D3D_ROOT_SIGNATURE_VERSION {
  D3D_ROOT_SIGNATURE_VERSION_1 = 1,
} D3D_ROOT_SIGNATURE_VERSION;

// x12DeviceCreateGraphicsPipelineState

typedef enum D3D12_BLEND {
  D3D12_BLEND_ZERO             = 1,
  D3D12_BLEND_ONE              = 2,
  D3D12_BLEND_SRC_COLOR        = 3,
  D3D12_BLEND_INV_SRC_COLOR    = 4,
  D3D12_BLEND_SRC_ALPHA        = 5,
  D3D12_BLEND_INV_SRC_ALPHA    = 6,
  D3D12_BLEND_DEST_ALPHA       = 7,
  D3D12_BLEND_INV_DEST_ALPHA   = 8,
  D3D12_BLEND_DEST_COLOR       = 9,
  D3D12_BLEND_INV_DEST_COLOR   = 10,
  D3D12_BLEND_SRC_ALPHA_SAT    = 11,
  D3D12_BLEND_BLEND_FACTOR     = 14,
  D3D12_BLEND_INV_BLEND_FACTOR = 15,
  D3D12_BLEND_SRC1_COLOR       = 16,
  D3D12_BLEND_INV_SRC1_COLOR   = 17,
  D3D12_BLEND_SRC1_ALPHA       = 18,
  D3D12_BLEND_INV_SRC1_ALPHA   = 19,
} D3D12_BLEND;

typedef enum D3D12_BLEND_OP {
  D3D12_BLEND_OP_ADD          = 1,
  D3D12_BLEND_OP_SUBTRACT     = 2,
  D3D12_BLEND_OP_REV_SUBTRACT = 3,
  D3D12_BLEND_OP_MIN          = 4,
  D3D12_BLEND_OP_MAX          = 5,
} D3D12_BLEND_OP;

typedef enum D3D12_LOGIC_OP {
  D3D12_LOGIC_OP_CLEAR         = 0,
  D3D12_LOGIC_OP_SET           = 1,
  D3D12_LOGIC_OP_COPY          = 2,
  D3D12_LOGIC_OP_COPY_INVERTED = 3,
  D3D12_LOGIC_OP_NOOP          = 4,
  D3D12_LOGIC_OP_INVERT        = 5,
  D3D12_LOGIC_OP_AND           = 6,
  D3D12_LOGIC_OP_NAND          = 7,
  D3D12_LOGIC_OP_OR            = 8,
  D3D12_LOGIC_OP_NOR           = 9,
  D3D12_LOGIC_OP_XOR           = 10,
  D3D12_LOGIC_OP_EQUIV         = 11,
  D3D12_LOGIC_OP_AND_REVERSE   = 12,
  D3D12_LOGIC_OP_AND_INVERTED  = 13,
  D3D12_LOGIC_OP_OR_REVERSE    = 14,
  D3D12_LOGIC_OP_OR_INVERTED   = 15,
} D3D12_LOGIC_OP;

typedef enum D3D12_COLOR_WRITE_ENABLE {
  D3D12_COLOR_WRITE_ENABLE_RED   = 1,
  D3D12_COLOR_WRITE_ENABLE_GREEN = 2,
  D3D12_COLOR_WRITE_ENABLE_BLUE  = 4,
  D3D12_COLOR_WRITE_ENABLE_ALPHA = 8,
  D3D12_COLOR_WRITE_ENABLE_ALL   = (((D3D12_COLOR_WRITE_ENABLE_RED | D3D12_COLOR_WRITE_ENABLE_GREEN) | D3D12_COLOR_WRITE_ENABLE_BLUE) | D3D12_COLOR_WRITE_ENABLE_ALPHA)
} D3D12_COLOR_WRITE_ENABLE;

typedef enum D3D12_FILL_MODE {
  D3D12_FILL_MODE_WIREFRAME = 2,
  D3D12_FILL_MODE_SOLID     = 3,
} D3D12_FILL_MODE;

typedef enum D3D12_CULL_MODE {
  D3D12_CULL_MODE_NONE  = 1,
  D3D12_CULL_MODE_FRONT = 2,
  D3D12_CULL_MODE_BACK  = 3,
} D3D12_CULL_MODE;

typedef enum D3D12_CONSERVATIVE_RASTERIZATION_MODE {
  D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF = 0,
  D3D12_CONSERVATIVE_RASTERIZATION_MODE_ON  = 1,
} D3D12_CONSERVATIVE_RASTERIZATION_MODE;

typedef enum D3D12_DEPTH_WRITE_MASK {
  D3D12_DEPTH_WRITE_MASK_ZERO = 0,
  D3D12_DEPTH_WRITE_MASK_ALL  = 1,
} D3D12_DEPTH_WRITE_MASK;

typedef enum D3D12_STENCIL_OP {
  D3D12_STENCIL_OP_KEEP     = 1,
  D3D12_STENCIL_OP_ZERO     = 2,
  D3D12_STENCIL_OP_REPLACE  = 3,
  D3D12_STENCIL_OP_INCR_SAT = 4,
  D3D12_STENCIL_OP_DECR_SAT = 5,
  D3D12_STENCIL_OP_INVERT   = 6,
  D3D12_STENCIL_OP_INCR     = 7,
  D3D12_STENCIL_OP_DECR     = 8,
} D3D12_STENCIL_OP;

typedef enum D3D12_INPUT_CLASSIFICATION {
  D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA   = 0,
  D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA = 1,
} D3D12_INPUT_CLASSIFICATION;

typedef enum D3D12_INDEX_BUFFER_STRIP_CUT_VALUE {
  D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_DISABLED   = 0,
  D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_0xFFFF     = 1,
  D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_0xFFFFFFFF = 2,
} D3D12_INDEX_BUFFER_STRIP_CUT_VALUE;

typedef enum D3D12_PRIMITIVE_TOPOLOGY_TYPE {
  D3D12_PRIMITIVE_TOPOLOGY_TYPE_UNDEFINED = 0,
  D3D12_PRIMITIVE_TOPOLOGY_TYPE_POINT     = 1,
  D3D12_PRIMITIVE_TOPOLOGY_TYPE_LINE      = 2,
  D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE  = 3,
  D3D12_PRIMITIVE_TOPOLOGY_TYPE_PATCH     = 4,
} D3D12_PRIMITIVE_TOPOLOGY_TYPE;

typedef unsigned D3D12_PIPELINE_STATE_FLAGS;
typedef enum D3D12_PIPELINE_STATE_FLAG {
  D3D12_PIPELINE_STATE_FLAG_NONE       = 0,
  D3D12_PIPELINE_STATE_FLAG_TOOL_DEBUG = 0x1,
} D3D12_PIPELINE_STATE_FLAG;

typedef struct D3D12_SHADER_BYTECODE {
  const void * pShaderBytecode; // _Field_size_bytes_full_(BytecodeLength)
  size_t       BytecodeLength;
} D3D12_SHADER_BYTECODE;

typedef struct D3D12_SO_DECLARATION_ENTRY {
  unsigned      Stream;
  const char *  SemanticName;
  unsigned      SemanticIndex;
  unsigned char StartComponent;
  unsigned char ComponentCount;
  unsigned char OutputSlot;
} D3D12_SO_DECLARATION_ENTRY;

typedef struct D3D12_STREAM_OUTPUT_DESC {
  const D3D12_SO_DECLARATION_ENTRY * pSODeclaration;   // _Field_size_full_(NumEntries)
  unsigned                           NumEntries;
  const unsigned *                   pBufferStrides;   // _Field_size_full_(NumStrides)
  unsigned                           NumStrides;
  unsigned                           RasterizedStream;
} D3D12_STREAM_OUTPUT_DESC;

typedef struct D3D12_RENDER_TARGET_BLEND_DESC {
  X12Bool        BlendEnable;
  X12Bool        LogicOpEnable;
  D3D12_BLEND    SrcBlend;
  D3D12_BLEND    DestBlend;
  D3D12_BLEND_OP BlendOp;
  D3D12_BLEND    SrcBlendAlpha;
  D3D12_BLEND    DestBlendAlpha;
  D3D12_BLEND_OP BlendOpAlpha;
  D3D12_LOGIC_OP LogicOp;
  unsigned char  RenderTargetWriteMask;
} D3D12_RENDER_TARGET_BLEND_DESC;

typedef struct D3D12_BLEND_DESC {
  X12Bool                        AlphaToCoverageEnable;
  X12Bool                        IndependentBlendEnable;
  D3D12_RENDER_TARGET_BLEND_DESC RenderTarget[8];
} D3D12_BLEND_DESC;

typedef struct D3D12_RASTERIZER_DESC {
  D3D12_FILL_MODE                       FillMode;
  D3D12_CULL_MODE                       CullMode;
  X12Bool                               FrontCounterClockwise;
  int                                   DepthBias;
  float                                 DepthBiasClamp;
  float                                 SlopeScaledDepthBias;
  X12Bool                               DepthClipEnable;
  X12Bool                               MultisampleEnable;
  X12Bool                               AntialiasedLineEnable;
  unsigned                              ForcedSampleCount;
  D3D12_CONSERVATIVE_RASTERIZATION_MODE ConservativeRaster;
} D3D12_RASTERIZER_DESC;

typedef struct D3D12_DEPTH_STENCILOP_DESC {
  D3D12_STENCIL_OP      StencilFailOp;
  D3D12_STENCIL_OP      StencilDepthFailOp;
  D3D12_STENCIL_OP      StencilPassOp;
  D3D12_COMPARISON_FUNC StencilFunc;
} D3D12_DEPTH_STENCILOP_DESC;

typedef struct D3D12_DEPTH_STENCIL_DESC {
  X12Bool                    DepthEnable;
  D3D12_DEPTH_WRITE_MASK     DepthWriteMask;
  D3D12_COMPARISON_FUNC      DepthFunc;
  X12Bool                    StencilEnable;
  unsigned char              StencilReadMask;
  unsigned char              StencilWriteMask;
  D3D12_DEPTH_STENCILOP_DESC FrontFace;
  D3D12_DEPTH_STENCILOP_DESC BackFace;
} D3D12_DEPTH_STENCIL_DESC;

typedef struct D3D12_INPUT_ELEMENT_DESC {
  unsigned char *            SemanticName;
  unsigned                   SemanticIndex;
  DXGI_FORMAT                Format;
  unsigned                   InputSlot;
  unsigned                   AlignedByteOffset;
  D3D12_INPUT_CLASSIFICATION InputSlotClass;
  unsigned                   InstanceDataStepRate;
} D3D12_INPUT_ELEMENT_DESC;

typedef struct D3D12_INPUT_LAYOUT_DESC {
  const D3D12_INPUT_ELEMENT_DESC * pInputElementDescs; // _Field_size_full_(NumElements)
  unsigned                         NumElements;
} D3D12_INPUT_LAYOUT_DESC;

typedef struct D3D12_CACHED_PIPELINE_STATE {
  const void * pCachedBlob;           // _Field_size_bytes_full_(CachedBlobSizeInBytes)
  size_t       CachedBlobSizeInBytes;
} D3D12_CACHED_PIPELINE_STATE;

typedef struct D3D12_GRAPHICS_PIPELINE_STATE_DESC {
  X12RootSignature *                 pRootSignature;
  D3D12_SHADER_BYTECODE              VS;
  D3D12_SHADER_BYTECODE              PS;
  D3D12_SHADER_BYTECODE              DS;
  D3D12_SHADER_BYTECODE              HS;
  D3D12_SHADER_BYTECODE              GS;
  D3D12_STREAM_OUTPUT_DESC           StreamOutput;
  D3D12_BLEND_DESC                   BlendState;
  unsigned                           SampleMask;
  D3D12_RASTERIZER_DESC              RasterizerState;
  D3D12_DEPTH_STENCIL_DESC           DepthStencilState;
  D3D12_INPUT_LAYOUT_DESC            InputLayout;
  D3D12_INDEX_BUFFER_STRIP_CUT_VALUE IBStripCutValue;
  D3D12_PRIMITIVE_TOPOLOGY_TYPE      PrimitiveTopologyType;
  unsigned                           NumRenderTargets;
  DXGI_FORMAT                        RTVFormats[8];
  DXGI_FORMAT                        DSVFormat;
  DXGI_SAMPLE_DESC                   SampleDesc;
  unsigned                           NodeMask;
  D3D12_CACHED_PIPELINE_STATE        CachedPSO;
  D3D12_PIPELINE_STATE_FLAGS         Flags;
} D3D12_GRAPHICS_PIPELINE_STATE_DESC;

// x12DeviceCreateComputePipelineState

typedef struct D3D12_COMPUTE_PIPELINE_STATE_DESC {
  X12RootSignature *          pRootSignature;
  D3D12_SHADER_BYTECODE       CS;
  unsigned                    NodeMask;
  D3D12_CACHED_PIPELINE_STATE CachedPSO;
  D3D12_PIPELINE_STATE_FLAGS  Flags;
} D3D12_COMPUTE_PIPELINE_STATE_DESC;

// x12DeviceCreateFence

typedef unsigned D3D12_FENCE_FLAGS;
typedef enum D3D12_FENCE_FLAG {
  D3D12_FENCE_FLAG_NONE                 = 0,
  D3D12_FENCE_FLAG_SHARED               = 0x1,
  D3D12_FENCE_FLAG_SHARED_CROSS_ADAPTER = 0x2,
} D3D12_FENCE_FLAG;

// x12DeviceCreateCommandQueue

typedef enum D3D12_COMMAND_LIST_TYPE {
  D3D12_COMMAND_LIST_TYPE_DIRECT  = 0,
  D3D12_COMMAND_LIST_TYPE_BUNDLE  = 1,
  D3D12_COMMAND_LIST_TYPE_COMPUTE = 2,
  D3D12_COMMAND_LIST_TYPE_COPY    = 3,
} D3D12_COMMAND_LIST_TYPE;

#define D3D12_COMMAND_QUEUE_PRIORITY_NORMAL (0)
#define D3D12_COMMAND_QUEUE_PRIORITY_HIGH   (100)

typedef unsigned D3D12_COMMAND_QUEUE_FLAGS;
typedef enum D3D12_COMMAND_QUEUE_FLAG {
  D3D12_COMMAND_QUEUE_FLAG_NONE                = 0,
  D3D12_COMMAND_QUEUE_FLAG_DISABLE_GPU_TIMEOUT = 0x1,
} D3D12_COMMAND_QUEUE_FLAG;

typedef struct D3D12_COMMAND_QUEUE_DESC {
  D3D12_COMMAND_LIST_TYPE   Type;
  int                       Priority;
  D3D12_COMMAND_QUEUE_FLAGS Flags;
  unsigned                  NodeMask;
} D3D12_COMMAND_QUEUE_DESC;

// x12DeviceSetEventOnMultipleFenceCompletion

typedef enum D3D12_MULTIPLE_FENCE_WAIT_FLAG {
  D3D12_MULTIPLE_FENCE_WAIT_FLAG_NONE = 0, // No flags are being passed. This means to use the default behavior, which is to wait for all fences before signaling the event.
  D3D12_MULTIPLE_FENCE_WAIT_FLAG_ALL  = 0, // An alias for D3D12_MULTIPLE_FENCE_WAIT_FLAG_NONE, meaning to use the default behavior and wait for all fences.
  D3D12_MULTIPLE_FENCE_WAIT_FLAG_ANY  = 1, // Modifies behavior to indicate that the event should be signaled after any one of the fence values has been reached by its corresponding fence.
} D3D12_MULTIPLE_FENCE_WAIT_FLAG;

// x12CommandListClearUnorderedAccessViewUint
// x12CommandListClearUnorderedAccessViewFloat
// x12CommandListRSSetScissorRects

typedef struct D3D12_RECT {
  int left;
  int top;
  int right;
  int bottom;
} D3D12_RECT;

// x12CommandListIASetPrimitiveTopology

typedef enum D3D12_PRIMITIVE_TOPOLOGY {
  D3D_PRIMITIVE_TOPOLOGY_UNDEFINED     = 0,
  D3D_PRIMITIVE_TOPOLOGY_POINTLIST     = 1,
  D3D_PRIMITIVE_TOPOLOGY_LINELIST      = 2,
  D3D_PRIMITIVE_TOPOLOGY_LINESTRIP     = 3,
  D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST  = 4,
  D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP = 5,
} D3D12_PRIMITIVE_TOPOLOGY;

// x12CommandListIASetIndexBuffer

typedef struct D3D12_INDEX_BUFFER_VIEW {
  D3D12_GPU_VIRTUAL_ADDRESS BufferLocation;
  unsigned                  SizeInBytes;
  DXGI_FORMAT               Format;
} D3D12_INDEX_BUFFER_VIEW;

// x12CommandListRSSetViewports

typedef struct D3D12_VIEWPORT {
  float TopLeftX;
  float TopLeftY;
  float Width;
  float Height;
  float MinDepth;
  float MaxDepth;
} D3D12_VIEWPORT;

// x12CommandListClearDepthStencilView

typedef unsigned D3D12_CLEAR_FLAGS;
typedef enum D3D12_CLEAR_FLAG {
  D3D12_CLEAR_FLAG_NONE    = 0,
  D3D12_CLEAR_FLAG_DEPTH   = 0x1,
  D3D12_CLEAR_FLAG_STENCIL = 0x2,
} D3D12_CLEAR_FLAG;

// x12CommandListDiscardResource

typedef struct D3D12_DISCARD_REGION {
  unsigned           NumRects;
  const D3D12_RECT * pRects;           // _In_reads_(NumRects)
  unsigned           FirstSubresource;
  unsigned           NumSubresources;
} D3D12_DISCARD_REGION;

// x12CommandListResourceBarrier

typedef enum D3D12_RESOURCE_BARRIER_TYPE {
  D3D12_RESOURCE_BARRIER_TYPE_TRANSITION = 0,
  D3D12_RESOURCE_BARRIER_TYPE_ALIASING   = 1,
  D3D12_RESOURCE_BARRIER_TYPE_UAV        = 2,
} D3D12_RESOURCE_BARRIER_TYPE;

typedef unsigned D3D12_RESOURCE_BARRIER_FLAGS;
typedef enum D3D12_RESOURCE_BARRIER_FLAG {
  D3D12_RESOURCE_BARRIER_FLAG_NONE       = 0,
  D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY = 0x1,
  D3D12_RESOURCE_BARRIER_FLAG_END_ONLY   = 0x2,
} D3D12_RESOURCE_BARRIER_FLAG;

typedef struct D3D12_RESOURCE_TRANSITION_BARRIER {
  X12Resource *         pResource;
  unsigned              Subresource;
  D3D12_RESOURCE_STATES StateBefore;
  D3D12_RESOURCE_STATES StateAfter;
} D3D12_RESOURCE_TRANSITION_BARRIER;

typedef struct D3D12_RESOURCE_ALIASING_BARRIER {
  X12Resource * pResourceBefore;
  X12Resource * pResourceAfter;
} D3D12_RESOURCE_ALIASING_BARRIER;

typedef struct D3D12_RESOURCE_UAV_BARRIER {
  X12Resource * pResource;
} D3D12_RESOURCE_UAV_BARRIER;

typedef struct D3D12_RESOURCE_BARRIER {
  D3D12_RESOURCE_BARRIER_TYPE         Type;
  D3D12_RESOURCE_BARRIER_FLAGS        Flags;
  union {
    D3D12_RESOURCE_TRANSITION_BARRIER Transition;
    D3D12_RESOURCE_ALIASING_BARRIER   Aliasing;
    D3D12_RESOURCE_UAV_BARRIER        UAV;
  };
} D3D12_RESOURCE_BARRIER;

// x12AdapterGetDesc2

typedef unsigned DXGI_ADAPTER_FLAGS;
typedef enum DXGI_ADAPTER_FLAG {
  DXGI_ADAPTER_FLAG_NONE     = 0,
  DXGI_ADAPTER_FLAG_REMOTE   = 0x1,
  DXGI_ADAPTER_FLAG_SOFTWARE = 0x2,
} DXGI_ADAPTER_FLAG;

typedef enum DXGI_GRAPHICS_PREEMPTION_GRANULARITY {
  DXGI_GRAPHICS_PREEMPTION_DMA_BUFFER_BOUNDARY  = 0,
  DXGI_GRAPHICS_PREEMPTION_PRIMITIVE_BOUNDARY   = 1,
  DXGI_GRAPHICS_PREEMPTION_TRIANGLE_BOUNDARY    = 2,
  DXGI_GRAPHICS_PREEMPTION_PIXEL_BOUNDARY       = 3,
  DXGI_GRAPHICS_PREEMPTION_INSTRUCTION_BOUNDARY = 4,
} DXGI_GRAPHICS_PREEMPTION_GRANULARITY;

typedef enum DXGI_COMPUTE_PREEMPTION_GRANULARITY {
  DXGI_COMPUTE_PREEMPTION_DMA_BUFFER_BOUNDARY   = 0,
  DXGI_COMPUTE_PREEMPTION_DISPATCH_BOUNDARY     = 1,
  DXGI_COMPUTE_PREEMPTION_THREAD_GROUP_BOUNDARY = 2,
  DXGI_COMPUTE_PREEMPTION_THREAD_BOUNDARY       = 3,
  DXGI_COMPUTE_PREEMPTION_INSTRUCTION_BOUNDARY  = 4,
} DXGI_COMPUTE_PREEMPTION_GRANULARITY;

typedef struct DXGI_ADAPTER_DESC2 {
  wchar_t                              Description[128];
  unsigned                             VendorId;
  unsigned                             DeviceId;
  unsigned                             SubSysId;
  unsigned                             Revision;
  size_t                               DedicatedVideoMemory;
  size_t                               DedicatedSystemMemory;
  size_t                               SharedSystemMemory;
  uint64_t                             AdapterLuid;
  DXGI_ADAPTER_FLAGS                   Flags;
  DXGI_GRAPHICS_PREEMPTION_GRANULARITY GraphicsPreemptionGranularity;
  DXGI_COMPUTE_PREEMPTION_GRANULARITY  ComputePreemptionGranularity;
} DXGI_ADAPTER_DESC2;

// x12DeviceCheckFeatureSupport

typedef enum D3D12_FEATURE {
  D3D12_FEATURE_D3D12_OPTIONS               = 0, // D3D12_FEATURE_DATA_D3D12_OPTIONS
  D3D12_FEATURE_ARCHITECTURE                = 1, // D3D12_FEATURE_DATA_ARCHITECTURE
  D3D12_FEATURE_FEATURE_LEVELS              = 2, // D3D12_FEATURE_DATA_FEATURE_LEVELS
  D3D12_FEATURE_FORMAT_SUPPORT              = 3, // D3D12_FEATURE_DATA_FORMAT_SUPPORT
  D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS  = 4, // D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS
  D3D12_FEATURE_FORMAT_INFO                 = 5, // D3D12_FEATURE_DATA_FORMAT_INFO
  D3D12_FEATURE_GPU_VIRTUAL_ADDRESS_SUPPORT = 6, // D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT
} D3D12_FEATURE;

typedef unsigned D3D12_SHADER_MIN_PRECISION_SUPPORT_FLAGS;
typedef enum D3D12_SHADER_MIN_PRECISION_SUPPORT_FLAG {
  D3D12_SHADER_MIN_PRECISION_SUPPORT_FLAG_NONE   = 0,
  D3D12_SHADER_MIN_PRECISION_SUPPORT_FLAG_10_BIT = 0x1,
  D3D12_SHADER_MIN_PRECISION_SUPPORT_FLAG_16_BIT = 0x2,
} D3D12_SHADER_MIN_PRECISION_SUPPORT_FLAG;

typedef enum D3D12_TILED_RESOURCES_TIER {
  D3D12_TILED_RESOURCES_TIER_NOT_SUPPORTED = 0,
  D3D12_TILED_RESOURCES_TIER_1             = 1,
  D3D12_TILED_RESOURCES_TIER_2             = 2,
  D3D12_TILED_RESOURCES_TIER_3             = 3,
} D3D12_TILED_RESOURCES_TIER;

typedef enum D3D12_RESOURCE_BINDING_TIER {
  D3D12_RESOURCE_BINDING_TIER_1 = 1,
  D3D12_RESOURCE_BINDING_TIER_2 = 2,
  D3D12_RESOURCE_BINDING_TIER_3 = 3,
} D3D12_RESOURCE_BINDING_TIER;

typedef enum D3D12_CONSERVATIVE_RASTERIZATION_TIER {
  D3D12_CONSERVATIVE_RASTERIZATION_TIER_NOT_SUPPORTED = 0,
  D3D12_CONSERVATIVE_RASTERIZATION_TIER_1             = 1,
  D3D12_CONSERVATIVE_RASTERIZATION_TIER_2             = 2,
  D3D12_CONSERVATIVE_RASTERIZATION_TIER_3             = 3,
} D3D12_CONSERVATIVE_RASTERIZATION_TIER;

typedef enum D3D12_CROSS_NODE_SHARING_TIER {
  D3D12_CROSS_NODE_SHARING_TIER_NOT_SUPPORTED = 0,
  D3D12_CROSS_NODE_SHARING_TIER_1_EMULATED    = 1,
  D3D12_CROSS_NODE_SHARING_TIER_1             = 2,
  D3D12_CROSS_NODE_SHARING_TIER_2             = 3,
} D3D12_CROSS_NODE_SHARING_TIER;

typedef enum D3D12_RESOURCE_HEAP_TIER {
  D3D12_RESOURCE_HEAP_TIER_1 = 1,
  D3D12_RESOURCE_HEAP_TIER_2 = 2,
} D3D12_RESOURCE_HEAP_TIER;

typedef unsigned D3D12_FORMAT_SUPPORT1_FLAGS;
typedef enum D3D12_FORMAT_SUPPORT1_FLAG {
  D3D12_FORMAT_SUPPORT1_FLAG_NONE                        = 0,
  D3D12_FORMAT_SUPPORT1_FLAG_BUFFER                      = 0x1,
  D3D12_FORMAT_SUPPORT1_FLAG_IA_VERTEX_BUFFER            = 0x2,
  D3D12_FORMAT_SUPPORT1_FLAG_IA_INDEX_BUFFER             = 0x4,
  D3D12_FORMAT_SUPPORT1_FLAG_SO_BUFFER                   = 0x8,
  D3D12_FORMAT_SUPPORT1_FLAG_TEXTURE1D                   = 0x10,
  D3D12_FORMAT_SUPPORT1_FLAG_TEXTURE2D                   = 0x20,
  D3D12_FORMAT_SUPPORT1_FLAG_TEXTURE3D                   = 0x40,
  D3D12_FORMAT_SUPPORT1_FLAG_TEXTURECUBE                 = 0x80,
  D3D12_FORMAT_SUPPORT1_FLAG_SHADER_LOAD                 = 0x100,
  D3D12_FORMAT_SUPPORT1_FLAG_SHADER_SAMPLE               = 0x200,
  D3D12_FORMAT_SUPPORT1_FLAG_SHADER_SAMPLE_COMPARISON    = 0x400,
  D3D12_FORMAT_SUPPORT1_FLAG_SHADER_SAMPLE_MONO_TEXT     = 0x800,
  D3D12_FORMAT_SUPPORT1_FLAG_MIP                         = 0x1000,
  D3D12_FORMAT_SUPPORT1_FLAG_RENDER_TARGET               = 0x4000,
  D3D12_FORMAT_SUPPORT1_FLAG_BLENDABLE                   = 0x8000,
  D3D12_FORMAT_SUPPORT1_FLAG_DEPTH_STENCIL               = 0x10000,
  D3D12_FORMAT_SUPPORT1_FLAG_MULTISAMPLE_RESOLVE         = 0x40000,
  D3D12_FORMAT_SUPPORT1_FLAG_DISPLAY                     = 0x80000,
  D3D12_FORMAT_SUPPORT1_FLAG_CAST_WITHIN_BIT_LAYOUT      = 0x100000,
  D3D12_FORMAT_SUPPORT1_FLAG_MULTISAMPLE_RENDERTARGET    = 0x200000,
  D3D12_FORMAT_SUPPORT1_FLAG_MULTISAMPLE_LOAD            = 0x400000,
  D3D12_FORMAT_SUPPORT1_FLAG_SHADER_GATHER               = 0x800000,
  D3D12_FORMAT_SUPPORT1_FLAG_BACK_BUFFER_CAST            = 0x1000000,
  D3D12_FORMAT_SUPPORT1_FLAG_TYPED_UNORDERED_ACCESS_VIEW = 0x2000000,
  D3D12_FORMAT_SUPPORT1_FLAG_SHADER_GATHER_COMPARISON    = 0x4000000,
  D3D12_FORMAT_SUPPORT1_FLAG_DECODER_OUTPUT              = 0x8000000,
  D3D12_FORMAT_SUPPORT1_FLAG_VIDEO_PROCESSOR_OUTPUT      = 0x10000000,
  D3D12_FORMAT_SUPPORT1_FLAG_VIDEO_PROCESSOR_INPUT       = 0x20000000,
  D3D12_FORMAT_SUPPORT1_FLAG_VIDEO_ENCODER               = 0x40000000,
} D3D12_FORMAT_SUPPORT1_FLAG;

typedef unsigned D3D12_FORMAT_SUPPORT2_FLAGS;
typedef enum D3D12_FORMAT_SUPPORT2_FLAG {
  D3D12_FORMAT_SUPPORT2_FLAG_NONE                                         = 0,
  D3D12_FORMAT_SUPPORT2_FLAG_UAV_ATOMIC_ADD                               = 0x1,
  D3D12_FORMAT_SUPPORT2_FLAG_UAV_ATOMIC_BITWISE_OPS                       = 0x2,
  D3D12_FORMAT_SUPPORT2_FLAG_UAV_ATOMIC_COMPARE_STORE_OR_COMPARE_EXCHANGE = 0x4,
  D3D12_FORMAT_SUPPORT2_FLAG_UAV_ATOMIC_EXCHANGE                          = 0x8,
  D3D12_FORMAT_SUPPORT2_FLAG_UAV_ATOMIC_SIGNED_MIN_OR_MAX                 = 0x10,
  D3D12_FORMAT_SUPPORT2_FLAG_UAV_ATOMIC_UNSIGNED_MIN_OR_MAX               = 0x20,
  D3D12_FORMAT_SUPPORT2_FLAG_UAV_TYPED_LOAD                               = 0x40,
  D3D12_FORMAT_SUPPORT2_FLAG_UAV_TYPED_STORE                              = 0x80,
  D3D12_FORMAT_SUPPORT2_FLAG_OUTPUT_MERGER_LOGIC_OP                       = 0x100,
  D3D12_FORMAT_SUPPORT2_FLAG_TILED                                        = 0x200,
  D3D12_FORMAT_SUPPORT2_FLAG_MULTIPLANE_OVERLAY                           = 0x4000,
} D3D12_FORMAT_SUPPORT2_FLAG;

typedef unsigned D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS;
typedef enum D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAG {
  D3D12_MULTISAMPLE_QUALITY_LEVELS_FLAG_NONE           = 0,
  D3D12_MULTISAMPLE_QUALITY_LEVELS_FLAG_TILED_RESOURCE = 0x1,
} D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAG;

typedef struct D3D12_FEATURE_DATA_D3D12_OPTIONS {
  X12Bool                                  DoublePrecisionFloatShaderOps;                                              // _Out_
  X12Bool                                  OutputMergerLogicOp;                                                        // _Out_
  D3D12_SHADER_MIN_PRECISION_SUPPORT_FLAGS MinPrecisionSupport;                                                        // _Out_
  D3D12_TILED_RESOURCES_TIER               TiledResourcesTier;                                                         // _Out_
  D3D12_RESOURCE_BINDING_TIER              ResourceBindingTier;                                                        // _Out_
  X12Bool                                  PSSpecifiedStencilRefSupported;                                             // _Out_
  X12Bool                                  TypedUAVLoadAdditionalFormats;                                              // _Out_
  X12Bool                                  ROVsSupported;                                                              // _Out_
  D3D12_CONSERVATIVE_RASTERIZATION_TIER    ConservativeRasterizationTier;                                              // _Out_
  unsigned                                 MaxGPUVirtualAddressBitsPerResource;                                        // _Out_
  X12Bool                                  StandardSwizzle64KBSupported;                                               // _Out_
  D3D12_CROSS_NODE_SHARING_TIER            CrossNodeSharingTier;                                                       // _Out_
  X12Bool                                  CrossAdapterRowMajorTextureSupported;                                       // _Out_
  X12Bool                                  VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation; // _Out_
  D3D12_RESOURCE_HEAP_TIER                 ResourceHeapTier;                                                           // _Out_
} D3D12_FEATURE_DATA_D3D12_OPTIONS;

typedef struct D3D12_FEATURE_DATA_ARCHITECTURE {
  unsigned NodeIndex;         // _In_
  X12Bool  TileBasedRenderer; // _Out_
  X12Bool  UMA;               // _Out_
  X12Bool  CacheCoherentUMA;  // _Out_
} D3D12_FEATURE_DATA_ARCHITECTURE;

typedef struct D3D12_FEATURE_DATA_FEATURE_LEVELS {
  unsigned                  NumFeatureLevels;         // _In_
  const D3D_FEATURE_LEVEL * pFeatureLevelsRequested;  // _In_reads_(NumFeatureLevels)
  D3D_FEATURE_LEVEL         MaxSupportedFeatureLevel; // _Out_
} D3D12_FEATURE_DATA_FEATURE_LEVELS;

typedef struct D3D12_FEATURE_DATA_FORMAT_SUPPORT {
  DXGI_FORMAT                 Format;   // _In_
  D3D12_FORMAT_SUPPORT1_FLAGS Support1; // _Out_
  D3D12_FORMAT_SUPPORT2_FLAGS Support2; // _Out_
} D3D12_FEATURE_DATA_FORMAT_SUPPORT;

typedef struct D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS {
  DXGI_FORMAT                           Format;           // _In_
  unsigned                              SampleCount;      // _In_
  D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS Flags;            // _In_
  unsigned                              NumQualityLevels; // _Out_
} D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS;

typedef struct D3D12_FEATURE_DATA_FORMAT_INFO {
  DXGI_FORMAT   Format;
  unsigned char PlaneCount;
} D3D12_FEATURE_DATA_FORMAT_INFO;

typedef struct D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT {
  unsigned MaxGPUVirtualAddressBitsPerResource;
  unsigned MaxGPUVirtualAddressBitsPerProcess;
} D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT;

// WSI

// x12FactoryCreateSwapChainForHwnd
// x12FactoryCreateSwapChainForCoreWindow
// x12FactoryCreateSwapChainForComposition
// x12SwapChainGetFullscreenDesc

// https://docs.microsoft.com/en-us/windows/win32/direct3ddxgi/dxgi-usage
// "Swap chain's only support the DXGI_CPU_ACCESS_NONE value in the DXGI_CPU_ACCESS_FIELD part of DXGI_USAGE."
//#define DXGI_CPU_ACCESS_NONE       (0)
//#define DXGI_CPU_ACCESS_DYNAMIC    (1)
//#define DXGI_CPU_ACCESS_READ_WRITE (2)
//#define DXGI_CPU_ACCESS_SCRATCH    (3)
//#define DXGI_CPU_ACCESS_FIELD      15

typedef unsigned DXGI_USAGE_FLAGS;
typedef enum DXGI_USAGE_FLAG {
  DXGI_USAGE_FLAG_NONE                 = 0,
  DXGI_USAGE_FLAG_SHADER_INPUT         = 0x10,
  DXGI_USAGE_FLAG_RENDER_TARGET_OUTPUT = 0x20,
  DXGI_USAGE_FLAG_BACK_BUFFER          = 0x40,
  DXGI_USAGE_FLAG_SHARED               = 0x80,
  DXGI_USAGE_FLAG_READ_ONLY            = 0x100,
  DXGI_USAGE_FLAG_DISCARD_ON_PRESENT   = 0x200,
  DXGI_USAGE_FLAG_UNORDERED_ACCESS     = 0x400,
} DXGI_USAGE_FLAG;

typedef enum DXGI_SCALING {
  DXGI_SCALING_STRETCH              = 0,
  DXGI_SCALING_NONE                 = 1,
  DXGI_SCALING_ASPECT_RATIO_STRETCH = 2,
} DXGI_SCALING;

typedef enum DXGI_SWAP_EFFECT {
  DXGI_SWAP_EFFECT_DISCARD         = 0,
  DXGI_SWAP_EFFECT_SEQUENTIAL      = 1,
  DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL = 3,
  DXGI_SWAP_EFFECT_FLIP_DISCARD    = 4,
} DXGI_SWAP_EFFECT;

typedef enum DXGI_ALPHA_MODE {
  DXGI_ALPHA_MODE_UNSPECIFIED   = 0,
  DXGI_ALPHA_MODE_PREMULTIPLIED = 1,
  DXGI_ALPHA_MODE_STRAIGHT      = 2,
  DXGI_ALPHA_MODE_IGNORE        = 3,
} DXGI_ALPHA_MODE;

typedef unsigned DXGI_SWAP_CHAIN_FLAGS;
typedef enum DXGI_SWAP_CHAIN_FLAG {
  DXGI_SWAP_CHAIN_FLAG_NONE                                   = 0,
  DXGI_SWAP_CHAIN_FLAG_NONPREROTATED                          = 0x1,
  DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH                      = 0x2,
  DXGI_SWAP_CHAIN_FLAG_GDI_COMPATIBLE                         = 0x4,
  DXGI_SWAP_CHAIN_FLAG_RESTRICTED_CONTENT                     = 0x8,
  DXGI_SWAP_CHAIN_FLAG_RESTRICT_SHARED_RESOURCE_DRIVER        = 0x10,
  DXGI_SWAP_CHAIN_FLAG_DISPLAY_ONLY                           = 0x20,
  DXGI_SWAP_CHAIN_FLAG_FRAME_LATENCY_WAITABLE_OBJECT          = 0x40,
  DXGI_SWAP_CHAIN_FLAG_FOREGROUND_LAYER                       = 0x80,
  DXGI_SWAP_CHAIN_FLAG_FULLSCREEN_VIDEO                       = 0x100,
  DXGI_SWAP_CHAIN_FLAG_YUV_VIDEO                              = 0x200,
  DXGI_SWAP_CHAIN_FLAG_HW_PROTECTED                           = 0x400,
  DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING                          = 0x800,
  DXGI_SWAP_CHAIN_FLAG_RESTRICTED_TO_ALL_HOLOGRAPHIC_DISPLAYS = 0x1000,
} DXGI_SWAP_CHAIN_FLAG;

typedef struct DXGI_SWAP_CHAIN_DESC1 {
  unsigned              Width;
  unsigned              Height;
  DXGI_FORMAT           Format;
  X12Bool               Stereo;
  DXGI_SAMPLE_DESC      SampleDesc;
  DXGI_USAGE_FLAGS      BufferUsage;
  unsigned              BufferCount;
  DXGI_SCALING          Scaling;
  DXGI_SWAP_EFFECT      SwapEffect;
  DXGI_ALPHA_MODE       AlphaMode;
  DXGI_SWAP_CHAIN_FLAGS Flags;
} DXGI_SWAP_CHAIN_DESC1;

typedef enum DXGI_MODE_SCANLINE_ORDER {
  DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED       = 0,
  DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE       = 1,
  DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST = 2,
  DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST = 3,
} DXGI_MODE_SCANLINE_ORDER;

typedef enum DXGI_MODE_SCALING {
  DXGI_MODE_SCALING_UNSPECIFIED = 0,
  DXGI_MODE_SCALING_CENTERED    = 1,
  DXGI_MODE_SCALING_STRETCHED   = 2,
} DXGI_MODE_SCALING;

typedef struct DXGI_RATIONAL {
  unsigned Numerator;
  unsigned Denominator;
} DXGI_RATIONAL;

typedef struct DXGI_SWAP_CHAIN_FULLSCREEN_DESC {
  DXGI_RATIONAL            RefreshRate;
  DXGI_MODE_SCANLINE_ORDER ScanlineOrdering;
  DXGI_MODE_SCALING        Scaling;
  X12Bool                  Windowed;
} DXGI_SWAP_CHAIN_FULLSCREEN_DESC;

// x12FactoryMakeWindowAssociation

typedef unsigned DXGI_MWA_FLAGS;
typedef enum DXGI_MWA_FLAG {
  DXGI_MWA_FLAG_NONE              = 0,
  DXGI_MWA_FLAG_NO_WINDOW_CHANGES = 0x1,
  DXGI_MWA_FLAG_NO_ALT_ENTER      = 0x2,
  DXGI_MWA_FLAG_NO_PRINT_SCREEN   = 0x4,
  DXGI_MWA_FLAG_VALID             = 0x7,
} DXGI_MWA_FLAG;

// x12SwapChainPresent1

// https://docs.microsoft.com/en-us/windows/win32/api/dxgi/nf-dxgi-idxgiswapchain-present
// https://docs.microsoft.com/en-us/windows/win32/direct3ddxgi/dxgi-present
typedef unsigned DXGI_PRESENT_FLAGS;
typedef enum DXGI_PRESENT_FLAG {
  DXGI_PRESENT_FLAG_NONE                  = 0,
  DXGI_PRESENT_FLAG_TEST                  = 0x1,
  DXGI_PRESENT_FLAG_DO_NOT_SEQUENCE       = 0x2,
  DXGI_PRESENT_FLAG_RESTART               = 0x4,
  DXGI_PRESENT_FLAG_DO_NOT_WAIT           = 0x8,
  DXGI_PRESENT_FLAG_STEREO_PREFER_RIGHT   = 0x10,
  DXGI_PRESENT_FLAG_STEREO_TEMPORARY_MONO = 0x20,
  DXGI_PRESENT_FLAG_RESTRICT_TO_OUTPUT    = 0x40,
  DXGI_PRESENT_FLAG_USE_DURATION          = 0x100,
  DXGI_PRESENT_FLAG_ALLOW_TEARING         = 0x200,
} DXGI_PRESENT_FLAG;

typedef struct D3D12_POINT {
  int x;
  int y;
} D3D12_POINT;

typedef struct DXGI_PRESENT_PARAMETERS {
  unsigned      DirtyRectsCount;
  D3D12_RECT *  pDirtyRects;     // _Field_size_full_opt_(DirtyRectsCount)
  D3D12_RECT *  pScrollRect;
  D3D12_POINT * pScrollOffset;
} DXGI_PRESENT_PARAMETERS;

// x12SwapChainResizeTarget
// x12OutputGetDisplayModeList1
// x12OutputFindClosestMatchingMode1

typedef unsigned DXGI_ENUM_MODES_FLAGS;
typedef enum DXGI_ENUM_MODES_FLAG {
  DXGI_ENUM_MODES_FLAG_NONE            = 0,
  DXGI_ENUM_MODES_FLAG_INTERLACED      = 0x1,
  DXGI_ENUM_MODES_FLAG_SCALING         = 0x2,
  DXGI_ENUM_MODES_FLAG_STEREO          = 0x4,
  DXGI_ENUM_MODES_FLAG_DISABLED_STEREO = 0x8,
} DXGI_ENUM_MODES_FLAG;

typedef struct DXGI_MODE_DESC {
  unsigned                 Width;
  unsigned                 Height;
  DXGI_RATIONAL            RefreshRate;
  DXGI_FORMAT              Format;
  DXGI_MODE_SCANLINE_ORDER ScanlineOrdering;
  DXGI_MODE_SCALING        Scaling;
} DXGI_MODE_DESC;

typedef struct DXGI_MODE_DESC1 {
  unsigned                 Width;
  unsigned                 Height;
  DXGI_RATIONAL            RefreshRate;
  DXGI_FORMAT              Format;
  DXGI_MODE_SCANLINE_ORDER ScanlineOrdering;
  DXGI_MODE_SCALING        Scaling;
  X12Bool                  Stereo;
} DXGI_MODE_DESC1;

// x12SwapChainGetFrameStatistics
// x12OutputGetFrameStatistics

typedef struct DXGI_FRAME_STATISTICS {
  unsigned PresentCount;
  unsigned PresentRefreshCount;
  unsigned SyncRefreshCount;
  int64_t  SyncQPCTime;
  int64_t  SyncGPUTime;
} DXGI_FRAME_STATISTICS;

// x12SwapChainSetBackgroundColor
// x12SwapChainGetBackgroundColor

typedef struct DXGI_RGBA {
  float r;
  float g;
  float b;
  float a;
} DXGI_RGBA;

// x12SwapChainSetRotation
// x12SwapChainGetRotation

typedef enum DXGI_MODE_ROTATION {
  DXGI_MODE_ROTATION_UNSPECIFIED = 0,
  DXGI_MODE_ROTATION_IDENTITY    = 1,
  DXGI_MODE_ROTATION_ROTATE90    = 2,
  DXGI_MODE_ROTATION_ROTATE180   = 3,
  DXGI_MODE_ROTATION_ROTATE270   = 4,
} DXGI_MODE_ROTATION;

// x12SwapChainSetMatrixTransform
// x12SwapChainGetMatrixTransform

typedef struct DXGI_MATRIX_3X2_F {
  float _11;
  float _12;
  float _21;
  float _22;
  float _31;
  float _32;
} DXGI_MATRIX_3X2_F;

// x12SwapChainCheckColorSpaceSupport
// x12SwapChainSetColorSpace1

typedef enum DXGI_COLOR_SPACE_TYPE {
  DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P709           = 0,
  DXGI_COLOR_SPACE_RGB_FULL_G10_NONE_P709           = 1,
  DXGI_COLOR_SPACE_RGB_STUDIO_G22_NONE_P709         = 2,
  DXGI_COLOR_SPACE_RGB_STUDIO_G22_NONE_P2020        = 3,
  DXGI_COLOR_SPACE_RESERVED                         = 4,
  DXGI_COLOR_SPACE_YCBCR_FULL_G22_NONE_P709_X601    = 5,
  DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P601       = 6,
  DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P601         = 7,
  DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P709       = 8,
  DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P709         = 9,
  DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_LEFT_P2020      = 10,
  DXGI_COLOR_SPACE_YCBCR_FULL_G22_LEFT_P2020        = 11,
  DXGI_COLOR_SPACE_RGB_FULL_G2084_NONE_P2020        = 12,
  DXGI_COLOR_SPACE_YCBCR_STUDIO_G2084_LEFT_P2020    = 13,
  DXGI_COLOR_SPACE_RGB_STUDIO_G2084_NONE_P2020      = 14,
  DXGI_COLOR_SPACE_YCBCR_STUDIO_G22_TOPLEFT_P2020   = 15,
  DXGI_COLOR_SPACE_YCBCR_STUDIO_G2084_TOPLEFT_P2020 = 16,
  DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P2020          = 17,
  DXGI_COLOR_SPACE_YCBCR_STUDIO_GHLG_TOPLEFT_P2020  = 18,
  DXGI_COLOR_SPACE_YCBCR_FULL_GHLG_TOPLEFT_P2020    = 19,
  DXGI_COLOR_SPACE_RGB_STUDIO_G24_NONE_P709         = 20,
  DXGI_COLOR_SPACE_RGB_STUDIO_G24_NONE_P2020        = 21,
  DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_LEFT_P709       = 22,
  DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_LEFT_P2020      = 23,
  DXGI_COLOR_SPACE_YCBCR_STUDIO_G24_TOPLEFT_P2020   = 24,
  DXGI_COLOR_SPACE_CUSTOM                           = 0xFFFFFFFF,
} DXGI_COLOR_SPACE_TYPE;

typedef unsigned DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAGS;
typedef enum DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG {
  DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG_NONE            = 0,
  DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG_PRESENT         = 0x1,
  DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG_OVERLAY_PRESENT = 0x2,
} DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAG;

// x12OutputGetDesc

typedef struct DXGI_OUTPUT_DESC {
  wchar_t            DeviceName[32];
  D3D12_RECT         DesktopCoordinates;
  X12Bool            AttachedToDesktop;
  DXGI_MODE_ROTATION Rotation;
  void *             Monitor;
} DXGI_OUTPUT_DESC;

// x12OutputGetGammaControlCapabilities

typedef struct DXGI_GAMMA_CONTROL_CAPABILITIES {
  X12Bool  ScaleAndOffsetSupported;
  float    MaxConvertedValue;
  float    MinConvertedValue;
  unsigned NumGammaControlPoints;
  float    ControlPointPositions[1025];
} DXGI_GAMMA_CONTROL_CAPABILITIES;

// x12OutputSetGammaControl
// x12OutputGetGammaControl

typedef struct DXGI_RGB {
  float Red;
  float Green;
  float Blue;
} DXGI_RGB;

typedef struct DXGI_GAMMA_CONTROL {
  DXGI_RGB Scale;
  DXGI_RGB Offset;
  DXGI_RGB GammaCurve[1025];
} DXGI_GAMMA_CONTROL;

// x12OutputCheckOverlayColorSpaceSupport

typedef unsigned DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAGS;
typedef enum DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG {
  DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG_NONE    = 0,
  DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG_PRESENT = 0x1,
} DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAG;

#ifndef X12_DECLSPEC
#define X12_DECLSPEC
#endif

// Memory budget

X12_DECLSPEC HRESULT  x12AdapterRegisterVideoMemoryBudgetChangeNotificationEvent (X12Adapter3 * pAdapter, void * hEvent, unsigned * outdwCookie, const char * optionalFile, int optionalLine);
X12_DECLSPEC void     x12AdapterUnregisterVideoMemoryBudgetChangeNotification    (X12Adapter3 * pAdapter, unsigned dwCookie, const char * optionalFile, int optionalLine);

// Memory

X12_DECLSPEC HRESULT  x12AdapterQueryVideoMemoryInfo                      (X12Adapter3 * pAdapter, unsigned NodeIndex, DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup, DXGI_QUERY_VIDEO_MEMORY_INFO * pVideoMemoryInfo, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12AdapterSetVideoMemoryReservation                 (X12Adapter3 * pAdapter, unsigned NodeIndex, DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup, uint64_t Reservation, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12DeviceCreateHeap                                 (X12Device3 * pDevice, const D3D12_HEAP_DESC * pDesc, X12Heap ** outpHeap, const char * optionalFile, int optionalLine);
X12_DECLSPEC void     x12DeviceGetResourceAllocationInfo                  (X12Device3 * pDevice, unsigned visibleMask, unsigned numResourceDescs, const D3D12_RESOURCE_DESC * pResourceDescs, D3D12_RESOURCE_ALLOCATION_INFO * outResourceAllocationInfo, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12DeviceCreatePlacedResource                       (X12Device3 * pDevice, X12Heap * pHeap, uint64_t HeapOffset, const D3D12_RESOURCE_DESC * pDesc, D3D12_RESOURCE_STATES InitialState, const D3D12_CLEAR_VALUE * pOptimizedClearValue, X12Resource ** outpResource, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12DeviceCreateCommittedResource                    (X12Device3 * pDevice, const D3D12_HEAP_PROPERTIES * pHeapProperties, D3D12_HEAP_FLAGS HeapFlags, const D3D12_RESOURCE_DESC * pDesc, D3D12_RESOURCE_STATES InitialResourceState, const D3D12_CLEAR_VALUE * pOptimizedClearValue, X12Resource ** outpResource, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12ResourceMap                                      (X12Resource * pResource, unsigned Subresource, const D3D12_RANGE * pReadRange, void ** outpData, const char * optionalFile, int optionalLine);
X12_DECLSPEC void     x12ResourceUnmap                                    (X12Resource * pResource, unsigned Subresource, const D3D12_RANGE * pWrittenRange, const char * optionalFile, int optionalLine);

// Memory struct

X12_DECLSPEC HRESULT  x12DeviceCreateDescriptorHeap                       (X12Device3 * pDevice, const D3D12_DESCRIPTOR_HEAP_DESC * pDescriptorHeapDesc, X12DescriptorHeap ** outpHeap, const char * optionalFile, int optionalLine);
X12_DECLSPEC void     x12DescriptorHeapGetCPUDescriptorHandleForHeapStart (X12DescriptorHeap * pDescriptorHeap, D3D12_CPU_DESCRIPTOR_HANDLE * pCpuDescriptorHandle);
X12_DECLSPEC void     x12DeviceCopyDescriptors                            (X12Device3 * pDevice, unsigned NumDestDescriptorRanges, const D3D12_CPU_DESCRIPTOR_HANDLE * pDestDescriptorRangeStarts, const unsigned * pDestDescriptorRangeSizes, unsigned NumSrcDescriptorRanges, const D3D12_CPU_DESCRIPTOR_HANDLE * pSrcDescriptorRangeStarts, const unsigned * pSrcDescriptorRangeSizes, D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType, const char * optionalFile, int optionalLine);
X12_DECLSPEC void     x12DescriptorHeapGetGPUDescriptorHandleForHeapStart (X12DescriptorHeap * pDescriptorHeap, D3D12_GPU_DESCRIPTOR_HANDLE * pGpuDescriptorHandle);

// Memory residency

X12_DECLSPEC HRESULT  x12DeviceSetResidencyPriority                       (X12Device3 * pDevice, unsigned NumObjects, const X12Pageable ** ppObjects, const unsigned * pPriorities, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12DeviceEvict                                      (X12Device3 * pDevice, unsigned NumObjects, const X12Pageable ** ppObjects, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12DeviceMakeResident                               (X12Device3 * pDevice, unsigned NumObjects, const X12Pageable ** ppObjects, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12DeviceEnqueueMakeResident                        (X12Device3 * pDevice, D3D12_RESIDENCY_FLAGS Flags, unsigned NumObjects, const X12Pageable ** ppObjects, X12Fence * pFenceToSignal, uint64_t FenceValueToSignal, const char * optionalFile, int optionalLine);

// Create

X12_DECLSPEC void *   x12DebugEnable                                      (const char * optionalFile, int optionalLine);
X12_DECLSPEC void     x12DebugReport                                      (void * debugContext, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12CreateFactory2                                   (DXGI_CREATE_FACTORY_FLAGS Flags, X12Factory4 ** outpFactory, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12FactoryEnumAdapters1                             (X12Factory4 * pFactory, unsigned Adapter, X12Adapter3 ** outpAdapter, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12CreateDevice                                     (X12Adapter3 * pAdapter, D3D_FEATURE_LEVEL MinimumFeatureLevel, X12Device3 ** outpDevice, const char * optionalFile, int optionalLine);
X12_DECLSPEC void     x12DeviceCreateUnorderedAccessView                  (X12Device3 * pDevice, X12Resource * pResource, X12Resource * pCounterResource, const D3D12_UNORDERED_ACCESS_VIEW_DESC * pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor, const char * optionalFile, int optionalLine);
X12_DECLSPEC void     x12DeviceCreateShaderResourceView                   (X12Device3 * pDevice, X12Resource * pResource, const D3D12_SHADER_RESOURCE_VIEW_DESC * pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor, const char * optionalFile, int optionalLine);
X12_DECLSPEC void     x12DeviceCreateConstantBufferView                   (X12Device3 * pDevice, const D3D12_CONSTANT_BUFFER_VIEW_DESC * pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor, const char * optionalFile, int optionalLine);
X12_DECLSPEC void     x12DeviceCreateSampler                              (X12Device3 * pDevice, const D3D12_SAMPLER_DESC * pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor, const char * optionalFile, int optionalLine);
X12_DECLSPEC void     x12DeviceCreateRenderTargetView                     (X12Device3 * pDevice, X12Resource * pResource, const D3D12_RENDER_TARGET_VIEW_DESC * pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor, const char * optionalFile, int optionalLine);
X12_DECLSPEC void     x12DeviceCreateDepthStencilView                     (X12Device3 * pDevice, X12Resource * pResource, const D3D12_DEPTH_STENCIL_VIEW_DESC * pDesc, D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SerializeRootSignature                           (const D3D12_ROOT_SIGNATURE_DESC * pRootSignature, D3D_ROOT_SIGNATURE_VERSION Version, X12Blob ** outpBlob, X12Blob ** outpErrorBlob, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12DeviceCreateRootSignature                        (X12Device3 * pDevice, unsigned nodeMask, const void * pBlobWithRootSignature, size_t blobLengthInBytes, X12RootSignature ** outpRootSignature, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12DeviceCreateGraphicsPipelineState                (X12Device3 * pDevice, const D3D12_GRAPHICS_PIPELINE_STATE_DESC * pDesc, X12PipelineState ** outpPipelineState, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12DeviceCreateComputePipelineState                 (X12Device3 * pDevice, const D3D12_COMPUTE_PIPELINE_STATE_DESC * pDesc, X12PipelineState ** outpPipelineState, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12DeviceCreateFence                                (X12Device3 * pDevice, uint64_t InitialValue, D3D12_FENCE_FLAGS Flags, X12Fence ** outpFence, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12DeviceCreateCommandQueue                         (X12Device3 * pDevice, const D3D12_COMMAND_QUEUE_DESC * pDesc, X12CommandQueue ** outpCommandQueue, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12DeviceCreateCommandAllocator                     (X12Device3 * pDevice, D3D12_COMMAND_LIST_TYPE type, X12CommandAllocator ** outpCommandAllocator, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12DeviceCreateCommandList                          (X12Device3 * pDevice, unsigned nodeMask, D3D12_COMMAND_LIST_TYPE type, X12CommandAllocator * pCommandAllocator, X12PipelineState * pInitialState, X12CommandList ** outpCommandList, const char * optionalFile, int optionalLine);

// Resource

X12_DECLSPEC D3D12_GPU_VIRTUAL_ADDRESS x12ResourceGetGPUVirtualAddress    (X12Resource * pResource);

// Blob

X12_DECLSPEC HRESULT  x12PipelineStateGetCachedBlob                       (X12PipelineState * pPipelineState, X12Blob ** outpBlob, const char * optionalFile, int optionalLine);
X12_DECLSPEC void *   x12BlobGetBufferPointer                             (X12Blob * pBlob);
X12_DECLSPEC size_t   x12BlobGetBufferSize                                (X12Blob * pBlob);

// Blob root signature description deserializer

X12_DECLSPEC HRESULT  x12CreateRootSignatureDeserializer                  (const void * pSrcData, size_t SrcDataSizeInBytes, X12RootSignatureDeserializer ** outpRootSignatureDeserializer, const char * optionalFile, int optionalLine);
X12_DECLSPEC const D3D12_ROOT_SIGNATURE_DESC * x12RootSignatureDeserializerGetRootSignatureDesc (X12RootSignatureDeserializer * pRootSignatureDeserializer, const char * optionalFile, int optionalLine);

// Signal

X12_DECLSPEC uint64_t x12FenceGetCompletedValue                           (X12Fence * pFence, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12FenceSetEventOnCompletion                        (X12Fence * pFence, uint64_t Value, void * hEvent, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12DeviceSetEventOnMultipleFenceCompletion          (X12Device3 * pDevice, const X12Fence ** ppFences, const uint64_t * pFenceValues, unsigned NumFences, D3D12_MULTIPLE_FENCE_WAIT_FLAG Flag, void * hEvent, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12FenceSignal                                      (X12Fence * pFence, uint64_t Value, const char * optionalFile, int optionalLine);

// Calls

X12_DECLSPEC HRESULT  x12CommandAllocatorReset                            (X12CommandAllocator * pCommandAllocator, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12CommandListReset                                 (X12CommandList * pCommandList, X12CommandAllocator * pAllocator, X12PipelineState * pInitialState, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12CommandListClose                                 (X12CommandList * pCommandList, const char * optionalFile, int optionalLine);

// Calls recording

X12_DECLSPEC void     x12CommandListCopyResource                          (X12CommandList * pCommandList, X12Resource * pDstResource, X12Resource * pSrcResource);
X12_DECLSPEC void     x12CommandListCopyBufferRegion                      (X12CommandList * pCommandList, X12Resource * pDstBuffer, uint64_t DstOffset, X12Resource * pSrcBuffer, uint64_t SrcOffset, uint64_t NumBytes);
X12_DECLSPEC void     x12CommandListClearUnorderedAccessViewUint          (X12CommandList * pCommandList, D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap, D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle, X12Resource * pResource, const unsigned Values[4], unsigned NumRects, const D3D12_RECT * pRects);
X12_DECLSPEC void     x12CommandListClearUnorderedAccessViewFloat         (X12CommandList * pCommandList, D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap, D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle, X12Resource * pResource, const float Values[4], unsigned NumRects, const D3D12_RECT * pRects);
X12_DECLSPEC void     x12CommandListDrawInstanced                         (X12CommandList * pCommandList, unsigned VertexCountPerInstance, unsigned InstanceCount, unsigned StartVertexLocation, unsigned StartInstanceLocation);
X12_DECLSPEC void     x12CommandListDrawIndexedInstanced                  (X12CommandList * pCommandList, unsigned IndexCountPerInstance, unsigned InstanceCount, unsigned StartIndexLocation, int BaseVertexLocation, unsigned StartInstanceLocation);
X12_DECLSPEC void     x12CommandListDispatch                              (X12CommandList * pCommandList, unsigned ThreadGroupCountX, unsigned ThreadGroupCountY, unsigned ThreadGroupCountZ);
X12_DECLSPEC void     x12CommandListSetDescriptorHeaps                    (X12CommandList * pCommandList, unsigned NumDescriptorHeaps, const X12DescriptorHeap ** ppDescriptorHeaps);
X12_DECLSPEC void     x12CommandListSetGraphicsRootSignature              (X12CommandList * pCommandList, X12RootSignature * pRootSignature);
X12_DECLSPEC void     x12CommandListSetGraphicsRoot32BitConstant          (X12CommandList * pCommandList, unsigned RootParameterIndex, unsigned SrcData, unsigned DestOffsetIn32BitValues);
X12_DECLSPEC void     x12CommandListSetGraphicsRoot32BitConstants         (X12CommandList * pCommandList, unsigned RootParameterIndex, unsigned Num32BitValuesToSet, const void * pSrcData, unsigned DestOffsetIn32BitValues);
X12_DECLSPEC void     x12CommandListSetGraphicsRootDescriptorTable        (X12CommandList * pCommandList, unsigned RootParameterIndex, D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor);
X12_DECLSPEC void     x12CommandListSetGraphicsRootUnorderedAccessView    (X12CommandList * pCommandList, unsigned RootParameterIndex, D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);
X12_DECLSPEC void     x12CommandListSetGraphicsRootShaderResourceView     (X12CommandList * pCommandList, unsigned RootParameterIndex, D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);
X12_DECLSPEC void     x12CommandListSetGraphicsRootConstantBufferView     (X12CommandList * pCommandList, unsigned RootParameterIndex, D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);
X12_DECLSPEC void     x12CommandListSetComputeRootSignature               (X12CommandList * pCommandList, X12RootSignature * pRootSignature);
X12_DECLSPEC void     x12CommandListSetComputeRoot32BitConstant           (X12CommandList * pCommandList, unsigned RootParameterIndex, unsigned SrcData, unsigned DestOffsetIn32BitValues);
X12_DECLSPEC void     x12CommandListSetComputeRoot32BitConstants          (X12CommandList * pCommandList, unsigned RootParameterIndex, unsigned Num32BitValuesToSet, const void * pSrcData, unsigned DestOffsetIn32BitValues);
X12_DECLSPEC void     x12CommandListSetComputeRootDescriptorTable         (X12CommandList * pCommandList, unsigned RootParameterIndex, D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor);
X12_DECLSPEC void     x12CommandListSetComputeRootUnorderedAccessView     (X12CommandList * pCommandList, unsigned RootParameterIndex, D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);
X12_DECLSPEC void     x12CommandListSetComputeRootShaderResourceView      (X12CommandList * pCommandList, unsigned RootParameterIndex, D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);
X12_DECLSPEC void     x12CommandListSetComputeRootConstantBufferView      (X12CommandList * pCommandList, unsigned RootParameterIndex, D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);
X12_DECLSPEC void     x12CommandListClearState                            (X12CommandList * pCommandList, X12PipelineState * pPipelineState);
X12_DECLSPEC void     x12CommandListSetPipelineState                      (X12CommandList * pCommandList, X12PipelineState * pPipelineState);
X12_DECLSPEC void     x12CommandListIASetPrimitiveTopology                (X12CommandList * pCommandList, D3D12_PRIMITIVE_TOPOLOGY PrimitiveTopology);
X12_DECLSPEC void     x12CommandListIASetIndexBuffer                      (X12CommandList * pCommandList, const D3D12_INDEX_BUFFER_VIEW * pView);
X12_DECLSPEC void     x12CommandListOMSetStencilRef                       (X12CommandList * pCommandList, unsigned StencilRef);
X12_DECLSPEC void     x12CommandListOMSetBlendFactor                      (X12CommandList * pCommandList, const float * BlendFactor4Values);
X12_DECLSPEC void     x12CommandListRSSetViewports                        (X12CommandList * pCommandList, unsigned NumViewports, const D3D12_VIEWPORT * pViewports);
X12_DECLSPEC void     x12CommandListRSSetScissorRects                     (X12CommandList * pCommandList, unsigned NumRects, const D3D12_RECT * pRects);
X12_DECLSPEC void     x12CommandListClearRenderTargetView                 (X12CommandList * pCommandList, D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView, const float ColorRGBA[4], unsigned NumRects, const D3D12_RECT * pRects);
X12_DECLSPEC void     x12CommandListClearDepthStencilView                 (X12CommandList * pCommandList, D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView, D3D12_CLEAR_FLAGS ClearFlags, float Depth, unsigned char Stencil, unsigned NumRects, const D3D12_RECT * pRects);
X12_DECLSPEC void     x12CommandListDiscardResource                       (X12CommandList * pCommandList, X12Resource * pResource, const D3D12_DISCARD_REGION * pRegion);
X12_DECLSPEC void     x12CommandListOMSetRenderTargets                    (X12CommandList * pCommandList, unsigned NumRenderTargetDescriptors, const D3D12_CPU_DESCRIPTOR_HANDLE * pRenderTargetDescriptors, X12Bool RTsSingleHandleToDescriptorRange, const D3D12_CPU_DESCRIPTOR_HANDLE * pDepthStencilDescriptor);
X12_DECLSPEC void     x12CommandListResolveSubresource                    (X12CommandList * pCommandList, X12Resource * pDstResource, unsigned DstSubresource, X12Resource * pSrcResource, unsigned SrcSubresource, DXGI_FORMAT Format);
X12_DECLSPEC void     x12CommandListResourceBarrier                       (X12CommandList * pCommandList, unsigned NumBarriers, const D3D12_RESOURCE_BARRIER * pBarriers);

// Queue

X12_DECLSPEC HRESULT  x12CommandQueueWait                                 (X12CommandQueue * pCommandQueue, X12Fence * pFence, uint64_t Value, const char * optionalFile, int optionalLine);
X12_DECLSPEC void     x12CommandQueueExecuteCommandLists                  (X12CommandQueue * pCommandQueue, unsigned NumCommandLists, const X12CommandList ** ppCommandLists, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12CommandQueueSignal                               (X12CommandQueue * pCommandQueue, X12Fence * pFence, uint64_t Value, const char * optionalFile, int optionalLine);

// Factory

X12_DECLSPEC X12Bool  x12FactoryIsCurrent                                 (X12Factory4 * pFactory, const char * optionalFile, int optionalLine);

// Adapter

X12_DECLSPEC HRESULT  x12AdapterGetDesc2                                  (X12Adapter3 * pAdapter, DXGI_ADAPTER_DESC2 * outDesc, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12AdapterEnumOutputs                               (X12Adapter3 * pAdapter, unsigned Output, X12Output4 ** outpOutput, const char * optionalFile, int optionalLine);

// Device

X12_DECLSPEC void     x12DeviceGetAdapterLuid                             (X12Device3 * pDevice, uint64_t * outLuid, const char * optionalFile, int optionalLine);
X12_DECLSPEC unsigned x12DeviceGetDescriptorHandleIncrementSize           (X12Device3 * pDevice, D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12DeviceCheckFeatureSupport                        (X12Device3 * pDevice, D3D12_FEATURE Feature, void * pFeatureSupportData, unsigned FeatureSupportDataSize, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12DeviceGetDeviceRemovedReason                     (X12Device3 * pDevice, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12DeviceSetStablePowerState                        (X12Device3 * pDevice, X12Bool Enable, const char * optionalFile, int optionalLine);

// WSI

// Factory

X12_DECLSPEC HRESULT  x12FactoryCreateSwapChainForHwnd                    (X12Factory4 * pFactory, X12CommandQueue * pCommandQueue, void * hWnd, const DXGI_SWAP_CHAIN_DESC1 * pDesc, const DXGI_SWAP_CHAIN_FULLSCREEN_DESC * pFullscreenDesc, X12Output4 * pRestrictToOutput, X12SwapChain3 ** outpSwapChain, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12FactoryCreateSwapChainForCoreWindow              (X12Factory4 * pFactory, X12CommandQueue * pCommandQueue, const void * pWindow, const DXGI_SWAP_CHAIN_DESC1 * pDesc, X12Output4 * pRestrictToOutput, X12SwapChain3 ** outpSwapChain, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12FactoryCreateSwapChainForComposition             (X12Factory4 * pFactory, X12CommandQueue * pCommandQueue, const DXGI_SWAP_CHAIN_DESC1 * pDesc, X12Output4 * pRestrictToOutput, X12SwapChain3 ** outpSwapChain, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12FactoryMakeWindowAssociation                     (X12Factory4 * pFactory, void * WindowHandle, DXGI_MWA_FLAGS Flags, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12FactoryGetWindowAssociation                      (X12Factory4 * pFactory, void ** outWindowHandle, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12FactoryRegisterOcclusionStatusWindow             (X12Factory4 * pFactory, void * WindowHandle, unsigned wMsg, unsigned * pdwCookie, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12FactoryRegisterOcclusionStatusEvent              (X12Factory4 * pFactory, void * hEvent, unsigned * pdwCookie, const char * optionalFile, int optionalLine);
X12_DECLSPEC void     x12FactoryUnregisterOcclusionStatus                 (X12Factory4 * pFactory, unsigned dwCookie, const char * optionalFile, int optionalLine);

// Swap chain

X12_DECLSPEC HRESULT  x12SwapChainGetBuffer                               (X12SwapChain3 * pSwapChain, unsigned Buffer, X12Resource ** outpSurface, const char * optionalFile, int optionalLine);
X12_DECLSPEC unsigned x12SwapChainGetCurrentBackBufferIndex               (X12SwapChain3 * pSwapChain, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SwapChainPresent1                                (X12SwapChain3 * pSwapChain, unsigned SyncInterval, DXGI_PRESENT_FLAGS PresentFlags, const DXGI_PRESENT_PARAMETERS * pPresentParameters, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SwapChainResizeTarget                            (X12SwapChain3 * pSwapChain, const DXGI_MODE_DESC * pNewTargetParameters, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SwapChainResizeBuffers1                          (X12SwapChain3 * pSwapChain, unsigned BufferCount, unsigned Width, unsigned Height, DXGI_FORMAT Format, unsigned SwapChainFlags, const unsigned * pCreationNodeMask, const X12CommandQueue ** ppPresentQueue, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SwapChainSetFullscreenState                      (X12SwapChain3 * pSwapChain, X12Bool Fullscreen, X12Output4 * pTarget, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SwapChainGetFullscreenDesc                       (X12SwapChain3 * pSwapChain, DXGI_SWAP_CHAIN_FULLSCREEN_DESC * outDesc, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SwapChainGetLastPresentCount                     (X12SwapChain3 * pSwapChain, unsigned * outLastPresentCount, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SwapChainGetFrameStatistics                      (X12SwapChain3 * pSwapChain, DXGI_FRAME_STATISTICS * outStats, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SwapChainSetBackgroundColor                      (X12SwapChain3 * pSwapChain, const DXGI_RGBA * pColor, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SwapChainGetBackgroundColor                      (X12SwapChain3 * pSwapChain, DXGI_RGBA * outColor, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SwapChainSetRotation                             (X12SwapChain3 * pSwapChain, DXGI_MODE_ROTATION Rotation, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SwapChainGetRotation                             (X12SwapChain3 * pSwapChain, DXGI_MODE_ROTATION * outRotation, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SwapChainSetSourceSize                           (X12SwapChain3 * pSwapChain, unsigned Width, unsigned Height, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SwapChainGetSourceSize                           (X12SwapChain3 * pSwapChain, unsigned * outWidth, unsigned * outHeight, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SwapChainSetMaximumFrameLatency                  (X12SwapChain3 * pSwapChain, unsigned MaxLatency, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SwapChainGetMaximumFrameLatency                  (X12SwapChain3 * pSwapChain, unsigned * outMaxLatency, const char * optionalFile, int optionalLine);
X12_DECLSPEC void *   x12SwapChainGetFrameLatencyWaitableObject           (X12SwapChain3 * pSwapChain, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SwapChainSetMatrixTransform                      (X12SwapChain3 * pSwapChain, const DXGI_MATRIX_3X2_F * pMatrix, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SwapChainGetMatrixTransform                      (X12SwapChain3 * pSwapChain, DXGI_MATRIX_3X2_F * outMatrix, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SwapChainCheckColorSpaceSupport                  (X12SwapChain3 * pSwapChain, DXGI_COLOR_SPACE_TYPE ColorSpace, DXGI_SWAP_CHAIN_COLOR_SPACE_SUPPORT_FLAGS * outColorSpaceSupport, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12SwapChainSetColorSpace1                          (X12SwapChain3 * pSwapChain, DXGI_COLOR_SPACE_TYPE ColorSpace, const char * optionalFile, int optionalLine);

// Output

X12_DECLSPEC HRESULT  x12OutputGetDesc                                    (X12Output4 * pOutput, DXGI_OUTPUT_DESC * outDesc, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12OutputGetDisplayModeList1                        (X12Output4 * pOutput, DXGI_FORMAT EnumFormat, DXGI_ENUM_MODES_FLAGS Flags, unsigned * pNumModes, DXGI_MODE_DESC1 * outDesc, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12OutputFindClosestMatchingMode1                   (X12Output4 * pOutput, const DXGI_MODE_DESC1 * pModeToMatch, DXGI_MODE_DESC1 * pClosestMatch, X12Device3 * pConcernedDevice, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12OutputWaitForVBlank                              (X12Output4 * pOutput, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12OutputGetGammaControlCapabilities                (X12Output4 * pOutput, DXGI_GAMMA_CONTROL_CAPABILITIES * outGammaCaps, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12OutputSetGammaControl                            (X12Output4 * pOutput, const DXGI_GAMMA_CONTROL * pArray, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12OutputGetGammaControl                            (X12Output4 * pOutput, DXGI_GAMMA_CONTROL * outArray, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12OutputGetFrameStatistics                         (X12Output4 * pOutput, DXGI_FRAME_STATISTICS * outStats, const char * optionalFile, int optionalLine);
X12_DECLSPEC X12Bool  x12OutputSupportsOverlays                           (X12Output4 * pOutput, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12OutputCheckOverlaySupport                        (X12Output4 * pOutput, DXGI_FORMAT EnumFormat, X12Device3 * pConcernedDevice, unsigned * pFlags, const char * optionalFile, int optionalLine);
X12_DECLSPEC HRESULT  x12OutputCheckOverlayColorSpaceSupport              (X12Output4 * pOutput, DXGI_FORMAT Format, DXGI_COLOR_SPACE_TYPE ColorSpace, X12Device3 * pConcernedDevice, DXGI_OVERLAY_COLOR_SPACE_SUPPORT_FLAGS * outFlags, const char * optionalFile, int optionalLine);

// Other

X12_DECLSPEC HRESULT  x12ObjectSetName                                    (void * handle, const wchar_t * Name, const char * optionalFile, int optionalLine);
X12_DECLSPEC void     x12Release                                          (void * handle, const char * optionalFile, int optionalLine);

// PIX

X12_DECLSPEC void     x12CommandListSetMarker                             (X12CommandList * handle, unsigned Metadata, const void * pData, unsigned Size);
X12_DECLSPEC void     x12CommandListBeginEvent                            (X12CommandList * handle, unsigned Metadata, const void * pData, unsigned Size);
X12_DECLSPEC void     x12CommandListEndEvent                              (X12CommandList * handle);
X12_DECLSPEC void     x12CommandQueueSetMarker                            (X12CommandQueue * handle, unsigned Metadata, const void * pData, unsigned Size);
X12_DECLSPEC void     x12CommandQueueBeginEvent                           (X12CommandQueue * handle, unsigned Metadata, const void * pData, unsigned Size);
X12_DECLSPEC void     x12CommandQueueEndEvent                             (X12CommandQueue * handle);

#ifdef __cplusplus
}
#endif
