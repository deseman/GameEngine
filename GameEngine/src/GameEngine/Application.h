#pragma once

#include "GameEngine/Core.h"
#include "GameEngine/Window.h"
#include "GameEngine/LayerStack.h"
#include "GameEngine/Events/ApplicationEvent.h"

namespace GameEngine {

	class GE_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		bool OnWindowClose(WindowCloseEvent& e);
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	};

	// To be defined in client
	Application* CreateApplication();
}