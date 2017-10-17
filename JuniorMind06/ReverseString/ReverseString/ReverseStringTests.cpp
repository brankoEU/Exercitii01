#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ReverseStrings
{		
	TEST_CLASS(ReverseStringTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual("da", ReverseString("ad").c_str());
		}

		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual("nofelet", ReverseString("telefon").c_str());
		}

		string ReverseString(string str, string prev = "")
		{
			return str.length() == 0 ? prev : ReverseString(str.substr(0, str.length() - 1), prev += str[str.length() - 1]);
		}

	};
}