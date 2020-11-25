#pragma once

class indexBuffer
{
private:
    unsigned int m_RendererID;
    unsigned int m_Count;
public:
    //count = element count
    indexBuffer(const unsigned int* data, unsigned int count);
    ~indexBuffer();
    //May need set data
    //Unlock/Lock
    void Bind() const;
    void Unbind() const;

    inline unsigned int GetCount() const {return m_Count;}
};