#include "header.hpp"
using namespace std;

double  evalMultivNorm(const Eigen::MatrixXd &x, const Eigen::MatrixXd &meanVec,
                        const Eigen::MatrixXd & covMat){
  double inv_sqrt_2pi = 1/(sqrt(2*M_PI));
  //double quadform = (x - meanVec).transpose() * covMat.inverse() * (x - meanVec);
  cout << "x: " << x.rows() << "," << x.cols() << endl;
  cout << "meanVec: " << meanVec.rows() << "," << meanVec.cols() << endl;
  cout << "covMat: " << covMat.rows() << "," << covMat.cols() << endl;
  double quadform = 0;
  //double normConst = pow(inv_sqrt_2pi, covMat.rows()) * pow(covMat.determinant(), -.5);
  //return normConst * exp(-.5*quadform);
  return 0;
}

Eigen::MatrixXd   CovarianceMatrix(const Eigen::MatrixXd mat){
  Eigen::MatrixXd centered = mat.rowwise() - mat.colwise().mean();
  return (centered.adjoint() * centered) / double(mat.rows() - 1); 
}

Eigen::MatrixXd   probaDistribution(const Eigen::MatrixXd mat){
  Eigen::MatrixXd p = Eigen::MatrixXd::Zero(mat.rows(),1);
  Eigen::MatrixXd cov = CovarianceMatrix(mat);
  Eigen::MatrixXd meanVec = estimate_mean(mat);

  for (int i=0;i<mat.size();i++){
    p(i) = evalMultivNorm(mat.row(i), meanVec, cov);
  }
  return p;
}
