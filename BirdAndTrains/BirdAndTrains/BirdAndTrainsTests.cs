
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
            return 3 * trainDistance / 4; //daca viteza unui tren este x, pentru ambele trenuri viteza este 2*x
            //return 3 * trainDistance / 2; //daca suma vitezelor ambelor trenuri este x 
        }
    }
}
