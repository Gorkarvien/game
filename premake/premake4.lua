solution "theGame"
	configurations {"Debug","Release"}

	--a comment
	project "engine"
		kind "WindowedApp"
		language "C++"
		location "../build"
		files {"../src/**.h", "../src/**.cpp"}
		includedirs {"../lib/SFML-2.1/include"}
		--libdirs {"../lib/SFML-2.1/build/lib"}
		-- link ? we install sfml on linux host ?
		links {	"sfml-audio", 
		       	"sfml-network", 
		       	"sfml-graphics", 
		       	"sfml-window",--sfmlwindows and sfmlsystem in last position of sfml libs for gcc 
			"sfml-system"}


		configuration "Debug"
			defines { "DEBUG" }
			flags { "Symbols" }

		configuration "Release"
			defines { "NDEBUG" }
			flags { "Optimize" }
