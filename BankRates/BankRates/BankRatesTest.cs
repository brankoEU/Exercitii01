﻿
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace BankRates
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void RateForFirstMonth()
        {
            decimal rate = CalculateBankRate(100, 2, 12, 1);
            Assert.AreEqual(51,rate);
        }

        [TestMethod]
        public void RateForSecondMonth()
        {
            decimal rate = CalculateBankRate(100, 2, 12, 2);
            Assert.AreEqual(50.5m, rate);
        }

        [TestMethod]
        public void RateForSevenMonth()
        {
            decimal rate = CalculateBankRate(100, 10, 12, 7);
            Assert.AreEqual(10.4m, rate);
        }

        [TestMethod]
        public void RateForThirdMonthOfForthYear()
        {
            decimal rate = CalculateBankRate(40000m, 240, 7.57m, 39);
            Assert.AreEqual(379.0472620172917m, rate);
        }

        decimal CalculateBankRate(decimal total, int periodInMonths, decimal interestPerYear, int currentMonth)
        {
            decimal interestPerMonth = interestPerYear / 12 / 100;
            decimal basePerMounth = total / periodInMonths;
            decimal sold = total - (currentMonth - 1) * basePerMounth;
            return basePerMounth + sold * interestPerMonth;
        }
    }
}
