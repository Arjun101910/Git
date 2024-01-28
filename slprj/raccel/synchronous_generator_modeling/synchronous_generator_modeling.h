#include "__cf_synchronous_generator_modeling.h"
#ifndef RTW_HEADER_synchronous_generator_modeling_h_
#define RTW_HEADER_synchronous_generator_modeling_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef synchronous_generator_modeling_COMMON_INCLUDES_
#define synchronous_generator_modeling_COMMON_INCLUDES_
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
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "synchronous_generator_modeling_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME synchronous_generator_modeling
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (120) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (18)   
#elif NCSTATES != 18
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
typedef struct { real_T kr1l0f0n1y ; real_T f0tfi2aikm ; real_T hcevlizke0 ;
real_T aevoxybjly [ 5 ] ; real_T ju1jshvwhr [ 25 ] ; real_T hgnzqmdjot [ 5 ]
; real_T plsr00p5pu [ 5 ] ; real_T omelmho425 ; real_T ieios15ick [ 3 ] ;
real_T hrt2qdvvir [ 2 ] ; real_T hodx3vvveu ; real_T b4cekmi0wt ; real_T
cb01jjmyfq ; real_T fiofh4kefk ; real_T kxk0zjan2u ; real_T eavm2lmu4f ;
real_T odntfboinc ; real_T fjd5s1suaw ; real_T grv35kz54w ; real_T pfingzy4pc
; real_T iwds2hww0j ; real_T inr4gxt4lu ; real_T php2zq2lhw ; real_T
bcynuxf3b4 ; real_T bc2m5qcx30 ; real_T gu3pd23vmg ; real_T b0uhmkj3mn ;
real_T frbgfp02s3 ; real_T frxkjjxjkt ; real_T jw0piz2ncq [ 2 ] ; real_T
lbzic3bakw [ 2 ] ; real_T m33avxegzn [ 2 ] ; real_T cnczf5kl3f ; real_T
n4pe4taf5k [ 3 ] ; real_T f3bhe2mrrl [ 3 ] ; real_T aekodpeb5p ; real_T
dytwitjqmo [ 2 ] ; real_T m2tczfrive [ 2 ] ; real_T fxn4vwgtsq ; real_T
d1kjzcrxkd ; real_T krjvbt2mq4 ; real_T pzqvo3sq2r ; real_T lhqwbn1q25 ;
real_T plibi3b3wz ; real_T ofl3u43bgw ; real_T c3oz1evhcw ; real_T gfo2bsicyk
; real_T dafsczeyd0 [ 18 ] ; real_T em31irqwpt ; real_T c4gaogg0kl ; real_T
jf2gkiczhf ; real_T n0daf3kfkx ; real_T p40ujyoefj [ 2 ] ; real_T dc5nymbuqt
[ 2 ] ; real_T fikrci5wnj ; real_T pz33wqr5tx ; real_T oiib5ytjjg ; real_T
diraslnu04 ; real_T jplifgq5sc ; real_T nvfqaxwy3k ; real_T pgkbrhcuia ;
real_T bl21y1dth5 ; real_T eslj0xnqak ; real_T m5410f2s1r ; real_T dcj3g23bnj
; real_T ekypfbfahe ; real_T gz1es4awfp ; real_T be2hetqlgl ; real_T
g0sbc5omlb ; real_T hddv0reyvo ; real_T ftidkuimh2 ; real_T b2bhql0adz ;
real_T hvj0m54a5e ; real_T dfmiczstqr ; real_T dcpqtuibpu [ 25 ] ; real_T
c2k2l0344v [ 25 ] ; real_T mhkgnw5dfa [ 25 ] ; real_T j3gwtsr3ih [ 5 ] ;
real_T gqdszdjmco [ 5 ] ; real_T pubf0ms0bt [ 5 ] ; real_T jiyiyrbb4a ;
real_T j0j5dylxjw ; real_T jvdtj4iup3 ; real_T p2ygvmxt5i ; real_T inhavjn1zx
; real_T gwtwwxhuqy ; real_T i04fclefuh [ 3 ] ; real_T cyggjdadcr ; real_T
pzj0ccucw1 ; real_T ftfak5o3sh ; real_T h0b31s25s4 ; real_T ilq0fkqsof ;
real_T jsb2lzsy5d ; real_T cheoaxmkwf ; real_T citrubba04 ; real_T mg4fjb0upp
; real_T jtyymi0w2q ; real_T f4ykvphd3j ; real_T a5unwbreth ; real_T
ggkhauomxo [ 25 ] ; real_T pbau2lhp5g [ 25 ] ; real_T fbgrxsow4f [ 25 ] ;
real_T fyyh0ebqhq ; real_T o5bfaqvpcy [ 2 ] ; real_T ix4epb55wg ; real_T
dlsxci2kgl ; real_T koxeovukjp ; real_T pwe1eclt2g ; real_T lqkqphi04w ;
real_T pz1e453xyk ; real_T g50stc2bsg ; real_T nh3cfumtvt ; real_T kmznpd4a0b
; real_T onshuqhaip ; real_T mrxcfcjegz ; real_T onh15amb3y ; real_T
ixrm34qqkr ; real_T mkzsniweyj ; real_T kf5ffc0rj1 ; real_T en43ee13dp ; } B
; typedef struct { real_T lxuclx5hmw [ 25 ] ; real_T n5hehfmjzl [ 2 ] ; void
* gxrfzfobfe [ 22 ] ; struct { void * LoggedData [ 3 ] ; } ndj0lgd3dt ;
uint32_T kk3urbel1a ; uint32_T h3oborupv1 ; int_T jdxobmdxq3 [ 23 ] ; int_T
jstmhifjto ; int_T a34lmbu2se ; int_T ii4frt2ihv ; int_T e1fpigwdyu ; int8_T
gudhnfthi4 ; int8_T ecn5ugdake ; boolean_T jb3iew0a1q ; boolean_T csrztzcibw
; boolean_T el4pqea2qg ; boolean_T noprxdeo2f ; boolean_T frpnm4xhbp ;
boolean_T njx10umgkj ; } DW ; typedef struct { real_T ecfyjwp3hk ; real_T
ltlvyqyjyu [ 5 ] ; real_T gclujrpfr4 ; real_T kml2oh1yt0 ; real_T kraqf3we4h
; real_T cqyd2pk3x0 ; real_T jyzfjmsmba ; real_T j5ogc35dcx ; real_T
aymajcn1ux ; real_T aybdlnsonf ; real_T jsupm2qpb3 ; real_T bitn2dxr3x ;
real_T bnuy0zz2ow ; real_T k52gxr3n2s ; } X ; typedef struct { real_T
ecfyjwp3hk ; real_T ltlvyqyjyu [ 5 ] ; real_T gclujrpfr4 ; real_T kml2oh1yt0
; real_T kraqf3we4h ; real_T cqyd2pk3x0 ; real_T jyzfjmsmba ; real_T
j5ogc35dcx ; real_T aymajcn1ux ; real_T aybdlnsonf ; real_T jsupm2qpb3 ;
real_T bitn2dxr3x ; real_T bnuy0zz2ow ; real_T k52gxr3n2s ; } XDot ; typedef
struct { boolean_T ecfyjwp3hk ; boolean_T ltlvyqyjyu [ 5 ] ; boolean_T
gclujrpfr4 ; boolean_T kml2oh1yt0 ; boolean_T kraqf3we4h ; boolean_T
cqyd2pk3x0 ; boolean_T jyzfjmsmba ; boolean_T j5ogc35dcx ; boolean_T
aymajcn1ux ; boolean_T aybdlnsonf ; boolean_T jsupm2qpb3 ; boolean_T
bitn2dxr3x ; boolean_T bnuy0zz2ow ; boolean_T k52gxr3n2s ; } XDis ; typedef
struct { real_T ecfyjwp3hk ; real_T ltlvyqyjyu [ 5 ] ; real_T gclujrpfr4 ;
real_T kml2oh1yt0 ; real_T kraqf3we4h ; real_T cqyd2pk3x0 ; real_T jyzfjmsmba
; real_T j5ogc35dcx ; real_T aymajcn1ux ; real_T aybdlnsonf ; real_T
jsupm2qpb3 ; real_T bitn2dxr3x ; real_T bnuy0zz2ow ; real_T k52gxr3n2s ; }
CStateAbsTol ; typedef struct { real_T p5mi14pdfs ; real_T jsouvt4a5a ;
real_T kjks0ywqes ; real_T byzuhbmhlm ; real_T brhgtkbkua ; real_T c2g1mk1m4u
; real_T nyuk2u0f43 ; real_T agjptjfiur ; real_T hqmzut01mc ; real_T
matzkzbiyt ; real_T jgp2qm4pl4 ; } ZCV ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
HydraulicTurbineandGovernor_dref ; real_T HydraulicTurbineandGovernor_po ;
real_T units1_Gain ; real_T Lmq_sat_Y0 ; real_T Laq_Y0 ; real_T uLl_q_Gain [
2 ] ; real_T u2_Value [ 3 ] ; real_T Integrator_IC ; real_T
uDLookupTable_tableData [ 10 ] ; real_T uDLookupTable_bp01Data [ 10 ] ;
real_T Constant1_Value ; real_T Lmq_Gain ; real_T uTT1e6s_Gain ; real_T
Linv_Y0 ; real_T RLinv_Y0 ; real_T Lmqd_Y0 ; real_T Laqd_Y0 ; real_T
uLl_d_Gain [ 3 ] ; real_T u1_Value [ 2 ] ; real_T Integrator_IC_okxqdvaqge ;
real_T uDLookupTable_tableData_oh1wox4m40 [ 10 ] ; real_T
uDLookupTable_bp01Data_i3bi2vd4wx [ 10 ] ; real_T Constant1_Value_j0subfzquq
; real_T Lmd_Gain ; real_T uTT1e6s_Gain_lygg4vbdad ; real_T
u1_Value_g2cyrwvzkh [ 25 ] ; real_T u1_Value_evk3gg0wa2 [ 25 ] ; real_T
u3_Value ; real_T u5_Value [ 25 ] ; real_T u2_Value_dgzm2q1ls3 ; real_T
Rotorangledtheta_IC ; real_T web2_Gain ; real_T Integrator_IC_ae1cznrs4o [ 5
] ; real_T Constant1_Value_fc0guqcyc4 ; real_T Constant3_Value ; real_T
Constant4_Value [ 25 ] ; real_T Switch_Threshold ; real_T
changeIqIdcurrentsigns_Gain [ 5 ] ; real_T ib_Gain ; real_T
StateSpace_P1_Size [ 2 ] ; real_T StateSpace_P1 [ 8 ] ; real_T
StateSpace_P2_Size [ 2 ] ; real_T StateSpace_P2 [ 4 ] ; real_T
StateSpace_P3_Size [ 2 ] ; real_T StateSpace_P4_Size [ 2 ] ; real_T
StateSpace_P4 [ 156 ] ; real_T nomspeed_Value ; real_T
Rotorspeeddeviationdw_IC ; real_T units_Gain ; real_T Constant_Value ; real_T
Constant1_Value_c5r2ow4pnn ; real_T StateSpace_A ; real_T StateSpace_B ;
real_T StateSpace_C ; real_T StateSpace_InitialCondition ; real_T
Constant1_Value_dxffpau3tt ; real_T StateSpace_A_gvjvm0zida ; real_T
StateSpace_B_cw5oh3slxt ; real_T StateSpace_C_brkogrmwzx ; real_T
StateSpace_InitialCondition_fevmgmfoek ; real_T Vfdmax1_Gain ; real_T
Constant_Value_cangz0hlbt ; real_T Constant3_Value_oy0hsbqr4o ; real_T
Vfdmax_Gain ; real_T StateSpace_D ; real_T StateSpace_A_jh2uawflmi ; real_T
StateSpace_B_mmoy0u0fuw ; real_T StateSpace_C_manifxflg5 ; real_T
StateSpace_D_h4wd5niec1 ; real_T StateSpace_InitialCondition_oqtdddz2en ;
real_T Vf0ka_Value ; real_T StateSpace_D_csfvldwlau ; real_T Constant2_Value
; real_T uLl_q_Gain_awlrmeuumw [ 2 ] ; real_T Constant8_Value ; real_T
Laqd_nosat_Value [ 2 ] ; real_T Switch3_Threshold ; real_T
uLl_d_Gain_jijxqv5vxr [ 3 ] ; real_T u_Vb_Gain ; real_T Constant5_Value ;
real_T Lmqd_nosat_Value [ 2 ] ; real_T Switch2_Threshold ; real_T Gain_Gain ;
real_T Gain_Gain_acjk3icicb ; real_T Gain1_Gain ; real_T
outputformatting_Gain [ 18 ] ; real_T Derivative_A ; real_T Derivative_C ;
real_T position_IC ; real_T position_UpperSat ; real_T position_LowerSat ;
real_T u1_Gain [ 2 ] ; real_T Switch_Threshold_b2t0vmw2we ; real_T
permanentdroop_Gain ; real_T Integral_Gain ; real_T Integrator1_IC ; real_T
Proportional_Gain ; real_T servomotor_A ; real_T servomotor_C ; real_T
speedlimit_UpperSat ; real_T speedlimit_LowerSat ; real_T
Constant_Value_f4yyiavgsx ; real_T turbinegain_Gain ; real_T beta_Gain ;
real_T Gain2_Gain ; real_T N_Gain ; real_T Constant2_Value_ewacipohvd ;
real_T Constant6_Value [ 25 ] ; real_T Gain1_Gain_fsvmmhhhj3 ; real_T
u1_Value_c5nzdrro12 [ 25 ] ; real_T Switch1_Threshold ; real_T
Vkd0Vkq10Vkq20_Value [ 2 ] ; real_T wbase_Gain ; real_T u_Pb_Gain ; real_T
F1_Gain ; real_T u_2H_Gain ; real_T theta_IC ; real_T web1_Gain ; real_T
web3_Gain ; boolean_T Constant1_Value_ottz5lhlaz ; boolean_T
Constant2_Value_ihmgbjdayf ; boolean_T Constant3_Value_c5mzzegack ; boolean_T
Constant1_Value_ai2pb13mhx ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
synchronous_generator_modeling_GetCAPIStaticMap ( void ) ; extern SimStruct *
const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( void ) ;
#endif
