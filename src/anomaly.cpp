#include "header.hpp"
using namespace std;

/*
 * p        : vector of likelihood of each example
 * epsilon  : threshold to consider an example an anomaly
*/
Eigen::MatrixXd classifyAnomaly(const Eigen::MatrixXd p, double epsilon){
  Eigen::MatrixXd anomaly = Eigen::MatrixXd::Zero(p.rows(), 1); //anomaly(i) = 1 iff i is an anomaly

  for (int i=0;i<p.rows();i++){
    if (p(i) < epsilon){
      anomaly(i) = 1;
    }
  }
  return anomaly;
}

double  calcF1Score(const Eigen::MatrixXd anomaly,
                                const Eigen::MatrixXd labels){
  int m = anomaly.rows();
  int true_pos = 0;
  int fals_pos = 0;
  int fals_neg = 0;
  double prec = 0;
  double recall = 0;

  for (int i=0;i<m;i++){
    if (anomaly(i) == 1 && labels(i) == 1)
      true_pos += 1;
    else if (anomaly(i) == 1 && labels(i) == 0)
      fals_pos += 1;
    else if (anomaly(i) == 0 && labels(i) == 1)
      fals_neg += 1;
  }
  prec = (double)true_pos / (double)(true_pos + fals_pos);
  recall = (double)true_pos / (double)(true_pos + fals_neg);
  return (2*prec*recall) / (prec + recall);
}
