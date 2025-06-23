project "Oni-Voxel-App"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   staticruntime "on"
   
   targetdir ("%{wks.location}/binaries/bin/" .. OutputDir .. "/%{prj.name}")
   objdir ("%{wks.location}/binaries/bin-int/" .. OutputDir .. "/%{prj.name}")

   files 
   { 
       "src/**.h", 
       "src/**.cpp" ,
   }

   defines
   {
		"_CRT_SECURE_NO_WARNINGS",
   }

   includedirs
   {
	  -- Include Engine Core and libraries
	  "%{wks.location}/Oniros/src",
      "%{IncludeDir.spdlog}",
      "%{IncludeDir.GLM}",
      "%{IncludeDir.ImGui}",
   }

   links
   {
      "Oniros",
      "ImGui",
   }

   filter "system:windows"
       systemversion "latest"

   filter "configurations:Debug"
       defines { "ONI_DEBUG" }
       runtime "Debug"
       symbols "on"

   filter "configurations:Release"
       defines { "ONI_RELEASE" }
       runtime "Release"
       optimize "on"
       symbols "on"

   filter "configurations:Dist"
        kind "WindowedApp"
        defines { "ONI_DIST" }
        runtime "Release"
        optimize "on"
        symbols "off"