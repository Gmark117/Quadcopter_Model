#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Quadcopter_Model_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "Quadcopter_Model.h"
#include "Quadcopter_Model_capi.h"
#include "Quadcopter_Model_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 1 , TARGET_STRING (
"Quadcopter_Model/Absolute_pos" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 1 , 2 , TARGET_STRING ( "Quadcopter_Model/Quadcopt-Eqns" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 2 , 2 , TARGET_STRING (
"Quadcopter_Model/Quadcopt-Eqns" ) , TARGET_STRING ( "" ) , 1 , 0 , 2 , 0 , 0
} , { 3 , 0 , TARGET_STRING ( "Quadcopter_Model/Gain" ) , TARGET_STRING ( ""
) , 0 , 0 , 3 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"Quadcopter_Model/Integrator" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 }
, { 5 , 0 , TARGET_STRING ( "Quadcopter_Model/Integrator1" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"Quadcopter_Model/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 0 ,
0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 7 , TARGET_STRING (
"Quadcopter_Model/Integrator1" ) , TARGET_STRING ( "InitialCondition" ) , 0 ,
4 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { - 1 } ; static const rtwCAPI_Signals
rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 , ( NULL ) , (
NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters
rtModelParameters [ ] = { { 8 , TARGET_STRING ( "K_z" ) , 0 , 3 , 0 } , { 9 ,
TARGET_STRING ( "h_des" ) , 0 , 3 , 0 } , { 10 , TARGET_STRING ( "quad_data"
) , 0 , 5 , 0 } , { 11 , TARGET_STRING ( "y_init_conds" ) , 0 , 5 , 0 } , { 0
, ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . mbn1xq5mss [ 0 ] , & rtB .
gjf5pnkv0b [ 0 ] , & rtB . pemdbh0ohw [ 0 ] , & rtB . hngr4i3plv , & rtB .
g3fdfwhbpo [ 0 ] , & rtB . b3b23sjygs [ 0 ] , & rtB . haoalcfic5 , & rtP .
Integrator1_IC [ 0 ] , & rtP . K_z , & rtP . h_des , & rtP . quad_data [ 0 ]
, & rtP . y_init_conds [ 0 ] , } ; static int32_T * rtVarDimsAddrMap [ ] = {
( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_MATRIX_COL_MAJOR , 0 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 2 , 2 ,
0 } , { rtwCAPI_MATRIX_COL_MAJOR , 4 , 2 , 0 } , { rtwCAPI_SCALAR , 6 , 2 , 0
} , { rtwCAPI_VECTOR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } } ;
static const uint_T rtDimensionArray [ ] = { 1 , 3 , 1 , 9 , 1 , 8 , 1 , 1 }
; static const real_T rtcapiStoredFloats [ ] = { 0.0 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 7 ,
rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 1 ,
rtModelParameters , 4 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 1106205740U , 3753947802U , 34558403U , 3514518916U } , ( NULL ) , 0 , 0
, rt_LoggedStateIdxList } ; const rtwCAPI_ModelMappingStaticInfo *
Quadcopter_Model_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void Quadcopter_Model_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( (
* rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Quadcopter_Model_host_InitializeDataMapInfo (
Quadcopter_Model_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
