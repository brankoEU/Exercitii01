
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Melone
{
    [TestClass]
    public class MelonTests
    {
        [TestMethod]
        public void TestMethod1()
        {
            Assert.AreEqual("DA", DivideMelon(4));
        }

        [TestMethod]
        public void TestMethod2()
        {
            Assert.AreEqual("NU", DivideMelon(11));
        }

        string DivideMelon(int melonWeight)
        {
            return melonWeight % 2 != 0 ? "NU" : "DA";
        }
    }
}
