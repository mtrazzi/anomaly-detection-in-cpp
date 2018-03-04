#include "header.hpp"
using namespace std;

int main(int argc, char *argv[]){
  std::vector <double> mu;
  std::vector <double> sigma_2;
  std::cout.precision(16);

  //if (argc != 2)
    //return -1;
  std::ifstream   file("../data/X.csv");
  std::vector< std::vector<double> > X;

  X = getMatrix(file);
  //for (auto const& row: X)
    //std::cout << row[0] << " " << row[1] << std::endl;
  mu = estimate_mean(X);
  sigma_2 = estimate_variance(X);
  cout << mu[0] << " " << mu[1] << endl;
  cout << sigma_2[0] << " " << sigma_2[1] << endl;
  return 0;
}
