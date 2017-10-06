#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Intersection
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestIntersetion)
		{
			Assert::AreEqual(Point(1, 0), FindIntersection());
		}

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
		};

		Point FindIntersection()
		{
			return Point(0, 0);
		}

	};
}