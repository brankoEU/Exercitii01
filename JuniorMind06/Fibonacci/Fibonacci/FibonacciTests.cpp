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
			Assert::AreEqual(1, Fibonacci(1));
		}

		TEST_METHOD(FibonacciTest2)
		{
			Assert::AreEqual(21, Fibonacci(8));
		}

		TEST_METHOD(FibonacciTest3)
		{
			Assert::AreEqual(610, Fibonacci(15));
		}

		int Fibonacci(int nr)
		{
			return nr < 2 ? nr : Fibonacci(nr - 1) + Fibonacci(nr - 2);
		}

	};
}