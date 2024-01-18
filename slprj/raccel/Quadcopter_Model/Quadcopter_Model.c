#include "rt_logging_mmi.h"
#include "Quadcopter_Model_capi.h"
#include <math.h>
#include "Quadcopter_Model.h"
#include "Quadcopter_Model_private.h"
#include "Quadcopter_Model_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 1 , & stopRequested ) ; }
rtExtModeShutdown ( 1 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "9.5 (R2021a) 14-Nov-2020" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes ( SimStruct
* S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void MdlInitialize ( void ) { rtX . mmuyaxdd34 [ 0 ] = rtP .
Integrator1_IC [ 0 ] ; rtX . mmuyaxdd34 [ 1 ] = rtP . Integrator1_IC [ 1 ] ;
rtX . mmuyaxdd34 [ 2 ] = rtP . Integrator1_IC [ 2 ] ; memcpy ( & rtX .
iuqbuhyal2 [ 0 ] , & rtP . y_init_conds [ 0 ] , 9U * sizeof ( real_T ) ) ; }
void MdlStart ( void ) { { bool externalInputIsInDatasetFormat = false ; void
* pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { int_T dimensions [ 2 ] = { 1 , 3 } ; rtDW . lczzojgca3 . LoggedData =
rt_CreateLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal
( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) , "pos" , SS_DOUBLE , 0 , 0 ,
1 , 3 , 2 , dimensions , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.0 ,
1 ) ; if ( rtDW . lczzojgca3 . LoggedData == ( NULL ) ) return ; } { int_T
dimensions [ 2 ] = { 1 , 9 } ; rtDW . njydrcv00u . LoggedData =
rt_CreateLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal
( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) , "velocities" , SS_DOUBLE , 0
, 0 , 1 , 9 , 2 , dimensions , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 ,
0.0 , 1 ) ; if ( rtDW . njydrcv00u . LoggedData == ( NULL ) ) return ; } {
int_T dimensions [ 2 ] = { 1 , 8 } ; rtDW . bkvsjieb3h . LoggedData =
rt_CreateLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal
( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) , "external_forces" ,
SS_DOUBLE , 0 , 0 , 1 , 8 , 2 , dimensions , NO_LOGVALDIMS , ( NULL ) , (
NULL ) , 0 , 1 , 0.0 , 1 ) ; if ( rtDW . bkvsjieb3h . LoggedData == ( NULL )
) return ; } MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T ft1
; real_T ft2 ; real_T ft3 ; real_T ft4 ; real_T tauD1 ; real_T tauD2 ; real_T
tauD3 ; real_T tauD4 ; rtB . b3b23sjygs [ 0 ] = rtX . mmuyaxdd34 [ 0 ] ; rtB
. b3b23sjygs [ 1 ] = rtX . mmuyaxdd34 [ 1 ] ; rtB . b3b23sjygs [ 2 ] = rtX .
mmuyaxdd34 [ 2 ] ; if ( ssGetLogOutput ( rtS ) ) { { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateLogVar ( ( LogVar * ) ( LogVar * ) ( rtDW . lczzojgca3
. LoggedData ) , & rtB . b3b23sjygs [ 0 ] , 0 ) ; } } } memcpy ( & rtB .
g3fdfwhbpo [ 0 ] , & rtX . iuqbuhyal2 [ 0 ] , 9U * sizeof ( real_T ) ) ; if (
ssGetLogOutput ( rtS ) ) { { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
if ( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS )
-> mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateLogVar ( ( LogVar * ) (
LogVar * ) ( rtDW . njydrcv00u . LoggedData ) , & rtB . g3fdfwhbpo [ 0 ] , 0
) ; } } } rtB . haoalcfic5 = rtP . h_des - rtB . b3b23sjygs [ 2 ] ; rtB .
hngr4i3plv = rtP . K_z * rtB . haoalcfic5 ; rtB . jbrsjob422 [ 0 ] = rtB .
hngr4i3plv ; rtB . jbrsjob422 [ 1 ] = rtB . hngr4i3plv ; rtB . jbrsjob422 [ 2
] = rtB . hngr4i3plv ; rtB . jbrsjob422 [ 3 ] = rtB . hngr4i3plv ; ft1 = rtP
. quad_data [ 6 ] * rtP . quad_data [ 8 ] * ( rtB . jbrsjob422 [ 0 ] * rtB .
jbrsjob422 [ 0 ] ) ; ft2 = rtP . quad_data [ 6 ] * rtP . quad_data [ 8 ] * (
rtB . jbrsjob422 [ 1 ] * rtB . jbrsjob422 [ 1 ] ) ; ft3 = rtP . quad_data [ 6
] * rtP . quad_data [ 8 ] * ( rtB . jbrsjob422 [ 2 ] * rtB . jbrsjob422 [ 2 ]
) ; ft4 = rtP . quad_data [ 6 ] * rtP . quad_data [ 8 ] * ( rtB . jbrsjob422
[ 3 ] * rtB . jbrsjob422 [ 3 ] ) ; tauD1 = rtP . quad_data [ 7 ] * rtP .
quad_data [ 8 ] * ( rtB . jbrsjob422 [ 0 ] * rtB . jbrsjob422 [ 0 ] ) ; tauD2
= - rtP . quad_data [ 8 ] * rtP . quad_data [ 7 ] * ( rtB . jbrsjob422 [ 1 ]
* rtB . jbrsjob422 [ 1 ] ) ; tauD3 = rtP . quad_data [ 7 ] * rtP . quad_data
[ 8 ] * ( rtB . jbrsjob422 [ 2 ] * rtB . jbrsjob422 [ 2 ] ) ; tauD4 = - rtP .
quad_data [ 8 ] * rtP . quad_data [ 7 ] * ( rtB . jbrsjob422 [ 3 ] * rtB .
jbrsjob422 [ 3 ] ) ; rtB . gjf5pnkv0b [ 0 ] = ( rtB . g3fdfwhbpo [ 1 ] * rtB
. g3fdfwhbpo [ 5 ] - rtB . g3fdfwhbpo [ 2 ] * rtB . g3fdfwhbpo [ 4 ] ) +
muDoubleScalarSin ( rtB . g3fdfwhbpo [ 7 ] ) * rtP . quad_data [ 0 ] ; rtB .
gjf5pnkv0b [ 1 ] = ( - rtB . g3fdfwhbpo [ 5 ] * rtB . g3fdfwhbpo [ 0 ] + rtB
. g3fdfwhbpo [ 2 ] * rtB . g3fdfwhbpo [ 3 ] ) - muDoubleScalarCos ( rtB .
g3fdfwhbpo [ 7 ] ) * muDoubleScalarSin ( rtB . g3fdfwhbpo [ 6 ] ) * rtP .
quad_data [ 0 ] ; rtB . gjf5pnkv0b [ 2 ] = ( ( ( ft1 + ft2 ) + ft3 ) + ft4 )
/ rtP . quad_data [ 1 ] + ( ( - rtB . g3fdfwhbpo [ 3 ] * rtB . g3fdfwhbpo [ 1
] + rtB . g3fdfwhbpo [ 0 ] * rtB . g3fdfwhbpo [ 4 ] ) + muDoubleScalarCos (
rtB . g3fdfwhbpo [ 6 ] ) * muDoubleScalarCos ( rtB . g3fdfwhbpo [ 7 ] ) * rtP
. quad_data [ 0 ] ) ; rtB . gjf5pnkv0b [ 3 ] = rtB . g3fdfwhbpo [ 4 ] * rtB .
g3fdfwhbpo [ 5 ] * ( rtP . quad_data [ 3 ] - rtP . quad_data [ 4 ] ) / rtP .
quad_data [ 2 ] - ( ft2 - ft4 ) * rtP . quad_data [ 5 ] / rtP . quad_data [ 2
] ; rtB . gjf5pnkv0b [ 4 ] = - rtB . g3fdfwhbpo [ 5 ] * rtB . g3fdfwhbpo [ 3
] * ( rtP . quad_data [ 2 ] - rtP . quad_data [ 4 ] ) / rtP . quad_data [ 3 ]
- ( ft1 - ft3 ) * rtP . quad_data [ 5 ] / rtP . quad_data [ 3 ] ; rtB .
gjf5pnkv0b [ 5 ] = ( ( ( tauD1 + tauD2 ) + tauD3 ) + tauD4 ) / rtP .
quad_data [ 4 ] + rtB . g3fdfwhbpo [ 3 ] * rtB . g3fdfwhbpo [ 4 ] * ( rtP .
quad_data [ 2 ] - rtP . quad_data [ 3 ] ) / rtP . quad_data [ 4 ] ; rtB .
gjf5pnkv0b [ 6 ] = ( - rtB . g3fdfwhbpo [ 3 ] - muDoubleScalarSin ( rtB .
g3fdfwhbpo [ 7 ] ) * muDoubleScalarSin ( rtB . g3fdfwhbpo [ 6 ] ) /
muDoubleScalarCos ( rtB . g3fdfwhbpo [ 7 ] ) * rtB . g3fdfwhbpo [ 4 ] ) -
muDoubleScalarSin ( rtB . g3fdfwhbpo [ 7 ] ) * muDoubleScalarCos ( rtB .
g3fdfwhbpo [ 6 ] ) / muDoubleScalarCos ( rtB . g3fdfwhbpo [ 7 ] ) * rtB .
g3fdfwhbpo [ 5 ] ; rtB . gjf5pnkv0b [ 7 ] = - muDoubleScalarCos ( rtB .
g3fdfwhbpo [ 6 ] ) * rtB . g3fdfwhbpo [ 4 ] + muDoubleScalarSin ( rtB .
g3fdfwhbpo [ 6 ] ) * rtB . g3fdfwhbpo [ 5 ] ; rtB . gjf5pnkv0b [ 8 ] = -
muDoubleScalarSin ( rtB . g3fdfwhbpo [ 6 ] ) / muDoubleScalarCos ( rtB .
g3fdfwhbpo [ 7 ] ) * rtB . g3fdfwhbpo [ 4 ] - muDoubleScalarCos ( rtB .
g3fdfwhbpo [ 6 ] ) / muDoubleScalarCos ( rtB . g3fdfwhbpo [ 7 ] ) * rtB .
g3fdfwhbpo [ 5 ] ; rtB . pemdbh0ohw [ 0 ] = ft1 ; rtB . pemdbh0ohw [ 1 ] =
ft2 ; rtB . pemdbh0ohw [ 2 ] = ft3 ; rtB . pemdbh0ohw [ 3 ] = ft4 ; rtB .
pemdbh0ohw [ 4 ] = tauD1 ; rtB . pemdbh0ohw [ 5 ] = tauD2 ; rtB . pemdbh0ohw
[ 6 ] = tauD3 ; rtB . pemdbh0ohw [ 7 ] = tauD4 ; if ( ssGetLogOutput ( rtS )
) { { double locTime = ssGetTaskTime ( rtS , 0 ) ; ; if (
rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS ) ->
mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateLogVar ( ( LogVar * ) (
LogVar * ) ( rtDW . bkvsjieb3h . LoggedData ) , & rtB . pemdbh0ohw [ 0 ] , 0
) ; } } } rtB . mbn1xq5mss [ 0 ] = ( ( muDoubleScalarSin ( rtB . g3fdfwhbpo [
6 ] ) * rtB . g3fdfwhbpo [ 1 ] + rtB . g3fdfwhbpo [ 2 ] * muDoubleScalarCos (
rtB . g3fdfwhbpo [ 6 ] ) ) * muDoubleScalarSin ( rtB . g3fdfwhbpo [ 7 ] ) +
muDoubleScalarCos ( rtB . g3fdfwhbpo [ 7 ] ) * rtB . g3fdfwhbpo [ 0 ] ) *
muDoubleScalarCos ( rtB . g3fdfwhbpo [ 8 ] ) + ( muDoubleScalarSin ( rtB .
g3fdfwhbpo [ 6 ] ) * rtB . g3fdfwhbpo [ 2 ] - rtB . g3fdfwhbpo [ 1 ] *
muDoubleScalarCos ( rtB . g3fdfwhbpo [ 6 ] ) ) * muDoubleScalarSin ( rtB .
g3fdfwhbpo [ 8 ] ) ; rtB . mbn1xq5mss [ 1 ] = ( ( muDoubleScalarSin ( rtB .
g3fdfwhbpo [ 6 ] ) * rtB . g3fdfwhbpo [ 1 ] + rtB . g3fdfwhbpo [ 2 ] *
muDoubleScalarCos ( rtB . g3fdfwhbpo [ 6 ] ) ) * muDoubleScalarSin ( rtB .
g3fdfwhbpo [ 7 ] ) + muDoubleScalarCos ( rtB . g3fdfwhbpo [ 7 ] ) * rtB .
g3fdfwhbpo [ 0 ] ) * muDoubleScalarSin ( rtB . g3fdfwhbpo [ 8 ] ) - (
muDoubleScalarSin ( rtB . g3fdfwhbpo [ 6 ] ) * rtB . g3fdfwhbpo [ 2 ] - rtB .
g3fdfwhbpo [ 1 ] * muDoubleScalarCos ( rtB . g3fdfwhbpo [ 6 ] ) ) *
muDoubleScalarCos ( rtB . g3fdfwhbpo [ 8 ] ) ; rtB . mbn1xq5mss [ 2 ] = ( rtB
. g3fdfwhbpo [ 2 ] * muDoubleScalarCos ( rtB . g3fdfwhbpo [ 7 ] ) *
muDoubleScalarCos ( rtB . g3fdfwhbpo [ 6 ] ) + rtB . g3fdfwhbpo [ 1 ] *
muDoubleScalarCos ( rtB . g3fdfwhbpo [ 7 ] ) * muDoubleScalarSin ( rtB .
g3fdfwhbpo [ 6 ] ) ) - rtB . g3fdfwhbpo [ 0 ] * muDoubleScalarSin ( rtB .
g3fdfwhbpo [ 7 ] ) ; UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID1 ( int_T
tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID1 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> mmuyaxdd34 [ 0 ] = rtB
. mbn1xq5mss [ 0 ] ; _rtXdot -> mmuyaxdd34 [ 1 ] = rtB . mbn1xq5mss [ 1 ] ;
_rtXdot -> mmuyaxdd34 [ 2 ] = rtB . mbn1xq5mss [ 2 ] ; memcpy ( & _rtXdot ->
iuqbuhyal2 [ 0 ] , & rtB . gjf5pnkv0b [ 0 ] , 9U * sizeof ( real_T ) ) ; }
void MdlProjection ( void ) { } void MdlTerminate ( void ) { } static void
mr_Quadcopter_Model_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) ; static void
mr_Quadcopter_Model_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_Quadcopter_Model_restoreDataFromMxArray ( void * destData
, const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_Quadcopter_Model_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_Quadcopter_Model_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i
, int j , uint_T bitVal ) ; static void
mr_Quadcopter_Model_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i
, int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_Quadcopter_Model_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_Quadcopter_Model_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_Quadcopter_Model_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
; static void mr_Quadcopter_Model_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_Quadcopter_Model_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void mr_Quadcopter_Model_restoreDataFromMxArrayWithOffset
( void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex
offset , size_t numBytes ) { const uint8_T * varData = ( const uint8_T * )
mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T *
) destData , ( const uint8_T * ) & varData [ offset * numBytes ] , numBytes )
; } static void mr_Quadcopter_Model_cacheBitFieldToCellArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal )
; static void mr_Quadcopter_Model_cacheBitFieldToCellArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal )
{ mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( double ) fieldVal ) ) ; } static uint_T
mr_Quadcopter_Model_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_Quadcopter_Model_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_Quadcopter_Model_GetDWork ( ) {
static const char * ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX"
, } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_Quadcopter_Model_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & (
rtB ) , sizeof ( rtB ) ) ; return ssDW ; } void mr_Quadcopter_Model_SetDWork
( const mxArray * ssDW ) { ( void ) ssDW ;
mr_Quadcopter_Model_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0
, 0 , sizeof ( rtB ) ) ; } mxArray *
mr_Quadcopter_Model_GetSimStateDisallowedBlocks ( ) { return NULL ; } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 12 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
1 ) ; ssSetNumBlocks ( rtS , 14 ) ; ssSetNumBlockIO ( rtS , 8 ) ;
ssSetNumBlockParams ( rtS , 23 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 1106205740U ) ;
ssSetChecksumVal ( rtS , 1 , 3753947802U ) ; ssSetChecksumVal ( rtS , 2 ,
34558403U ) ; ssSetChecksumVal ( rtS , 3 , 3514518916U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; ( void ) memset ( ( char * ) rtS , 0 ,
sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0 , sizeof
( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ;
ssSetExecutionInfo ( rtS , executionInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
Quadcopter_Model_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive (
rtS , true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "Quadcopter_Model" ) ;
ssSetPath ( rtS , "Quadcopter_Model" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 2.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 3 , 9
} ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 3 , 9 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) } ; static
const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" } ; static
const char_T * rt_LoggedStateBlockNames [ ] = {
"Quadcopter_Model/Integrator1" , "Quadcopter_Model/Integrator" } ; static
const char_T * rt_LoggedStateNames [ ] = { "" , "" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } }
; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 2 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 2 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . mmuyaxdd34 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . iuqbuhyal2 [ 0 ] ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 12 ] ;
static real_T absTol [ 12 ] = { 1.0E-5 , 1.0E-5 , 1.0E-5 , 1.0E-5 , 1.0E-5 ,
1.0E-5 , 1.0E-5 , 1.0E-5 , 1.0E-5 , 1.0E-5 , 1.0E-5 , 1.0E-5 } ; static
uint8_T absTolControl [ 12 ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U } ; static real_T contStateJacPerturbBoundMinVec [ 12 ] ; static
real_T contStateJacPerturbBoundMaxVec [ 12 ] ; { int i ; for ( i = 0 ; i < 12
; ++ i ) { contStateJacPerturbBoundMinVec [ i ] = 0 ;
contStateJacPerturbBoundMaxVec [ i ] = rtGetInf ( ) ; } } ssSetSolverRelTol (
rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 )
; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 0.04 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
0 ) ; ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS ,
& slvrInfo ) ; ssSetSolverName ( rtS , "VariableStepAuto" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol )
; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 1106205740U ) ; ssSetChecksumVal ( rtS , 1 ,
3753947802U ) ; ssSetChecksumVal ( rtS , 2 , 34558403U ) ; ssSetChecksumVal (
rtS , 3 , 3514518916U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 3 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; }
slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_Quadcopter_Model_GetSimStateDisallowedBlocks ) ;
slsaGetWorkFcnForSimTargetOP ( rtS , mr_Quadcopter_Model_GetDWork ) ;
slsaSetWorkFcnForSimTargetOP ( rtS , mr_Quadcopter_Model_SetDWork ) ;
rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if ( ssGetErrorStatus ( rtS ) )
{ return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 1 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID1 ( tid ) ; }
