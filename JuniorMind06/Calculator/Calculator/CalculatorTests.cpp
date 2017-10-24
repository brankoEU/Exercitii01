#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>
#include <iterator>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Calculator
{		
	TEST_CLASS(CalculatorTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int i = 0;
			Assert::AreEqual(12.0, Calculate("* 3 4" , i));
		}
		TEST_METHOD(TestMethod2)
		{
			int i = 0;
			Assert::AreEqual(4.0, Calculate("* + 1 1 2", i));
		}
		TEST_METHOD(TestMethod3)
		{
			int i = 0;
			Assert::AreEqual(1549.4166666666667, Calculate("+ / * + 56 45 46 3 - 1 0.25",i));
		}

		bool isOperator(const string& s)
		{
			string ops = "+-*/";
			return (ops.find(s)!=string::npos);
		}

		double Calculate(string expresion, int& i)
		{
			istringstream iss(expresion);
			vector<string> split((istream_iterator<string>(iss)), istream_iterator<string>());

			string token = split[i++];
			if (!isOperator(token)) { return stod(token); }
			else
			{
				if (token == "+") return Calculate(expresion, i) + Calculate(expresion, i);
				if (token == "-") return Calculate(expresion, i) - Calculate(expresion, i);
				if (token == "*") return Calculate(expresion, i) * Calculate(expresion, i);
				if (token == "/") return Calculate(expresion, i) / Calculate(expresion, i);
			}
		}

	};
}