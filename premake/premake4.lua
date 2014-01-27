solution "theGame"
	configurations {"Debug","Release"}

	--a comment
	project "engine"
		kind "WindowedApp"
		language "C++"
		location "../build"
		files {"../src/**.h", "../src/**.cpp"}
		includedirs {"../lib/SFML-2.1/include"}
		libdirs {"../lib/SFML-2.1/lib"}

		configuration "Debug"
			defines { "DEBUG" }
			flags { "Symbols" }

		configuration "Release"
			defines { "NDEBUG" }
			flags { "Optimize" }
