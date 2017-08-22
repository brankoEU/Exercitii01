#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ByteOperations
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual("1010", ConvertToBaseTwo(10).c_str());
		}
		
		string ConvertToBaseTwo(int number)
		{
			string bin = "";
			while (number > 0)
			{
				if(number % 2>0) bin = '1' + bin;
				else bin = '0' + bin;
				number /= 2;
			}
			return bin;
		}

	};
}