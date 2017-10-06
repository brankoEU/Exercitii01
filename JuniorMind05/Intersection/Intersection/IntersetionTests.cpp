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
			//Assert::IsTrue(Point(1, 3) == FindIntersection(Point(1, 1), { Directions::UP, Directions::UP }));
		}

		TEST_METHOD(TestBuild)
		{
			Assert::AreEqual(3, FindIntersection(Point(1, 1), { Directions::UP, Directions::UP }));
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

		int FindIntersection(Point start, vector<Directions> directions)
		{
			for (int i = 0; i < directions.size(); i++)
			{
				start.Build(directions[i]);
			}
			return start.y;
		}

	};
}