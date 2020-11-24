#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <initializer_list>

namespace EPAM
{
	template<typename Type>
	class Matrix
	{
	public:
		Matrix() = delete;
	public:
		Matrix(size_t n, size_t m);
		Matrix(const std::vector<std::vector<Type>>& rawMatrix);
		Matrix(const Matrix<Type>& other);
		Matrix(const Matrix<Type>&& other);

		const size_t rowSize();
		const size_t columnSize();
		std::pair<const size_t, const size_t> size();

		friend void Task(Matrix<Type>& matrix);

		std::vector<Type>& operator[] (size_t index);

		template<typename Type>
		friend std::ostream& operator << (std::ostream& out, const Matrix<Type>& matrix);
		template<typename Type>
		friend std::istream& operator >> (std::istream& in,        Matrix<Type>& matrix);
	private:
		std::vector<std::vector<Type>> m_matrix{};
	};

	template<typename Type>
	Matrix<Type>::Matrix(size_t n, size_t m)
	{
		this->m_matrix.resize(n);
		for (auto& row : this->m_matrix)
		{
			row.resize(m);
			for (auto& columnElem : row)
			{
				columnElem = Type();
			}
		}
	}
	template<typename Type>
	Matrix<Type>::Matrix(const std::vector<std::vector<Type>>& other)
	{
		std::copy(other.begin(), other.end(), this->m_matrix);
	}
	template<typename Type>
	Matrix<Type>::Matrix(const Matrix<Type>& other)
	{
		std::copy(other.m_matrix.begin(), other.m_matrix.end(), this->m_matrix);
	}
	template<typename Type>
	Matrix<Type>::Matrix(const Matrix<Type>&& other)
	{
		std::copy(other.m_matrix.begin(), other.m_matrix.end(), this->m_matrix);
	}


	template<typename Type>
	const size_t Matrix<Type>::rowSize()
	{
		return this->m_matrix.size();
	}
	template<typename Type>
	const size_t Matrix<Type>::columnSize()
	{
		return this->m_matrix[0].size();
	}
	template<typename Type>
	std::pair<const size_t, const size_t> Matrix<Type>::size()
	{
		return { this->m_matrix.size(), this->m_matrix[0].size() };
	}


	template<typename Type>
	void Task(Matrix<Type>& matrix) 
	{
		for (auto i{ 0 }; i < static_cast<int>(matrix.size().first); i++)
		{
			bool isGreaterThanZero{ true };

			for (auto j{ 0 }; j < static_cast<int>(matrix[i].size()); j++)
			{
				if (matrix[i][j] < 0)
				{
					isGreaterThanZero = false;
					break;
				}
			}

			if (isGreaterThanZero)
			{
				unsigned int sum{};

				for (auto& elem : matrix[i])
					sum += elem;

				std::cout << i + 1 << ") " << sum << ".\n";
			}
		}
	}
	

	template<typename Type>
	std::vector<Type>& Matrix<Type>::operator[] (size_t index)
	{
		return this->m_matrix[index];
	}


	template<typename Type>
	std::ostream& operator << (std::ostream& out, const Matrix<Type>& matrix)
	{
		for (auto& row : matrix.m_matrix)
		{
			for (auto& columnElem : row)
			{
				out << columnElem << ' ';
			}
			out << '\n';
		}

		return out;
	}
	template<typename Type>
	std::istream& operator >> (std::istream& in,        Matrix<Type>& matrix)
	{
		for (auto& row : matrix.m_matrix)
		{
			for (auto& columnElem : row)
			{
				in >> columnElem;
			}
		}

		return in;
	}
}
