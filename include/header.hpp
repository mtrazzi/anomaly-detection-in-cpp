#ifndef HEADER_H
# define HEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <numeric>
#include <tgmath.h>
#include <Eigen/Core>
#include <Eigen/LU>

std::vector< std::vector<double> > getMatrix(std::istream& str);
Eigen::MatrixXd estimate_mean(Eigen::MatrixXd X);
Eigen::MatrixXd estimate_variance(Eigen::MatrixXd X);
Eigen::MatrixXd convertVectorToEigen(const std::vector<double> &x);
Eigen::MatrixXd convertVectorToEigen(const std::vector< std::vector <double> > &x);
double  evalMultivNorm(const Eigen::MatrixXd &x, const Eigen::MatrixXd &meanVec,
                        const Eigen::MatrixXd & covMat);
Eigen::MatrixXd   CovarianceMatrix(const Eigen::MatrixXd mat);
Eigen::MatrixXd   probaDistribution(const Eigen::MatrixXd mat);

#endif
