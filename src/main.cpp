#include "header.hpp"
using namespace std;

int main(int argc, char *argv[]){
  std::cout.precision(16);
  Eigen::MatrixXd X;

  std::ifstream   file("../data/X.csv");
  X = convertVectorToEigen(getMatrix(file));
  //for (auto const& row: X)
    //std::cout << row[0] << " " << row[1] << std::endl;
  return 0;
}
