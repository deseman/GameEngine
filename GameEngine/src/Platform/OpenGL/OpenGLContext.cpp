#include "gepch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <gl/GL.h>

namespace GameEngine {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		GE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		GE_ASSERT(status, "Failed to initialize Glad!");

		LOG_INFO("OpenGL Info");
		LOG_INFO("   Vendor   : {0}", glGetString(GL_VENDOR));
		LOG_INFO("   Renderer : {0}", glGetString(GL_RENDERER));
		LOG_INFO("   Vendor   : {0}", glGetString(GL_VERSION));

#ifdef GE_ENABLE_ASSERTS
		int versionMajor, versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		GE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "OpenGL version 4.5 or higher is required!")
#endif
	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}