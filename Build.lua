workspace "Oniros"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "Oni-Voxel-App"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus", "/utf-8" }

      flags
      {
         "MultiProcessorCompile"
      }

OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Core"
	include "Oniros/Build-Core.lua"
group ""

group "Dependencies"
	--include "Oniros/vendor/Glad"
	--include "Oniros/vendor/imgui"
group ""



include "Oni-Voxel-App/Build-App.lua"