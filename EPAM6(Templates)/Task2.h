#pragma once
#include <algorithm>
#include <initializer_list>

namespace EPAM
{
	template<typename Type>
	class Array
	{
	public:
		Array() = delete;
	public:
		Array(size_t size);
		Array(std::initializer_list<Type>&& elems);
		Array(const Array<Type>& other);
		Array(const Array<Type>&& other);

		size_t max() const;
		size_t size() const;

		Type& operator [] (size_t index);

		~Array();
	private:
		Type* m_array{};
		size_t m_size{};
	};

	template<typename Type>
	Array<Type>::Array(size_t size)
		: m_size{ size }
	{
		this->m_array = new Type[this->m_size];
		std::fill(this->m_array, this->m_array + this->m_size, Type());
	}
	template<typename Type>
	Array<Type>::Array(std::initializer_list<Type>&& elems)
		: m_size{ elems.size() }
	{
		this->m_array = new Type[this->m_size];
		std::copy(elems.begin(), elems.end(), this->m_array);
	}
	template<typename Type>
	Array<Type>::Array(const Array<Type>& other)
		: m_size{ other.size() }
	{
		this->m_array = new Type[m_size];
		std::copy(other.m_array, other.m_array + other.m_size, this->m_array);
	}
	template<typename Type>
	Array<Type>::Array(const Array<Type>&& other)
		: m_size{ other.size() }
	{
		this->m_array = new Type[m_size];
		std::copy(other.m_array, other.m_array + other.m_size, this->m_array);
	}

	template<typename Type>
	size_t Array<Type>::max() const
	{
		return *std::max_element(this->m_array, this->m_array + this->m_size);
	}
	template<typename Type>
	size_t Array<Type>::size() const
	{
		return this->m_size;
	}

	template<typename Type>
	Type& Array<Type>::operator [] (size_t index)
	{
		return this->m_array[index];
	}

	template<typename Type>
	Array<Type>::~Array()
	{
		delete[] this->m_array;
	}
}