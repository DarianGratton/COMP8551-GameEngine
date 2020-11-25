#pragma once

#include <glad/glad.h>
#include <Windows.h>

#include "vertexArray.h"
#include "indexBuffer.h"
#include "shader.h"

//macro - break points debugger if error is found
#define ASSERT(x) if (!(x)) DebugBreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();
bool GLLogCall( const char* function, const char* file, int line);

class renderer
{
    public:
        void Clear() const;
        void Draw(const vertexArray& va, const indexBuffer& ib, const shader& shader) const;
};