#include "header.hpp"
using namespace std;

vector<double> estimate_mean(const vector< vector<double > >X){
  int p = X[0].size();
  int m = X.size();
  vector<double> mu(p,0);

  for (int i=0;i<m;i++){
    for (int j=0;j<p;j++){
      mu[j] += X[i][j];
    }
  }
  for (int j=0;j<m;j++){
    mu[j] /= m;
  }
  return mu;
}

vector<double> estimate_variance(const vector< vector<double > > X) {
  int p = X[0].size();
  int m = X.size();
  vector<double> mu(p,0);
  vector<double> variance(p,0);

  mu = estimate_mean(X);
  for (int i=0;i<m;i++){
    for (int j=0;j<p;j++){
      variance[j] += pow(X[i][j]-mu[j],2);
    }
  }
  for (int j=0;j<p;j++){
    variance[j] /= m;
  }
  return variance;
}
