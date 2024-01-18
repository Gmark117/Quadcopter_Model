#include "rt_logging_mmi.h"
#include "quadcopter_model_capi.h"
#include <math.h>
#include "quadcopter_model.h"
#include "quadcopter_model_private.h"
#include "quadcopter_model_dt.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 1 , & stopRequested ) ; }
rtExtModeShutdown ( 1 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "9.4 (R2020b) 29-Jul-2020" ; void
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
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; } B rtB
; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; void MdlInitialize ( void ) { rtX . gth4lhpyvz [ 0 ] = rtP .
Integrator1_IC [ 0 ] ; rtX . gth4lhpyvz [ 1 ] = rtP . Integrator1_IC [ 1 ] ;
rtX . gth4lhpyvz [ 2 ] = rtP . Integrator1_IC [ 2 ] ; memcpy ( & rtX .
ovlbff2b0r [ 0 ] , & rtP . y_init_conds [ 0 ] , 9U * sizeof ( real_T ) ) ; }
void MdlStart ( void ) { { bool externalInputIsInDatasetFormat = false ; void
* pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { static int_T rt_ToWksWidths [ ] = { 3 } ; static int_T
rt_ToWksNumDimensions [ ] = { 2 } ; static int_T rt_ToWksDimensions [ ] = { 1
, 3 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) , ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 , 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
"quadcopter_model/To Workspace" ; rtDW . gvmdm3s2n1 . LoggedData =
rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) ,
ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) , "pos" , 1 , 0 ,
1 , 0.0 , & rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . gvmdm3s2n1
. LoggedData == ( NULL ) ) return ; ssCachePointer ( rtS , & ( rtDW .
gvmdm3s2n1 . LoggedData ) ) ; } { static int_T rt_ToWksWidths [ ] = { 9 } ;
static int_T rt_ToWksNumDimensions [ ] = { 2 } ; static int_T
rt_ToWksDimensions [ ] = { 1 , 9 } ; static boolean_T rt_ToWksIsVarDims [ ] =
{ 0 } ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) , ( NULL ) } ;
static int_T rt_ToWksCurrSigDimsSize [ ] = { 4 , 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
"quadcopter_model/To Workspace1" ; rtDW . ccuaj3d1in . LoggedData =
rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) ,
ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) , "velocities" , 1
, 0 , 1 , 0.0 , & rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW .
ccuaj3d1in . LoggedData == ( NULL ) ) return ; ssCachePointer ( rtS , & (
rtDW . ccuaj3d1in . LoggedData ) ) ; } { static int_T rt_ToWksWidths [ ] = {
8 } ; static int_T rt_ToWksNumDimensions [ ] = { 2 } ; static int_T
rt_ToWksDimensions [ ] = { 1 , 8 } ; static boolean_T rt_ToWksIsVarDims [ ] =
{ 0 } ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) , ( NULL ) } ;
static int_T rt_ToWksCurrSigDimsSize [ ] = { 4 , 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
"quadcopter_model/To Workspace2" ; rtDW . gcdxafgp2r . LoggedData =
rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) ,
ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) ,
"externat_forces" , 1 , 0 , 1 , 0.0 , & rt_ToWksSignalInfo ,
rt_ToWksBlockName ) ; if ( rtDW . gcdxafgp2r . LoggedData == ( NULL ) )
return ; ssCachePointer ( rtS , & ( rtDW . gcdxafgp2r . LoggedData ) ) ; }
MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T ft1 ; real_T ft2
; real_T ft3 ; real_T ft4 ; real_T tauD1 ; real_T tauD2 ; real_T tauD3 ;
real_T tauD4 ; rtB . kxute4dok2 [ 0 ] = rtX . gth4lhpyvz [ 0 ] ; rtB .
kxute4dok2 [ 1 ] = rtX . gth4lhpyvz [ 1 ] ; rtB . kxute4dok2 [ 2 ] = rtX .
gth4lhpyvz [ 2 ] ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ; if (
ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . gvmdm3s2n1 .
LoggedData , & locTime , & rtB . kxute4dok2 [ 0 ] ) ; } } } } memcpy ( & rtB
. cnvn12114y [ 0 ] , & rtX . ovlbff2b0r [ 0 ] , 9U * sizeof ( real_T ) ) ; {
double locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) )
{ { if ( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS (
rtS ) -> mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . ccuaj3d1in . LoggedData , & locTime , & rtB .
cnvn12114y [ 0 ] ) ; } } } } rtB . cl2xjd5eqd = rtP . h_des - rtB .
kxute4dok2 [ 2 ] ; rtB . gd2vivdw2i = rtP . K_z * rtB . cl2xjd5eqd ; rtB .
iqe5l0qubf [ 0 ] = rtB . gd2vivdw2i ; rtB . iqe5l0qubf [ 1 ] = rtB .
gd2vivdw2i ; rtB . iqe5l0qubf [ 2 ] = rtB . gd2vivdw2i ; rtB . iqe5l0qubf [ 3
] = rtB . gd2vivdw2i ; ft1 = rtP . quad_data [ 8 ] * rtP . quad_data [ 6 ] *
( rtB . iqe5l0qubf [ 0 ] * rtB . iqe5l0qubf [ 0 ] ) ; ft2 = rtP . quad_data [
8 ] * rtP . quad_data [ 6 ] * ( rtB . iqe5l0qubf [ 1 ] * rtB . iqe5l0qubf [ 1
] ) ; ft3 = rtP . quad_data [ 8 ] * rtP . quad_data [ 6 ] * ( rtB .
iqe5l0qubf [ 2 ] * rtB . iqe5l0qubf [ 2 ] ) ; ft4 = rtP . quad_data [ 8 ] *
rtP . quad_data [ 6 ] * ( rtB . iqe5l0qubf [ 3 ] * rtB . iqe5l0qubf [ 3 ] ) ;
tauD1 = rtP . quad_data [ 8 ] * rtP . quad_data [ 7 ] * ( rtB . iqe5l0qubf [
0 ] * rtB . iqe5l0qubf [ 0 ] ) ; tauD2 = - rtP . quad_data [ 8 ] * rtP .
quad_data [ 7 ] * ( rtB . iqe5l0qubf [ 1 ] * rtB . iqe5l0qubf [ 1 ] ) ; tauD3
= rtP . quad_data [ 8 ] * rtP . quad_data [ 7 ] * ( rtB . iqe5l0qubf [ 2 ] *
rtB . iqe5l0qubf [ 2 ] ) ; tauD4 = - rtP . quad_data [ 8 ] * rtP . quad_data
[ 7 ] * ( rtB . iqe5l0qubf [ 3 ] * rtB . iqe5l0qubf [ 3 ] ) ; rtB .
opmcsbpyyp [ 0 ] = ( rtB . cnvn12114y [ 5 ] * rtB . cnvn12114y [ 1 ] - rtB .
cnvn12114y [ 4 ] * rtB . cnvn12114y [ 2 ] ) + muDoubleScalarSin ( rtB .
cnvn12114y [ 7 ] ) * rtP . quad_data [ 0 ] ; rtB . opmcsbpyyp [ 1 ] = ( - rtB
. cnvn12114y [ 5 ] * rtB . cnvn12114y [ 0 ] + rtB . cnvn12114y [ 2 ] * rtB .
cnvn12114y [ 3 ] ) - muDoubleScalarCos ( rtB . cnvn12114y [ 7 ] ) *
muDoubleScalarSin ( rtB . cnvn12114y [ 6 ] ) * rtP . quad_data [ 0 ] ; rtB .
opmcsbpyyp [ 2 ] = ( ( ( ft1 + ft2 ) + ft3 ) + ft4 ) / rtP . quad_data [ 1 ]
+ ( ( - rtB . cnvn12114y [ 1 ] * rtB . cnvn12114y [ 3 ] + rtB . cnvn12114y [
0 ] * rtB . cnvn12114y [ 4 ] ) + muDoubleScalarCos ( rtB . cnvn12114y [ 6 ] )
* muDoubleScalarCos ( rtB . cnvn12114y [ 7 ] ) * rtP . quad_data [ 0 ] ) ;
rtB . opmcsbpyyp [ 3 ] = rtB . cnvn12114y [ 5 ] * rtB . cnvn12114y [ 4 ] * (
rtP . quad_data [ 3 ] - rtP . quad_data [ 4 ] ) / rtP . quad_data [ 2 ] - (
ft2 - ft4 ) * rtP . quad_data [ 5 ] / rtP . quad_data [ 2 ] ; rtB .
opmcsbpyyp [ 4 ] = - rtB . cnvn12114y [ 5 ] * rtB . cnvn12114y [ 3 ] * ( rtP
. quad_data [ 2 ] - rtP . quad_data [ 4 ] ) / rtP . quad_data [ 3 ] - ( ft1 -
ft3 ) * rtP . quad_data [ 5 ] / rtP . quad_data [ 3 ] ; rtB . opmcsbpyyp [ 5
] = ( ( ( tauD1 + tauD2 ) + tauD3 ) + tauD4 ) / rtP . quad_data [ 4 ] + rtB .
cnvn12114y [ 4 ] * rtB . cnvn12114y [ 3 ] * ( rtP . quad_data [ 2 ] - rtP .
quad_data [ 3 ] ) / rtP . quad_data [ 4 ] ; rtB . opmcsbpyyp [ 6 ] = ( - rtB
. cnvn12114y [ 3 ] - muDoubleScalarSin ( rtB . cnvn12114y [ 7 ] ) *
muDoubleScalarSin ( rtB . cnvn12114y [ 6 ] ) / muDoubleScalarCos ( rtB .
cnvn12114y [ 7 ] ) * rtB . cnvn12114y [ 4 ] ) - muDoubleScalarSin ( rtB .
cnvn12114y [ 7 ] ) * muDoubleScalarCos ( rtB . cnvn12114y [ 6 ] ) /
muDoubleScalarCos ( rtB . cnvn12114y [ 7 ] ) * rtB . cnvn12114y [ 5 ] ; rtB .
opmcsbpyyp [ 7 ] = - muDoubleScalarCos ( rtB . cnvn12114y [ 6 ] ) * rtB .
cnvn12114y [ 4 ] + muDoubleScalarSin ( rtB . cnvn12114y [ 6 ] ) * rtB .
cnvn12114y [ 5 ] ; rtB . opmcsbpyyp [ 8 ] = - muDoubleScalarSin ( rtB .
cnvn12114y [ 6 ] ) / muDoubleScalarCos ( rtB . cnvn12114y [ 7 ] ) * rtB .
cnvn12114y [ 4 ] - muDoubleScalarCos ( rtB . cnvn12114y [ 6 ] ) /
muDoubleScalarCos ( rtB . cnvn12114y [ 7 ] ) * rtB . cnvn12114y [ 5 ] ; rtB .
dmjl1m4evq [ 0 ] = ft1 ; rtB . dmjl1m4evq [ 1 ] = ft2 ; rtB . dmjl1m4evq [ 2
] = ft3 ; rtB . dmjl1m4evq [ 3 ] = ft4 ; rtB . dmjl1m4evq [ 4 ] = tauD1 ; rtB
. dmjl1m4evq [ 5 ] = tauD2 ; rtB . dmjl1m4evq [ 6 ] = tauD3 ; rtB .
dmjl1m4evq [ 7 ] = tauD4 ; { double locTime = ssGetTaskTime ( rtS , 0 ) ; ;
if ( ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . gcdxafgp2r .
LoggedData , & locTime , & rtB . dmjl1m4evq [ 0 ] ) ; } } } } rtB .
pi4eofv0sv [ 0 ] = ( ( muDoubleScalarSin ( rtB . cnvn12114y [ 6 ] ) * rtB .
cnvn12114y [ 1 ] + rtB . cnvn12114y [ 2 ] * muDoubleScalarCos ( rtB .
cnvn12114y [ 6 ] ) ) * muDoubleScalarSin ( rtB . cnvn12114y [ 7 ] ) +
muDoubleScalarCos ( rtB . cnvn12114y [ 7 ] ) * rtB . cnvn12114y [ 0 ] ) *
muDoubleScalarCos ( rtB . cnvn12114y [ 8 ] ) + ( muDoubleScalarSin ( rtB .
cnvn12114y [ 6 ] ) * rtB . cnvn12114y [ 2 ] - rtB . cnvn12114y [ 1 ] *
muDoubleScalarCos ( rtB . cnvn12114y [ 6 ] ) ) * muDoubleScalarSin ( rtB .
cnvn12114y [ 8 ] ) ; rtB . pi4eofv0sv [ 1 ] = ( ( muDoubleScalarSin ( rtB .
cnvn12114y [ 6 ] ) * rtB . cnvn12114y [ 1 ] + rtB . cnvn12114y [ 2 ] *
muDoubleScalarCos ( rtB . cnvn12114y [ 6 ] ) ) * muDoubleScalarSin ( rtB .
cnvn12114y [ 7 ] ) + muDoubleScalarCos ( rtB . cnvn12114y [ 7 ] ) * rtB .
cnvn12114y [ 0 ] ) * muDoubleScalarSin ( rtB . cnvn12114y [ 8 ] ) - (
muDoubleScalarSin ( rtB . cnvn12114y [ 6 ] ) * rtB . cnvn12114y [ 2 ] - rtB .
cnvn12114y [ 1 ] * muDoubleScalarCos ( rtB . cnvn12114y [ 6 ] ) ) *
muDoubleScalarCos ( rtB . cnvn12114y [ 8 ] ) ; rtB . pi4eofv0sv [ 2 ] = ( rtB
. cnvn12114y [ 2 ] * muDoubleScalarCos ( rtB . cnvn12114y [ 7 ] ) *
muDoubleScalarCos ( rtB . cnvn12114y [ 6 ] ) + rtB . cnvn12114y [ 1 ] *
muDoubleScalarCos ( rtB . cnvn12114y [ 7 ] ) * muDoubleScalarSin ( rtB .
cnvn12114y [ 6 ] ) ) - rtB . cnvn12114y [ 0 ] * muDoubleScalarSin ( rtB .
cnvn12114y [ 7 ] ) ; UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID1 ( int_T
tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID1 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> gth4lhpyvz [ 0 ] = rtB
. pi4eofv0sv [ 0 ] ; _rtXdot -> gth4lhpyvz [ 1 ] = rtB . pi4eofv0sv [ 1 ] ;
_rtXdot -> gth4lhpyvz [ 2 ] = rtB . pi4eofv0sv [ 2 ] ; memcpy ( & _rtXdot ->
ovlbff2b0r [ 0 ] , & rtB . opmcsbpyyp [ 0 ] , 9U * sizeof ( real_T ) ) ; }
void MdlProjection ( void ) { } void MdlTerminate ( void ) { } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 12 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
1 ) ; ssSetNumBlocks ( rtS , 14 ) ; ssSetNumBlockIO ( rtS , 8 ) ;
ssSetNumBlockParams ( rtS , 23 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 1331684444U ) ;
ssSetChecksumVal ( rtS , 1 , 1905909690U ) ; ssSetChecksumVal ( rtS , 2 ,
1892146517U ) ; ssSetChecksumVal ( rtS , 3 , 387458579U ) ; }
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
( ( void * ) & rtB ) ) ; ssSetWorkSizeInBytes ( rtS , sizeof ( rtB ) ,
"BlockIO" ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; }
{ real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void )
memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) &
rtDW ; ssSetRootDWork ( rtS , dwork ) ; ssSetWorkSizeInBytes ( rtS , sizeof (
rtDW ) , "DWork" ) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } {
static DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0
, sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 14 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; }
quadcopter_model_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive (
rtS , true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "quadcopter_model" ) ;
ssSetPath ( rtS , "quadcopter_model" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 10.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 3 , 9
} ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 3 , 9 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) } ; static
const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" } ; static
const char_T * rt_LoggedStateBlockNames [ ] = {
"quadcopter_model/Integrator1" , "quadcopter_model/Integrator" } ; static
const char_T * rt_LoggedStateNames [ ] = { "" , "" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } }
; static RTWLogSignalInfo rt_LoggedStateSignalInfo = { 2 ,
rt_LoggedStateWidths , rt_LoggedStateNumDimensions , rt_LoggedStateDimensions
, rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 2 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . gth4lhpyvz [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . ovlbff2b0r [ 0 ] ; }
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
ssSetMaxStepSize ( rtS , 0.2 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
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
ssSetChecksumVal ( rtS , 0 , 1331684444U ) ; ssSetChecksumVal ( rtS , 1 ,
1905909690U ) ; ssSetChecksumVal ( rtS , 2 , 1892146517U ) ; ssSetChecksumVal
( rtS , 3 , 387458579U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 3 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 1 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID1 ( tid ) ; }
