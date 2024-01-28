#include "__cf_synchronous_generator_modeling.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "synchronous_generator_modeling_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "synchronous_generator_modeling.h"
#include "synchronous_generator_modeling_capi.h"
#include "synchronous_generator_modeling_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Positive Sequence Voltage"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 , TARGET_STRING (
"synchronous_generator_modeling/Excitation System/Model/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/permanent droop"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/Sum1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 5 , 1 , TARGET_STRING (
"synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/Sum5" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/N"
) , TARGET_STRING ( "Vfd" ) , 0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/1_(2H)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/1_Pb"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/F1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/units"
) , TARGET_STRING ( "n" ) , 0 , 0 , 0 , 0 , 0 } , { 12 , 1 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/units1"
) , TARGET_STRING ( "Pe" ) , 0 , 0 , 0 , 0 , 0 } , { 13 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/web1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/web2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/web3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/Rotor angle dtheta"
) , TARGET_STRING ( "d_theta (rad)" ) , 0 , 0 , 0 , 0 , 0 } , { 17 , 0 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/Rotor speed deviation (dw)"
) , TARGET_STRING ( "dw" ) , 0 , 0 , 0 , 0 , 0 } , { 18 , 1 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/Product"
) , TARGET_STRING ( "Pe" ) , 0 , 0 , 0 , 0 , 0 } , { 19 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/Sum"
) , TARGET_STRING ( "n" ) , 0 , 0 , 0 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 21 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/Sum3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 22 , 0 , TARGET_STRING (
"synchronous_generator_modeling/powergui/EquivalentModel1/State-Space" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 23 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Damping kfd.s | (tfd.s+1)/State Space"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 24 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Exciter 1| (te.s+ke)/State Space"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 25 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Lead Lag Compensator (tc.s+1) | (tb.s+1)/State Space"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 26 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Low Pass Filter 1 | (tr.s+1)/State Space"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 27 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Main Regulator ka | (ta.s +1)/State Space"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 28 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Proportional Saturation/Data Type  Conversion"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 29 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Proportional Saturation/Data Type  Conversion2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 30 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Proportional Saturation/Vfdmax"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 31 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Proportional Saturation/Vfdmax1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 32 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Proportional Saturation/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 33 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Proportional Saturation/Product1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 34 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Proportional Saturation/Product2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 35 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Proportional Saturation/Sum"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 36 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Proportional Saturation/Sum1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 37 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/PID/Integral"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 38 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/PID/Proportional"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 39 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/PID/Integrator1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 40 , 0 , TARGET_STRING (
"synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/PID/Sum"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 41 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/PID/Derivative"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 42 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/servo-motor/position"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 43 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/servo-motor/speed limit"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 44 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/servo-motor/Sum4"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 45 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/servo-motor/servo- motor"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 46 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/turbine/Gain2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 47 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/turbine/beta"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 48 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/turbine/turbine gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 49 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/turbine/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 50 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/turbine/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 51 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/turbine/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 52 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/turbine/Sum3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 53 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Machine measurements/output formatting"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 54 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Machine measurements/Switch"
) , TARGET_STRING ( "ikq2" ) , 0 , 0 , 0 , 0 , 0 } , { 55 , 5 , TARGET_STRING
(
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 56 , 5 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 1 , 0 , 3 , 0 , 0 } , { 57 , 5 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 2 , 0 , 0 , 0 , 0 } , { 58 , 5 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "Lmsatd" ) , 2 , 0 , 0 , 0 , 0 } , { 59 , 5 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 3 , 0 , 0 , 0 , 0 } , { 60 , 5 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation"
) , TARGET_STRING ( "" ) , 3 , 0 , 0 , 0 , 0 } , { 61 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/change Iq Id  current signs"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 62 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Product3"
) , TARGET_STRING ( "I(k)" ) , 0 , 0 , 4 , 0 , 0 } , { 63 , 0 , TARGET_STRING
(
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Sum1"
) , TARGET_STRING ( "A" ) , 0 , 0 , 3 , 0 , 0 } , { 64 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Switch"
) , TARGET_STRING ( "Linv" ) , 0 , 0 , 3 , 0 , 0 } , { 65 , 0 , TARGET_STRING
(
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 66 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 67 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Switch3"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 68 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/abc to qd transformation/1_Vb"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 69 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/qd to abc transformation/ib"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 70 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/qd to abc transformation/Sum"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 71 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Machine measurements/PQ/Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 72 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Machine measurements/PQ/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 73 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Machine measurements/PQ/Product2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 74 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Machine measurements/PQ/Product3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 75 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Machine measurements/PQ/Product4"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 76 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Machine measurements/PQ/Product5"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 77 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Machine measurements/PQ/Sum"
) , TARGET_STRING ( "Peo" ) , 0 , 0 , 0 , 0 , 0 } , { 78 , 0 , TARGET_STRING
(
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Machine measurements/PQ/Sum1"
) , TARGET_STRING ( "Qeo" ) , 0 , 0 , 0 , 0 , 0 } , { 79 , 0 , TARGET_STRING
(
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Electromagnetic Torque/1-1"
) , TARGET_STRING ( "iqs -ids" ) , 0 , 0 , 1 , 0 , 0 } , { 80 , 0 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Electromagnetic Torque/Mult1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 81 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Electromagnetic Torque/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 82 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Matrix W/Gain1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 83 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Phimqd/1//Ll_d"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 84 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Phimqd/1//Ll_q"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 85 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Phimqd/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 86 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Phimqd/Product1"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 87 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Phimqd/sum1"
) , TARGET_STRING ( "phimd" ) , 0 , 0 , 0 , 0 , 0 } , { 88 , 0 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Phimqd/sum2"
) , TARGET_STRING ( "phimq" ) , 0 , 0 , 0 , 0 , 0 } , { 89 , 4 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 90 , 4 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat"
) , TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 91 , 5 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Product1"
) , TARGET_STRING ( "R*Linv" ) , 0 , 0 , 3 , 0 , 0 } , { 92 , 5 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/inversion"
) , TARGET_STRING ( "Linv" ) , 0 , 0 , 3 , 0 , 0 } , { 93 , 5 , TARGET_STRING
(
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 94 , 5 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Switch2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 95 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/phi/wbase"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 96 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/phi/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 97 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/phi/Product1"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 98 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/phi/sum1"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 0 } , { 99 , 0 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Machine measurements/Delta angle/Radians to Degrees/Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 100 , 5 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Abs"
) , TARGET_STRING ( "Phisat" ) , 0 , 0 , 0 , 0 , 0 } , { 101 , 5 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lmd"
) , TARGET_STRING ( "Lmsatd" ) , 0 , 0 , 0 , 0 , 0 } , { 102 , 5 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/1-D Lookup Table"
) , TARGET_STRING ( "Ifdsat" ) , 0 , 0 , 0 , 0 , 0 } , { 103 , 2 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 104 , 5 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 105 , 4 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Abs"
) , TARGET_STRING ( "Phisat" ) , 0 , 0 , 0 , 0 , 0 } , { 106 , 4 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Lmq"
) , TARGET_STRING ( "Lmsatq" ) , 0 , 0 , 0 , 0 , 0 } , { 107 , 4 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/1-D Lookup Table"
) , TARGET_STRING ( "Ifqsat" ) , 0 , 0 , 0 , 0 , 0 } , { 108 , 3 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 109 , 4 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 110 , 5 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Update Matrix L/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 0 } , { 111 , 5 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lad/Math Function3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 112 , 5 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lad/Sum1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 113 , 5 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 114 , 5 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 115 , 5 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 116 , 5 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/phimd/1//Ll_d"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 117 , 5 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/phimd/Product4"
) , TARGET_STRING ( "phimd" ) , 0 , 0 , 0 , 0 , 0 } , { 118 , 5 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/phimd/sum2"
) , TARGET_STRING ( "phimd" ) , 0 , 0 , 0 , 0 , 0 } , { 119 , 4 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Laq/Math Function1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 120 , 4 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Laq/Sum2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 121 , 4 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 122 , 4 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 123 , 4 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/Add"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 124 , 4 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/phimq/1//Ll_q"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 125 , 4 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/phimq/Product3"
) , TARGET_STRING ( "phimq" ) , 0 , 0 , 0 , 0 , 0 } , { 126 , 4 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/phimq/sum1"
) , TARGET_STRING ( "phimq" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , (
NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 127 , TARGET_STRING (
"synchronous_generator_modeling/Hydraulic Turbine and Governor" ) ,
TARGET_STRING ( "dref" ) , 0 , 0 , 0 } , { 128 , TARGET_STRING (
"synchronous_generator_modeling/Hydraulic Turbine and Governor" ) ,
TARGET_STRING ( "po" ) , 0 , 0 , 0 } , { 129 , TARGET_STRING (
"synchronous_generator_modeling/Constant" ) , TARGET_STRING ( "Value" ) , 0 ,
0 , 0 } , { 130 , TARGET_STRING ( "synchronous_generator_modeling/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 131 , TARGET_STRING (
"synchronous_generator_modeling/Excitation System/Model/Vf0| ka" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 132 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/permanent droop"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 133 , TARGET_STRING (
"synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/Switch"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 134 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/[ Vkd =0 Vkq1=0  Vkq2=0 ]"
) , TARGET_STRING ( "Value" ) , 0 , 6 , 0 } , { 135 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/N"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 136 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/nom. speed"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 137 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/1_(2H)"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 138 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/1_Pb"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 139 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/F1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 140 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/units"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 141 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/units1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 142 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/web1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 143 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/web2"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 144 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/web3"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 145 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/Rotor angle dtheta"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 146 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/Rotor speed deviation (dw)"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 147 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Mechanical model/theta"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 148 ,
TARGET_STRING (
"synchronous_generator_modeling/powergui/EquivalentModel1/State-Space" ) ,
TARGET_STRING ( "P1" ) , 0 , 7 , 0 } , { 149 , TARGET_STRING (
"synchronous_generator_modeling/powergui/EquivalentModel1/State-Space" ) ,
TARGET_STRING ( "P2" ) , 0 , 8 , 0 } , { 150 , TARGET_STRING (
"synchronous_generator_modeling/powergui/EquivalentModel1/State-Space" ) ,
TARGET_STRING ( "P4" ) , 0 , 9 , 0 } , { 151 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Damping kfd.s | (tfd.s+1)/State Space"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 152 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Damping kfd.s | (tfd.s+1)/State Space"
) , TARGET_STRING ( "B" ) , 0 , 0 , 0 } , { 153 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Damping kfd.s | (tfd.s+1)/State Space"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 154 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Damping kfd.s | (tfd.s+1)/State Space"
) , TARGET_STRING ( "D" ) , 0 , 0 , 0 } , { 155 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Damping kfd.s | (tfd.s+1)/State Space"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 156 ,
TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Exciter 1| (te.s+ke)/State Space"
) , TARGET_STRING ( "D" ) , 0 , 0 , 0 } , { 157 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Lead Lag Compensator (tc.s+1) | (tb.s+1)/State Space"
) , TARGET_STRING ( "D" ) , 0 , 0 , 0 } , { 158 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Low Pass Filter 1 | (tr.s+1)/State Space"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 159 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Low Pass Filter 1 | (tr.s+1)/State Space"
) , TARGET_STRING ( "B" ) , 0 , 0 , 0 } , { 160 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Low Pass Filter 1 | (tr.s+1)/State Space"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 161 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Low Pass Filter 1 | (tr.s+1)/State Space"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 162 ,
TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Main Regulator ka | (ta.s +1)/State Space"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 163 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Main Regulator ka | (ta.s +1)/State Space"
) , TARGET_STRING ( "B" ) , 0 , 0 , 0 } , { 164 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Main Regulator ka | (ta.s +1)/State Space"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 165 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Main Regulator ka | (ta.s +1)/State Space"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 166 ,
TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Proportional Saturation/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 167 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Proportional Saturation/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 168 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Proportional Saturation/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 169 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Proportional Saturation/Vfdmax"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 170 , TARGET_STRING (
 "synchronous_generator_modeling/Excitation System/Model/Proportional Saturation/Vfdmax1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 171 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/PID/Integral"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 172 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/PID/Proportional"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 173 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/PID/Integrator1"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 174 ,
TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/PID/Derivative"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 175 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/PID/Derivative"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 176 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/servo-motor/position"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 177 ,
TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/servo-motor/position"
) , TARGET_STRING ( "UpperSaturationLimit" ) , 0 , 0 , 0 } , { 178 ,
TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/servo-motor/position"
) , TARGET_STRING ( "LowerSaturationLimit" ) , 0 , 0 , 0 } , { 179 ,
TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/servo-motor/speed limit"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 180 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/servo-motor/speed limit"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 181 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/servo-motor/servo- motor"
) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 182 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/servo-motor/servo- motor"
) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 183 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/turbine/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 184 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/turbine/Gain2"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 185 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/turbine/beta"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 186 , TARGET_STRING (
 "synchronous_generator_modeling/Hydraulic Turbine and Governor/Model/turbine/turbine gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 187 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Machine measurements/Constant1"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 188 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Machine measurements/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 189 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Machine measurements/output formatting"
) , TARGET_STRING ( "Gain" ) , 0 , 10 , 0 } , { 190 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 191 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 192 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 193 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 3 , 0 } , { 194 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Constant5"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 195 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Constant6"
) , TARGET_STRING ( "Value" ) , 0 , 3 , 0 } , { 196 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Constant8"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 197 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Laqd_nosat"
) , TARGET_STRING ( "Value" ) , 0 , 6 , 0 } , { 198 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Lmqd_nosat"
) , TARGET_STRING ( "Value" ) , 0 , 6 , 0 } , { 199 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/change Iq Id  current signs"
) , TARGET_STRING ( "Gain" ) , 0 , 11 , 0 } , { 200 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Switch"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 201 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Switch1"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 202 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Switch2"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 203 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Switch3"
) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 204 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/abc to qd transformation/1_Vb"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 205 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/qd to abc transformation/ib"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 206 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Machine measurements/PQ/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 207 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Machine measurements/PQ/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 208 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Electromagnetic Torque/1-1"
) , TARGET_STRING ( "Gain" ) , 0 , 6 , 0 } , { 209 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Matrix W/u1"
) , TARGET_STRING ( "Value" ) , 0 , 3 , 0 } , { 210 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Matrix W/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 211 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Phimqd/1//Ll_d"
) , TARGET_STRING ( "Gain" ) , 0 , 12 , 0 } , { 212 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Phimqd/1//Ll_q"
) , TARGET_STRING ( "Gain" ) , 0 , 6 , 0 } , { 213 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Linv"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 214 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/R*Linv"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 215 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmqd"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 216 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Laqd"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 217 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Constant1"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 218 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Constant2"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 219 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Constant3"
) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } , { 220 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/u1"
) , TARGET_STRING ( "Value" ) , 0 , 3 , 0 } , { 221 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/u2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 222 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/u3"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 223 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/phi/wbase"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 224 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/phi/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 4 , 0 } , { 225 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Machine measurements/Delta angle/Radians to Degrees/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 226 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 227 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lmd"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 228 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/1-D Lookup Table"
) , TARGET_STRING ( "Table" ) , 0 , 13 , 0 } , { 229 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/1-D Lookup Table"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 13 , 0 } , { 230 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Lmq_sat "
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 231 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Laq_"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 232 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 233 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Lmq"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 234 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/1-D Lookup Table"
) , TARGET_STRING ( "Table" ) , 0 , 13 , 0 } , { 235 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/1-D Lookup Table"
) , TARGET_STRING ( "BreakpointsForDimension1" ) , 0 , 13 , 0 } , { 236 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Update Matrix L/u1"
) , TARGET_STRING ( "Value" ) , 0 , 3 , 0 } , { 237 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Update Matrix L/u5"
) , TARGET_STRING ( "Value" ) , 0 , 3 , 0 } , { 238 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Lad/u1"
) , TARGET_STRING ( "Value" ) , 0 , 6 , 0 } , { 239 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 240 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/Time Constant/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 241 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmd_sat/phimd/1//Ll_d"
) , TARGET_STRING ( "Gain" ) , 0 , 12 , 0 } , { 242 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Laq/u2"
) , TARGET_STRING ( "Value" ) , 0 , 12 , 0 } , { 243 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/1//T (T= 1e-6s)"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 244 , TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/Time Constant/Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 245 ,
TARGET_STRING (
 "synchronous_generator_modeling/Synchronous Machine pu Standard/Electrical model/Synchronous Machine Continuous Model/Saturation/Lmq_sat/phimq/1//Ll_q"
) , TARGET_STRING ( "Gain" ) , 0 , 6 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { {
0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . em31irqwpt , & rtB . b0uhmkj3mn ,
& rtB . oiib5ytjjg , & rtB . jf2gkiczhf , & rtB . diraslnu04 , & rtB .
en43ee13dp , & rtB . pz33wqr5tx , & rtB . hvj0m54a5e , & rtB . p2ygvmxt5i , &
rtB . jiyiyrbb4a , & rtB . j0j5dylxjw , & rtB . cb01jjmyfq , & rtB .
kf5ffc0rj1 , & rtB . inhavjn1zx , & rtB . f0tfi2aikm , & rtB . gwtwwxhuqy , &
rtB . kr1l0f0n1y , & rtB . hodx3vvveu , & rtB . mkzsniweyj , & rtB .
b4cekmi0wt , & rtB . jvdtj4iup3 , & rtB . hcevlizke0 , & rtB . hrt2qdvvir [ 0
] , & rtB . gu3pd23vmg , & rtB . bc2m5qcx30 , & rtB . frbgfp02s3 , & rtB .
kxk0zjan2u , & rtB . fiofh4kefk , & rtB . grv35kz54w , & rtB . inr4gxt4lu , &
rtB . odntfboinc , & rtB . eavm2lmu4f , & rtB . pfingzy4pc , & rtB .
iwds2hww0j , & rtB . php2zq2lhw , & rtB . fjd5s1suaw , & rtB . bcynuxf3b4 , &
rtB . jplifgq5sc , & rtB . pgkbrhcuia , & rtB . nvfqaxwy3k , & rtB .
bl21y1dth5 , & rtB . c4gaogg0kl , & rtB . n0daf3kfkx , & rtB . dcj3g23bnj , &
rtB . eslj0xnqak , & rtB . m5410f2s1r , & rtB . ftidkuimh2 , & rtB .
be2hetqlgl , & rtB . ekypfbfahe , & rtB . gz1es4awfp , & rtB . b2bhql0adz , &
rtB . g0sbc5omlb , & rtB . hddv0reyvo , & rtB . dafsczeyd0 [ 0 ] , & rtB .
frxkjjxjkt , & rtB . pbau2lhp5g [ 0 ] , & rtB . fbgrxsow4f [ 0 ] , & rtB .
a5unwbreth , & rtB . mg4fjb0upp , & rtB . fyyh0ebqhq , & rtB . h0b31s25s4 , &
rtB . plsr00p5pu [ 0 ] , & rtB . hgnzqmdjot [ 0 ] , & rtB . mhkgnw5dfa [ 0 ]
, & rtB . ju1jshvwhr [ 0 ] , & rtB . c2k2l0344v [ 0 ] , & rtB . m2tczfrive [
0 ] , & rtB . lbzic3bakw [ 0 ] , & rtB . dytwitjqmo [ 0 ] , & rtB .
ieios15ick [ 0 ] , & rtB . omelmho425 , & rtB . lhqwbn1q25 , & rtB .
gfo2bsicyk , & rtB . d1kjzcrxkd , & rtB . krjvbt2mq4 , & rtB . plibi3b3wz , &
rtB . ofl3u43bgw , & rtB . pzqvo3sq2r , & rtB . c3oz1evhcw , & rtB .
p40ujyoefj [ 0 ] , & rtB . dc5nymbuqt [ 0 ] , & rtB . fikrci5wnj , & rtB .
dfmiczstqr , & rtB . n4pe4taf5k [ 0 ] , & rtB . jw0piz2ncq [ 0 ] , & rtB .
m33avxegzn [ 0 ] , & rtB . f3bhe2mrrl [ 0 ] , & rtB . aekodpeb5p , & rtB .
cnczf5kl3f , & rtB . kmznpd4a0b , & rtB . pwe1eclt2g , & rtB . fbgrxsow4f [ 0
] , & rtB . pbau2lhp5g [ 0 ] , & rtB . a5unwbreth , & rtB . fyyh0ebqhq , &
rtB . pubf0ms0bt [ 0 ] , & rtB . aevoxybjly [ 0 ] , & rtB . j3gwtsr3ih [ 0 ]
, & rtB . gqdszdjmco [ 0 ] , & rtB . fxn4vwgtsq , & rtB . jsb2lzsy5d , & rtB
. mg4fjb0upp , & rtB . cheoaxmkwf , & rtB . ixrm34qqkr , & rtB . citrubba04 ,
& rtB . pz1e453xyk , & rtB . kmznpd4a0b , & rtB . g50stc2bsg , & rtB .
onh15amb3y , & rtB . nh3cfumtvt , & rtB . ggkhauomxo [ 0 ] , & rtB .
h0b31s25s4 , & rtB . ftfak5o3sh , & rtB . f4ykvphd3j , & rtB . pzj0ccucw1 , &
rtB . jtyymi0w2q , & rtB . i04fclefuh [ 0 ] , & rtB . ilq0fkqsof , & rtB .
cyggjdadcr , & rtB . pwe1eclt2g , & rtB . koxeovukjp , & rtB . mrxcfcjegz , &
rtB . dlsxci2kgl , & rtB . onshuqhaip , & rtB . o5bfaqvpcy [ 0 ] , & rtB .
lqkqphi04w , & rtB . ix4epb55wg , & rtP . HydraulicTurbineandGovernor_dref ,
& rtP . HydraulicTurbineandGovernor_po , & rtP . Constant_Value , & rtP .
Constant1_Value_c5r2ow4pnn , & rtP . Vf0ka_Value , & rtP .
permanentdroop_Gain , & rtP . Switch_Threshold_b2t0vmw2we , & rtP .
Vkd0Vkq10Vkq20_Value [ 0 ] , & rtP . N_Gain , & rtP . nomspeed_Value , & rtP
. u_2H_Gain , & rtP . u_Pb_Gain , & rtP . F1_Gain , & rtP . units_Gain , &
rtP . units1_Gain , & rtP . web1_Gain , & rtP . web2_Gain , & rtP . web3_Gain
, & rtP . Rotorangledtheta_IC , & rtP . Rotorspeeddeviationdw_IC , & rtP .
theta_IC , & rtP . StateSpace_P1 [ 0 ] , & rtP . StateSpace_P2 [ 0 ] , & rtP
. StateSpace_P4 [ 0 ] , & rtP . StateSpace_A_jh2uawflmi , & rtP .
StateSpace_B_mmoy0u0fuw , & rtP . StateSpace_C_manifxflg5 , & rtP .
StateSpace_D_h4wd5niec1 , & rtP . StateSpace_InitialCondition_oqtdddz2en , &
rtP . StateSpace_D , & rtP . StateSpace_D_csfvldwlau , & rtP .
StateSpace_A_gvjvm0zida , & rtP . StateSpace_B_cw5oh3slxt , & rtP .
StateSpace_C_brkogrmwzx , & rtP . StateSpace_InitialCondition_fevmgmfoek , &
rtP . StateSpace_A , & rtP . StateSpace_B , & rtP . StateSpace_C , & rtP .
StateSpace_InitialCondition , & rtP . Constant_Value_cangz0hlbt , & rtP .
Constant1_Value_dxffpau3tt , & rtP . Constant3_Value_oy0hsbqr4o , & rtP .
Vfdmax_Gain , & rtP . Vfdmax1_Gain , & rtP . Integral_Gain , & rtP .
Proportional_Gain , & rtP . Integrator1_IC , & rtP . Derivative_A , & rtP .
Derivative_C , & rtP . position_IC , & rtP . position_UpperSat , & rtP .
position_LowerSat , & rtP . speedlimit_UpperSat , & rtP . speedlimit_LowerSat
, & rtP . servomotor_A , & rtP . servomotor_C , & rtP .
Constant_Value_f4yyiavgsx , & rtP . Gain2_Gain , & rtP . beta_Gain , & rtP .
turbinegain_Gain , & rtP . Constant1_Value_ai2pb13mhx , & rtP .
Constant2_Value , & rtP . outputformatting_Gain [ 0 ] , & rtP .
Constant1_Value_fc0guqcyc4 , & rtP . Constant2_Value_ewacipohvd , & rtP .
Constant3_Value , & rtP . Constant4_Value [ 0 ] , & rtP . Constant5_Value , &
rtP . Constant6_Value [ 0 ] , & rtP . Constant8_Value , & rtP .
Laqd_nosat_Value [ 0 ] , & rtP . Lmqd_nosat_Value [ 0 ] , & rtP .
changeIqIdcurrentsigns_Gain [ 0 ] , & rtP . Switch_Threshold , & rtP .
Switch1_Threshold , & rtP . Switch2_Threshold , & rtP . Switch3_Threshold , &
rtP . u_Vb_Gain , & rtP . ib_Gain , & rtP . Gain_Gain_acjk3icicb , & rtP .
Gain1_Gain , & rtP . u1_Gain [ 0 ] , & rtP . u1_Value_c5nzdrro12 [ 0 ] , &
rtP . Gain1_Gain_fsvmmhhhj3 , & rtP . uLl_d_Gain_jijxqv5vxr [ 0 ] , & rtP .
uLl_q_Gain_awlrmeuumw [ 0 ] , & rtP . Linv_Y0 , & rtP . RLinv_Y0 , & rtP .
Lmqd_Y0 , & rtP . Laqd_Y0 , & rtP . Constant1_Value_ottz5lhlaz , & rtP .
Constant2_Value_ihmgbjdayf , & rtP . Constant3_Value_c5mzzegack , & rtP .
u1_Value_g2cyrwvzkh [ 0 ] , & rtP . u2_Value_dgzm2q1ls3 , & rtP . u3_Value ,
& rtP . wbase_Gain , & rtP . Integrator_IC_ae1cznrs4o [ 0 ] , & rtP .
Gain_Gain , & rtP . Constant1_Value_j0subfzquq , & rtP . Lmd_Gain , & rtP .
uDLookupTable_tableData_oh1wox4m40 [ 0 ] , & rtP .
uDLookupTable_bp01Data_i3bi2vd4wx [ 0 ] , & rtP . Lmq_sat_Y0 , & rtP . Laq_Y0
, & rtP . Constant1_Value , & rtP . Lmq_Gain , & rtP .
uDLookupTable_tableData [ 0 ] , & rtP . uDLookupTable_bp01Data [ 0 ] , & rtP
. u1_Value_evk3gg0wa2 [ 0 ] , & rtP . u5_Value [ 0 ] , & rtP . u1_Value [ 0 ]
, & rtP . uTT1e6s_Gain_lygg4vbdad , & rtP . Integrator_IC_okxqdvaqge , & rtP
. uLl_d_Gain [ 0 ] , & rtP . u2_Value [ 0 ] , & rtP . uTT1e6s_Gain , & rtP .
Integrator_IC , & rtP . uLl_q_Gain [ 0 ] , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } , {
"unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , SS_BOOLEAN , 0
, 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } , {
rtwCAPI_VECTOR , 12 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 14 , 2 , 0 } , {
rtwCAPI_VECTOR , 16 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 18 , 2 , 0 } , {
rtwCAPI_VECTOR , 20 , 2 , 0 } , { rtwCAPI_VECTOR , 22 , 2 , 0 } , {
rtwCAPI_VECTOR , 24 , 2 , 0 } , { rtwCAPI_VECTOR , 26 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 2 , 1 , 18 , 1 , 5 , 5 , 5 , 1
, 3 , 1 , 1 , 2 , 4 , 2 , 1 , 4 , 4 , 39 , 1 , 18 , 1 , 5 , 1 , 3 , 1 , 10 }
; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 1 ,
0 } , { ( NULL ) , ( NULL ) , 2 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 127 , ( NULL
) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 119 , rtModelParameters , 0 }
, { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap ,
rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" , { 3651298471U
, 610010315U , 2930865888U , 89649121U } , ( NULL ) , 0 , 0 } ; const
rtwCAPI_ModelMappingStaticInfo *
synchronous_generator_modeling_GetCAPIStaticMap ( void ) { return & mmiStatic
; }
#ifndef HOST_CAPI_BUILD
void synchronous_generator_modeling_InitializeDataMapInfo ( void ) {
rtwCAPI_SetVersion ( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetDataAddressMap ( ( * rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ;
rtwCAPI_SetVarDimsAddressMap ( ( * rt_dataMapInfoPtr ) . mmi ,
rtVarDimsAddrMap ) ; rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr )
. mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi
, ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi ,
0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void synchronous_generator_modeling_host_InitializeDataMapInfo (
synchronous_generator_modeling_host_DataMapInfo_T * dataMap , const char *
path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap (
dataMap -> mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi ,
NULL ) ; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , NULL ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
