#pragma once
#include <initializer_list>
#include <algorithm>

namespace EPAM
{
	template<typename Type>
	class Vector
	{
	public:
		Vector() = default;
		Vector(size_t size);
		Vector(const std::initializer_list<Type>&& lst);

		Vector(const Vector<Type>& other);
		Vector(Vector<Type>&& other);

		~Vector();
	public:
		size_t size() const noexcept { return this->m_size; }
		void clear() noexcept  { delete[] this->mp_arr; this->m_size = 0; }
		void resize(size_t newSize);

		void push_back(Type elem);
		void pop_back();
	public:
		Vector<Type>& operator = (const Vector<Type>& other);
		Vector<Type>& operator = (Vector<Type>&& other);

		Type& operator [] (size_t index) const noexcept;
	private:
		Type  *mp_arr{};
		size_t m_size{};
	};



	template<typename Type>
	Vector<Type>::Vector(size_t size) : m_size{ size } 
	{
		this->mp_arr = new Type[m_size];

		std::fill(this->mp_arr, this->mp_arr + this->m_size, 0);
	}
	template<typename Type>
	Vector<Type>::Vector(const std::initializer_list<Type>&& lst) : m_size{ lst.size() }
	{
		this->mp_arr = new Type[m_size];

		std::copy(lst.begin(), lst.end(), this->mp_arr);
	}

	template<typename Type>
	Vector<Type>::Vector(const Vector<Type>& other)
	{
		this->mp_arr = new Type[other.size()];

		std::copy(other.mp_arr, other.mp_arr + other.m_size, this->mp_arr);
	}
	template<typename Type>
	Vector<Type>::Vector(Vector<Type>&& other)
	{
		this->mp_arr = new Type[other.size()];

		std::copy(other.mp_arr, other.mp_arr + other.m_size, this->mp_arr);

		delete[] other.mp_arr;
		other.m_size = 0;
	}

	template<typename Type>
	Vector<Type>::~Vector()
	{
		this->m_size = 0;
		delete[] this->mp_arr;
	}



	template<typename Type>
	void Vector<Type>::resize(size_t newSize)
	{
		Type* 
	}
}