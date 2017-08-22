
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
            Assert.AreEqual(12, totalCobblestones);
        }

        [TestMethod]
        public void TestMethod3()
        {
            int totalCobblestones = CalcutateCobblestones(6, 6, 4);
            Assert.AreEqual(4, totalCobblestones);
        }

        int CalcutateCobblestones(double squareLength, double squareWidth, double cobblestoneSide)
        {
            int cobblestonesPerLenght = (int)Math.Ceiling(squareLength / cobblestoneSide);
            int cobblestonePerWidth = (int)Math.Ceiling(squareWidth / cobblestoneSide);
            return cobblestonePerWidth*cobblestonesPerLenght;
        }
    }
}
