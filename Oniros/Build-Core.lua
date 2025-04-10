project "Oniros"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   staticruntime "on"

   targetdir ("%{wks.location}/binaries/bin/" .. OutputDir .. "/%{prj.name}")
   objdir ("%{wks.location}/binaries/bin-int/" .. OutputDir .. "/%{prj.name}")

--    pchheader "onipch.h"
--    pchsource "src/onipch.cpp"

   files 
   {
       "src/**.h", 
       "src/**.cpp" ,
   } 

   defines
   {
 		"_CRT_SECURE_NO_WARNINGS"
   }
       
   includedirs
   {
      "src",
      "%{IncludeDir.spdlog}",
      "%{IncludeDir.SDL}",
   }

   libdirs{
       "%{wks.location}/Oniros/vendor/SDL/SDL3/bin/" .. OutputDir .. "/SDL3"
   }

   links
   {
      "SDL3",
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
       defines { "ONI_DIST" }
       runtime "Release"
       optimize "on"
       symbols "off"