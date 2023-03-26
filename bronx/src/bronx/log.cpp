#include "log.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
using namespace std;
using namespace spdlog;
namespace bronx {
	shared_ptr<logger> Log::s_CoreLogger;
	shared_ptr<logger> Log::s_ClientLogger;



	void Log::Init() {
		set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
		s_CoreLogger = stdout_color_mt("bronx");
		s_CoreLogger->set_level(level::trace);


		s_ClientLogger = stdout_color_mt("v1");
		s_ClientLogger->set_level(level::trace);
	}






}