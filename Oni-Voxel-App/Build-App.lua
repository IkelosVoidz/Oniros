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
      "%{wks.location}/Oniros/vendor/spdlog/include"
   }

   links
   {
      "Oniros"
   }

   filter "system:windows"
       systemversion "latest"
       defines { "WINDOWS" }

   filter "configurations:Debug"
       defines { "ONI_DEBUG" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "ONI_RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"

   filter "configurations:Dist"
        kind "WindowedApp"
        defines { "ONI_DIST" }
        runtime "Release"
        optimize "On"
        symbols "Off"