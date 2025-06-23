#pragma once
#include "Oniros/Renderer/RendererContext.h"
#include <SDL3/SDL.h>
namespace Oniros {

	class OpenGLContext : public RendererContext
	{
	public:
		OpenGLContext(SDL_Window* windowHandle)
			: RendererContext(), m_WindowHandle(windowHandle) {
		}

		virtual ~OpenGLContext() = default;

		virtual void Create() override;
		virtual void Destroy() override;

		virtual void BeginFrame() override {}; //These two methods are Unimplemented, this is more for other kinds of contexts, like Vulkan or DirectX.
		virtual void OnResize(uint32_t width, uint32_t height) override {};
		virtual void SwapBuffers() override;

		inline virtual void* GetNativeContext() const override {
			return m_Context;
		}


	private:
		SDL_Window* m_WindowHandle;
		SDL_GLContext m_Context;
	};
}


