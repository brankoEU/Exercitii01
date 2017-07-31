
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace BirdAndTrains
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void Distance100()
        {
            float birdDistance = CalcutateDistance(100);
            Assert.AreEqual(75, birdDistance);
        }
        float CalcutateDistance(float trainDistance)
        {
            return 0;
        }
    }
}
