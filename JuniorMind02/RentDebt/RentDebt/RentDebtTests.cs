
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
            int penalty = 0;
            if (daysDelay > 0 && daysDelay <= 10)  penalty = 2;
            if (daysDelay > 10 && daysDelay <= 30) penalty = 5;
            if (daysDelay > 30 && daysDelay <= 40) penalty = 10;
            return rent*penalty/100*daysDelay+rent;
        }
    }
}
