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
			//Assert::AreEqual(12.0, Calculate("* 3 4"));
			Assert::AreEqual( "0" , Calculate("* 3 4").c_str());
		}

		string Calculate(string expresion)
		{
			istringstream iss(expresion);
			vector<string> split((istream_iterator<string>(iss)), istream_iterator<string>());
			return split[2];
		}

	};
}