#ifndef RTW_HEADER_Quadcopter_Model_h_
#define RTW_HEADER_Quadcopter_Model_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#ifndef Quadcopter_Model_COMMON_INCLUDES_
#define Quadcopter_Model_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "Quadcopter_Model_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME Quadcopter_Model
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (8) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (12)   
#elif NCSTATES != 12
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T b3b23sjygs [ 3 ] ; real_T g3fdfwhbpo [ 9 ] ; real_T
haoalcfic5 ; real_T hngr4i3plv ; real_T jbrsjob422 [ 4 ] ; real_T gjf5pnkv0b
[ 9 ] ; real_T pemdbh0ohw [ 8 ] ; real_T mbn1xq5mss [ 3 ] ; } B ; typedef
struct { struct { void * LoggedData ; } lczzojgca3 ; struct { void *
LoggedData ; } njydrcv00u ; struct { void * LoggedData ; } bkvsjieb3h ; } DW
; typedef struct { real_T mmuyaxdd34 [ 3 ] ; real_T iuqbuhyal2 [ 9 ] ; } X ;
typedef struct { real_T mmuyaxdd34 [ 3 ] ; real_T iuqbuhyal2 [ 9 ] ; } XDot ;
typedef struct { boolean_T mmuyaxdd34 [ 3 ] ; boolean_T iuqbuhyal2 [ 9 ] ; }
XDis ; typedef struct { real_T mmuyaxdd34 [ 3 ] ; real_T iuqbuhyal2 [ 9 ] ; }
CStateAbsTol ; typedef struct { real_T mmuyaxdd34 [ 3 ] ; real_T iuqbuhyal2 [
9 ] ; } CXPtMin ; typedef struct { real_T mmuyaxdd34 [ 3 ] ; real_T
iuqbuhyal2 [ 9 ] ; } CXPtMax ; typedef struct { rtwCAPI_ModelMappingInfo mmi
; } DataMapInfo ; struct P_ { real_T K_z ; real_T h_des ; real_T quad_data [
9 ] ; real_T y_init_conds [ 9 ] ; real_T Integrator1_IC [ 3 ] ; } ; extern
const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ;
extern DW rtDW ; extern P rtP ; extern mxArray * mr_Quadcopter_Model_GetDWork
( ) ; extern void mr_Quadcopter_Model_SetDWork ( const mxArray * ssDW ) ;
extern mxArray * mr_Quadcopter_Model_GetSimStateDisallowedBlocks ( ) ; extern
const rtwCAPI_ModelMappingStaticInfo * Quadcopter_Model_GetCAPIStaticMap (
void ) ; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ;
extern const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; extern const int_T gblNumRootInportBlks ; extern const
int_T gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ;
extern const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [
] ; extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
