include "Dependencies.lua"

workspace "Oniros"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "Oni-Voxel-App"

   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus", "/utf-8" }

      flags
      {
         "MultiProcessorCompile"
      }

OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	-- include "Oniros/vendor/SDL/SDL3"
	include "Oniros/vendor/imgui"
   include "Oniros/vendor/GLAD"
group ""

group "Core"
	include "Oniros/Build-Core.lua"
group ""


include "Oni-Voxel-App/Build-App.lua"