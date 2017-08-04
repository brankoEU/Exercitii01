#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TablaDeSah
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(SquaresFor1x1)
		{
			Assert::AreEqual(1, CalculateChessSquares(1));
		}

		int CalculateChessSquares(int dimension)
		{
			return pow(dimension,2);
		}

	};
}