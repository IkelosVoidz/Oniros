#include "onipch.h"
#include "SDLWindow.h"

#include "Oniros/Events/ApplicationEvent.h"
#include "Oniros/Events/MouseEvent.h"
#include "Oniros/Events/KeyEvent.h"
#include "Oniros/Core/Input.h"

#include <backends/imgui_impl_sdl3.h>

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

		m_Context = RendererContext::Create(m_Window);
		m_Context->Init(); 

		// Enable VSync by default
		SetVSync(true);
	}
	void SDLWindow::Shutdown()
	{
		m_Context->Shutdown();

		if (m_Window) {
			SDL_DestroyWindow(m_Window);
		}
		SDL_Quit();
	}
	
	void SDLWindow::ProcessEvents()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event)) {

			//Bit of a hack but honestly its fine, its just how IMGUI works, i dont want to make it go through my event system just to go back to regular SDL events, not worth it
			//if it ever becomes a problem (events being blocked or processed twice) we can always rework this)
			ImGui_ImplSDL3_ProcessEvent(&event); 

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
					KeyCode key = static_cast<KeyCode>(event.key.key);
					KeyDownEvent keyDownEvt(key, event.key.repeat);
					m_WindowData.EventCallback(keyDownEvt);

					if (event.key.repeat == 0) {
						
						Input::UpdateKeyState(key, KeyState::Pressed);
					}
					else {
						Input::UpdateKeyState(key, KeyState::Held);
					}

					break;
				}
				case SDL_EVENT_KEY_UP: {
					KeyCode key = static_cast<KeyCode>(event.key.key);
					KeyUpEvent keyUpEvt(key);
					m_WindowData.EventCallback(keyUpEvt);

					Input::UpdateKeyState(key, KeyState::Released);
					break;
				}
				case SDL_EVENT_MOUSE_BUTTON_DOWN: {

					MouseButton button = static_cast<MouseButton>(event.button.button);
					Input::UpdateMouseButtonState(button, KeyState::Pressed);
					MouseButtonPressedEvent mouseButtonPressedEvt(button);
					m_WindowData.EventCallback(mouseButtonPressedEvt);
					break;
				}
				case SDL_EVENT_MOUSE_BUTTON_UP: {
					MouseButton button = static_cast<MouseButton>(event.button.button);
					Input::UpdateMouseButtonState(button, KeyState::Released);
					MouseButtonReleasedEvent mouseButtonReleasedEvt(button);
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
	}

	void SDLWindow::SwapBuffers()
	{
		m_Context->SwapBuffers();
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
