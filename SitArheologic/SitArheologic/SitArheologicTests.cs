
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace SitArheologic
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            double buildingArea = CalculateMinimalArea(2, 1, 4, 2, 5, 1);
            Assert.AreEqual(1.5d, buildingArea);
        }

        [TestMethod]
        public void TestMethod2()
        {
            double buildingArea = CalculateMinimalArea(2.124587, 1.567542, 4.987512, 2.654821, 5.248657, 1.124589);
            Assert.AreEqual(2.332438, buildingArea);
        }

        double CalculateMinimalArea(double x1, double y1, double x2, double y2, double x3, double y3)
        {
            double determinant = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
            double triangleArea = Math.Abs(determinant / 2);
            return Math.Round(triangleArea, 6);
        }
    }
}
