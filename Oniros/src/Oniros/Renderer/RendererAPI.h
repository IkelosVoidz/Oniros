#pragma once

namespace Oniros {

	enum class RendererAPIType
	{
		None,
		Vulkan,
		OpenGL
	};

	class RendererAPI
	{

	public:

		static RendererAPIType GetCurrentAPI() { return s_CurrentAPI; }
		static void SetCurrentAPI(RendererAPIType api)
		{
			s_CurrentAPI = api;
		}
	
	private: 

		inline static RendererAPIType s_CurrentAPI = RendererAPIType::OpenGL; // Default to OpenGL
	};
}



