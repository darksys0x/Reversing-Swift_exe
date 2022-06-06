newoption {
    trigger     = "outdir",
    value       = "path",
    description = "Output directory for the build files"
}
if not _OPTIONS["outdir"] then
    _OPTIONS["outdir"] = "Build"
end


--[[
    The Solution
--]]

solution "swift_main"

    configurations { "Release", "Debug" }

    location( _OPTIONS["outdir"] )
    targetdir "Bin"
    implibdir "Bin"
    flags { symbols ("On") }  

    configuration "Release*"
        defines { "NDEBUG" }
        optimize "Full"

    filter "system:windows"
        buildoptions {"/MD"}

    filter "system:windows"
        flags {
            staticruntime("On"),
            "NoImportLib",
            rtti ("Off"),
            "NoBufferSecurityCheck"
        }
        defines { "_CRT_SECURE_NO_WARNINGS", "_SCL_SECURE_NO_WARNINGS"}

group ""
        project "swift_main"
            vpaths {
                ["Headers/*"] = {"swift_main/**.h*",},
                ["Sources/*"] = {"swift_main/**.c*",},
                ["*"] = {"premake5.lua"}
            }
            defines { }
            includedirs { "swift_main", "swift_main/**" }
            links { }
        language "C++"
        kind "ConsoleApp"
        targetname "swift_main"         
        files {
            "swift_main/**.h*",
            "swift_main/**.c*"
        }
