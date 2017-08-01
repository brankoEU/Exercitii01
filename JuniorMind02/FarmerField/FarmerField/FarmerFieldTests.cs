
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

        [TestMethod]
        public void TestMethod2()
        {
            Assert.AreEqual(770, CalculateInitialFieldSize(230, 770000));
        }

        double CalculEcuatie(int b, int c)
        {
            double delta = Math.Pow(b, 2) + 4 * c;
            double x1 = (-b + Math.Sqrt(delta)) / 2;
            double x2 = (-b - Math.Sqrt(delta)) / 2;
            return x1 > 0 ? x1 : x2;
        }

        double CalculateInitialFieldSize(int fieldWidth, int fieldTotalSize)
        {
            double fieldLenght = CalculEcuatie(fieldWidth, fieldTotalSize);
            return fieldLenght;
        }
    }
}
