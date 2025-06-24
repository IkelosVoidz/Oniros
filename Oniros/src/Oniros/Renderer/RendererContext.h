#pragma once


#include "Oniros/Core/Base.h"


struct SDL_Window; //This class doesnt need to actually load SDL, so we forward declare it to avoid including SDL3/SDL.h here.

namespace Oniros {
	class RendererContext
	{
	public:
		RendererContext() = default;
		virtual ~RendererContext() = default;

		virtual void Init() = 0;
		virtual void Shutdown() = 0;


		virtual void BeginFrame() = 0;
		virtual void SwapBuffers() = 0;

		virtual void OnResize(uint32_t width, uint32_t height) = 0;

		virtual void* GetNativeContext() const = 0;

		static Ref<RendererContext> Create(SDL_Window* windowHandle);
	};
	
}


