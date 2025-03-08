#pragma once
#include <cstdlib>
#include <algorithm>
#include <stdexcept>

template<typename T>
class DynamicIntArray
{
public:
    DynamicIntArray(std::size_t size);

    ~DynamicIntArray();

    DynamicIntArray(const DynamicIntArray<T>& other);

    T& operator[](std::size_t index);
    bool operator==(const DynamicIntArray<T>& other) const;
    bool operator!=(const DynamicIntArray<T>& other) const;
    DynamicIntArray& operator=(const DynamicIntArray<T>& other);

    std::size_t getCapacity() const;
    std::size_t getSize() const;

    void clear();
    void setSize(std::size_t newSize);
    void push_back(const T& element);

    void reserve(std::size_t reservedSpace);
    void shrinkToFit();
    void pop_back();

    T back() const;

private:
    T* m_data = nullptr;
    std::size_t m_size = 0;
    std::size_t m_capacity = 0;
};

template<typename T>
DynamicIntArray<T>::DynamicIntArray(std::size_t size) : m_size(size), m_capacity(size)
{
    m_data = new T[m_capacity]{};
}

template<typename T>
DynamicIntArray<T>::~DynamicIntArray()
{
    delete[] m_data;
}

template<typename T>
DynamicIntArray<T>::DynamicIntArray(const DynamicIntArray& other)
    : m_size(other.m_size), m_capacity(other.m_capacity)
{
    m_data = new T[m_capacity];
    std::copy(other.m_data, other.m_data + m_size, m_data);
}

template<typename T>
DynamicIntArray<T>& DynamicIntArray<T>::operator=(const DynamicIntArray& other)
{
    if (this != &other)
    {
        delete[] m_data;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = new T[m_capacity];
        std::copy(other.m_data, other.m_data + m_size, m_data);
    }
    return *this;
}

template<typename T>
T& DynamicIntArray<T>::operator[](std::size_t index)
{
    if (index >= m_size)
        throw std::out_of_range("Index out of range");
    return m_data[index];
}

template<typename T>
void DynamicIntArray<T>::clear()
{
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;
}

template<typename T>
bool DynamicIntArray<T>::operator==(const DynamicIntArray& other) const
{
    if (m_size != other.m_size)
        return false;

    for (std::size_t i = 0; i < m_size; ++i)
    {
        if (m_data[i] != other.m_data[i])
            return false;
    }
    return true;
}

template<typename T>
bool DynamicIntArray<T>::operator!=(const DynamicIntArray& other) const
{
    return !(*this == other);
}

template<typename T>
std::size_t DynamicIntArray<T>::getSize() const
{
    return m_size;
}

template<typename T>
std::size_t DynamicIntArray<T>::getCapacity() const
{
    return m_capacity;
}

template<typename T>
void DynamicIntArray<T>::setSize(std::size_t newSize)
{
    if (newSize > m_capacity)
    {
        reserve(newSize * 2);
    }
    m_size = newSize;
}

template<typename T>
void DynamicIntArray<T>::push_back(const T& element)
{
    if (m_size >= m_capacity)
    {
        reserve(m_capacity == 0 ? 1 : m_capacity * 2);
    }
    m_data[m_size++] = element;
}

template<typename T>
void DynamicIntArray<T>::reserve(std::size_t reservedSpace)
{
    if (reservedSpace > m_capacity)
    {
        T* newData = new T[reservedSpace]{};
        std::copy(m_data, m_data + m_size, newData);
        delete[] m_data;
        m_data = newData;
        m_capacity = reservedSpace;
    }
}

template<typename T>
void DynamicIntArray<T>::shrinkToFit()
{
    if (m_capacity > m_size)
    {
        T* newData = new T[m_size]{};
        std::copy(m_data, m_data + m_size, newData);
        delete[] m_data;
        m_data = newData;
        m_capacity = m_size;
    }
}

template<typename T>
void DynamicIntArray<T>::pop_back()
{
    if (m_size > 0)
    {
        --m_size;
    }
}

template<typename T>
T DynamicIntArray<T>::back() const
{
    if (m_size > 0)
    {
        return m_data[m_size - 1];
    }
    throw std::out_of_range("Array is empty");
}
