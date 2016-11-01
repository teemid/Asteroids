#ifndef ASTEROIDS_OPENGL_SHADERS_H
#define ASTEROIDS_OPENGL_SHADERS_H

#include "gl/glcorearb.h"

namespace asteroids
{
namespace opengl
{
    GLuint CompileShader (GLenum type, const GLchar * source);
    GLuint CreateProgram (int shader_count, ...);
}
}

#endif