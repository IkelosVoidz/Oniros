#include "onipch.h"
#include <glad/glad.h>
#include "SDLWindow.h"

#include "Oniros/Events/ApplicationEvent.h"
#include "Oniros/Events/MouseEvent.h"
#include "Oniros/Events/KeyEvent.h"

#define SDL_MAIN_HANDLED


namespace Oniros
{
	Window* Window::Create(const WindowProps& props)
	{
		return new SDLWindow(props);
	}
	 
	SDLWindow::SDLWindow(const WindowProps& props): m_WindowProps(props)
	{	
		
	}

	SDLWindow::~SDLWindow()
	{
		Shutdown();
	}

	void SDLWindow::Init()
	{
		m_WindowData.Title = m_WindowProps.Title;
		m_WindowData.Width = m_WindowProps.Width;
		m_WindowData.Height = m_WindowProps.Height;

		ONI_CORE_INFO("Creating window: {0}, {1}x{2}", m_WindowData.Title, m_WindowData.Width, m_WindowData.Height);

		
		if (!SDL_Init(SDL_INIT_VIDEO)) {

			ONI_CORE_ERROR("Failed to initialize SDL: {0}", SDL_GetError());
			return;
		}

		Uint32 windowFlags = SDL_WINDOW_OPENGL;

		if (m_WindowProps.Resizable) {
			windowFlags |= SDL_WINDOW_RESIZABLE;
		}

		if (m_WindowProps.Borderless) {
			windowFlags |= SDL_WINDOW_BORDERLESS;
		}

		if (m_WindowProps.Fullscreen) {
			windowFlags |= SDL_WINDOW_FULLSCREEN;
		}

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);



		// Create SDL window
		m_Window = SDL_CreateWindow(m_WindowData.Title.c_str(),
			m_WindowData.Width,
			m_WindowData.Height,
			windowFlags 
		);
		if (!m_Window) {

			ONI_CORE_ERROR("Failed to create SDL window: {0}", SDL_GetError());
			return;
		}

		// Create OpenGL context
		m_Context = SDL_GL_CreateContext(m_Window);
		if (!m_Context) {

			ONI_CORE_ERROR("Failed to create OpenGL context: {0}", SDL_GetError());
			return;
		}

		gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

