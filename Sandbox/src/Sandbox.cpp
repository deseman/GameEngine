#include <GameEngine.h>

#include "imgui/imgui.h"

class ExampleLayer : public GameEngine::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		//LOG_CLIENT_INFO("ExampleLayer::OnUpdate");

		if (GameEngine::Input::IsKeyPressed(GE_KEY_TAB))
			LOG_CLIENT_INFO("Tab key is pressed!");
	}

	void OnEvent(GameEngine::Event& event) override
	{
		// LOG_CLIENT_TRACE("ExampleLayer::OnEvent - {0}", event);
	}

};

class Sandbox : public GameEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

GameEngine::Application* GameEngine::CreateApplication()
{
	return new Sandbox();
}