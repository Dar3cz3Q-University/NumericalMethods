project "NumericalMethods_Tests"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   staticruntime "off"
   targetdir ("%{_WORKING_DIR}/Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("%{_WORKING_DIR}/Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   flags {
    "MultiProcessorCompile"
   }

   files { 
    "Tests/**.cpp"
   }

   includedirs {
    "../NumericalMethods_Core/Source",
	"../Dependencies/googletest/googletest/include"
   }

   links {
    "NumericalMethods_Core",
    "GoogleTest"
   }

   filter "system:windows"
       systemversion "latest"
       defines { "WINDOWS" }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "NDEBUG" }
       runtime "Release"
       optimize "On"
       symbols "On"
       