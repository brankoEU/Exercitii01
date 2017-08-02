
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

        [TestMethod]
        public void TestNightTimeShortDistance()
        {
            Assert.AreEqual(35, CalculateTaxiFare(5, 21));
        }

        [TestMethod]
        public void TestNightTimeMediumDistance()
        {
            Assert.AreEqual(300, CalculateTaxiFare(30, 21));
        }

        decimal CalculateTaxiFare(int numberKm, int hour)
        {
            decimal[] DayTimePrices = DayTime(hour);
            return numberKm * GetPrice(numberKm, DayTime(hour));
        }

        private static decimal[] DayTime(int hour)
        {
            decimal[] DayTimePrices = { 5, 8, 6 };
            decimal[] NightTimePrices = { 7, 10 };
            return 8 <= hour && hour < 21 ? DayTimePrices : NightTimePrices;
        }

        private static decimal GetPrice(int numberKm, decimal[] Prices)
        {
            decimal pricePerKm = Prices[0];
            if (IsLongDistance(numberKm))
                pricePerKm = Prices[2];
            else if (IsMediumDistance(numberKm))
                pricePerKm = Prices[1];
            return pricePerKm;
        }

        private static bool IsMediumDistance(int numberKm)
        {
            return numberKm >= 21;
        }

        private static bool IsLongDistance(int numberKm)
        {
            return numberKm >= 61;
        }
    }
}
