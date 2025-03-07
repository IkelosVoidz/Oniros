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

   includedirs
   {
	  -- Include Engine Core
	  "%{wks.location}/Oniros/src"
   }

   links
   {
      "Oniros"
   }

   filter "system:windows"
       systemversion "latest"
       defines { "WINDOWS" }

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
        kind "WindowedApp"
        defines { "DIST" }
        runtime "Release"
        optimize "On"
        symbols "Off"