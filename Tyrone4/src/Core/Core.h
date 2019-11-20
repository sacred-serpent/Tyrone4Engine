#pragma once

// Core file contains build information.

#ifdef TY_PLATFORM_WINDOWS
	#ifdef TY_BUILD_DLL
		#define TYRONE4_API __declspec(dllexport)
	#else
		#define TYRONE4_API __declspec(dllimport)
	#endif
#else
	#error Tyrone4 currently supports Windows only.
#endif

#ifdef TY_ENABLE_ASSERTS
	#define TY_CORE_ASSERT(x, ...) { if (!(x)) { TY_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define TY_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)