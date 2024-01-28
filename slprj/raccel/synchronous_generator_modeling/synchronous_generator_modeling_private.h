#include "__cf_synchronous_generator_modeling.h"
#ifndef RTW_HEADER_synchronous_generator_modeling_private_h_
#define RTW_HEADER_synchronous_generator_modeling_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
extern void rt_invd5x5_snf ( const real_T u [ 25 ] , real_T y [ 25 ] ) ;
extern real_T look1_pbinlxpw ( real_T u0 , const real_T bp0 [ ] , const
real_T table [ ] , uint32_T prevIndex [ ] , uint32_T maxIndex ) ; extern void
sfun_spid_contc ( SimStruct * rts ) ;
#if defined(MULTITASKING)
#error Models using the variable step solvers cannot define MULTITASKING
#endif
#endif
