project "Oniros"
   kind "StaticLib"
   language "C++"
   cppdialect "C++20"
   staticruntime "on"

   targetdir ("%{wks.location}/binaries/bin/" .. OutputDir .. "/%{prj.name}")
   objdir ("%{wks.location}/binaries/bin-int/" .. OutputDir .. "/%{prj.name}")

   pchheader "onipch.h"
   pchsource "src/onipch.cpp"

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
      "%{IncludeDir.GLAD}",
      "%{IncludeDir.ImGui}",
      "%{IncludeDir.GLM}",

   }

   libdirs
   {
       "%{LibDir.SDL}",
   }

   links {
        "SDL3.lib",
        "GLAD",
        "ImGui"
   }

--    links{
--         "SDL3-static",
--    }

   filter "system:windows"
       systemversion "latest"

       postbuildcommands { "{COPY} %{LibDir.SDL}/SDL3.dll ../binaries/bin/" .. OutputDir .. "/Oni-Voxel-App" } -- Copy SDL3.dll to build folder

    --    links {
    --         "setupapi",  
    --         "winmm",     
    --         "imm32",  
    --         "version"   
    --     }
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
    
