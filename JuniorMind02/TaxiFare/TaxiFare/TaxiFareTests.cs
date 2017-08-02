
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace TaxiFare
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestDayTimeShortDistance()
        {
            Assert.AreEqual(25, CalculateTaxiFare(5, 9));
        }

        [TestMethod]
        public void TestDayTimeMediumDistance()
        {
            Assert.AreEqual(240, CalculateTaxiFare(30, 9));
        }

        decimal CalculateTaxiFare(int numberKm, int hour)
        {
            decimal pricePerKm = 0;
            if (numberKm >= 21 && numberKm <= 60) pricePerKm = 8;
            else pricePerKm = 5;
            return numberKm * pricePerKm;
        }
    }
}
