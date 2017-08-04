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

		string CheckPanagram(string text, string alphabet)
		{
			//const string alphabet = "abcdefghijklmnopqrstuvwxyz";
			bool isPanagram = true;
			int alphabetIndex = 0;
			while (isPanagram && alphabetIndex < alphabet.length())
			{
				int i = 0;
				isPanagram = false;
				while (!isPanagram && i < text.length())
				{
					if (alphabet[alphabetIndex] == text[i]) { isPanagram = true; }
					i++;
				}

				alphabetIndex++;
			}

			if (isPanagram) return "yes";
			else return "no";
		}

	};
}