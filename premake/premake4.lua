solution "theGame"
	configurations {"Debug","Release"}

	--a comment
	project "TFranchementGros"
		kind "WindowedApp"
		language "C++"
		location "../build"
		files {"../src/**.h", "../src/**.cpp"}
		includedirs {	"../lib/SFML-2.1/include"
				,"../src/engine"
				,"../src/gameplay"
				,"../src/module"
				,"../src/libext"}

		libdirs {"../lib/SFML-2.1/build/lib"}
		-- link ? we install sfml on linux host ?
		

		

		configuration "Debug"
			defines { "DEBUG" }
			flags { "Symbols" }
			links {	"sfml-audio-d", 
					"sfml-network-d", 
					"sfml-graphics-d", 
					"sfml-window-d",--sfmlwindows and sfmlsystem in last position of sfml libs for gcc 
					"sfml-system-d"}
			
			--if os.is("windows") then
				-- Enables console for the TEST project on Windows
				--linkoptions { "/SUBSYSTEM:CONSOLE" }
			--end

		configuration "Release"
			defines { "NDEBUG" }
			flags { "Optimize" }
			links {	"sfml-audio", 
					"sfml-network", 
					"sfml-graphics", 
					"sfml-window",--sfmlwindows and sfmlsystem in last position of sfml libs for gcc 
					"sfml-system"}
