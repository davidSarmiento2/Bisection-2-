#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

#define epsilon0 10e-8
#define epsilon1 10e-4
#define epsilon2 10e-2

const double EulerConstant = std::exp(1.0);
const double pi = M_PI;


double funct(double x);


int main(int argc, char* argv[])
{
  //intervalo [ 0,1 ]
  double a,b;
  a = 0;
  b = 1;
  int iteration = 0;


  //bisection
  double midPoint = 0;
  while( funct(midPoint) !=0 || fabs( funct(midPoint ) ) > epsilon0 )
  {
    ++iteration;
    if( funct( a ) * funct( b ) < 0)
    {
      midPoint = (a+b)/2;
      if( fabs( funct( midPoint ) ) < epsilon2 )
      {
        break;
      }
      if( funct( a )*funct( midPoint ) )
      {
        a = midPoint;
      }
      else
      {
        b = midPoint;
      }
    }
    else
    {
      std::cout << "Sorry";
      return 0;
    }
  }
  //bisection-end
  std::cout << "La raiz es: " << midPoint << std::endl;

  //std::cout << funct( 0.59 ) << std::endl;
  return( 0 );
}


double funct(double x)
{
  return ( pow( EulerConstant, x ) ) - (pi * x);
}
