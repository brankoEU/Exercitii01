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

		TEST_METHOD(SquaresFor2x2)
		{
			Assert::AreEqual(5, CalculateChessSquares(2));
		}

		int CalculateChessSquares(int dimension)
		{
			int totalSquares = 0;
			for (int i = 1; i <= dimension; i++)
			{
				totalSquares += pow(i, 2);
			}
			return totalSquares;
		}

	};
}