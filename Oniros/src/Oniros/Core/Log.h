#pragma once
#include <memory>

#include <spdlog/spdlog.h>


namespace Oniros {
	class Log
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

// Core log macros
#define ONI_CORE_TRACE(...)    ::Oniros::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ONI_CORE_INFO(...)     ::Oniros::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ONI_CORE_WARN(...)     ::Oniros::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ONI_CORE_ERROR(...)    ::Oniros::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ONI_CORE_CRITICAL(...) ::Oniros::Log::GetCoreLogger()->critical(__VA_ARGS__)
						
// Client log macros			
#define ONI_TRACE(...)         ::Oniros::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ONI_INFO(...)          ::Oniros::Log::GetClientLogger()->info(__VA_ARGS__)
#define ONI_WARN(...)          ::Oniros::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ONI_ERROR(...)         ::Oniros::Log::GetClientLogger()->error(__VA_ARGS__)
#define ONI_CRITICAL(...)      ::Oniros::Log::GetClientLogger()->critical(__VA_ARGS__)