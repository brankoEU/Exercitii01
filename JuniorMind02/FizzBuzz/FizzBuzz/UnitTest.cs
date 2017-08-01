
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace FizzBuzz
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            Assert.AreEqual("Fizz", FizzBuzz(3));
        }

        string FizzBuzz(int number)
        {
            return "";
        }
    }
}
