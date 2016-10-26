@echo off

if exist build goto compile

mkdir build

:compile
    SET COMPILER_FLAGS=/nologo /EHsc /c /I "include" /MTd /Od /Fdbuild\ /Fobuild\ /Zi /W3 /wd4996
    SET LIB_FILES=user32.lib gdi32.lib opengl32.lib
    SET LINKER_FLAGS=/NOLOGO /DEBUG /OUT:asteroids.exe

    FOR /R source\ %%f IN ("*.cpp") DO cl %COMPILER_FLAGS% "%%f"
    
    cl %COMPILER_FLAGS% target/win32.cpp

    PUSHD build

    link %LINKER_FLAGS% %LIB_FILES% *.obj

    POPD
