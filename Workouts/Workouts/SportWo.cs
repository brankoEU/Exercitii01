
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Workouts
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            int totalRepetitions = CalculateWorkouts(3);
            Assert.AreEqual(9, totalRepetitions);
        }

        [TestMethod]
        public void TestMethod2()
        {
            int totalRepetitions = CalculateWorkouts(9);
            Assert.AreEqual(81, totalRepetitions);
        }

        [TestMethod]
        public void TestMethod3()
        {
            int totalRepetitions = CalculateWorkouts(12);
            Assert.AreEqual(144, totalRepetitions);
        }

        int CalculateWorkouts(int series)
        {
            return series*series;
        }
    }
}
