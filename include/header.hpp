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
#include <map>
#include <stdio.h>

std::vector< std::vector<double> > getMatrix(std::istream& str);
Eigen::MatrixXd estimate_mean(Eigen::MatrixXd X);
Eigen::MatrixXd estimate_variance(Eigen::MatrixXd X);
Eigen::MatrixXd convertVectorToEigen(const std::vector<double> &x);
Eigen::MatrixXd convertVectorToEigen(const std::vector< std::vector <double> > &x);
double  evalMultivNorm(const Eigen::VectorXd &x, const Eigen::VectorXd &meanVec,
                        const Eigen::MatrixXd & covMat);
Eigen::MatrixXd   CovarianceMatrix(const Eigen::MatrixXd mat);
Eigen::MatrixXd   probaDistribution(const Eigen::MatrixXd mat,
    Eigen::MatrixXd cov, Eigen::MatrixXd meanVec);
Eigen::MatrixXd classifyAnomaly(const Eigen::MatrixXd p, double epsilon);
double  calcF1Score(const Eigen::MatrixXd anomaly,
                    const Eigen::MatrixXd cross_val);
double  selectBestThreshold(Eigen::MatrixXd p, Eigen::MatrixXd labels, int nbTestedValues);
void  printListAnomalies(const Eigen::MatrixXd p, double threshold);

#endif
