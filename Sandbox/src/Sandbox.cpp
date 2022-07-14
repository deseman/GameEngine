#include <GameEngine.h>

class ExampleLayer : public GameEngine::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		LOG_CLIENT_INFO("ExampleLayer::OnUpdate");
	}

	void OnEvent(GameEngine::Event& event) override
	{
		LOG_CLIENT_TRACE("ExampleLayer::OnEvent - {0}", event);
	}

};

class Sandbox : public GameEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new GameEngine::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

GameEngine::Application* GameEngine::CreateApplication()
{
	return new Sandbox();
}