#include "imf.h"
#include <cmath>

const float EPS = 3.0e-11;
const float A1 = 0.256;
const float A2 = 0.137;
const float A3 = 0.137;
const float alfa = -2.35;
const int N = 1000;
const float  N_all = 1e11;

float f(float x);
void gauleg(float x1, float x2, float x[], float w[], int n);

Imf::Imf()
{
    float w[N],x[N];
    float x1=0.08;
    float x2=150.;
    float sum;
    int i,k;


   //liczenie sredniej
   for(i=1;i<N-1;i=i+1)
     {
      w[i]=0.;
      x[i]=0.;
     }
   gauleg(x1,x2,x,w,N-1);
   sum=0.;
   for(i=1;i<N-1;i=i+1)
   {
   sum=sum+w[i]*f(x[i])*x[i];
    }
   //printf("%s%.2g%s\n","srednia masa gwiazdy w Galaktyce ",sum," M_sun");
     sredniaMasa = sum;
   //liczba gwiazd pomiedzy 0.08 a 1
   x1=0.08;
   x2=1.;
   for(i=1;i<N-1;i=i+1)
     {
      w[i]=0.;
      x[i]=0.;
     }
   gauleg(x1,x2,x,w,N-1);
   sum=0.;
   for(i=1;i<N-1;i=i+1)
   {
   sum=sum+w[i]*f(x[i]);
    }
   //printf("%s%.2g\n","liczba gwiazd pomiedzy 0.08 a 1 M_sun ",sum*N_all);

   starBetweenBDSun = sum*N_all;

   //liczba gwiazd pomiedzy 1 a 8
   x1=1.;
   x2=8.;
   for(i=1;i<N-1;i=i+1)
     {
      w[i]=0.;
      x[i]=0.;
     }
   gauleg(x1,x2,x,w,N-1);
   sum=0.;
   for(i=1;i<N-1;i=i+1)
   {
   sum=sum+w[i]*f(x[i]);
    }

   starBetween18 = sum*N_all;
   //printf("%s%.2g\n","liczba gwiazd pomiedzy 1 a 8 M_sun ",sum*N_all);

 //liczba gwiazd pomiedzy  8 a 21
   x1=8.;
   x2=21.;
   for(i=1;i<N-1;i=i+1)
     {
      w[i]=0.;
      x[i]=0.;
     }
   gauleg(x1,x2,x,w,N-1);
   sum=0.;
   for(i=1;i<N-1;i=i+1)
   {
   sum=sum+w[i]*f(x[i]);
    }
   //printf("%s%.2g\n","liczba gwiazd pomiedzy  8 a 21 M_sun ",sum*N_all);
   starBetween821 = sum*N_all;

   //liczba gwiazd pomiedzy 21 a 150
   x1=21.;
   x2=150.;
   for(i=1;i<N-1;i=i+1)
     {
      w[i]=0.;
      x[i]=0.;
     }
   gauleg(x1,x2,x,w,N-1);
   sum=0.;
   for(i=1;i<N-1;i=i+1)
   {
   sum=sum+w[i]*f(x[i]);
    }
   //printf("%s%.2g\n","liczba gwiazd pomiedzy 21 a 150 M_sun ",sum*N_all);
   starBetween21150 = sum*N_all;
}

Imf::~Imf()
{

}



float Imf::f(float x)
{
  float b;
  if (x<0.5){
   b=A1*pow(x,(-1.3));
   }
  if ((x>=0.5)&&(x<1.)){
   b=A2*pow(x,(-2.2));
   }
  if ((x>=1.0)&&(x<=150.)){
   b=A2*pow(x,(-2.7));
   }
  return b;
}

void gauleg(float x1, float x2, float x[], float w[], int n)
{
    int m,j,i;
    double z1,z,xm,xl,pp,p3,p2,p1;

    m=(n+1)/2;
    xm=0.5*(x2+x1);
    xl=0.5*(x2-x1);
    for (i=1;i<=m;i++) {
        z=cos(3.141592654*(i-0.25)/(n+0.5));
        do {
            p1=1.0;
            p2=0.0;
            for (j=1;j<=n;j++) {
                p3=p2;
                p2=p1;
                p1=((2.0*j-1.0)*z*p2-(j-1.0)*p3)/j;
            }
            pp=n*(z*p1-p2)/(z*z-1.0);
            z1=z;
            z=z1-p1/pp;
        } while (fabs(z-z1) > EPS);
        x[i]=xm-xl*z;
        x[n+1-i]=xm+xl*z;
        w[i]=2.0*xl/((1.0-z*z)*pp*pp);
        w[n+1-i]=w[i];
    }
}
