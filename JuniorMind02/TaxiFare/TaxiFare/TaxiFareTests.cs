
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
            decimal pricePerKm = GetPrice(numberKm, DayTimePrices);

            return numberKm * pricePerKm;
        }

        private static decimal GetPrice(int numberKm, decimal[] DayTimePrices)
        {
            decimal pricePerKm = DayTimePrices[0]; ;
            if (IsLongDistance(numberKm))
                pricePerKm = DayTimePrices[2];
            else if (IsMediumDistance(numberKm))
                pricePerKm = DayTimePrices[1];
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
