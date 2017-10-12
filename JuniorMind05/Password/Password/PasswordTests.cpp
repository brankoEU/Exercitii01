#include "stdafx.h"
#include "CppUnitTest.h"
#include <random>
#include <algorithm>
#include <string>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Password
{		
	TEST_CLASS(PasswordTest)
	{
	public:
		
		TEST_METHOD(VerifyUpperCase)
		{
			string password = GeneratePassword({ 7,2,2,1,true,true });
			PasswordOptions options;
			Assert::AreEqual(2, VerifyPassword(password, options.restricted.uppercase));
		}

		TEST_METHOD(VerifySymbols)
		{
			string password = GeneratePassword({ 7,2,2,1,true,true });
			PasswordOptions options;
			Assert::AreEqual(1, VerifyPassword(password, options.restricted.symbols));
		}

		TEST_METHOD(VerifyAmbiguous)
		{
			string password = GeneratePassword({ 7,2,2,1,true,true });
			PasswordOptions options;
			Assert::AreEqual(true, VerifyAmbiguousAndSimilars(password, options.restricted.ambiguous));
		}

		TEST_METHOD(VerifyPassword)
		{
			string password = GeneratePassword({ 20,5,7,3,true,true });
			PasswordOptions options;
			Assert::AreEqual(5, VerifyPassword(password, options.restricted.uppercase));
			Assert::AreEqual(7, VerifyPassword(password, options.restricted.numbers));
			Assert::AreEqual(3, VerifyPassword(password, options.restricted.symbols));
			Assert::AreEqual(true, VerifyAmbiguousAndSimilars(password, options.restricted.ambiguous));
			Assert::AreEqual(true, VerifyAmbiguousAndSimilars(password, options.restricted.similar));
		}
		
		struct PasswordOptions
		{
			int passLenght;
			int uppercase;
			int numbers;
			int symbols;
			bool excludeAmbiguius;
			bool excludeSimilar;

			struct Restrictions
			{
				string ambiguous = "{}[]()/\'`~,;:.<>\"";
				string symbols = "!@#$%^&*-_+=|?";
				string numbers = "1234567890";
				string lowercase = "abcdefghijklmnopqrstuvwxyz";
				string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				string similar = "iIl10oO";
			}restricted;

			int GetLowerCaseLenght()
			{
				return passLenght - numbers - symbols - uppercase;
			}

			string GetRestricted()
			{
				string restrict = "";
				if (excludeAmbiguius) restrict += restricted.ambiguous;
				if (excludeSimilar) restrict += restricted.similar;
				return restrict;
			}

		};

		string GeneratePassword(PasswordOptions options)
		{
			string password = "";
			string restricted = options.GetRestricted();
			int countUpper = options.uppercase, countSymbols = options.symbols, countNumbers = options.numbers, countLower = options.GetLowerCaseLenght();

			static random_device rd;
			static mt19937 generator(rd());
			uniform_int_distribution<int> rndNo(33, 126);

			while (password.size() < options.passLenght)
			{
				char nextChar = char(rndNo(generator));
				if (CheckChar(restricted, nextChar)) { continue; }
				else
				{
					if (CheckChar(options.restricted.symbols, nextChar) && countSymbols > 0) { countSymbols--; password += nextChar; }
					if (CheckChar(options.restricted.uppercase, nextChar) && countUpper > 0) { countUpper--; password += nextChar; }
					if (CheckChar(options.restricted.numbers, nextChar) && countNumbers > 0) { countNumbers--; password += nextChar; }
					if (CheckChar(options.restricted.lowercase, nextChar) && countLower > 0) { countLower--; password += nextChar; }
				}
				
			}
			return password;
		}

		

		bool CheckChar(string str, char toCheck)
		{
			for (int i = 0; i < str.size(); i++)
			{
				if (toCheck == str[i]) return true;
			}
			return false;
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