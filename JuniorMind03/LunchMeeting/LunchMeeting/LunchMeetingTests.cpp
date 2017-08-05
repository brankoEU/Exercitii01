#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LunchMeeting
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestFor2And4)
		{
			Assert::AreEqual(4, CalculateDaysToNextMeeting(2, 4));
		}

		int CalculateDaysToNextMeeting(int numaberOne, int numberTwo)
		{
			return 0;
		}

	};
}