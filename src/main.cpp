#include "header.hpp"
using namespace std;

int main(int argc, char *argv[]){
  std::cout.precision(16);
  Eigen::MatrixXd X;
  Eigen::MatrixXd Xval;
  Eigen::MatrixXd yval;
  Eigen::MatrixXd p;
  Eigen::MatrixXd pval;
  Eigen::MatrixXd anomaly;

  if (argc != 2)
  {
    cout << "usage: ./threshold dataset{1|2}" << endl;
    return 0;
  } 
  string  dataset = argv[1];
  string  directory = "../data/" + dataset;
  
  std::ifstream   file(directory +  "/X.csv");
  std::ifstream   file2(directory + "/Xval.csv");
  std::ifstream   file3(directory + "/yval.csv");

  X = convertVectorToEigen(getMatrix(file));
  Xval = convertVectorToEigen(getMatrix(file2));
  yval = convertVectorToEigen(getMatrix(file3));

  pval = probaDistribution(Xval, CovarianceMatrix(X), estimate_mean(X));
  double threshold = selectBestThreshold(pval, yval, 1000);
  cout << "BEST_THRESHOLD:" << endl << threshold << endl << endl;
  p = probaDistribution(X, CovarianceMatrix(X), estimate_mean(X));
  printListAnomalies(p, threshold);
  return 0;
}
