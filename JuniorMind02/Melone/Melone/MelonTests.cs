
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

        [TestMethod]
        public void TestMethod3()
        {
            Assert.AreEqual("MESAJ", DivideMelon(3));
        }

        [TestMethod]
        public void TestMethod4()
        {
            Assert.AreEqual("DA", DivideMelon(4));
        }

        string DivideMelon(int melonWeight)
        {
            if(melonWeight<4) { return "MESAJ"; }
            else { return melonWeight % 2 != 0 ? "NU" : "DA"; }
        }
    }
}
