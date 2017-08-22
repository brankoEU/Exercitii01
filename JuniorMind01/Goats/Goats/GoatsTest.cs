
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Goats
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            float HayPerGoat = KgHayPerGoatPerDay(18, 2, 5);
            Assert.AreEqual(1.8f, HayPerGoat);
        }
        [TestMethod]
        public void TestMethod2()
        {
            float HayPerGoat = KgHayPerGoatPerDay(18, 2, 6);
            float total = KgTotal(3, 5, HayPerGoat);
            Assert.AreEqual(22.5f, total);
        }

        float KgHayPerGoatPerDay(float hayZ, int goatsY, int daysX)
        {
            return hayZ / goatsY / daysX;
        }
        float KgTotal(int goatsQ, int daysW,float KgPerGoat)
        {
            return KgPerGoat * goatsQ * daysW;
        }

    }
}
