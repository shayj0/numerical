#include <stdio.h>
#include <math.h>

int main()
{
    printf("x=5, y=5�� �������� ���: \n\n");
    double a1, b1, b2, a0, d1, Sr;
    int aver_x, aver_y;
    int n = 12;               //�������� ���� ����
    int x[] = {5, 6, 10, 14, 16, 20, 22, 28, 28, 36, 38, 5};   //x �迭 ����
    int y[] = {30, 22, 28, 14, 22, 16, 8, 8, 14, 0, 4, 5};     //y �迭 ����
    int xsum = 0;
    int ysum = 0;
    int xysum = 0;
    int x2sum = 0;
    for(int i=0; i<n; i++) {     //for���� Ȱ���Ͽ�
        xsum = xsum + x[i];     //x�� ��
        ysum = ysum + y[i];     //y�� ��
        xysum = xysum + x[i] * y[i];    //xy�� ��
        x2sum = x2sum + x[i] * x[i];    //x^2�� �� �� ���Ѵ�.
    }
    aver_x = (xsum/n);   //x�� ���� ���
    aver_y = (ysum/n);   //y�� ���� ���

    b1 = (n*xysum)-(xsum*ysum);
    b2 = (n*x2sum)-(xsum*xsum);
    a1 = (b1/b2);        //xy�� ��, x�� ��, y�� ��, x^2�� ���� �̿��Ͽ� a1�� ���Ѵ�.
    d1 = (a1*aver_x);
    a0 = (aver_y-d1);    //x�� ���, y�� ���, a1���� �̿��Ͽ� a0�� ���Ѵ�.

    printf("������ ����(a1): %.3f\n", a1);
    printf("a0(y ����): %.3f\n", a0);
    printf("Regression line: y = %.3f + %.3fx\n", a0, a1);

    Sr = 0;
    for(int i=0; i<n; i++) {
        Sr = Sr + (y[i]-a0-a1*x[i])*(y[i]-a0-a1*x[i]);    //for���� Ȱ���Ͽ� ���� Sr�� ���Ѵ�.
    }
    printf("����(Sr): %.3f\n\n", Sr);
}
