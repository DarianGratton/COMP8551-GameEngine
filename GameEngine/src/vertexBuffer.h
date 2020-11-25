#pragma once

class vertexBuffer
{
private:
    unsigned int m_RendererID;
public:
    //size = bytes
    vertexBuffer(const void* data, unsigned int size);
    ~vertexBuffer();
    //May need set data
    //Unlock/Lock
    void Bind() const;
    void Unbind() const;
};