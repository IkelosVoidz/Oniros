#include "onipch.h"
#include "Window.h"
#include <SDL3/SDL.h>
#define SDL_MAIN_HANDLED

namespace Oniros
{

	SDL_Window* m_Window = nullptr;
	SDL_GLContext m_Context = nullptr;

	Window::Window(const WindowProps& props)
	{
		m_WindowData.Title = props.Title;
		m_WindowData.Width = props.Width;
		m_WindowData.Height = props.Height;
		m_WindowData.VSync = false;

		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
			return;
		}

		// Create SDL window
		m_Window = SDL_CreateWindow(m_WindowData.Title.c_str(),
			m_WindowData.Width,
			m_WindowData.Height,
			SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
		if (!m_Window) {
			std::cerr << "Failed to create SDL window: " << SDL_GetError() << std::endl;
			return;
		}

		// Create OpenGL context
		m_Context = SDL_GL_CreateContext(m_Window);
		if (!m_Context) {
			std::cerr << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
			return;
		}

		// Enable VSync by default
		SetVSync(true);
	}

	Window::~Window()
	{
		if (m_Context) {
			SDL_GL_DestroyContext(m_Context);
		}
		if (m_Window) {
			SDL_DestroyWindow(m_Window);
		}
		SDL_Quit();
	}

	void Window::OnUpdate()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (m_WindowData.EventCallback) {
				int dummy = event.type; // Replace with actual event when integrated
				m_WindowData.EventCallback(dummy);
			}
		}

		SDL_GL_SwapWindow(m_Window);
	}

	uint32_t Window::GetWidth()
	{
		return m_WindowData.Width;
	}

	uint32_t Window::GetHeight()
	{
		return m_WindowData.Height;
	}

	void Window::SetEventCallback(const EventCallbackFn& callback)
	{
		m_WindowData.EventCallback = callback;
	}

	void Window::SetVSync(bool enabled)
	{
		if (enabled) {
			SDL_GL_SetSwapInterval(1);
		}
		else {
			SDL_GL_SetSwapInterval(0);
		}
		m_WindowData.VSync = enabled;
	}

	bool Window::IsVSync()
	{
		return m_WindowData.VSync;
	}
}
