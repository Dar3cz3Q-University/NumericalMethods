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
        include "Numerical methods - Core/premake5.lua"
    group ""
    
    include "Numerical methods - Runtime/premake5.lua"
