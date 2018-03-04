#include "header.hpp"
using namespace std;

Eigen::MatrixXd estimate_mean(Eigen::MatrixXd X){
  int p = X.cols();
  int m = X.rows();
  Eigen::MatrixXd mu = Eigen::MatrixXd::Zero(p,1);

  for (int i=0;i<m;i++){
    for (int j=0;j<p;j++){
      mu(j) += X(i,j);
    }
  }
  for (int j=0;j<m;j++){
    mu(j) /= m;
  }
  return mu;
}

Eigen::MatrixXd estimate_variance(Eigen::MatrixXd X){
  int p = X.cols();
  int m = X.rows();
  Eigen::MatrixXd mu = Eigen::MatrixXd::Zero(p,1);
  Eigen::MatrixXd var = Eigen::MatrixXd::Zero(p,1);

  mu = estimate_mean(X);
  for (int i=0;i<m;i++){
    for (int j=0;j<p;j++){
      var(j) += pow(X(i,j)-mu(j),2);
    }
  }
  for (int j=0;j<p;j++){
    var(j) /= m;
  }
  return var;
}
