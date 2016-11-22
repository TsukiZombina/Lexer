#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  size_t size = atoi(argv[1]);
  unsigned* arry = new unsigned[size];
  unsigned* arry2 = new unsigned[3] {1, 2, 3};
  for (int i = 0; i < size; i++)
    arry[i] = i;
  for (int i = 0; i < size; i++)
    cout << arry[i] << ' ';
  cout << endl;
  for (int i = 0; i < 3; i++)
    cout << arry2[i] << ' ';
  cout << endl;
  cout << "size: " << sizeof(*arry) << endl;
  delete[] arry;
  delete[] arry2;
  return 0;
}