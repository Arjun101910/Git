#include "synchronous_generator_modeling_capi_host.h"
static synchronous_generator_modeling_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        synchronous_generator_modeling_host_InitializeDataMapInfo(&(root), "synchronous_generator_modeling");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
