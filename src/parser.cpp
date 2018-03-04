#include "header.hpp"

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
