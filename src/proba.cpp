#include "header.hpp"
using namespace std;

double  evalMultivNorm(const Eigen::MatrixXd &x, const Eigen::MatrixXd &meanVec,
                        const Eigen::MatrixXd & covMat){
  double inv_sqrt_2pi = 1/(sqrt(2*M_PI));
  double quadform = (x - meanVec).transpose() * covMat.inverse() * (x - meanVec);
  double normConst = pow(inv_sqrt_2pi, covMat.rows()) * pow(covMat.determinant(), -.5);
  return normConst * exp(-.5*quadform);
}

Eigen::MatrixXd   CovarianceMatrix(const Eigen::MatrixXd mat){
  MatrixXd centered = mat.rowwise() - mat.colwise.mean();
  return (centered.adjoint() * centered) / double(mat.rows() - 1); 
}

//Eigen::MatrixXd   probaDistribution(const Eigen::MatrixXd mat){
//  Eigen::MatrixXd p = Eigen::MatrixXd::Zero(mat.size(),1);
//  cov = CovarianceMatrix(mat);
//  meanVec = convertVectorToEigen(estimate_mean(mat));
//
//  for (int i=0;i<mat.size();i++){
//    p(i) = evalMultivNorm(mat(i), meanVec, cov);
//  }
//  return p;
//}
