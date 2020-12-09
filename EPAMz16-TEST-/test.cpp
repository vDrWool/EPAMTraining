#include "gtest/gtest.h"

#include <memory>

#include "Shapes.cpp"

TEST(Shapes, ShapeCircle)
{
	std::unique_ptr<EPAM::IShape> shape = std::make_unique<EPAM::Circle>(EPAM::Point{ 0.0f, 0.5f }, 15.0f);

	EXPECT_TRUE(shape->perimeter() == 2 * 3.1415f * 15.0f);
	EXPECT_TRUE(shape->square()    == 3.1415f * 15.0f * 15.0f);
}

TEST(Shapes, ShapeSquare)
{
	std::unique_ptr<EPAM::IShape> shape = std::make_unique<EPAM::Square>(EPAM::Point{ 0.0f, 1.0f }, 1.0f);

	EXPECT_TRUE(shape->perimeter() == 4 * 1.0f);
	EXPECT_TRUE(shape->square()    == 1.0f * 1.0f);
}

TEST(Shapes, ShapeRect)
{
	std::unique_ptr<EPAM::IShape> shape = std::make_unique<EPAM::Rectangle>(EPAM::Point{ 0.0f, 2.0f }, EPAM::Point{ 4.0f, 0.0f });
	
	EXPECT_TRUE(shape->perimeter() == 2 * 4.0f + 2 * 2.0f);
	EXPECT_TRUE(shape->square()    == 2.0f * 4.0f);
}