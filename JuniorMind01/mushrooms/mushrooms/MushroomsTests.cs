
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace mushrooms
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            int redMushrooms = CalculateRedMushrooms(3, 2);
            Assert.AreEqual(2, redMushrooms);
        }

        [TestMethod]
        public void TestMethod2()
        {
            int redMushrooms = CalculateRedMushrooms(12, 3);
            Assert.AreEqual(9, redMushrooms);
        }

        int CalculateRedMushrooms(int TotalMushrooms, int difference)
        {
            int whiteMushrooms = TotalMushrooms / (1 + difference);
            return whiteMushrooms*difference;
        }
    }
}
