// CVTutor.ImgProc.CommonLib.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "CVTutor.ImgProc.CommonLib.h"


// This is an example of an exported variable
CVTUTORIMGPROCCOMMONLIB_API int nCVTutorImgProcCommonLib=0;

// This is an example of an exported function.
CVTUTORIMGPROCCOMMONLIB_API int fnCVTutorImgProcCommonLib(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see CVTutor.ImgProc.CommonLib.h for the class definition
CCVTutorImgProcCommonLib::CCVTutorImgProcCommonLib()
{
    return;
}
