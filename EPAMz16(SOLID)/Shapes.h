#pragma once
#include <exception>

namespace EPAM
{
	struct Point
	{
		int x{};
		int y{};

		bool operator == (const Point& other) { return this->x == other.x && this->y == other.y; }
	};

	class IShape
	{
	public:
		virtual float perimeter() const = 0;
		virtual float square() const = 0;

		// virtual type draw(args) = 0;
	};

	class Circle : public IShape
	{
	public:
		Circle() noexcept = default;
		Circle(Point center) noexcept : m_center{ center }, m_radius{ 0 } {}
		Circle(Point center, unsigned radius) noexcept : m_center{ center }, m_radius{ radius } {}

		Circle(const Circle& other) noexcept : m_center{ other.m_center }, m_radius{ other.m_radius } {}
		Circle& operator = (const Circle& other) noexcept;
	public:
		bool operator == (const Circle& other) noexcept;
	public:
		float perimeter() const override;
		float square() const override;
	private:
		Point    m_center{};
		unsigned m_radius{};
	};

	class Square : public IShape
	{
	public:
		Square() noexcept = default;
		Square(Point leftUp) noexcept : m_leftUp{ leftUp }, m_length{ 0 } {}
		Square(Point leftUp, unsigned length) noexcept : m_leftUp{ leftUp }, m_length{ length } {}

		Square(const Square& other) noexcept : m_leftUp{ other.m_leftUp }, m_length{ other.m_length } {}
		Square& operator = (const Square& other) noexcept;
	public:
		bool operator == (const Square& other) noexcept;
	public:
		float perimeter() const override;
		float square() const override;
	private:
		Point    m_leftUp{};
		unsigned m_length{};
	};

	class Rectangle : public IShape
	{
	public:
		Rectangle() noexcept = default;
		Rectangle(Point leftUp, Point rightDown) noexcept : m_leftUp{ leftUp }, m_rightDown{ rightDown } {}

		Rectangle(const Rectangle& other) noexcept : m_leftUp{ other.m_leftUp }, m_rightDown{ other.m_rightDown } {}
		Rectangle& operator = (const Rectangle& other) noexcept;
	public:
		bool operator == (const Rectangle& other) noexcept;
	public:
		float perimeter() const override;
		float square() const override;
	private:
		Point m_leftUp{};
		Point m_rightDown{};
	};
}