
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

        [TestMethod]
        public void TestMethod3()
        {
            Assert.AreEqual("FizzBuzz", FizzBuzz(15));
        }

        [TestMethod]
        public void TestMethod4()
        {
            Assert.AreEqual("Numarul nu este divizibil prin 3 sau 5!", FizzBuzz(8));
        }

        string FizzBuzz(int number)
        {
            /*int aux = 0;
            if (number % 3 == 0) { aux = 1; }
            if (number % 5 == 0) { aux = 2; }
            if (number % 3 == 0 && number % 5 == 0) { aux = 3; } 
            switch(aux)
                {
                    case 1: return "Fizz";
                    case 2: return "Buzz";
                    case 3: return "FizzBuzz";
                    default: return "Numarul nu este divizibil prin 3 sau 5!";
                }*/
            return number % 3 == 0 && number % 5 == 0 ? "FizzBuzz" : number % 3 == 0 ? "Fizz" : number % 5 == 0 ? "Buzz" : "Numarul nu este divizibil prin 3 sau 5!";
        }
    }
}
