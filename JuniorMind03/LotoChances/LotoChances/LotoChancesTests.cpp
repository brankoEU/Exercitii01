#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LotoChances
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(ChanceOfOneFromTenTest)
		{
			Assert::AreEqual(10, CalculateLotoChance(1, 10));
		}

		double CalculateLotoChance(int numbers, int loto)
		{
			return 0;
		}

	};
}