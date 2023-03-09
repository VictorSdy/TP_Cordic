#include <stdio.h>
#include <stdlib.h>
#define N 13
#define pi 3.141592654
double tab_thetai[N];
double tab_Ki[N];
float cordic(double phi,int n)
{
int j=0;
double x=tab_Ki[0];
double xs=0; //xs pour x_suivant
double y=0;
double ys=0;
double d=1;
double a=0;

for (int i=0;i<13;i++){
if (a<64)
{
        xs=x-(y*d);
        ys=y+(x*d);
        a=a+tab_thetai[i];
        printf("Val de x CAS1 : %lf\n",xs);
        printf("Val de y CAS1 : %lf\n",ys);
}
else
{
        xs=x+(y*d);
        ys=y-(x*d);
        a=a-tab_thetai[i];
        printf("Val de x CAS2 : %lf\n",xs);
        printf("Val de y CAS2 : %lf\n",ys);
}
x=xs;
y=ys;
d=d/2;
}



}
int main()
{
    int i=0;
    for (i=0;i<N;i++)
    {
        tab_thetai[i]=atan(pow(2,(-i)));
        tab_Ki[i]=pow((1+pow(2,(-2*i))),(-0.5));
    }
 cordic(60,13);
    //printf("Hello world!\n");
    /*for (i=0;i<N;i++)
    {
        printf("les resultats sont %f\n",tab_thetai[i]);
        printf("Ki %f\n",tab_Ki[i]);
    }*/
    return 0;
}
