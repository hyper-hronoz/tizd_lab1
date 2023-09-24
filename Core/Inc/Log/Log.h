#pragma once 

#include "string"
#include "fstream"
#include "iostream"

using namespace std;

class Log {
 public:
  static std::string filename;

  static void writeLog(std::string info) {
		ofstream stream(Log::filename, ios::app);

		stream << info << "\n";

  std::cout << info << std::endl;

		stream.close();
  };
};

