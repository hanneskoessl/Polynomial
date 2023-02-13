#include "nvec.h"
class polynom:public nvec
{
  public:
  polynom(double *a,int l): nvec(a,l) {}

  double operator()(const double x);
  double fast(const double x);

};

polynom operator+(polynom &a, polynom &b);

// ------------------------------------------------

