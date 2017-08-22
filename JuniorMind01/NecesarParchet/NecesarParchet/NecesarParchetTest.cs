
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace NecesarParchet
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethod1()
        {
            int totalParquet = CalculateParquetRequaired(4, 5, 2, 1);
            Assert.AreEqual(12,totalParquet);
        }

        [TestMethod]
        public void TestMethod2()
        {
            int totalParquet = CalculateParquetRequaired(20, 11, 1.5, 0.3);
            Assert.AreEqual(563, totalParquet);
        }

        int CalculateParquetRequaired(double roomLenght, double roomWidth, double parquetLenght, double parquetWidth)
        {
            double parquetPerLenght = roomLenght / parquetLenght;
            double parquetPerWidth = roomWidth / parquetWidth;
            double required = parquetPerLenght * parquetPerWidth * 115 / 100;
            return (int)Math.Ceiling(required);
        }
    }
}
