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
			Assert::AreEqual(2, CalculateCMMDC(2, 4));
		}

		TEST_METHOD(TestCMMDC9And27)
		{
			Assert::AreEqual(9, CalculateCMMDC(9, 27));
		}

		TEST_METHOD(TestCMMC4And6)
		{
			Assert::AreEqual(12, CalculateDaysToNextMeeting(4, 6));
		}

		TEST_METHOD(TestCMMC7And18)
		{
			Assert::AreEqual(126, CalculateDaysToNextMeeting(7, 18));
		}

		TEST_METHOD(TestCMMC18And124)
		{
			Assert::AreEqual(1116, CalculateDaysToNextMeeting(18, 124));
		}

		int CalculateDaysToNextMeeting(int numberOne, int numberTwo)
		{
			return CalculateCMMMC(numberOne, numberTwo);
		}

		int CalculateCMMMC(int a, int b)
		{
			//calcul CMMMC
			return a * b / CalculateCMMDC(a, b);
		}

		int CalculateCMMDC(int a, int b)
		{
			//calcul CMMDC
			while (b != 0)
			{
				int aux = b;
				b = a % b;
				a = aux;
			}
			return a;
		}

	};
}