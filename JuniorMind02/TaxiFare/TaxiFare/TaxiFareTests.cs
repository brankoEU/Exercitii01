
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

        [TestMethod]
        public void TestDayTimeLongDistance()
        {
            Assert.AreEqual(600, CalculateTaxiFare(100, 9));
        }

        decimal CalculateTaxiFare(int numberKm, int hour)
        {
            decimal[] DayTimePrices = { 5, 8, 6 };
            decimal pricePerKm = 0;
            if (numberKm >= 21 && numberKm <= 60) pricePerKm = DayTimePrices[1];
            else if (numberKm >= 61) pricePerKm = DayTimePrices[2];
            else pricePerKm = DayTimePrices[0];
            return numberKm * pricePerKm;
        }
    }
}
