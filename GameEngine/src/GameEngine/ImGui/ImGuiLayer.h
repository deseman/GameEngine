#pragma once

#include "GameEngine/Layer.h"
#include "GameEngine/Events/ApplicationEvent.h"
#include "GameEngine/Events/MouseEvent.h"
#include "GameEngine/Events/KeyEvent.h"

namespace GameEngine {

	class GE_API ImGuiLayer : public Layer
	{
	private:
		float m_Time = 0.0f;
	private:
		bool OnMouseButtonPressed(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleased(MouseButtonReleasedEvent& e);
		bool OnMouseMoved(MouseMovedEvent& e);
		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnKeyPressed(KeyPressedEvent& e);
		bool OnKeyReleased(KeyReleasedEvent& e);
		bool OnKeyTyped(KeyTypedEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	};
}