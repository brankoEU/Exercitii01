#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace HanoiTowers
{		
	TEST_CLASS(HanoiTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual("AB", Hanoi(1, 'A', 'B', 'C').c_str());
		}

		string Hanoi(int disc, char a, char b, char c)
		{
			return "";
		}

	};
}