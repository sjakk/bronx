#pragma once

#	ifdef BRX_PLATFORM_WINDOWS
	#ifdef BRX_BUILD_DLL
		#define BRX_API	__declspec(dllexport)
	#else
	#define BRX_API	__declspec(dllimport)
		#endif // BRX_BUILD_DLL
#else
	#error JUST WINDOWS


#endif

