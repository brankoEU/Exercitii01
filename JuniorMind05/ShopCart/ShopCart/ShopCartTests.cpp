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
			Assert::AreEqual(9.8, TotalShopingCart());
		}

		TEST_METHOD(CheapestProduct)
		{
			Assert::AreEqual("Water", FindCheapestProduct().c_str());
		}

		TEST_METHOD(ExpensiveProduct)
		{
			Assert::AreEqual("Bread", EraseExpensiveProduct().c_str());
		}

		TEST_METHOD(AddProduct)
		{
			AddToCart();
			Assert::IsTrue(ShoppingCart[ShoppingCart.size()-1].name == "Butter");
		}

		TEST_METHOD(AverageCartPrice)
		{
			Assert::AreEqual(4.9, CalculateAveragePrice());
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

		vector<Product> ShoppingCart = { { "Water", 2.5 } ,{ "Bread", 4.1 } ,{ "Orange", 3.2 } };

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
			double temp = ShoppingCart[0].price;
			for (int i = 1; i < ShoppingCart.size(); i++)
			{
				if (ShoppingCart[i].price < temp)
				{
					cheapest = ShoppingCart[i].name;
					temp = ShoppingCart[i].price;
				}

			}
			return cheapest;
		}

		void AddToCart()
		{
			ShoppingCart.emplace_back("Butter", 2.1);
		}

		double CalculateAveragePrice()
		{
			return TotalShopingCart()/2;
		}

		string EraseExpensiveProduct()
		{
			int pos = 0;
			string expensive = ShoppingCart[0].name;
			double temp = ShoppingCart[0].price;
			for (int i = 1; i < ShoppingCart.size(); i++)
			{
				if (ShoppingCart[i].price > temp)
				{
					expensive = ShoppingCart[i].name;
					temp = ShoppingCart[i].price;
					pos = i;
				}
			}
			ShoppingCart.erase(ShoppingCart.begin() + pos);
			return expensive;
		}


	};
}