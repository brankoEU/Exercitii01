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

		string FindAndReplace(string str, char c, string replacer)
		{
			return "";
		}

	};
}