#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include <algorithm>

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

			for (int i = 0; i < min(text1.length(), text2.length()) && text1[i] == text2[i]; i++)    
				prefix += text1[i];
			
			return prefix;
		}
	};
}