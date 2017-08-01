
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

        [TestMethod]
        public void TestMethod2()
        {
            Assert.AreEqual("Buzz", FizzBuzz(5));
        }

        string FizzBuzz(int number)
        {
            int aux = 0;
            if (number % 3 == 0) { aux = 1; }
            else
            {
                if (number % 5 == 0) { aux = 2; }
                else { if (number % 3 == 0 || number % 5 == 0) { aux = 3; } }
            }
            switch(aux)
                {
                    case 1: return "Fizz";
                    case 2: return "Buzz";
                    case 3: return "FizzBuzz";
                    default: return "Numarul nu este divizibil prin 3 sau 5!";
                }
        }
    }
}
