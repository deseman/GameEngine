#pragma once

#include "GameEngine/Core/Window.h"
#include "GameEngine/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace GameEngine {

	class WindowsWindow : public Window
	{
	private:
		GLFWwindow* m_Window;
		Scope<GraphicsContext> m_Context;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
		
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline void* GetNativeWindow() const { return m_Window; }
	};
}
