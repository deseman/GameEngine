#pragma once

#include "GameEngine/Core.h"
#include "GameEngine/Window.h"
#include "GameEngine/Events/ApplicationEvent.h"

namespace GameEngine {

	class GE_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		bool OnWindowClose(WindowCloseEvent& e);
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	};

	// To be defined in client
	Application* CreateApplication();
}