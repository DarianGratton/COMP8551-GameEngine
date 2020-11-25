#pragma once

#include "vertexBuffer.h"

class vertexBufferLayout;

class vertexArray
{
    private:
        unsigned int m_RendererID;
    public:
        vertexArray();
        ~vertexArray();

        void AddBuffer(const vertexBuffer& vb, const vertexBufferLayout& layout);
        
        void Bind() const; 
        void Unbind() const;
};