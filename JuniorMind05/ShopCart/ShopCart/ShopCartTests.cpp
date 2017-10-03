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

		TEST_METHOD(CheapestProduct)
		{
			Assert::AreEqual("Water", FindCheapestProduct().c_str());
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

		vector<Product> ShoppingCart = { { "Water", 2.5 } ,{ "Bread", 3.1 } ,{ "Orange", 5.2 } };

		double TotalShopingCart()
		{
			double totalPriceSC = 0;
			for (int i = 0; i < ShoppingCart.size(); i++)
			{
				totalPriceSC += ShoppingCart[i].price;
			}
			return totalPriceSC;
		} 

		string FindCheapestProduct()
		{
			string cheapest = ShoppingCart[0].name;
			for (int i = 1; i < ShoppingCart.size(); i++)
			{
				if (ShoppingCart[i].price < ShoppingCart[i - 1].price) cheapest = ShoppingCart[i].name;
			}
			return cheapest;
		}
	};
}