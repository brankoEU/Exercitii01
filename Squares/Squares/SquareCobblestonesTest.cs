
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

        int CalcutateCobblestones(double squareLength, double squareWidth, double cobblestoneSide)
        {
            double squareArea = squareLength * squareWidth;
            double cobblestoneArea = cobblestoneSide * cobblestoneSide;
            double cobblestones = squareArea / cobblestoneArea;
            return (int)Math.Ceiling(cobblestones);
        }
    }
}
