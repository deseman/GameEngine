#pragma once

#include "GameEngine.h"

class Sandbox2D : public GameEngine::Layer
{
private:
	GameEngine::OrthographicCameraController m_CameraController;

	// Temp
	GameEngine::Ref<GameEngine::VertexArray> m_SquareVA;
	GameEngine::Ref<GameEngine::Shader> m_FlatColorShader;
	GameEngine::Ref<GameEngine::Texture2D> m_CheckerboardTexture;

	struct ProfileResult
	{
		const char* Name;
		float Time;
	};

	std::vector<ProfileResult> m_ProfileResults;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(GameEngine::Timestep td) override;
	virtual void OnImGuiRender() override;
	void OnEvent(GameEngine::Event& e) override;
};

