#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//欧几里得算法
//又名辗转相除法
//用于快速计算两个数字的最大公约数
//还可以用于快速求解a*x+b*y=1方程的一组整数解

/*
定理：a和b两个整数的最大公约数等于b与a%b的最大公约数
形式化表示：假设a，b ！=0 则，gcd(a,b) = gcd(b,a%b)
证明1：
	1.设c = gcd(a,b), 则 a = cx, b = cy
	2.可知 a%b = r = a-k*b =cx-kcy=c(x-ky)
	3.可知c也是r的因数
	4.其中x-ky与y互素
所以可知：gcd(a,b) = gcd(b,r) = gcd(b, a%b)

证明2：
	1.假设gcd(x-ky,y) = d
	2.则y= nd，x-ky = md, 则x=knd+md=d(kn+m)
	3.重新表示a，b ，则有a = cd(kn+m), b = cdn
	4.则可得gcd(a,b)>=cd, 又因为gcd(a,b) = c, 所以 d = 1
*/

/*
//求最大公因数
int gcd(int a, int b)
{
	return (b ? gcd(b, a % b) : a);
}

//求最小公倍数
int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}

int main()
{
	int a, b;
	while (~scanf("%d%d", &a, &b))
	{
		printf("gcd(%d, %d) = %d\n", a, b, gcd(a,b));
		printf("lcm(%d, %d) = %d\n", a, b, lcm(a,b));
	}

	return 0;
}
*/



//求解a*x+b*y=1方程的一组整数解
int ex_gcd(int a, int b, int* x, int* y)
{
	if (!b)
	{
		*x = 1, * y = 0;
		return a;
	}

	//int xx, yy, ret = ex_gcd(b, a % b, &xx, &yy);
	//*x = yy;
	//*y = xx - a / b * yy;
	//return ret;

	//优化
	int ret = ex_gcd(b, a % b, y, x);
	*y -= a / b * (*x);
	return ret;

}


int main()
{
	int a, b, x, y;
	while (~scanf("%d%d", &a, &b))
	{
		printf("gcd(%d, %d) = %d\n", a, b, ex_gcd(a, b, &x, &y));
		printf("%d * %d + %d * %d = %d\n", a, x, b, y, a * x + b * y);
	}

	return 0;
}