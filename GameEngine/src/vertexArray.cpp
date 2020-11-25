#include "vertexArray.h"
#include "renderer.h"
#include "vertexBufferLayout.h"

vertexArray::vertexArray()
{
    GLCall(glGenVertexArrays(1, &m_RendererID));
}

vertexArray::~vertexArray()
{
    GLCall(glDeleteVertexArrays(1, &m_RendererID));
}

void vertexArray::AddBuffer(const vertexBuffer& vb, const vertexBufferLayout& layout)
{
    //Bind vertex array
    Bind();
    //Bind buffer
    vb.Bind();

    //Set up layout
    const auto& elements = layout.GetElements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const auto& element = elements[i];
        GLCall(glEnableVertexAttribArray(i));
        GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalised, layout.GetStride(), reinterpret_cast<const void *>((const intptr_t) offset)));
        offset += element.count * vertexBufferElement::GetSizeOfType(element.type);
    }
}

void vertexArray::Bind() const
{
    GLCall(glBindVertexArray(m_RendererID));
}

void vertexArray::Unbind() const
{
    GLCall(glBindVertexArray(0));
}