#include "__cf_synchronous_generator_modeling.h"
#include "rt_logging_mmi.h"
#include "synchronous_generator_modeling_capi.h"
#include <math.h>
#include "synchronous_generator_modeling.h"
#include "synchronous_generator_modeling_private.h"
#include "synchronous_generator_modeling_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "9.1 (R2019a) 23-Nov-2018" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
 "slprj\\raccel\\synchronous_generator_modeling\\synchronous_generator_modeling_Jpattern.mat"
; const int_T gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; extern void * gblAperiodicPartitionHitTimes ; const int_T
gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [ ] = { - 1 }
; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( const char * inportFileName , int *
matFileFormat ) { return rt_RapidReadInportsMatFile ( inportFileName ,
matFileFormat , 1 ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; real_T look1_pbinlxpw ( real_T u0 , const real_T bp0 [ ] , const
real_T table [ ] , uint32_T prevIndex [ ] , uint32_T maxIndex ) { real_T frac
; uint32_T iRght ; uint32_T iLeft ; uint32_T bpIdx ; uint32_T found ; if ( u0
<= bp0 [ 0U ] ) { bpIdx = 0U ; frac = ( u0 - bp0 [ 0U ] ) / ( bp0 [ 1U ] -
bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex ] ) { bpIdx = prevIndex [ 0U ]
; iLeft = 0U ; iRght = maxIndex ; found = 0U ; while ( found == 0U ) { if (
u0 < bp0 [ bpIdx ] ) { iRght = bpIdx - 1U ; bpIdx = ( iRght + iLeft ) >> 1U ;
} else if ( u0 < bp0 [ bpIdx + 1U ] ) { found = 1U ; } else { iLeft = bpIdx +
1U ; bpIdx = ( iRght + iLeft ) >> 1U ; } } frac = ( u0 - bp0 [ bpIdx ] ) / (
bp0 [ bpIdx + 1U ] - bp0 [ bpIdx ] ) ; } else { bpIdx = maxIndex - 1U ; frac
= ( u0 - bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex - 1U ]
) ; } prevIndex [ 0U ] = bpIdx ; return ( table [ bpIdx + 1U ] - table [
bpIdx ] ) * frac + table [ bpIdx ] ; } void rt_invd5x5_snf ( const real_T u [
25 ] , real_T y [ 25 ] ) { int8_T p [ 5 ] ; real_T A [ 25 ] ; int8_T ipiv [ 5
] ; int32_T jj ; int32_T jp1j ; int32_T c ; int32_T ix ; real_T smax ; real_T
s ; int32_T iy ; int32_T jA ; int32_T ijA ; int32_T pipk ; int32_T jBcol ;
for ( iy = 0 ; iy < 25 ; iy ++ ) { y [ iy ] = 0.0 ; A [ iy ] = u [ iy ] ; }
for ( iy = 0 ; iy < 5 ; iy ++ ) { ipiv [ iy ] = ( int8_T ) ( 1 + iy ) ; } for
( pipk = 0 ; pipk < 4 ; pipk ++ ) { jBcol = pipk * 6 + 2 ; jj = pipk * 6 ; c
= 5 - pipk ; iy = 1 ; ix = jBcol - 2 ; smax = muDoubleScalarAbs ( A [ jj ] )
; for ( jA = 2 ; jA <= c ; jA ++ ) { ix ++ ; s = muDoubleScalarAbs ( A [ ix ]
) ; if ( s > smax ) { iy = jA ; smax = s ; } } if ( A [ ( jBcol + iy ) - 3 ]
!= 0.0 ) { if ( iy - 1 != 0 ) { ipiv [ pipk ] = ( int8_T ) ( pipk + iy ) ; ix
= pipk ; iy = ( pipk + iy ) - 1 ; for ( jA = 0 ; jA < 5 ; jA ++ ) { smax = A
[ ix ] ; A [ ix ] = A [ iy ] ; A [ iy ] = smax ; ix += 5 ; iy += 5 ; } } iy =
jBcol - pipk ; for ( ix = jBcol ; ix <= iy + 3 ; ix ++ ) { A [ ix - 1 ] /= A
[ jj ] ; } } c = 3 - pipk ; jA = jj ; jj += 5 ; for ( jp1j = 0 ; jp1j <= c ;
jp1j ++ ) { if ( A [ jj ] != 0.0 ) { smax = - A [ jj ] ; ix = jBcol - 1 ; iy
= jA - pipk ; for ( ijA = jA + 7 ; ijA <= iy + 10 ; ijA ++ ) { A [ ijA - 1 ]
+= A [ ix ] * smax ; ix ++ ; } } jj += 5 ; jA += 5 ; } } for ( iy = 0 ; iy <
5 ; iy ++ ) { p [ iy ] = ( int8_T ) ( 1 + iy ) ; } if ( ipiv [ 0 ] > 1 ) {
pipk = p [ ipiv [ 0 ] - 1 ] ; p [ ipiv [ 0 ] - 1 ] = p [ 0 ] ; p [ 0 ] = (
int8_T ) pipk ; } if ( ipiv [ 1 ] > 2 ) { pipk = p [ ipiv [ 1 ] - 1 ] ; p [
ipiv [ 1 ] - 1 ] = p [ 1 ] ; p [ 1 ] = ( int8_T ) pipk ; } if ( ipiv [ 2 ] >
3 ) { pipk = p [ ipiv [ 2 ] - 1 ] ; p [ ipiv [ 2 ] - 1 ] = p [ 2 ] ; p [ 2 ]
= ( int8_T ) pipk ; } if ( ipiv [ 3 ] > 4 ) { pipk = p [ ipiv [ 3 ] - 1 ] ; p
[ ipiv [ 3 ] - 1 ] = p [ 3 ] ; p [ 3 ] = ( int8_T ) pipk ; } for ( jA = 0 ;
jA < 5 ; jA ++ ) { jBcol = p [ jA ] - 1 ; y [ jA + 5 * ( p [ jA ] - 1 ) ] =
1.0 ; for ( pipk = jA + 1 ; pipk < 6 ; pipk ++ ) { if ( y [ ( 5 * jBcol +
pipk ) - 1 ] != 0.0 ) { for ( ix = pipk + 1 ; ix < 6 ; ix ++ ) { y [ ( ix + 5
* jBcol ) - 1 ] -= A [ ( ( pipk - 1 ) * 5 + ix ) - 1 ] * y [ ( 5 * jBcol +
pipk ) - 1 ] ; } } } } for ( pipk = 0 ; pipk < 5 ; pipk ++ ) { jBcol = 5 *
pipk ; for ( jA = 4 ; jA >= 0 ; jA -- ) { jj = 5 * jA ; if ( y [ jA + jBcol ]
!= 0.0 ) { y [ jA + jBcol ] /= A [ jA + jj ] ; iy = jA - 1 ; for ( ix = 0 ;
ix <= iy ; ix ++ ) { y [ ix + jBcol ] -= y [ jA + jBcol ] * A [ ix + jj ] ; }
} } } } void MdlInitialize ( void ) { int32_T i ; rtX . ecfyjwp3hk = rtP .
Rotorangledtheta_IC ; for ( i = 0 ; i < 5 ; i ++ ) { rtX . ltlvyqyjyu [ i ] =
rtP . Integrator_IC_ae1cznrs4o [ i ] ; } { SimStruct * rts = ssGetSFunction (
rtS , 0 ) ; sfcnInitializeConditions ( rts ) ; if ( ssGetErrorStatus ( rts )
!= ( NULL ) ) return ; } rtX . gclujrpfr4 = rtP . Rotorspeeddeviationdw_IC ;
rtX . kml2oh1yt0 = rtP . StateSpace_InitialCondition ; rtX . kraqf3we4h = rtP
. StateSpace_InitialCondition_fevmgmfoek ; rtX . cqyd2pk3x0 = rtP .
StateSpace_InitialCondition_oqtdddz2en ; rtX . jyzfjmsmba = 0.0 ; rtX .
j5ogc35dcx = rtP . position_IC ; rtX . aymajcn1ux = rtP . Integrator1_IC ;
rtX . aybdlnsonf = 0.0 ; rtX . jsupm2qpb3 = rtP .
HydraulicTurbineandGovernor_po ; rtX . bitn2dxr3x = rtP . theta_IC ; rtX .
bnuy0zz2ow = rtP . Integrator_IC_okxqdvaqge ; rtX . k52gxr3n2s = rtP .
Integrator_IC ; rtB . kmznpd4a0b = rtP . Lmq_sat_Y0 ; rtB . pwe1eclt2g = rtP
. Laq_Y0 ; for ( i = 0 ; i < 25 ; i ++ ) { rtB . pbau2lhp5g [ i ] = rtP .
Linv_Y0 ; rtB . fbgrxsow4f [ i ] = rtP . RLinv_Y0 ; } rtB . a5unwbreth = rtP
. Lmqd_Y0 ; rtB . mg4fjb0upp = rtP . Lmqd_Y0 ; rtB . fyyh0ebqhq = rtP .
Laqd_Y0 ; rtB . h0b31s25s4 = rtP . Laqd_Y0 ; } void MdlStart ( void ) { {
void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL )
; void * * pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize =
16384 ; char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } rtDW . frpnm4xhbp = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; ( void ) memset ( & ( (
( XDis * ) ssGetContStateDisabled ( rtS ) ) -> bnuy0zz2ow ) , 1 , 2 * sizeof
( boolean_T ) ) ; rtDW . njx10umgkj = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> k52gxr3n2s = 1 ; { SimStruct * rts =
ssGetSFunction ( rtS , 0 ) ; sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts
) != ( NULL ) ) return ; } MdlInitialize ( ) ; } void MdlOutputs ( int_T tid
) { real_T gi55l50kyv ; real_T ognblrjw2o ; real_T iaygvxx4z0 ; real_T
bzqqrejlgg ; boolean_T kcgpugi0va ; boolean_T nqdezxcxhs ; real_T hbfhrzc1zx
; real_T dxq0zhxkai [ 25 ] ; int32_T i ; int32_T i_p ; int32_T i_e ;
srClearBC ( rtDW . ecn5ugdake ) ; srClearBC ( rtDW . gudhnfthi4 ) ; rtB .
kr1l0f0n1y = rtX . ecfyjwp3hk ; rtB . f0tfi2aikm = rtP . web2_Gain * ssGetT (
rtS ) ; rtB . hcevlizke0 = rtB . kr1l0f0n1y + rtB . f0tfi2aikm ;
muDoubleScalarSinCos ( rtB . hcevlizke0 , & gi55l50kyv , & ognblrjw2o ) ; for
( i = 0 ; i < 5 ; i ++ ) { rtB . aevoxybjly [ i ] = rtX . ltlvyqyjyu [ i ] ;
} if ( ssIsSampleHit ( rtS , 1 , 0 ) && ssIsMajorTimeStep ( rtS ) ) { if (
rtP . Constant1_Value_fc0guqcyc4 > 0.0 ) { if ( ! rtDW . frpnm4xhbp ) { if (
ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } ( void ) memset ( & (
( ( XDis * ) ssGetContStateDisabled ( rtS ) ) -> bnuy0zz2ow ) , 0 , 2 *
sizeof ( boolean_T ) ) ; rtDW . frpnm4xhbp = true ; } } else { if ( rtDW .
frpnm4xhbp ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; ( void )
memset ( & ( ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) -> bnuy0zz2ow ) ,
1 , 2 * sizeof ( boolean_T ) ) ; if ( rtDW . njx10umgkj ) { rtDW . njx10umgkj
= false ; } rtDW . frpnm4xhbp = false ; } } } if ( rtDW . frpnm4xhbp ) { rtB
. i04fclefuh [ 0 ] = rtP . uLl_d_Gain [ 0 ] * rtB . aevoxybjly [ 1 ] ; rtB .
i04fclefuh [ 1 ] = rtP . uLl_d_Gain [ 1 ] * rtB . aevoxybjly [ 2 ] ; rtB .
i04fclefuh [ 2 ] = rtP . uLl_d_Gain [ 2 ] * rtB . aevoxybjly [ 3 ] ; rtB .
cyggjdadcr = ( rtB . i04fclefuh [ 0 ] + rtB . i04fclefuh [ 1 ] ) + rtB .
i04fclefuh [ 2 ] ; rtB . pzj0ccucw1 = rtX . bnuy0zz2ow ; rtB . ftfak5o3sh = (
rtP . u1_Value [ 0 ] + rtP . u1_Value [ 1 ] ) + 1.0 / rtB . pzj0ccucw1 ; rtB
. h0b31s25s4 = 1.0 / rtB . ftfak5o3sh ; rtB . ilq0fkqsof = rtB . cyggjdadcr *
rtB . h0b31s25s4 ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . ii4frt2ihv = (
rtB . ilq0fkqsof >= 0.0 ) ; } rtB . jsb2lzsy5d = rtDW . ii4frt2ihv > 0 ? rtB
. ilq0fkqsof : - rtB . ilq0fkqsof ; rtB . cheoaxmkwf = look1_pbinlxpw ( rtB .
jsb2lzsy5d , rtP . uDLookupTable_bp01Data_i3bi2vd4wx , rtP .
uDLookupTable_tableData_oh1wox4m40 , & rtDW . kk3urbel1a , 9U ) ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . el4pqea2qg = ( rtB . cheoaxmkwf != 0.0 )
; } if ( rtDW . el4pqea2qg ) { rtB . ixrm34qqkr = rtB . jsb2lzsy5d / rtB .
cheoaxmkwf ; rtB . citrubba04 = rtB . ixrm34qqkr ; } else { rtB . citrubba04
= rtP . Constant1_Value_j0subfzquq ; } rtB . mg4fjb0upp = rtP . Lmd_Gain *
rtB . citrubba04 ; rtB . jtyymi0w2q = rtB . mg4fjb0upp - rtB . pzj0ccucw1 ;
rtB . f4ykvphd3j = rtP . uTT1e6s_Gain_lygg4vbdad * rtB . jtyymi0w2q ; if (
ssIsSampleHit ( rtS , 1 , 0 ) && ssIsMajorTimeStep ( rtS ) ) { if ( rtP .
Constant1_Value_ottz5lhlaz ) { if ( ! rtDW . njx10umgkj ) { if (
ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> k52gxr3n2s = 0 ; rtDW . njx10umgkj = true
; } } else { if ( rtDW . njx10umgkj ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; ( ( XDis * )
ssGetContStateDisabled ( rtS ) ) -> k52gxr3n2s = 1 ; rtDW . njx10umgkj =
false ; } } } if ( rtDW . njx10umgkj ) { rtB . o5bfaqvpcy [ 0 ] = rtP .
uLl_q_Gain [ 0 ] * rtB . aevoxybjly [ 0 ] ; rtB . o5bfaqvpcy [ 1 ] = rtP .
uLl_q_Gain [ 1 ] * rtB . aevoxybjly [ 4 ] ; rtB . ix4epb55wg = rtB .
o5bfaqvpcy [ 0 ] + rtB . o5bfaqvpcy [ 1 ] ; rtB . dlsxci2kgl = rtX .
k52gxr3n2s ; rtB . koxeovukjp = ( ( rtP . u2_Value [ 0 ] + rtP . u2_Value [ 1
] ) + rtP . u2_Value [ 2 ] ) + 1.0 / rtB . dlsxci2kgl ; rtB . pwe1eclt2g =
1.0 / rtB . koxeovukjp ; rtB . lqkqphi04w = rtB . ix4epb55wg * rtB .
pwe1eclt2g ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . e1fpigwdyu = ( rtB .
lqkqphi04w >= 0.0 ) ; } rtB . pz1e453xyk = rtDW . e1fpigwdyu > 0 ? rtB .
lqkqphi04w : - rtB . lqkqphi04w ; rtB . g50stc2bsg = look1_pbinlxpw ( rtB .
pz1e453xyk , rtP . uDLookupTable_bp01Data , rtP . uDLookupTable_tableData , &
rtDW . h3oborupv1 , 9U ) ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
noprxdeo2f = ( rtB . g50stc2bsg != 0.0 ) ; } if ( rtDW . noprxdeo2f ) { rtB .
onh15amb3y = rtB . pz1e453xyk / rtB . g50stc2bsg ; rtB . nh3cfumtvt = rtB .
onh15amb3y ; } else { rtB . nh3cfumtvt = rtP . Constant1_Value ; } rtB .
kmznpd4a0b = rtP . Lmq_Gain * rtB . nh3cfumtvt ; rtB . onshuqhaip = rtB .
kmznpd4a0b - rtB . dlsxci2kgl ; rtB . mrxcfcjegz = rtP . uTT1e6s_Gain * rtB .
onshuqhaip ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
ecn5ugdake ) ; } } if ( rtP . Constant2_Value_ihmgbjdayf ) { rtB . a5unwbreth
= rtB . kmznpd4a0b ; } else { rtB . a5unwbreth = rtP . u3_Value ; } memcpy (
& dxq0zhxkai [ 0 ] , & rtP . u1_Value_evk3gg0wa2 [ 0 ] , 25U * sizeof (
real_T ) ) ; dxq0zhxkai [ 0 ] = rtB . a5unwbreth ; dxq0zhxkai [ 4 ] = rtB .
a5unwbreth ; dxq0zhxkai [ 20 ] = rtB . a5unwbreth ; dxq0zhxkai [ 24 ] = rtB .
a5unwbreth ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { dxq0zhxkai [ 1 + 5 * ( 1 +
i_p ) ] = rtB . mg4fjb0upp ; dxq0zhxkai [ 2 + 5 * ( 1 + i_p ) ] = rtB .
mg4fjb0upp ; dxq0zhxkai [ 3 + 5 * ( 1 + i_p ) ] = rtB . mg4fjb0upp ; } for (
i = 0 ; i < 25 ; i ++ ) { rtB . ggkhauomxo [ i ] = dxq0zhxkai [ i ] + rtP .
u5_Value [ i ] ; } rt_invd5x5_snf ( rtB . ggkhauomxo , rtB . pbau2lhp5g ) ;
for ( i_p = 0 ; i_p < 5 ; i_p ++ ) { for ( i = 0 ; i < 5 ; i ++ ) { rtB .
fbgrxsow4f [ i + 5 * i_p ] = 0.0 ; for ( i_e = 0 ; i_e < 5 ; i_e ++ ) { rtB .
fbgrxsow4f [ i + 5 * i_p ] += rtP . u1_Value_g2cyrwvzkh [ 5 * i_e + i ] * rtB
. pbau2lhp5g [ 5 * i_p + i_e ] ; } } } if ( rtP . Constant3_Value_c5mzzegack
) { rtB . fyyh0ebqhq = rtB . pwe1eclt2g ; } else { rtB . fyyh0ebqhq = rtP .
u2_Value_dgzm2q1ls3 ; } if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW
. gudhnfthi4 ) ; } } if ( rtP . Constant3_Value >= rtP . Switch_Threshold ) {
memcpy ( & rtB . ju1jshvwhr [ 0 ] , & rtB . pbau2lhp5g [ 0 ] , 25U * sizeof (
real_T ) ) ; } else { memcpy ( & rtB . ju1jshvwhr [ 0 ] , & rtP .
Constant4_Value [ 0 ] , 25U * sizeof ( real_T ) ) ; } for ( i = 0 ; i < 5 ; i
++ ) { rtB . hgnzqmdjot [ i ] = 0.0 ; for ( i_p = 0 ; i_p < 5 ; i_p ++ ) {
rtB . hgnzqmdjot [ i ] += rtB . ju1jshvwhr [ 5 * i_p + i ] * rtB . aevoxybjly
[ i_p ] ; } rtB . plsr00p5pu [ i ] = rtP . changeIqIdcurrentsigns_Gain [ i ]
* rtB . hgnzqmdjot [ i ] ; } iaygvxx4z0 = rtB . plsr00p5pu [ 0 ] * ognblrjw2o
+ rtB . plsr00p5pu [ 1 ] * gi55l50kyv ; bzqqrejlgg = ( ( - rtB . plsr00p5pu [
0 ] - 1.7320508075688772 * rtB . plsr00p5pu [ 1 ] ) * ognblrjw2o + (
1.7320508075688772 * rtB . plsr00p5pu [ 0 ] - rtB . plsr00p5pu [ 1 ] ) *
gi55l50kyv ) * 0.5 ; rtB . omelmho425 = ( 0.0 - iaygvxx4z0 ) - bzqqrejlgg ;
rtB . ieios15ick [ 0 ] = rtP . ib_Gain * iaygvxx4z0 ; rtB . ieios15ick [ 1 ]
= rtP . ib_Gain * bzqqrejlgg ; rtB . ieios15ick [ 2 ] = rtP . ib_Gain * rtB .
omelmho425 ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnOutputs (
rts , 0 ) ; } rtB . hodx3vvveu = rtX . gclujrpfr4 ; rtB . b4cekmi0wt = rtP .
nomspeed_Value + rtB . hodx3vvveu ; rtB . cb01jjmyfq = rtP . units_Gain * rtB
. b4cekmi0wt ; rtB . fiofh4kefk = 0.0 ; rtB . fiofh4kefk += rtP .
StateSpace_C * rtX . kml2oh1yt0 ; rtB . kxk0zjan2u = 0.0 ; rtB . kxk0zjan2u
+= rtP . StateSpace_C_brkogrmwzx * rtX . kraqf3we4h ; rtB . eavm2lmu4f = rtP
. Vfdmax1_Gain * rtB . kxk0zjan2u ; rtB . fjd5s1suaw = rtB . eavm2lmu4f + rtB
. odntfboinc ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep
( rtS ) ) { rtDW . jb3iew0a1q = ( rtB . fiofh4kefk > rtP .
Constant1_Value_dxffpau3tt ) ; } kcgpugi0va = rtDW . jb3iew0a1q ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . csrztzcibw = ( rtB . fiofh4kefk < rtB .
fjd5s1suaw ) ; } nqdezxcxhs = rtDW . csrztzcibw ; rtB . grv35kz54w = (
kcgpugi0va && rtDW . csrztzcibw ) ; rtB . iwds2hww0j = rtP .
Constant1_Value_dxffpau3tt * ( real_T ) ! kcgpugi0va ; rtB . inr4gxt4lu = !
nqdezxcxhs ; } rtB . pfingzy4pc = rtB . fiofh4kefk * rtB . grv35kz54w ; rtB .
php2zq2lhw = rtB . inr4gxt4lu * rtB . fjd5s1suaw ; rtB . bcynuxf3b4 = ( rtB .
pfingzy4pc + rtB . iwds2hww0j ) + rtB . php2zq2lhw ; rtB . bc2m5qcx30 = 0.0 ;
rtB . bc2m5qcx30 += rtP . StateSpace_D * rtB . bcynuxf3b4 ; rtB . gu3pd23vmg
= 0.0 ; rtB . gu3pd23vmg += rtP . StateSpace_C_manifxflg5 * rtX . cqyd2pk3x0
; rtB . gu3pd23vmg += rtP . StateSpace_D_h4wd5niec1 * rtB . bc2m5qcx30 ; rtB
. b0uhmkj3mn = ( ( rtP . Constant1_Value_c5r2ow4pnn + rtP . Vf0ka_Value ) -
rtB . kxk0zjan2u ) - rtB . gu3pd23vmg ; rtB . frbgfp02s3 = 0.0 ; rtB .
frbgfp02s3 += rtP . StateSpace_D_csfvldwlau * rtB . b0uhmkj3mn ; if ( rtP .
Constant1_Value_ai2pb13mhx ) { rtB . frxkjjxjkt = rtB . plsr00p5pu [ 0 ] ; }
else { rtB . frxkjjxjkt = rtP . Constant2_Value ; } rtB . jw0piz2ncq [ 0 ] =
rtP . uLl_q_Gain_awlrmeuumw [ 0 ] * rtB . aevoxybjly [ 0 ] ; rtB . jw0piz2ncq
[ 1 ] = rtP . uLl_q_Gain_awlrmeuumw [ 1 ] * rtB . aevoxybjly [ 4 ] ; if ( rtP
. Constant8_Value >= rtP . Switch3_Threshold ) { rtB . lbzic3bakw [ 0 ] = rtB
. fyyh0ebqhq ; rtB . lbzic3bakw [ 1 ] = rtB . h0b31s25s4 ; } else { rtB .
lbzic3bakw [ 0 ] = rtP . Laqd_nosat_Value [ 0 ] ; rtB . lbzic3bakw [ 1 ] =
rtP . Laqd_nosat_Value [ 1 ] ; } rtB . m33avxegzn [ 0 ] = rtB . jw0piz2ncq [
0 ] * rtB . lbzic3bakw [ 0 ] ; rtB . m33avxegzn [ 1 ] = rtB . jw0piz2ncq [ 1
] * rtB . lbzic3bakw [ 0 ] ; rtB . cnczf5kl3f = rtB . m33avxegzn [ 0 ] + rtB
. m33avxegzn [ 1 ] ; rtB . n4pe4taf5k [ 0 ] = rtP . uLl_d_Gain_jijxqv5vxr [ 0
] * rtB . aevoxybjly [ 1 ] ; rtB . f3bhe2mrrl [ 0 ] = rtB . n4pe4taf5k [ 0 ]
* rtB . lbzic3bakw [ 1 ] ; rtB . n4pe4taf5k [ 1 ] = rtP .
uLl_d_Gain_jijxqv5vxr [ 1 ] * rtB . aevoxybjly [ 2 ] ; rtB . f3bhe2mrrl [ 1 ]
= rtB . n4pe4taf5k [ 1 ] * rtB . lbzic3bakw [ 1 ] ; rtB . n4pe4taf5k [ 2 ] =
rtP . uLl_d_Gain_jijxqv5vxr [ 2 ] * rtB . aevoxybjly [ 3 ] ; rtB . f3bhe2mrrl
[ 2 ] = rtB . n4pe4taf5k [ 2 ] * rtB . lbzic3bakw [ 1 ] ; rtB . aekodpeb5p =
( rtB . f3bhe2mrrl [ 0 ] + rtB . f3bhe2mrrl [ 1 ] ) + rtB . f3bhe2mrrl [ 2 ]
; rtB . dytwitjqmo [ 0 ] = rtP . u_Vb_Gain * rtB . hrt2qdvvir [ 0 ] ; rtB .
dytwitjqmo [ 1 ] = rtP . u_Vb_Gain * rtB . hrt2qdvvir [ 1 ] ; hbfhrzc1zx = (
( 2.0 * rtB . dytwitjqmo [ 0 ] + rtB . dytwitjqmo [ 1 ] ) * ognblrjw2o +
1.7320508075688772 * rtB . dytwitjqmo [ 1 ] * gi55l50kyv ) *
0.33333333333333331 ; gi55l50kyv = ( ( 2.0 * rtB . dytwitjqmo [ 0 ] + rtB .
dytwitjqmo [ 1 ] ) * gi55l50kyv + - 1.7320508075688772 * rtB . dytwitjqmo [ 1
] * ognblrjw2o ) * 0.33333333333333331 ; if ( rtP . Constant5_Value >= rtP .
Switch2_Threshold ) { rtB . m2tczfrive [ 0 ] = rtB . a5unwbreth ; rtB .
m2tczfrive [ 1 ] = rtB . mg4fjb0upp ; } else { rtB . m2tczfrive [ 0 ] = rtP .
Lmqd_nosat_Value [ 0 ] ; rtB . m2tczfrive [ 1 ] = rtP . Lmqd_nosat_Value [ 1
] ; } rtB . fxn4vwgtsq = rtP . Gain_Gain * muDoubleScalarAtan2 ( gi55l50kyv ,
hbfhrzc1zx ) ; rtB . d1kjzcrxkd = hbfhrzc1zx * rtB . plsr00p5pu [ 0 ] ; rtB .
krjvbt2mq4 = gi55l50kyv * rtB . plsr00p5pu [ 1 ] ; rtB . pzqvo3sq2r = rtB .
d1kjzcrxkd + rtB . krjvbt2mq4 ; rtB . lhqwbn1q25 = rtP . Gain_Gain_acjk3icicb
* rtB . pzqvo3sq2r ; rtB . plibi3b3wz = hbfhrzc1zx * rtB . plsr00p5pu [ 1 ] ;
rtB . ofl3u43bgw = gi55l50kyv * rtB . plsr00p5pu [ 0 ] ; rtB . c3oz1evhcw =
rtB . plibi3b3wz - rtB . ofl3u43bgw ; rtB . gfo2bsicyk = rtP . Gain1_Gain *
rtB . c3oz1evhcw ; rtB . dafsczeyd0 [ 0 ] = rtP . outputformatting_Gain [ 0 ]
* iaygvxx4z0 ; rtB . dafsczeyd0 [ 1 ] = rtP . outputformatting_Gain [ 1 ] *
bzqqrejlgg ; rtB . dafsczeyd0 [ 2 ] = rtP . outputformatting_Gain [ 2 ] * rtB
. omelmho425 ; rtB . dafsczeyd0 [ 3 ] = rtP . outputformatting_Gain [ 3 ] *
rtB . plsr00p5pu [ 0 ] ; rtB . dafsczeyd0 [ 4 ] = rtP . outputformatting_Gain
[ 4 ] * rtB . plsr00p5pu [ 1 ] ; rtB . dafsczeyd0 [ 5 ] = rtP .
outputformatting_Gain [ 5 ] * rtB . plsr00p5pu [ 2 ] ; rtB . dafsczeyd0 [ 6 ]
= rtP . outputformatting_Gain [ 6 ] * rtB . plsr00p5pu [ 4 ] ; rtB .
dafsczeyd0 [ 7 ] = rtP . outputformatting_Gain [ 7 ] * rtB . frxkjjxjkt ; rtB
. dafsczeyd0 [ 8 ] = rtP . outputformatting_Gain [ 8 ] * rtB . plsr00p5pu [ 3
] ; rtB . dafsczeyd0 [ 9 ] = rtP . outputformatting_Gain [ 9 ] * rtB .
cnczf5kl3f ; rtB . dafsczeyd0 [ 10 ] = rtP . outputformatting_Gain [ 10 ] *
rtB . aekodpeb5p ; rtB . dafsczeyd0 [ 11 ] = rtP . outputformatting_Gain [ 11
] * hbfhrzc1zx ; rtB . dafsczeyd0 [ 12 ] = rtP . outputformatting_Gain [ 12 ]
* gi55l50kyv ; rtB . dafsczeyd0 [ 13 ] = rtP . outputformatting_Gain [ 13 ] *
rtB . m2tczfrive [ 0 ] ; rtB . dafsczeyd0 [ 14 ] = rtP .
outputformatting_Gain [ 14 ] * rtB . m2tczfrive [ 1 ] ; rtB . dafsczeyd0 [ 15
] = rtP . outputformatting_Gain [ 15 ] * rtB . fxn4vwgtsq ; rtB . dafsczeyd0
[ 16 ] = rtP . outputformatting_Gain [ 16 ] * rtB . lhqwbn1q25 ; rtB .
dafsczeyd0 [ 17 ] = rtP . outputformatting_Gain [ 17 ] * rtB . gfo2bsicyk ;
iaygvxx4z0 = muDoubleScalarPower ( rtB . dafsczeyd0 [ 12 ] , 2.0 ) +
muDoubleScalarPower ( rtB . dafsczeyd0 [ 11 ] , 2.0 ) ; if ( iaygvxx4z0 < 0.0
) { rtB . em31irqwpt = - muDoubleScalarSqrt ( - iaygvxx4z0 ) ; } else { rtB .
em31irqwpt = muDoubleScalarSqrt ( iaygvxx4z0 ) ; } rtB . c4gaogg0kl = 0.0 ;
rtB . c4gaogg0kl += rtP . Derivative_C * rtX . jyzfjmsmba ; rtB . jf2gkiczhf
= rtP . Constant_Value - rtB . cb01jjmyfq ; if ( ssIsMajorTimeStep ( rtS ) )
{ if ( rtX . j5ogc35dcx >= rtP . position_UpperSat ) { rtX . j5ogc35dcx = rtP
. position_UpperSat ; } else { if ( rtX . j5ogc35dcx <= rtP .
position_LowerSat ) { rtX . j5ogc35dcx = rtP . position_LowerSat ; } } } rtB
. n0daf3kfkx = rtX . j5ogc35dcx ; rtB . p40ujyoefj [ 0 ] = rtP . u1_Gain [ 0
] * rtB . plsr00p5pu [ 0 ] ; rtB . p40ujyoefj [ 1 ] = rtP . u1_Gain [ 1 ] *
rtB . plsr00p5pu [ 1 ] ; rtB . dc5nymbuqt [ 0 ] = rtB . aevoxybjly [ 1 ] *
rtB . p40ujyoefj [ 0 ] ; rtB . dc5nymbuqt [ 1 ] = rtB . aevoxybjly [ 0 ] *
rtB . p40ujyoefj [ 1 ] ; rtB . fikrci5wnj = rtB . dc5nymbuqt [ 0 ] + rtB .
dc5nymbuqt [ 1 ] ; if ( rtP . HydraulicTurbineandGovernor_dref >= rtP .
Switch_Threshold_b2t0vmw2we ) { rtB . pz33wqr5tx = rtB . n0daf3kfkx ; } else
{ rtB . mkzsniweyj = rtB . b4cekmi0wt * rtB . fikrci5wnj ; rtB . kf5ffc0rj1 =
rtP . units1_Gain * rtB . mkzsniweyj ; rtB . en43ee13dp = rtB . kf5ffc0rj1 -
rtB . kf5ffc0rj1 ; rtB . pz33wqr5tx = rtB . en43ee13dp ; } rtB . oiib5ytjjg =
rtP . permanentdroop_Gain * rtB . pz33wqr5tx ; rtB . diraslnu04 = rtB .
jf2gkiczhf - rtB . oiib5ytjjg ; rtB . jplifgq5sc = rtP . Integral_Gain * rtB
. diraslnu04 ; rtB . nvfqaxwy3k = rtX . aymajcn1ux ; rtB . pgkbrhcuia = rtP .
Proportional_Gain * rtB . diraslnu04 ; rtB . bl21y1dth5 = ( rtB . pgkbrhcuia
+ rtB . nvfqaxwy3k ) + rtB . c4gaogg0kl ; rtB . eslj0xnqak = rtB . bl21y1dth5
- rtB . n0daf3kfkx ; rtB . m5410f2s1r = 0.0 ; rtB . m5410f2s1r += rtP .
servomotor_C * rtX . aybdlnsonf ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
a34lmbu2se = rtB . m5410f2s1r >= rtP . speedlimit_UpperSat ? 1 : rtB .
m5410f2s1r > rtP . speedlimit_LowerSat ? 0 : - 1 ; } rtB . dcj3g23bnj = rtDW
. a34lmbu2se == 1 ? rtP . speedlimit_UpperSat : rtDW . a34lmbu2se == - 1 ?
rtP . speedlimit_LowerSat : rtB . m5410f2s1r ; rtB . ekypfbfahe = rtP .
turbinegain_Gain * rtB . n0daf3kfkx ; rtB . gz1es4awfp = rtX . jsupm2qpb3 ;
rtB . be2hetqlgl = rtP . beta_Gain * rtB . hodx3vvveu ; rtB . g0sbc5omlb =
muDoubleScalarPower ( rtB . gz1es4awfp / rtB . ekypfbfahe , 2.0 ) - rtB .
be2hetqlgl ; rtB . hddv0reyvo = rtP . Constant_Value_f4yyiavgsx - rtB .
g0sbc5omlb ; rtB . ftidkuimh2 = rtP . Gain2_Gain * rtB . hddv0reyvo ; rtB .
b2bhql0adz = rtB . g0sbc5omlb * rtB . gz1es4awfp ; rtB . hvj0m54a5e = rtP .
N_Gain * rtB . bc2m5qcx30 ; rtB . dfmiczstqr = rtP . Gain1_Gain_fsvmmhhhj3 *
rtB . b4cekmi0wt ; if ( rtP . Constant2_Value_ewacipohvd >= rtP .
Switch1_Threshold ) { memcpy ( & rtB . c2k2l0344v [ 0 ] , & rtB . fbgrxsow4f
[ 0 ] , 25U * sizeof ( real_T ) ) ; } else { memcpy ( & rtB . c2k2l0344v [ 0
] , & rtP . Constant6_Value [ 0 ] , 25U * sizeof ( real_T ) ) ; } for ( i = 0
; i < 25 ; i ++ ) { rtB . dcpqtuibpu [ i ] = rtP . u1_Value_c5nzdrro12 [ i ]
; dxq0zhxkai [ i ] = rtB . dcpqtuibpu [ i ] ; } dxq0zhxkai [ 5 ] = rtB .
b4cekmi0wt ; dxq0zhxkai [ 1 ] = rtB . dfmiczstqr ; for ( i = 0 ; i < 25 ; i
++ ) { rtB . mhkgnw5dfa [ i ] = ( 0.0 - dxq0zhxkai [ i ] ) - rtB . c2k2l0344v
[ i ] ; } for ( i_p = 0 ; i_p < 5 ; i_p ++ ) { rtB . j3gwtsr3ih [ i_p ] = 0.0
; for ( i = 0 ; i < 5 ; i ++ ) { rtB . j3gwtsr3ih [ i_p ] += rtB . mhkgnw5dfa
[ 5 * i + i_p ] * rtB . aevoxybjly [ i ] ; } } rtB . gqdszdjmco [ 0 ] =
hbfhrzc1zx + rtB . j3gwtsr3ih [ 0 ] ; rtB . gqdszdjmco [ 1 ] = gi55l50kyv +
rtB . j3gwtsr3ih [ 1 ] ; rtB . gqdszdjmco [ 2 ] = rtB . hvj0m54a5e + rtB .
j3gwtsr3ih [ 2 ] ; rtB . gqdszdjmco [ 3 ] = rtP . Vkd0Vkq10Vkq20_Value [ 0 ]
+ rtB . j3gwtsr3ih [ 3 ] ; rtB . gqdszdjmco [ 4 ] = rtP .
Vkd0Vkq10Vkq20_Value [ 1 ] + rtB . j3gwtsr3ih [ 4 ] ; for ( i = 0 ; i < 5 ; i
++ ) { rtB . pubf0ms0bt [ i ] = rtP . wbase_Gain * rtB . gqdszdjmco [ i ] ; }
rtB . jiyiyrbb4a = rtP . u_Pb_Gain * rtB . b2bhql0adz ; rtB . j0j5dylxjw =
rtP . F1_Gain * rtB . b4cekmi0wt ; rtB . jvdtj4iup3 = ( rtB . jiyiyrbb4a / (
rtB . b4cekmi0wt + 2.2204460492503131e-16 ) - rtB . fikrci5wnj ) - rtB .
j0j5dylxjw ; rtB . p2ygvmxt5i = rtP . u_2H_Gain * rtB . jvdtj4iup3 ; rtB .
inhavjn1zx = rtP . web1_Gain * rtB . hodx3vvveu ; rtB . gwtwwxhuqy = rtP .
web3_Gain * rtB . b4cekmi0wt ; UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID2 ( int_T tid ) { if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC
( rtDW . ecn5ugdake ) ; srUpdateBC ( rtDW . gudhnfthi4 ) ; } rtB . odntfboinc
= ( real_T ) ( rtP . Constant_Value_cangz0hlbt == rtP .
Constant3_Value_oy0hsbqr4o ) * rtP . Vfdmax_Gain ; UNUSED_PARAMETER ( tid ) ;
} void MdlUpdate ( int_T tid ) { { SimStruct * rts = ssGetSFunction ( rtS , 0
) ; sfcnUpdate ( rts , 0 ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) )
return ; } if ( rtX . j5ogc35dcx == rtP . position_UpperSat ) { switch ( rtDW
. jstmhifjto ) { case 3 : if ( rtB . dcj3g23bnj < 0.0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . jstmhifjto = 1 ;
} break ; case 1 : if ( rtB . dcj3g23bnj >= 0.0 ) { rtDW . jstmhifjto = 3 ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } break ; default :
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if ( rtB . dcj3g23bnj <
0.0 ) { rtDW . jstmhifjto = 1 ; } else { rtDW . jstmhifjto = 3 ; } break ; }
} else if ( rtX . j5ogc35dcx == rtP . position_LowerSat ) { switch ( rtDW .
jstmhifjto ) { case 4 : if ( rtB . dcj3g23bnj > 0.0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . jstmhifjto = 2 ;
} break ; case 2 : if ( rtB . dcj3g23bnj <= 0.0 ) { rtDW . jstmhifjto = 4 ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } break ; default :
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; if ( rtB . dcj3g23bnj >
0.0 ) { rtDW . jstmhifjto = 2 ; } else { rtDW . jstmhifjto = 4 ; } break ; }
} else { rtDW . jstmhifjto = 0 ; } UNUSED_PARAMETER ( tid ) ; } void
MdlUpdateTID2 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { int32_T i ; XDot * _rtXdot ; XDis * _rtXdis ;
_rtXdis = ( ( XDis * ) ssGetContStateDisabled ( rtS ) ) ; _rtXdot = ( ( XDot
* ) ssGetdX ( rtS ) ) ; _rtXdot -> ecfyjwp3hk = rtB . inhavjn1zx ; for ( i =
0 ; i < 5 ; i ++ ) { _rtXdot -> ltlvyqyjyu [ i ] = rtB . pubf0ms0bt [ i ] ; }
if ( rtDW . frpnm4xhbp ) { _rtXdot -> bnuy0zz2ow = rtB . f4ykvphd3j ; if (
rtDW . njx10umgkj ) { _rtXdot -> k52gxr3n2s = rtB . mrxcfcjegz ; } else { ( (
XDot * ) ssGetdX ( rtS ) ) -> k52gxr3n2s = 0.0 ; } } else { { real_T * dx ;
int_T i ; dx = & ( ( ( XDot * ) ssGetdX ( rtS ) ) -> bnuy0zz2ow ) ; for ( i =
0 ; i < 2 ; i ++ ) { dx [ i ] = 0.0 ; } } } _rtXdot -> gclujrpfr4 = rtB .
p2ygvmxt5i ; _rtXdot -> kml2oh1yt0 = 0.0 ; _rtXdot -> kml2oh1yt0 += rtP .
StateSpace_A * rtX . kml2oh1yt0 ; _rtXdot -> kml2oh1yt0 += rtP . StateSpace_B
* rtB . frbgfp02s3 ; _rtXdot -> kraqf3we4h = 0.0 ; _rtXdot -> kraqf3we4h +=
rtP . StateSpace_A_gvjvm0zida * rtX . kraqf3we4h ; _rtXdot -> kraqf3we4h +=
rtP . StateSpace_B_cw5oh3slxt * rtB . em31irqwpt ; _rtXdot -> cqyd2pk3x0 =
0.0 ; _rtXdot -> cqyd2pk3x0 += rtP . StateSpace_A_jh2uawflmi * rtX .
cqyd2pk3x0 ; _rtXdot -> cqyd2pk3x0 += rtP . StateSpace_B_mmoy0u0fuw * rtB .
bc2m5qcx30 ; _rtXdot -> jyzfjmsmba = 0.0 ; _rtXdot -> jyzfjmsmba += rtP .
Derivative_A * rtX . jyzfjmsmba ; _rtXdot -> jyzfjmsmba += rtB . diraslnu04 ;
if ( ( rtDW . jstmhifjto != 3 ) && ( rtDW . jstmhifjto != 4 ) ) { _rtXdot ->
j5ogc35dcx = rtB . dcj3g23bnj ; _rtXdis -> j5ogc35dcx = false ; } else {
_rtXdot -> j5ogc35dcx = 0.0 ; if ( ( rtDW . jstmhifjto == 3 ) || ( rtDW .
jstmhifjto == 4 ) ) { _rtXdis -> j5ogc35dcx = true ; } } _rtXdot ->
aymajcn1ux = rtB . jplifgq5sc ; _rtXdot -> aybdlnsonf = 0.0 ; _rtXdot ->
aybdlnsonf += rtP . servomotor_A * rtX . aybdlnsonf ; _rtXdot -> aybdlnsonf
+= rtB . eslj0xnqak ; _rtXdot -> jsupm2qpb3 = rtB . ftidkuimh2 ; _rtXdot ->
bitn2dxr3x = rtB . gwtwwxhuqy ; } void MdlProjection ( void ) { } void
MdlZeroCrossings ( void ) { boolean_T anyStateSaturated ; ZCV * _rtZCSV ;
_rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ; if ( rtDW .
frpnm4xhbp ) { _rtZCSV -> agjptjfiur = rtB . ilq0fkqsof ; _rtZCSV ->
hqmzut01mc = rtB . cheoaxmkwf ; if ( rtDW . njx10umgkj ) { _rtZCSV ->
matzkzbiyt = rtB . lqkqphi04w ; _rtZCSV -> jgp2qm4pl4 = rtB . g50stc2bsg ; }
else { { real_T * zcsv = & ( ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) )
-> matzkzbiyt ) ; int_T i ; for ( i = 0 ; i < 2 ; i ++ ) { zcsv [ i ] = 0.0 ;
} } } } else { { real_T * zcsv = & ( ( ( ZCV * ) ssGetSolverZcSignalVector (
rtS ) ) -> agjptjfiur ) ; int_T i ; for ( i = 0 ; i < 4 ; i ++ ) { zcsv [ i ]
= 0.0 ; } } } _rtZCSV -> p5mi14pdfs = rtB . fiofh4kefk - rtP .
Constant1_Value_dxffpau3tt ; _rtZCSV -> jsouvt4a5a = rtB . fiofh4kefk - rtB .
fjd5s1suaw ; if ( ( rtDW . jstmhifjto == 1 ) && ( rtX . j5ogc35dcx >= rtP .
position_UpperSat ) ) { _rtZCSV -> kjks0ywqes = 0.0 ; } else { _rtZCSV ->
kjks0ywqes = rtX . j5ogc35dcx - rtP . position_UpperSat ; } if ( ( rtDW .
jstmhifjto == 2 ) && ( rtX . j5ogc35dcx <= rtP . position_LowerSat ) ) {
_rtZCSV -> byzuhbmhlm = 0.0 ; } else { _rtZCSV -> byzuhbmhlm = rtX .
j5ogc35dcx - rtP . position_LowerSat ; } anyStateSaturated = false ; if ( (
rtDW . jstmhifjto == 3 ) || ( rtDW . jstmhifjto == 4 ) ) { anyStateSaturated
= true ; } if ( anyStateSaturated ) { _rtZCSV -> brhgtkbkua = rtB .
dcj3g23bnj ; } else { _rtZCSV -> brhgtkbkua = 0.0 ; } _rtZCSV -> c2g1mk1m4u =
rtB . m5410f2s1r - rtP . speedlimit_UpperSat ; _rtZCSV -> nyuk2u0f43 = rtB .
m5410f2s1r - rtP . speedlimit_LowerSat ; } void MdlTerminate ( void ) { {
SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnTerminate ( rts ) ; } if (
rt_slioCatalogue ( ) != ( NULL ) ) { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 18 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 190 ) ; ssSetNumBlockIO ( rtS , 120 ) ;
ssSetNumBlockParams ( rtS , 510 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 3651298471U ) ;
ssSetChecksumVal ( rtS , 1 , 610010315U ) ; ssSetChecksumVal ( rtS , 2 ,
2930865888U ) ; ssSetChecksumVal ( rtS , 3 , 89649121U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
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
synchronous_generator_modeling_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"synchronous_generator_modeling" ) ; ssSetPath ( rtS ,
"synchronous_generator_modeling" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal
( rtS , 10.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo
. loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; }
{ rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; rtliSetLogT (
ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 18 ] ; static
real_T absTol [ 18 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6
, 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 } ; static uint8_T absTolControl [ 18 ] = {
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U } ; static uint8_T zcAttributes [ 11 ] = { ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_DN ) , ( ZC_EVENT_ALL )
, ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) ,
( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) } ; static ssNonContDerivSigInfo
nonContDerivSigInfo [ 3 ] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
inr4gxt4lu ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
iwds2hww0j ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
grv35kz54w ) , ( NULL ) } } ; ssSetSolverRelTol ( rtS , 0.001 ) ;
ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ;
ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 0.2 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 1 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
3 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode23tb" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol )
; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetSolverZcSignalAttrib (
rtS , zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 11 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetSolverMaxConsecutiveMinStep
( rtS , 1 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid (
rtS , INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset (
rtS ) ; ssSetNumNonsampledZCs ( rtS , 11 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 3651298471U ) ; ssSetChecksumVal ( rtS , 1 ,
610010315U ) ; ssSetChecksumVal ( rtS , 2 , 2930865888U ) ; ssSetChecksumVal
( rtS , 3 , 89649121U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 6 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = ( sysRanDType * ) & rtDW . gudhnfthi4 ; systemRan [ 3 ] = (
sysRanDType * ) & rtDW . ecn5ugdake ; systemRan [ 4 ] = ( sysRanDType * ) &
rtDW . ecn5ugdake ; systemRan [ 5 ] = ( sysRanDType * ) & rtDW . gudhnfthi4 ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } ssSetNumSFunctions ( rtS , 1 ) ; { static SimStruct
childSFunctions [ 1 ] ; static SimStruct * childSFunctionPtrs [ 1 ] ; ( void
) memset ( ( void * ) & childSFunctions [ 0 ] , 0 , sizeof ( childSFunctions
) ) ; ssSetSFunctions ( rtS , & childSFunctionPtrs [ 0 ] ) ; ssSetSFunction (
rtS , 0 , & childSFunctions [ 0 ] ) ; { SimStruct * rts = ssGetSFunction (
rtS , 0 ) ; static time_T sfcnPeriod [ 1 ] ; static time_T sfcnOffset [ 1 ] ;
static int_T sfcnTsMap [ 1 ] ; ( void ) memset ( ( void * ) sfcnPeriod , 0 ,
sizeof ( time_T ) * 1 ) ; ( void ) memset ( ( void * ) sfcnOffset , 0 ,
sizeof ( time_T ) * 1 ) ; ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ;
ssSetOffsetTimePtr ( rts , & sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rts , sfcnTsMap ) ; { static struct _ssBlkInfo2 _blkInfo2 ; struct
_ssBlkInfo2 * blkInfo2 = & _blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ;
} { static struct _ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 =
& _portInfo2 ; _ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; }
ssSetMdlInfoPtr ( rts , ssGetMdlInfoPtr ( rtS ) ) ; { static struct
_ssSFcnModelMethods2 methods2 ; ssSetModelMethods2 ( rts , & methods2 ) ; } {
static struct _ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , &
methods3 ) ; } { static struct _ssSFcnModelMethods4 methods4 ;
ssSetModelMethods4 ( rts , & methods4 ) ; } { static struct _ssStatesInfo2
statesInfo2 ; static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetStatesInfo2 ( rts , & statesInfo2 ) ; ssSetPeriodicStatesInfo ( rts , &
periodicStatesInfo ) ; } { static struct _ssPortInputs inputPortInfo [ 1 ] ;
_ssSetNumInputPorts ( rts , 1 ) ; ssSetPortInfoForInputs ( rts , &
inputPortInfo [ 0 ] ) ; { static struct _ssInPortUnit inputPortUnits [ 1 ] ;
_ssSetPortInfo2ForInputUnits ( rts , & inputPortUnits [ 0 ] ) ; }
ssSetInputPortUnit ( rts , 0 , 0 ) ; { static struct _ssInPortCoSimAttribute
inputPortCoSimAttribute [ 1 ] ; _ssSetPortInfo2ForInputCoSimAttribute ( rts ,
& inputPortCoSimAttribute [ 0 ] ) ; } ssSetInputPortIsContinuousQuantity (
rts , 0 , 0 ) ; { static real_T const * sfcnUPtrs [ 2 ] ; sfcnUPtrs [ 0 ] = &
rtB . ieios15ick [ 0 ] ; sfcnUPtrs [ 1 ] = & rtB . ieios15ick [ 1 ] ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidth ( rts , 0
, 2 ) ; } } { static struct _ssPortOutputs outputPortInfo [ 1 ] ;
ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ] ) ;
_ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidth ( rts ,
0 , 2 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) rtB . hrt2qdvvir )
) ; } } ssSetModelName ( rts , "State-Space" ) ; ssSetPath ( rts ,
"synchronous_generator_modeling/powergui/EquivalentModel1/State-Space" ) ; if
( ssGetRTModel ( rtS ) == ( NULL ) ) { ssSetParentSS ( rts , rtS ) ;
ssSetRootSS ( rts , ssGetRootSS ( rtS ) ) ; } else { ssSetRTModel ( rts ,
ssGetRTModel ( rtS ) ) ; ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts
, rts ) ; } ssSetVersion ( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static
mxArray * sfcnParams [ 4 ] ; ssSetSFcnParamsCount ( rts , 4 ) ;
ssSetSFcnParamsPtr ( rts , & sfcnParams [ 0 ] ) ; ssSetSFcnParam ( rts , 0 ,
( mxArray * ) rtP . StateSpace_P1_Size ) ; ssSetSFcnParam ( rts , 1 , (
mxArray * ) rtP . StateSpace_P2_Size ) ; ssSetSFcnParam ( rts , 2 , ( mxArray
* ) rtP . StateSpace_P3_Size ) ; ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP
. StateSpace_P4_Size ) ; } ssSetRWork ( rts , ( real_T * ) & rtDW .
n5hehfmjzl [ 0 ] ) ; ssSetIWork ( rts , ( int_T * ) & rtDW . jdxobmdxq3 [ 0 ]
) ; ssSetPWork ( rts , ( void * * ) & rtDW . gxrfzfobfe [ 0 ] ) ; { static
struct _ssDWorkRecord dWorkRecord [ 3 ] ; static struct _ssDWorkAuxRecord
dWorkAuxRecord [ 3 ] ; ssSetSFcnDWork ( rts , dWorkRecord ) ;
ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; _ssSetNumDWork ( rts , 3 ) ;
ssSetDWorkWidth ( rts , 0 , 2 ) ; ssSetDWorkDataType ( rts , 0 , SS_DOUBLE )
; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
n5hehfmjzl [ 0 ] ) ; ssSetDWorkWidth ( rts , 1 , 23 ) ; ssSetDWorkDataType (
rts , 1 , SS_INTEGER ) ; ssSetDWorkComplexSignal ( rts , 1 , 0 ) ; ssSetDWork
( rts , 1 , & rtDW . jdxobmdxq3 [ 0 ] ) ; ssSetDWorkWidth ( rts , 2 , 22 ) ;
ssSetDWorkDataType ( rts , 2 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts ,
2 , 0 ) ; ssSetDWork ( rts , 2 , & rtDW . gxrfzfobfe [ 0 ] ) ; }
sfun_spid_contc ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.0 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 0 ;
ssSetNumNonsampledZCs ( rts , 0 ) ; _ssSetInputPortConnected ( rts , 0 , 1 )
; _ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortBeingMerged (
rts , 0 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } } return
rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
