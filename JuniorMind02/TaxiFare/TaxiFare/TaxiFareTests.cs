
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

        decimal CalculateTaxiFare(int numberKm, int hour)
        {
            return numberKm * 5;
        }
    }
}
