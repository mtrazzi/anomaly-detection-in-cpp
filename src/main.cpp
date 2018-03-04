#include "header.hpp"
using namespace std;

int main(int argc, char *argv[]){
  std::cout.precision(16);
  Eigen::MatrixXd X;
  Eigen::MatrixXd p;

  std::ifstream   file("../data/X.csv");
  X = convertVectorToEigen(getMatrix(file));
  p = probaDistribution(X);
  for (int i=0;i<p.rows();i++)
    cout << i << ": " << p(i) << endl;
  return 0;
}
