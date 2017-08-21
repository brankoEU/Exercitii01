#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Panagram
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual("no", CheckPanagram("a", "b").c_str());
		}

		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual("yes", CheckPanagram("abc", "abc").c_str());
		}

		TEST_METHOD(TestMethod3)
		{
			Assert::AreEqual("no", CheckPanagram("ac", "abc").c_str());
		}

		TEST_METHOD(TestMethod4)
		{
			Assert::AreEqual("yes", CheckPanagram("abcdef", "abcdef").c_str());
		}

		TEST_METHOD(TestMethod5Final)
		{
			Assert::AreEqual("yes", CheckPanagram("The quick brown fox jumps over the lazy dog", "abcdefghijklmnopqrstuvwxyz").c_str());
		}

		string CheckPanagram(string text, string alphabet)
		{
			bool isPanagram = true;
			int alphabetIndex = 0;
			while (isPanagram && alphabetIndex < 26)
			{
				int i = 0;
				isPanagram = false;
				while (!isPanagram && i < text.length())
				{
					if (char('a' + alphabetIndex) == text[i]) { isPanagram = true; }
					i++;
				}

				alphabetIndex++;
			}

			if (isPanagram) return "yes";
			else return "no";
		}

	};
}