workspace "Oniros Project"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "Voxel-App"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Core"
	include "Core/Build-Core.lua"
group ""

include "Voxel-App/Build-App.lua"