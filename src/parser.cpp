#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

std::vector<double> getNextLine(std::istream& str){
  std::vector<double>  result;
  std::string       line;
  std::getline(str,line);

  std::stringstream lineStream(line);
  std::string       cell;
  while(std::getline(lineStream, cell, ',')){
    result.push_back(stod(cell));
  }
  return result;
}

std::vector< std::vector<double> > getMatrix(std::istream& str){
  std::vector< std::vector<double> > X;
  std::vector<double> row;

  (row = getNextLine(str));
  while(!row.empty()){
    X.push_back(row);
    row = getNextLine(str);
  }
  return X;
}

int main(int argc, char *argv[]){
  std::cout.precision(16);
  if (argc != 2)
    return -1;
  std::ifstream   file(argv[1]);
  std::vector< std::vector<double> > X;

  X = getMatrix(file);
  for (auto const& row: X)
    std::cout << row[0] << " " << row[1] << std::endl;
  return 0;
}
