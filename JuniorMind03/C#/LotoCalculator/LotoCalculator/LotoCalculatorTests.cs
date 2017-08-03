
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace LotoCalculator
{
    [TestClass]
    public class LotoCalculatorTests
    {
        [TestMethod]
        public void Loto1From10()
        {
            Assert.AreEqual(0.1, CalculateLotoChances(1, 10));
        }

        [TestMethod]
        public void Loto6From49()
        {
            Assert.AreEqual(0.00000007151123842018516, CalculateLotoChances(6, 49));
        }

        double CalculateLotoChances(int numbers, int loto)
        {
            return 1 / CalculateCombinations(numbers, loto);
        }

        double CalculateCombinations(int k, int n)
        {
            return CalculateFactorial(n) / (CalculateFactorial(k) * CalculateFactorial(n - k));
        }

        double CalculateFactorial(int n)
        {
            double fact = 1;
            for (int i=2; i<=n; i++)
            {fact *= i;}
            return fact;
        }
    }
}
