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

		TEST_METHOD(TestMethod3)
		{
			Assert::AreEqual("AC AB CB AC BA BC AC", Hanoi(3, "A", "B", "C").c_str());
		}

		string Hanoi(int disks, string a, string b, string c)
		{
			string result = "";
			if (disks == 1) { return a + c; }
			result += Hanoi(disks - 1, a, c, b);
			result += " " + Hanoi(1, a, b, c);
			result += " " + Hanoi(disks - 1, b, a, c);
			return result;
		}

	};
}