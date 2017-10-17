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
			Assert::AreEqual(1, Fibonacci(1,1,1));
		}

		TEST_METHOD(FibonacciTest2)
		{
			Assert::AreEqual(21, Fibonacci(8,1,1));
		}

		TEST_METHOD(FibonacciTest3)
		{
			Assert::AreEqual(34, Fibonacci(9,1,1));
		}

		TEST_METHOD(FibonacciTest4)
		{
			Assert::AreEqual(610, Fibonacci(15,1,1));
		}

		/*int Fibonacci(int n)
		{
			return n < 2 ? n : Fibonacci(n - 1) + Fibonacci(n - 2);
		}*/

		int Fibonacci(int n, int res, int next)
		{
			if (n < 2) { return res; }
			return Fibonacci(n - 1, next, res + next);
		}

	};
}