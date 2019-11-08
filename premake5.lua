workspace "Tyrone4Engine"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Tyrone4"
	location "Tyrone4"
	kind "SharedLib"

	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "typch.h"
	pchsource "Tyrone4/src/typch.cpp"

	files {
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include", 
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"TY_PLATFORM_WINDOWS",
			"TY_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "TY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TY_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Tyrone4/vendor/spdlog/include", 
		"Tyrone4/src"
	}

	links {
		"Tyrone4"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"TY_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "TY_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TY_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TY_DIST"
		optimize "On"