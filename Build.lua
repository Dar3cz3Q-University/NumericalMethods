workspace "Numerical methods"
    architecture "x64"
    configurations {
        "Debug",
        "Release"
    }
    startproject "Numerical methods - Runtime"

    filter "system:windows"
        buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

    OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"
    
    group "Core"
        include "Numerical methods - Core/Build-Core.lua"
    group ""
    
    include "Numerical methods - Runtime/Build-Runtime.lua"