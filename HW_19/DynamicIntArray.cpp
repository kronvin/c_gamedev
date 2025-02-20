#include "DynamicIntArray.h"
#include <algorithm> 
#include <iostream>


DynamicIntArray::DynamicIntArray() : m_data(nullptr), m_size(0) {}

DynamicIntArray::DynamicIntArray(std::size_t size) : m_size(size) 
{
    m_data = new int[m_size] {};
}

DynamicIntArray::~DynamicIntArray() 
{
    delete[] m_data;
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other) : m_size(other.m_size) 
{
    m_data = new int[m_size];
    std::copy(other.m_data, other.m_data + m_size, m_data);
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other) 
{
    if (this != &other) 
    {
        delete[] m_data;
        m_size = other.m_size;
        m_data = new int[m_size];
        std::copy(other.m_data, other.m_data + m_size, m_data);
    }
    return *this;
}

int& DynamicIntArray::operator[](std::size_t index) 
{
    return m_data[index];
}

void DynamicIntArray::clear() 
{
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
}

bool DynamicIntArray::operator==(const DynamicIntArray& other) 
{
    if (m_size != other.m_size) return false;
    for (std::size_t i = 0; i < m_size; ++i) 
    {
        if (m_data[i] != other.m_data[i]) return false;
    }
    return true;
}

bool DynamicIntArray::operator!=(const DynamicIntArray& other) 
{
    return !(*this == other);
}

std::size_t DynamicIntArray::getSize() const 
{
    return m_size;
}

void DynamicIntArray::setSize(std::size_t newSize) 
{
    int* newData = new int[newSize] {};
    std::size_t copySize = (newSize < m_size) ? newSize : m_size;
    std::copy(m_data, m_data + copySize, newData);
    delete[] m_data;
    m_data = newData;
    m_size = newSize;
}

void DynamicIntArray::push_back(int element) {
    setSize(m_size + 1);
    m_data[m_size - 1] = element;
}
