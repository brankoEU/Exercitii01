#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Prefix
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual("a", GetTextPrefix("a", "a").c_str());
		}

		string GetTextPrefix(string text1, string text2)
		{
			string prefix = "";
			if (text1[0]==text2[0])
			{
				prefix += text1[0];
			}
			return prefix;
		}

	};
}