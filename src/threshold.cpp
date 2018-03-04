#include "header.hpp"
using namespace std;

double  selectBestThreshold(Eigen::MatrixXd p, Eigen::MatrixXd labels, int nbTestedValues){
  double step = (p.maxCoeff() - p.minCoeff()) / nbTestedValues;
  double epsilon = 0;
  Eigen::MatrixXd anomaly;
  double F1Score = 0;
  double max = 0;
  double argmax = 0;

  for (int i=0;i<nbTestedValues;i++){
    anomaly = classifyAnomaly(p, epsilon);
    F1Score = calcF1Score(anomaly, labels);
    if (F1Score > max){
      max = F1Score;
      argmax = epsilon;
    }
    epsilon += step;
  }
  return argmax;
}
