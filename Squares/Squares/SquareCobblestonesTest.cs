
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
            int totalCobblestones = CalcutateCobblestones(4, 3, 1);
            Assert.AreEqual(12, totalCobblestones);
        }

        [TestMethod]
        public void TestMethod2()
        {
            int totalCobblestones = CalcutateCobblestones(7, 5, 2);
            Assert.AreEqual(9, totalCobblestones);
        }

        int CalcutateCobblestones(int squareLength, int squareWidth, int cobblestoneSide)
        {
            int squareArea = squareLength * squareWidth;
            int cobblestoneArea = cobblestoneSide * cobblestoneSide;
            double cobblestones = squareArea / cobblestoneArea;
            return (int)Math.Ceiling(cobblestones);
        }
    }
}
