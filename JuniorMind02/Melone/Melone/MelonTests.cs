
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

        string DivideMelon(int melonWeight)
        {
            return "NU";
        }
    }
}
