// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CVTUTORIMGPROCCOMMONLIB_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CVTUTORIMGPROCCOMMONLIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CVTUTORIMGPROCCOMMONLIB_EXPORTS
#define CVTUTORIMGPROCCOMMONLIB_API __declspec(dllexport)
#else
#define CVTUTORIMGPROCCOMMONLIB_API __declspec(dllimport)
#endif

// This class is exported from the CVTutor.ImgProc.CommonLib.dll
class CVTUTORIMGPROCCOMMONLIB_API CCVTutorImgProcCommonLib {
public:
	CCVTutorImgProcCommonLib(void);
	// TODO: add your methods here.
};

extern CVTUTORIMGPROCCOMMONLIB_API int nCVTutorImgProcCommonLib;

CVTUTORIMGPROCCOMMONLIB_API int fnCVTutorImgProcCommonLib(void);
