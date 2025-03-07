project "Oniros"
   kind "StaticLib"
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
       
   includedirs
   {
      "src",
      "vendor/spdlog/include"
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
       defines { "ONI_DIST" }
       runtime "Release"
       optimize "On"
       symbols "Off"