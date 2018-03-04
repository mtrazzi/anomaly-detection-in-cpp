#include "header.hpp"
using namespace std;

Eigen::MatrixXd convertVectorToEigen(const vector<double> &x){
  Eigen::MatrixXd result = Eigen::MatrixXd::Zero(x.size(),1);

  for (int i=0;i<x.size();i++){
    result(i) = x[i];
  }
  return result;
}

Eigen::MatrixXd convertVectorToEigen(const vector< vector <double> > &x){
  Eigen::MatrixXd result = Eigen::MatrixXd::Zero(x.size(),x[0].size());

  for (int i=0;i<x.size();i++){
    for (int j=0;j<x[0].size();j++){
      result(i,j) = x[i][j];
    }
  }
  return result;
}
