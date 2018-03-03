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

std::vector< std::vector<double> > getMatrix(std::istream& str);
std::vector<double> estimate_mean(std::vector< std::vector<double > >X);
std::vector<double> estimate_variance(std::vector< std::vector<double > >X);

#endif
