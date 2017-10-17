#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace FindAndReplace
{		
	TEST_CLASS(FAR_Tests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual("ama", FindAndReplace("ada",'d',"m").c_str());
		}

		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual("amnamn", FindAndReplace("adad", 'd', "mn").c_str());
		}

		TEST_METHOD(TestMethod3)
		{
			Assert::AreEqual("telefon", FindAndReplace("txlxfon", 'x', "e").c_str());
		}

		string FindAndReplace(string str, char c, string replacer)
		{
			if (str.find(c) == string::npos) return str;
			return FindAndReplace((str.replace(str.find(c), str.find(c),replacer)),c,replacer);
		}

	};
}