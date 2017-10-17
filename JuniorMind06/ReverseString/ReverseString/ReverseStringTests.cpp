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

		string ReverseString(string str)
		{
			if (str.size() < 2) return str;
			return str[str.size() - 1]+ReverseString(str.substr(0, str.size() - 1));
		}

	};
}