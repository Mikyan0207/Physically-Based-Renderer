@echo off

set Includes=-I"..\Headers" -I"..\Libraries"
set SourceFiles=..\Source\main.cpp^
 ..\Source\OpenGL\glad.c^
 ..\Source\OpenGL\VertexBuffer.cpp^
 ..\Source\OpenGL\IndexBuffer.cpp^
 ..\Source\OpenGL\VertexArray.cpp^
 ..\Source\OpenGL\FrameBuffer.cpp^
 ..\Source\OpenGL\RenderBuffer.cpp

set ClangCompileFlags=-g -Wall -Wextra -Werror
set ClangLinkFlags=-lopengl32

if not exist build mkdir build

pushd build

clang %ClangCompileFlags% %ClangLinkFlags% %Includes% %SourceFiles% -o Renderer_Debug.exe

popd build
