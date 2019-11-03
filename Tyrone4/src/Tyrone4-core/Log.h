#pragma once

#include <memory.h>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Tyrone4 {

	class TYRONE4_API Log {
		
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define TY_CORE_ERROR(...)         ::Tyrone4::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TY_CORE_WARN(...)          ::Tyrone4::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TY_CORE_INFO(...)          ::Tyrone4::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TY_CORE_TRACE(...)         ::Tyrone4::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TY_CORE_FATAL(...)         ::Tyrone4::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define TY_CLIENT_ERROR(...)       ::Tyrone4::Log::GetClientLogger()->error(__VA_ARGS__)
#define TY_CLIENT_WARN(...)        ::Tyrone4::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TY_CLIENT_INFO(...)        ::Tyrone4::Log::GetClientLogger()->info(__VA_ARGS__)
#define TY_CLIENT_TRACE(...)       ::Tyrone4::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TY_CLIENT_FATAL(...)       ::Tyrone4::Log::GetClientLogger()->fatal(__VA_ARGS__)