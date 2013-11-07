#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int parse(string in);
int error(string mesg, int code=1);
string addition(int a, int b);
string subtraction(int a, int b);

int main(int argc, char** argv) {
  string input;
  getline(cin,input);
  return parse(input);
}

int parse(string input) {
  stringstream in(input);
  int a, b;
  char o;
  in >> a >> o >> b;
  if (in.fail())
    return error("Syntax Error");
  if (o == '+')
    cout << addition(a,b) << endl;
  else if (o == '-')
    cout << subtraction(a,b) << endl;
  else
    return error("Invalid Operator");
  return 0;
}

int error(string mesg, int code) {
  cout << "ERROR: " << mesg << endl;
  return code;
}

string addition(int a, int b) {
  stringstream out;
  out << a << " plus " << b << endl;
  return out.str();
}

string subtraction(int a, int b) {
  stringstream out;
  out << a << " plus " << -b << endl;
  return out.str();
}
