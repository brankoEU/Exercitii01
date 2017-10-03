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

		void PopulateShop()
		{
			ShoppingCart.emplace_back("Water", 2.5);
			ShoppingCart.emplace_back("Bread", 3.1);
			ShoppingCart.emplace_back("Orange", 5.2);
		}

		double TotalShopingCart()
		{
			PopulateShop();
			double totalPriceSC = 0;
			for (int i = 0; i < ShoppingCart.size(); i++)
			{
				totalPriceSC += ShoppingCart[i].price;
			}
			return totalPriceSC;
		}
	};
}