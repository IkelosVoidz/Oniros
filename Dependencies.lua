IncludeDir = {}

IncludeDir["SDL"] = "%{wks.location}/Oniros/vendor/SDL/SDL3/include"
IncludeDir["spdlog"] = "%{wks.location}/Oniros/vendor/spdlog/include"

LibDir = {}

LibDir["SDL"] = "%{wks.location}/Oniros/vendor/SDL/SDL3/build/%{cfg.buildcfg}"