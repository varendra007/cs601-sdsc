// Please not that walue of w provided in question was inappropriate. So I took values from wikipedia

#include <bits/stdc++.h>
using namespace std;
double calcIntgral(int upperLimit, int lowerLimit)
{
  double ans = (2 / M_PI);
  ans *= (sin(M_PI_2 * upperLimit) - sin(M_PI_2 * lowerLimit));
  return ans;
}
double NumericalIntegral()
{
  vector<double> W;
  W.push_back(0.6521451548625461);
  W.push_back(0.6521451548625461);
  W.push_back(0.3478548451374538);
  W.push_back(0.3478548451374538);
  vector<double> Z;
  Z.push_back(-0.3399810435848563);
  Z.push_back(0.3399810435848563);
  Z.push_back(-0.861136311594052);
  Z.push_back(-0.861136311594052);
  double numericalValue = 0;
  for (int i = 0; i < 4; i++)
  {
    numericalValue += W[i] * cos(M_PI_2 * Z[i]);
  }
  return numericalValue;
}
double calcError(double numerical, double analytical)
{
  return (analytical - numerical) * 100 / analytical;
}
int main()
{
  double numericalValue = NumericalIntegral();
  double analytical = calcIntgral(1, -1);
  double err = calcError(numericalValue, analytical);
  cout << "Analytical Solution: " << setprecision(9) << analytical << endl;
  cout << "Numerical Solution: " << setprecision(9) << numericalValue << endl;
  cout << "Percentage err: " << setprecision(9) << err << endl;
  return 0;
}