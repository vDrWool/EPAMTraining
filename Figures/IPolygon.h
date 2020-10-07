#pragma once

namespace Figures
{
	struct Point
	{
		unsigned int x{};
		unsigned int y{};
	};

	class IPolygon
	{
	public:
		virtual void setPos(const Point&& leftUp) = 0;
	};
}