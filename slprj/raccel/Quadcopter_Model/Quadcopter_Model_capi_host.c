#include "Quadcopter_Model_capi_host.h"
static Quadcopter_Model_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        Quadcopter_Model_host_InitializeDataMapInfo(&(root), "Quadcopter_Model");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
