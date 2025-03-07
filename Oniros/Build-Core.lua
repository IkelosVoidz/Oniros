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
      "src"
   }


   filter "system:windows"
       systemversion "latest"
       defines { }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"

   filter "configurations:Dist"
       defines { "DIST" }
       runtime "Release"
       optimize "On"
       symbols "Off"