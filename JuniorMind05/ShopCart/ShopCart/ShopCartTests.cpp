#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ShopCart
{		
	TEST_CLASS(ShoppingCartTests)
	{
	public:
		
		TEST_METHOD(TotalPriceSHOPPING)
		{
			Assert::AreEqual(10.8, TotalShopingCart());
		}

		struct Product
		{
			string name;
			double price;
			Product(string name, double price)
			{
				this->name = name;
				this->price = price;
			}
		};
		vector<Product> ShoppingCart;
		ShoppingCart() = { ("Water", 2.5), ("Bread", 3.1), ("Orange", 5.2) };

		double TotalShopingCart()
		{
			double totalPriceSC = 0;
			for (int i = 0; i < sizeof(ShoppingCart[0]); i++)
			{
				totalPriceSC += ShoppingCart[i].price;
			}
			return totalPriceSC;
		}
	};
}