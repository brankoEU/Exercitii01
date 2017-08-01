
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace FarmerField
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            Assert.AreEqual(2, CalculateInitialFieldSize(1, 6));
        }

        double CalculateInitialFieldSize(int fieldWidth, int fieldTotalSize)
        {
            return 0;
        }
    }
}
