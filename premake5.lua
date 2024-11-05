workspace "NumericalMethods"
    architecture "x64"
    configurations {
        "Debug",
        "Release"
    }
    startproject "NumericalMethods_Runtime"

    filter "system:windows"
        buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

    OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"
    
    group "Dependencies"
        include "Dependencies/googletest/googletest/premake5.lua"
    group ""

    include "NumericalMethods_Core/premake5.lua"
    include "NumericalMethods_Runtime/premake5.lua"
    include "NumericalMethods_Tests/premake5.lua"
