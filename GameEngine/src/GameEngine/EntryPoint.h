#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern GameEngine::Application* GameEngine::CreateApplication();

int main(int argc, char** argv)
{
	GameEngine::Log::Init();
	LOG_INFO("Game Engine Initialized");

	auto app = GameEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif