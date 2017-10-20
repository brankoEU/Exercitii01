#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Calculator
{		
	TEST_CLASS(CalculatorTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(12.0, Calculate("* 3 4"));
		}

		double Calculate(string expresion)
		{
			return 0;
		}

	};
}