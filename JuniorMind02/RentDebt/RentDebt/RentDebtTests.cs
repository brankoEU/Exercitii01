
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace RentDebt
{
    [TestClass]
    public class RentDebtTests
    {
        [TestMethod]
        public void Delay5Days()
        {
            Assert.AreEqual(11m, CalculateRent(10, 5));
        }

        [TestMethod]
        public void Delay15Days()
        {
            Assert.AreEqual(17.5m, CalculateRent(10, 15));
        }

        [TestMethod]
        public void Delay35Days()
        {
            Assert.AreEqual(45m, CalculateRent(10, 35));
        }

        decimal CalculateRent(decimal rent, int daysDelay)
        {
            return rent*2/100*daysDelay+rent;
        }
    }
}
