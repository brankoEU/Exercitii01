
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
            Assert.AreEqual(11, CalculateRent(10, 5));
        }

        decimal CalculateRent(decimal rent, int daysDelay)
        {
            return 0;
        }
    }
}
