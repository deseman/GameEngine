#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern GameEngine::Application* GameEngine::CreateApplication();

int main(int argc, char** argv)
{
	GameEngine::Log::Init();
	LOG_TRACE("This is a trace message");
	LOG_DEBUG("This is a debug message");
	LOG_INFO("This is an info message");
	LOG_WARN("This is a warning message");
	LOG_ERROR("This is an error message");
	
	CLIENT_LOG_TRACE("This is a trace message");
	CLIENT_LOG_DEBUG("This is a debug message");
	CLIENT_LOG_INFO("This is an info message");
	CLIENT_LOG_WARN("This is a warning message");
	CLIENT_LOG_ERROR("This is an error message");

	auto app = GameEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif