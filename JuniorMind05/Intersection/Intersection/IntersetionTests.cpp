#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Intersection
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestIntersetion)
		{
			Assert::AreEqual({ 1,0 }, FindIntersection());
		}

		struct Point
		{
			int x;
			int y;
			Point point(int x, int y)
			{
				this->x = x;
				this->y = y;
			}
		};

		Point FindIntersection()
		{
			Point point = { 0,0 };
			return point;
		}

	};
}