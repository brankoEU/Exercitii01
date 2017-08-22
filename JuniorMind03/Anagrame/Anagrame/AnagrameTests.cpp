#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Anagrame
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(1, CalculateAnagrams("ab"));
		}

		int CalculateAnagrams(string text)
		{
			return 0;
		}

	};
}