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

		string ReverseString(string str)
		{
			return "";
		}

	};
}