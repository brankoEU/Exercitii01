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
			Assert::AreEqual("AC", Hanoi(1, "A", "B", "C").c_str());
		}

		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual("AB AC BC", Hanoi(2, "A", "B", "C").c_str());
		}

		string Hanoi(int disc, string a, string b, string c, string r = "")
		{
			if (disc == 1)  {return (a + c); }

			r+=(Hanoi(disc - 1, a, c, b, r));
			r+=" " + (Hanoi(1, a, b, c, r));
			r+=" " + (Hanoi(disc - 1, b, a, c, r));

			return r;
		}

	};
}