		// Enable VSync by default
		SetVSync(true);
	}
	void SDLWindow::Shutdown()
	{
		if (m_Context) {
			SDL_GL_DestroyContext(m_Context);
		}
		if (m_Window) {
			SDL_DestroyWindow(m_Window);
		}
		SDL_Quit();
	}
	
	void SDLWindow::OnUpdate()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_EVENT_QUIT: {
					WindowCloseEvent windowCloseEvt;
					m_WindowData.EventCallback(windowCloseEvt);
					break;
				}
				case SDL_EVENT_WINDOW_RESIZED: {
					WindowResizeEvent windowResizeEvt(event.window.data1, event.window.data2);
					m_WindowData.Width = event.window.data1;
					m_WindowData.Height = event.window.data2;
					m_WindowData.EventCallback(windowResizeEvt);
					break;
				}
				case SDL_EVENT_WINDOW_FOCUS_GAINED: {
					WindowFocusChangeEvent windowFocusChangeEvt(true);
					m_WindowData.EventCallback(windowFocusChangeEvt);
					break;
				}
				case SDL_EVENT_WINDOW_FOCUS_LOST: {
					WindowFocusChangeEvent windowFocusChangeEvt(false);
					m_WindowData.EventCallback(windowFocusChangeEvt);
					break;
				}	
				case SDL_EVENT_WINDOW_MINIMIZED: {
					WindowMinimizeEvent windowMinimizeEvt(true);
					m_WindowData.EventCallback(windowMinimizeEvt);
					break;
				}
				case SDL_EVENT_WINDOW_MAXIMIZED: {
					WindowMinimizeEvent windowMinimizeEvt(false);
					m_WindowData.EventCallback(windowMinimizeEvt);
					break;
				}
				case SDL_EVENT_KEY_DOWN: {
					KeyDownEvent keyDownEvt((KeyCode)event.key.key, event.key.repeat);
					m_WindowData.EventCallback(keyDownEvt);
					break;
				}
				case SDL_EVENT_KEY_UP: {
					KeyUpEvent keyUpEvt((KeyCode)event.key.key);
					m_WindowData.EventCallback(keyUpEvt);
					break;
				}
				case SDL_EVENT_MOUSE_BUTTON_DOWN: {
					MouseButtonPressedEvent mouseButtonPressedEvt((MouseCode)event.button.button);
					m_WindowData.EventCallback(mouseButtonPressedEvt);
					break;
				}
				case SDL_EVENT_MOUSE_BUTTON_UP: {
					MouseButtonReleasedEvent mouseButtonReleasedEvt((MouseCode)event.button.button);
					m_WindowData.EventCallback(mouseButtonReleasedEvt);
					break;
				}
				case SDL_EVENT_MOUSE_MOTION: {
					MouseDragEvent mouseDragEvt(event.motion.x, event.motion.y);
					m_WindowData.EventCallback(mouseDragEvt);
					break;
				}
				case SDL_EVENT_MOUSE_WHEEL: {
					MouseScrollEvent mouseScrollEvt(event.wheel.x, event.wheel.y);
					m_WindowData.EventCallback(mouseScrollEvt);
					break;
				}
			}
		}

		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		SDL_GL_SwapWindow(m_Window);
	}

 
	void SDLWindow::SetVSync(bool enabled)
	{
		if (enabled) {
			SDL_GL_SetSwapInterval(1);
		}
		else {
			SDL_GL_SetSwapInterval(0);
		}
		m_WindowProps.VSync = enabled;
	}

	std::pair<float, float> SDLWindow::GetWindowPos() const
	{
		int x, y;
		SDL_GetWindowPosition(m_Window, &x, &y);
		return { static_cast<float>(x), static_cast<float>(y) };
	}

	bool SDLWindow::IsVSync() const 
	{
		return m_WindowProps.VSync;
	}

	void SDLWindow::SetResizable(bool resizable) 
	{
		m_WindowProps.Resizable = resizable;
		SDL_SetWindowResizable(m_Window, resizable);
	}

	bool SDLWindow::isResizable() const
	{
		return m_WindowProps.Resizable;
	}

	void SDLWindow::SetFullscreen(bool enabled)
	{
		m_WindowProps.Fullscreen = enabled;
		SDL_SetWindowFullscreen(m_Window, enabled);

	}

	bool SDLWindow::IsFullscreen() const
	{
		return m_WindowProps.Fullscreen;
	}

	void SDLWindow::SetBorderless(bool enabled)
	{
		m_WindowProps.Borderless = enabled;
		SDL_SetWindowBordered(m_Window, !enabled);

		
	}

	bool SDLWindow::IsBorderless() const
	{
		return m_WindowProps.Borderless;
	}

	void SDLWindow::Maximize()
	{
		SDL_MaximizeWindow(m_Window);
	}

	void SDLWindow::CenterWindow()
	{
		SDL_Rect displayBounds;
		if (SDL_GetDisplayBounds(0, &displayBounds) == 0) {
			int displayWidth = displayBounds.w;
			int displayHeight = displayBounds.h;
			int x = displayBounds.x + (displayWidth - m_WindowData.Width) / 2;
			int y = displayBounds.y + (displayHeight - m_WindowData.Height) / 2;
			SDL_SetWindowPosition(m_Window, x, y);
		}
		else {
			ONI_CORE_ERROR("Failed to get display bounds: {0}", SDL_GetError());
		}
	}

	void SDLWindow::SetTitle(const std::string& title)
	{
		m_WindowData.Title = title;
		SDL_SetWindowTitle(m_Window, m_WindowData.Title.c_str());
	}
	
}
