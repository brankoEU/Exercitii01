
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Squares
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            int squareArea = 4 * 3;
            int cobblestoneArea = 1 * 1;
            int totalCobblestones = CalcutateCobblestones(squareArea, cobblestoneArea);
            Assert.AreEqual(12, totalCobblestones);
        }

        int CalcutateCobblestones(int squareSurface, int cobblestoneSurface)
        {
            return squareSurface / cobblestoneSurface;
        }
    }
}
