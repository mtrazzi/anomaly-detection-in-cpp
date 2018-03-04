#include "header.hpp"
using namespace std;

int main(int argc, char *argv[]){
  std::cout.precision(16);
  Eigen::MatrixXd X;
  Eigen::MatrixXd Xval;
  Eigen::MatrixXd yval;
  Eigen::MatrixXd pval;
  Eigen::MatrixXd anomaly;

  std::ifstream   file("../data/X.csv");
  std::ifstream   file2("../data/Xval.csv");
  std::ifstream   file3("../data/yval.csv");

  X = convertVectorToEigen(getMatrix(file));
  Xval = convertVectorToEigen(getMatrix(file2));
  yval = convertVectorToEigen(getMatrix(file3));

  pval = probaDistribution(Xval, CovarianceMatrix(X), estimate_mean(X));
  anomaly = classifyAnomaly(pval, 0.001);
  double result = calcF1Score(anomaly, yval);
  cout << endl << "RESULT:" << endl << result << endl;
  return 0;
}
