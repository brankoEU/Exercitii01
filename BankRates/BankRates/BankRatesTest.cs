
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

        decimal CalculateBankRate(decimal total, int periodInMonths, decimal interestPerYear, int currentMonth)
        {
            return total/periodInMonths+total * interestPerYear/12/100;
        }
    }
}
