#include "header.hpp"
using namespace std;

double          mean(vector<double> v){
  return (accumulate(v.begin(), v.end(), 0.0)/v.size());
}

vector<double> estimate_mean(vector< vector<double > >X){
  vector<double> mu(2,0);

  for (int i=0;i<X.size();i++){
    mu[0] += X[i][0];
    mu[1] += X[i][1];
  }
  mu[0] /= X.size();
  mu[1] /= X.size();
  return mu;
}

vector<double> estimate_variance(vector< vector<double > > X) {
  vector<double> mu;
  vector<double> variance(2,0);

  mu = estimate_mean(X);
  for (int i=0;i<X.size();i++){
    variance[0] += pow((X[i][0] - mu[0]), 2);
    variance[1] += pow((X[i][1] - mu[1]), 2);
  }
  variance[0] /= X.size();
  variance[1] /= X.size();
  return variance;
}
