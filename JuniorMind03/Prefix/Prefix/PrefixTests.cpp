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

		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual("aa", GetTextPrefix("aac", "aab").c_str());
		}

		TEST_METHOD(TestMethod3)
		{
			Assert::AreEqual("aaab", GetTextPrefix("aaabcjh", "aaabbaa").c_str());
		}

		TEST_METHOD(TestMethod4)
		{
			Assert::AreEqual("ada", GetTextPrefix("adam", "adabbaa").c_str());
		}

		TEST_METHOD(TestMethod5)
		{
			Assert::AreEqual("a", GetTextPrefix("axamodevbg", "adabbaa").c_str());
		}

		string GetTextPrefix(string text1, string text2)
		{
			string prefix = "";
			bool found = true;
			int index = 0;
			do
			{
				found = false;
				if (text1[index] == text2[index])
				{
					prefix += text1[index];
					found = true;
				}
				index++;
			} while (found && StringNotEnded(index, text1, text2));
			
			
			return prefix;
		}

		bool StringNotEnded(int i, std::string &text1, std::string &text2)
		{
			return i<text1.length() || i<text2.length();
		}

	};
}