#pragma once

#ifdef GE_PLATFORM_WINDOWS
	#ifdef GE_BUILD_DLL
		#define GE_API __declspec(dllexport)
	#else
		#define GE_API __declspec(dllimport)
	#endif
#else
	#error GameEngine only supports Windows!
#endif

#ifdef GE_ENABLE_ASSERTS
	#define GE_ASSERT(x, ...) { if(!(x)) { LOG_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define GE_CLIENT_ASSERT(x, ...) { if(!(x)) { LOG_CLIENT_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define GE_ASSERT(x, ...)
	#define GE_CLIENT_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define GE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1) 