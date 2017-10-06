#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Intersection
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestIntersetion)
		{
			vector<Directions> build = { Directions::UP, Directions::UP ,Directions::RIGHT, Directions::RIGHT };
			Assert::IsTrue(Point(2, 3) == FindIntersection(Point(1, 1), build));
		}

		enum class Directions { UP, DOWN, LEFT, RIGHT };

		struct Point
		{
			int x;
			int y;
			Point(int x, int y)
			{
				this->x = x;
				this->y = y;
			}

			const inline bool operator==(const Point& other) const 
			{
				return (x == other.x && y == other.y);
			}

			int Build(Directions direction)
			{
				switch (direction)
				{
				case Directions::UP: return y++;
				case Directions::DOWN: return y--;
				case Directions::LEFT: return x--;
				case Directions::RIGHT: return x++;

				}
			}

		};

		Point FindIntersection(Point start, vector<Directions> directions)
		{
			vector<Point> buildPoins;
			for (int i = 0; i < directions.size(); i++)
			{
				buildPoins.emplace_back(start);
				start.Build(directions[i]);
			}
			return buildPoins[3];
		}

	};
}