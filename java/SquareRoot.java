// https://blog.naver.com/knwer782/220725515324

public class SquareRoot
{
    // Returns the square root of input value.
    // Square-root value is calculated through the algorithm called "개평법".
    // Check out the link below for more detail explanation.
    // https://namu.wiki/w/%EC%84%B8%EB%A1%9C%EC%85%88%EB%B2%95?from=%EA%B0%9C%ED%8F%89%EB%B2%95#toc
    public static double sqrt(long value)
    {
        long nod = 10;
        long approx = value;
        long d = 1;

        for (; approx > 0; d += 2)
            approx -= d;

        approx = approx == 0 ? (d - 1) >> 1 : ((d - 1) >> 1) - 1;

        double squareroot = approx;
        long n = value - approx * approx;
        long t = approx * 2;

        for (int i = 0; i < nod; i++)
        {
            n *= 100;
            t *= 10;
            long j = 0;

            if (t > n)
            {
                continue;
            } else
            {
                for (; (t + j) * j < n; j++)
                    ;

                j -= 1;
                n -= (t + j) * j;
                t = t + (j * 2);

            }
            squareroot += j * Math.pow(10, -(i + 1));
        }

        System.out.println(squareroot);
        return squareroot;
    }
}