#include "__cf_synchronous_generator_modeling.h"
#ifndef RTW_HEADER_synchronous_generator_modeling_cap_host_h_
#define RTW_HEADER_synchronous_generator_modeling_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
synchronous_generator_modeling_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void synchronous_generator_modeling_host_InitializeDataMapInfo (
synchronous_generator_modeling_host_DataMapInfo_T * dataMap , const char *
path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
