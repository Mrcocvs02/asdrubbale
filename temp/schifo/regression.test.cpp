#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

struct Result
{
  double A{};
  double B{};
};

class Regression
{ 
    int N_{};
    double sum_x_{};
    double sum_y_{};
    double sum_xx_{};
    double sum_xy_{};

    public:
  void add (double x, double y) 
  {
      ++N_;
      sum_x_ += x;
      sum_y_ += y;
      sum_xx_ += x*x;
      sum_xy_ += x*y;
  }
   Result fit()
  {
      double const a =(sum_y_*sum_xx_-sum_x_*sum_xy_)/(N_*sum_xx_-sum_x_*sum_x_);
      double const b =(N_*sum_xy_-sum_x_*sum_y_)/(N_*sum_xx_-sum_x_*sum_x_);
    return Result{a, b};
  }
};
TEST_CASE("Testing Regression") {
  Regression reg;
  reg.add(0., 1.);
  reg.add(1., 2.);
  auto result = reg.fit();
  CHECK(result.A == doctest::Approx(1.));
  CHECK(result.B == doctest::Approx(1.));
}