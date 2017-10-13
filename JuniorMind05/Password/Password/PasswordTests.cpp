#include "stdafx.h"
#include "CppUnitTest.h"
#include <random>
#include <algorithm>
#include <string>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Password
{	
	class Generator {
		std::uniform_int_distribution<int> dis;
		std::mt19937 gen;
	public:
		Generator(int lower = 33, int upper = 126)
			: gen(std::random_device()()), dis(lower, upper) {}

		int operator()() {
			return dis(gen);
		}
	};

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
		
		struct PasswordOptions
		{
			int passLenght;
			int uppercase;
			int numbers;
			int symbols;
			bool excludeAmbiguius;
			bool excludeSimilar;

			struct StringSets
			{
				string ambiguous = "{}[]()/\\'`~,;:.<>\"";
				string symbols = "!@#$%^&*-_+=|?";
				string numbers = "1234567890";
				string lowercase = "abcdefghijklmnopqrstuvwxyz";
				string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
				string similar = "iIl10oO";
			}strSets;

			string GetAllowed()
			{
				string allowed = strSets.lowercase;
				if (!excludeAmbiguius) allowed += strSets.ambiguous;
				if (!excludeSimilar) allowed += strSets.similar;
				return allowed;
			}

			string GetRestricted()
			{
				string restricted = "";
				if (excludeAmbiguius) restricted += strSets.ambiguous;
				if (excludeSimilar) restricted += strSets.similar;
				return restricted;
			}

			bool CheckChar(string str, char toCheck)
			{
				for each(char c in str)
				{
					if (toCheck == c) return true;
				}
				return false;
			}

			string GetUpperCases()
			{
				Generator rndNo;
				string str = "";
				int i = 0;
				while (i < uppercase)
				{
					char nextChar = char(rndNo());
					if (CheckChar(strSets.uppercase, nextChar) && !CheckChar(GetRestricted(), nextChar))
					{
						str += nextChar;
						i++;
					}
				}
				return str;
			}

			string GetNumbers()
			{
				Generator rndNo;
				string str = "";
				int i = 0;
				while (i < numbers)
				{
					char nextChar = char(rndNo());
					if (CheckChar(strSets.numbers, nextChar) && !CheckChar(GetRestricted(), nextChar))
					{
						str += nextChar;
						i++;
					}
				}
				return str;
			}

			string GetSymbols()
			{
				Generator rndNo;
				string str = "";
				int i = 0;
				while (i < symbols)
				{
					char nextChar = char(rndNo());
					if (CheckChar(strSets.symbols, nextChar) && !CheckChar(GetRestricted(), nextChar))
					{
						str += nextChar;
						i++;
					}
				}
				return str;
			}

			string GeneratePassword()
			{
				Generator rndNo;
				string password = GetUpperCases() + GetNumbers() + GetSymbols();

				while (password.size() < passLenght)
				{
					char nextChar = char(rndNo());
					if (CheckChar(GetAllowed(), nextChar) && !CheckChar(GetRestricted(), nextChar)) { password += nextChar; }
				}
				return password;
			}

		};

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