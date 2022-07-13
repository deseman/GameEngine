#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace GameEngine {
	
	class GE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

#define LOG_ERROR(...)        ::GameEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_WARN(...)         ::GameEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_INFO(...)         ::GameEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_DEBUG(...)        ::GameEngine::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define LOG_TRACE(...)        ::GameEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)

#define CLIENT_LOG_ERROR(...) ::GameEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CLIENT_LOG_WARN(...)  ::GameEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CLIENT_LOG_INFO(...)  ::GameEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CLIENT_LOG_DEBUG(...) ::GameEngine::Log::GetClientLogger()->debug(__VA_ARGS__)
#define CLIENT_LOG_TRACE(...) ::GameEngine::Log::GetClientLogger()->trace(__VA_ARGS__)