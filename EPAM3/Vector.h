#pragma once
#include <algorithm>
#include <iostream>
#include <initializer_list>


namespace EPAM
{
	template<typename T>
	class Vector
	{
	public:
		Vector();
		Vector(unsigned int size);
		Vector(const Vector& other);
		Vector(const Vector&& other);
		Vector(std::initializer_list<T>& lst);


		T mult() noexcept;
		void print() const noexcept;

		T& max();
		T& min();
		T avarage();

		T* begin();
		T* end();


		Vector& operator = (const Vector& other);
		
		bool operator >  (const Vector& other);
		bool operator <  (const Vector& other);
		bool operator >= (const Vector& other);
		bool operator <= (const Vector& other);
		bool operator == (const Vector& other);
		bool operator != (const Vector& other);

		T& operator [] (size_t index);

		~Vector();
	private:
		T* m_vector{};
		unsigned int m_size{};
	};


	template<typename T>
	Vector<T>::Vector() {}

	template<typename T>
	Vector<T>::Vector(unsigned int size) : m_size{ size }
	{
		this->m_vector = new T[this->m_size]{};
	}

	template<typename T>
	Vector<T>::Vector(const Vector& other) 
	{
		this->m_vector = new T[this->m_size];
		std::copy(other.m_vector, other.m_vector + m_size, this->m_vector);
	}

	template<typename T>
	Vector<T>::Vector(const Vector&& other) 
	{
		this->m_vector = new T[this->m_size];
		std::copy(other.m_vector, other.m_vector + m_size, this->m_vector);
	}

	template<typename T>
	Vector<T>::Vector(std::initializer_list<T>& lst) 
	{
		this->m_vector = new T[lst.size()];
		std::copy(lst.begin(), lst.end(), this->m_vector);
	}

	template<typename T>
	T Vector<T>::mult() noexcept
	{
		int mult{ 1 };

		int* minIndex{ std::find(this->begin(), this->end(), this->min()) };
		int* maxIndex{ std::find(this->begin(), this->end(), this->max()) };

		int* begin{};
		int* end{};
		if (maxIndex > minIndex)
		{
			begin = minIndex;
			end = maxIndex;
		}
		else
		{
			begin = maxIndex;
			end = minIndex;
		}

		for (; begin <= end; begin++)
		{
			mult *= *begin;
		}

		return mult;
	}

	template<typename T>
	void Vector<T>::print() const noexcept
	{
		for (auto i{ 0 }; i < static_cast<int>(this->m_size); i++)
		{
			std::cout << this->m_vector[i] << ' ';
		}

		std::cout << '\n';
	}

	template<typename T>
	T& Vector<T>::max() 
	{
		return *std::max_element(this->m_vector, this->m_vector + this->m_size);
	}
	template<typename T>
	T& Vector<T>::min()
	{
		return *std::min_element(this->m_vector, this->m_vector + this->m_size);
	}
	template<typename T>
	T Vector<T>::avarage()
	{
		int av{};

		for (auto i{ 0 }; i < static_cast<int>(this->m_size); i++)
		{
			av += this->m_vector[i];
		}

		return av /= this->m_size;
	}

	template<typename T>
	T* Vector<T>::begin()
	{
		return this->m_vector;
	}
	template<typename T>
	T* Vector<T>::end()
	{
		return this->m_vector + this->m_size;
	}


	template<typename T>
	Vector<T>& Vector<T>::operator = (const Vector<T>& other)
	{
		if (this->m_size != 0)
			delete[] this->m_vector;

		this->m_vector = new T[other.m_size];
		std::copy(other.m_vector, other.m_vector + other.m_size, this->m_vector);

		return *this;
	}

	template<typename T>
	bool Vector<T>::operator > (const Vector& other)
	{
		return this->m_size > other.m_size;
	}
	template<typename T>
	bool Vector<T>::operator < (const Vector& other)
	{
		return this->m_size < other.m_size;
	}
	template<typename T>
	bool Vector<T>::operator >= (const Vector& other)
	{
		return this->m_size < other.m_size;
	}
	template<typename T>
	bool Vector<T>::operator <= (const Vector& other)
	{
		return this->m_size < other.m_size;
	}
	template<typename T>
	bool Vector<T>::operator == (const Vector& other)
	{
		return this->m_size == other.m_size;
	}
	template<typename T>
	bool Vector<T>::operator != (const Vector& other)
	{
		return this->m_size != other.m_size;
	}

	template<typename T>
	T& Vector<T>::operator[] (size_t index)
	{
		return this->m_vector[index];
	}


	template<typename T>
	Vector<T>::~Vector()
	{
		delete[] this->m_vector;
	}
}