#include <cstdio>

#include "asteroids/OpenGL/shaders.h"
#include "asteroids/OpenGL/opengl.h"

#include "asteroids/memory.h"


namespace asteroids
{
namespace opengl
{
    GLuint CompileShader (GLenum type, const GLchar * source)
    {
        GLuint shader = glCreateShader(type);
        glShaderSource(shader, 1, &source, NULL);
        glCompileShader(shader);

        GLint status;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

        if (GL_FALSE == status)
        {
            GLint length;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

            GLchar * log = ALLOCATE(GLchar, length + 1);
            glGetShaderInfoLog(shader, length, NULL, log);

            printf("Shader fail to compile: \n%s\n", log);

            DEALLOCATE(log);

            glDeleteShader(shader);
        }

        return shader;
    }

    GLuint CreateProgram (int shader_count, ...)
    {
        GLuint program = glCreateProgram();

        va_list arguments;
        va_start(arguments, shader_count);

        for (GLint i = 0; i < shader_count; i++)
        {
            GLuint shader = va_arg(arguments, GLuint);

            glAttachShader(program, shader);
        }

        va_end(arguments);

        GLint status;
        glGetProgramiv(program, GL_LINK_STATUS, &status);

        if (GL_FALSE == status)
        {
            GLint length;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);

            GLchar * log = ALLOCATE(GLchar, length + 1);
            glGetProgramInfoLog(program, length, NULL, log);

            printf("Program failed to link: \n%s\n", log);

            DEALLOCATE(log);

            glDeleteProgram(program);
        }

        return program;
    }
}
}