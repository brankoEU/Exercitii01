#include "stdafx.h"
#include "CppUnitTest.h"
#include "password.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Password
{	
	TEST_CLASS(PasswordTest)
	{
	public:
		
		TEST_METHOD(VerifyGetUpperCases)
		{
			PasswordOptions options = { 7,2,2,1,true,true };
			string password = options.GetUpperCases();
			Assert::AreEqual(2, VerifyPassword(password, options.strSets.uppercase));
		}

		TEST_METHOD(VerifyGetNumbers)
		{
			PasswordOptions options = { 7,2,2,1,true,true };
			string password = options.GetNumbers();
			Assert::AreEqual(2, VerifyPassword(password, options.strSets.numbers));
		}

		TEST_METHOD(VerifyGetSymbols)
		{
			PasswordOptions options = { 7,2,2,1,true,true };
			string password = options.GetSymbols();
			Assert::AreEqual(1, VerifyPassword(password, options.strSets.symbols));
		}

		TEST_METHOD(VerifyAmbiguous)
		{
			PasswordOptions options = { 7,2,2,1,true,true };
			string password = options.GeneratePassword();
			Assert::AreEqual(true, VerifyAmbiguousAndSimilars(password, options.strSets.ambiguous));
		}

		TEST_METHOD(VerifyPassword)
		{
			PasswordOptions options = { 20,5,7,3,true,true };
			string password = options.GeneratePassword();
			Assert::AreEqual(5, VerifyPassword(password, options.strSets.uppercase));
			Assert::AreEqual(7, VerifyPassword(password, options.strSets.numbers));
			Assert::AreEqual(3, VerifyPassword(password, options.strSets.symbols));
			Assert::AreEqual(true, VerifyAmbiguousAndSimilars(password, options.strSets.ambiguous));
			Assert::AreEqual(true, VerifyAmbiguousAndSimilars(password, options.strSets.similar));
		}
		
		int VerifyPassword(string password, string str)
		{
			int count = 0;
			for each (char c in password)
			{
				for (int i = 0; i < str.size(); i++)
				{
					if (str[i] == c) { count++; }
				}
			}
			return count;
		}

		bool VerifyAmbiguousAndSimilars(string password, string str)
		{
			for each (char c in password)
			{
				for (int i = 0; i < str.size(); i++)
				{
					if (str[i] == c) { return false; }
				}
			}
			return true;
		}

	};
}