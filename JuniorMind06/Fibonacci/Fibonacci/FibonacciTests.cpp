#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Fibonacci
{		
	TEST_CLASS(FibonacciTests)
	{
	public:
		
		TEST_METHOD(FibonacciTest1)
		{
			Assert::AreEqual(21, Fibonacci(8));
		}

		int Fibonacci(int nr)
		{
			return 0;
		}

	};
}