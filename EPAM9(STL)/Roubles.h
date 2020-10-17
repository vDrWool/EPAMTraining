#pragma once
#include <iostream>
#include <string>

namespace EPAM
{
	class Roubles
	{
	public:
		Roubles() : m_count{} {};
		Roubles(long double count) : m_count{ count } {};
		Roubles(const Roubles& other) : m_count{ other.m_count } {};

		Roubles(Roubles&& other) noexcept : m_count{ other.m_count } { other.m_count = 0; };
	public:
		Roubles& operator = (Roubles& other);
		Roubles& operator = (Roubles&& other) noexcept;

		bool operator <  (const Roubles& other) { return this->m_count <  other.m_count; }
		bool operator >  (const Roubles& other) { return this->m_count >  other.m_count; }
		bool operator <= (const Roubles& other) { return this->m_count <= other.m_count; }
		bool operator >= (const Roubles& other) { return this->m_count >= other.m_count; }
		bool operator == (const Roubles& other) { return this->m_count == other.m_count; }
		bool operator != (const Roubles& other) { return this->m_count != other.m_count; }

		friend Roubles operator + (const Roubles& first, const Roubles& second) { return Roubles(first.m_count + second.m_count); }
		friend Roubles operator - (const Roubles& first, const Roubles& second) { return Roubles(first.m_count - second.m_count); }
		friend Roubles operator * (const Roubles& first, const Roubles& second) { return Roubles(first.m_count * second.m_count); }
		friend Roubles operator / (const Roubles& first, const Roubles& second) { return Roubles(first.m_count / second.m_count); }

		friend Roubles operator + (const Roubles& first, const long double second) { return Roubles(first.m_count + second); }
		friend Roubles operator + (const long double first, const Roubles& second) { return Roubles(first + second.m_count); }
		friend Roubles operator - (const Roubles& first, const long double second) { return Roubles(first.m_count - second); }
		friend Roubles operator - (const long double first, const Roubles& second) { return Roubles(first - second.m_count); }
		friend Roubles operator * (const Roubles& first, const long double second) { return Roubles(first.m_count * second); }
		friend Roubles operator * (const long double first, const Roubles& second) { return Roubles(first * second.m_count); }
		friend Roubles operator / (const Roubles& first, const long double second) { return Roubles(first.m_count / second); }
		friend Roubles operator / (const long double first, const Roubles& second) { return Roubles(first / second.m_count); }

		friend Roubles operator + (const Roubles& first, const int second) { return Roubles(first.m_count + second); }
		friend Roubles operator + (const int first, const Roubles& second) { return Roubles(first + second.m_count); }
		friend Roubles operator - (const Roubles& first, const int second) { return Roubles(first.m_count - second); }
		friend Roubles operator - (const int first, const Roubles& second) { return Roubles(first - second.m_count); }
		friend Roubles operator * (const Roubles& first, const int second) { return Roubles(first.m_count * second); }
		friend Roubles operator * (const int first, const Roubles& second) { return Roubles(first * second.m_count); }
		friend Roubles operator / (const Roubles& first, const int second) { return Roubles(first.m_count / second); }
		friend Roubles operator / (const int first, const Roubles& second) { return Roubles(first / second.m_count); }

		Roubles& operator += (const Roubles&    value) { this->m_count += value.m_count; return *this; }
		Roubles& operator += (const long double value) { this->m_count += value;         return *this; }
		Roubles& operator += (const int         value) { this->m_count += value;         return *this; }
		Roubles& operator -= (const Roubles&    value) { this->m_count -= value.m_count; return *this; }
		Roubles& operator -= (const long double value) { this->m_count -= value;         return *this; }
		Roubles& operator -= (const int         value) { this->m_count -= value;         return *this; }
		Roubles& operator *= (const Roubles&    value) { this->m_count *= value.m_count; return *this; }
		Roubles& operator *= (const long double value) { this->m_count *= value;         return *this; }
		Roubles& operator *= (const int         value) { this->m_count *= value;         return *this; }
		Roubles& operator /= (const Roubles&    value) { this->m_count /= value.m_count; return *this; }
		Roubles& operator /= (const long double value) { this->m_count /= value;         return *this; }
		Roubles& operator /= (const int         value) { this->m_count /= value;         return *this; }

		friend std::ostream& operator << (std::ostream& out, const Roubles& value);
		friend std::istream& operator >> (std::istream&  in,       Roubles& value);
		
		Roubles& operator = (const Roubles&& other) = delete;
	private:
		long double m_count{};
	};

	namespace currency
	{
		inline Roubles operator ""_RUB(unsigned long long value) { return Roubles(static_cast<long double>(value)); }
		inline Roubles operator ""_RUB(long double value)        { return Roubles(value); }
	}
} 