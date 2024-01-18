#include "quadcopter_model_capi_host.h"
static quadcopter_model_host_DataMapInfo_T root;
static int initialized = 0;
rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        quadcopter_model_host_InitializeDataMapInfo(&(root), "quadcopter_model");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
