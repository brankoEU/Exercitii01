
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
            float buildingArea = CalculateMinimalArea(2, 1, 4, 2, 5, 1);
            Assert.AreEqual(6, buildingArea);
        }

        float CalculateMinimalArea(float x1, float y1, float x2, float y2, float x3, float y3)
        {
            float triangleArea = x1 * y2 + x2 * y3 + x3 * y1 - x3 * y2 - x1 * y3 - x2 * y1;
            return Math.Abs(triangleArea * 2);
        }
    }
}
