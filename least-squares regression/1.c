#include <stdio.h>
#include <math.h>

int main()
{
    printf("x=5, y=5를 포함했을 경우: \n\n");
    double a1, b1, b2, a0, d1, Sr;
    int aver_x, aver_y;
    int n = 12;               //데이터의 개수 정의
    int x[] = {5, 6, 10, 14, 16, 20, 22, 28, 28, 36, 38, 5};   //x 배열 정의
    int y[] = {30, 22, 28, 14, 22, 16, 8, 8, 14, 0, 4, 5};     //y 배열 정의
    int xsum = 0;
    int ysum = 0;
    int xysum = 0;
    int x2sum = 0;
    for(int i=0; i<n; i++) {     //for문을 활용하여
        xsum = xsum + x[i];     //x의 합
        ysum = ysum + y[i];     //y의 합
        xysum = xysum + x[i] * y[i];    //xy의 합
        x2sum = x2sum + x[i] * x[i];    //x^2의 합 을 구한다.
    }
    aver_x = (xsum/n);   //x의 합의 평균
    aver_y = (ysum/n);   //y의 합의 평균

    b1 = (n*xysum)-(xsum*ysum);
    b2 = (n*x2sum)-(xsum*xsum);
    a1 = (b1/b2);        //xy의 합, x의 합, y의 합, x^2의 합을 이용하여 a1을 구한다.
    d1 = (a1*aver_x);
    a0 = (aver_y-d1);    //x의 평균, y의 평균, a1값을 이용하여 a0을 구한다.

    printf("직선의 기울기(a1): %.3f\n", a1);
    printf("a0(y 절편): %.3f\n", a0);
    printf("Regression line: y = %.3f + %.3fx\n", a0, a1);

    Sr = 0;
    for(int i=0; i<n; i++) {
        Sr = Sr + (y[i]-a0-a1*x[i])*(y[i]-a0-a1*x[i]);    //for문을 활용하여 오차 Sr을 구한다.
    }
    printf("오차(Sr): %.3f\n\n", Sr);
}
