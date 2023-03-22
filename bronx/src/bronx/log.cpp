#include "log.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace bronx {
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;



	void Log::Init() {
		spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
		s_CoreLogger = spdlog::stdout_color_mt("bronx");
		s_CoreLogger->set_level(spdlog::level::trace);


		s_ClientLogger = spdlog::stdout_color_mt("v1");
		s_ClientLogger->set_level(spdlog::level::trace);
	}






}