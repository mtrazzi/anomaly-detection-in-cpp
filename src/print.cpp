#include "header.hpp"
using namespace std;

void  printListAnomalies(const Eigen::MatrixXd p, double threshold){
  string to_print;
  Eigen::MatrixXd anomaly = classifyAnomaly(p, threshold);
  for (int i=0;i<anomaly.rows();i++){ 
    to_print = (anomaly(i) ? "\033[0;31mANOMALY\033[0m" : "\033[0;32mOK\033[0m");
    printf("Example #%3d : ", i);
    cout << to_print << endl;
  }
}
