#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LunchMeeting
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestCMMDC2And4)
		{
			Assert::AreEqual(2, CalculateDaysToNextMeeting(2, 4));
		}

		int CalculateDaysToNextMeeting(int numberOne, int numberTwo)
		{
			//calcul CMMDC
			while (numberTwo != 0)
			{
				int aux = numberTwo;
			    numberTwo = numberOne%numberTwo;
				numberOne = aux;
			}

			return numberOne;
		}

	};
}