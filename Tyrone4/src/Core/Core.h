#pragma once

#ifdef TY_PLATFORM_WINDOWS
	#ifdef TY_BUILD_DLL
		#define TYRONE4_API __declspec(dllexport)
	#else
		#define TYRONE4_API __declspec(dllimport)
	#endif
#else
	#error Tyrone4 currently supports Windows only.
#endif

#define BIT(x) (1 << x)