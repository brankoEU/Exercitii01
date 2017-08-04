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

		string CheckPanagram(string text, string alphabet)
		{
			//const string alphabet = "abcdefghijklmnopqrstuvwxyz";
			//int textLength = text.length();
			bool isPanagram = true;
			for (int i = 0; i < alphabet.length(); i++)
			{
				if (alphabet[i] != text[0]) { isPanagram = false; }
			}

			if (isPanagram) return "yes";
			else return "no";
		}

	};
}