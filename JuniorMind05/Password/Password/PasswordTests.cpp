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
			Assert::AreEqual(2, VerifyCharacters(password, 'A', 'Z'));
		}

		TEST_METHOD(VerifyGetNumbers)
		{
			PasswordOptions options = { 7,2,2,1,true,true };
			string password = options.GetNumbers();
			Assert::AreEqual(2, VerifyCharacters(password, '0', '9'));
		}

		TEST_METHOD(VerifyGetSymbols)
		{
			PasswordOptions options = { 7,2,2,1,true,true };
			string password = options.GetSymbols();
			Assert::AreEqual(1, VerifySymbols(password, options.strSets.symbols));
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
			Assert::AreEqual(5, VerifyCharacters(password, 'A', 'Z'));
			Assert::AreEqual(7, VerifyCharacters(password, '0', '9'));
			Assert::AreEqual(3, VerifySymbols(password, options.strSets.symbols));
			Assert::AreEqual(true, VerifyAmbiguousAndSimilars(password, options.strSets.ambiguous));
			Assert::AreEqual(true, VerifyAmbiguousAndSimilars(password, options.strSets.similar));
		}
		
		int VerifyCharacters(string password, char min, char max)
		{
			int count = 0;
			for each (char c in password)
			{
				if (c >= min && c <= max) { count++; }
			}
			return count;
		}

		int VerifySymbols(string password, string str)
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