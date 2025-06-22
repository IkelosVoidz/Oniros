#pragma once
#include "Oniros/Core/Window.h"
#include "Oniros/Core/Base.h"
#include <SDL3/SDL.h>

namespace Oniros
{
	class SDLWindow : public Window
	{
	public:

		SDLWindow(const WindowProps& props = WindowProps());
		virtual ~SDLWindow();


		virtual void Init();

		void OnUpdate() override;
		inline uint32_t GetWidth() const override { return m_WindowData.Width; };
		inline uint32_t GetHeight() const override { return m_WindowData.Height; }
		virtual std::pair<uint32_t, uint32_t> GetSize() const override { return { m_WindowData.Width, m_WindowData.Height }; }
		virtual std::pair<float, float> GetWindowPos() const override;


		inline void SetEventCallback(const EventCallbackFn& callback) override { m_WindowData.EventCallback = callback; };



		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
		virtual void SetResizable(bool resizable) override;
		virtual bool isResizable() const override;
		virtual void SetFullscreen(bool enabled) override;
		virtual bool IsFullscreen() const override;
		virtual void SetBorderless(bool enabled) override;
		virtual bool IsBorderless() const override;



		virtual void Maximize() override;
		virtual void CenterWindow() override;

		virtual const std::string& GetTitle() const override { return m_WindowData.Title; }
		virtual void SetTitle(const std::string& title) override;

		virtual inline void* GetNativeWindow() const { return m_Window; }
		
	private:

		virtual void Shutdown();


		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;

			EventCallbackFn EventCallback;
		};

		WindowProps m_WindowProps;
		WindowData m_WindowData;

		SDL_Window* m_Window;
		SDL_GLContext m_Context;
	};
}

