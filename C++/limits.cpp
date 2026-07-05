#include <iostream>
#include <limits>
using namespace std;
int main() {
cout << "Limiti per int:" << endl;
cout << "Min: " << numeric_limits<int> :: min() << endl;
cout << "Max: " << numeric_limits<int> :: max() << endl;
cout << "taglia " << sizeof(int) << endl;
cout << "\nLimiti per double:" << endl;
cout << "Min: " << numeric_limits<double> :: min() << endl;
cout << "Max: " << numeric_limits<double> :: max() << endl;
cout << "taglia " << sizeof(double) << endl;
cout << "\nLimiti per char:" << endl;
cout << "Min: " << (int) numeric_limits<char> :: min() << endl;
cout << "Max: " << (int) numeric_limits<char> :: max() << endl;
cout << "taglia " << sizeof(char) << endl;
cout << "\nLimiti per wchar_t:" << endl;
cout << "Min: " << (int) numeric_limits<wchar_t> :: min() << endl;
cout << "Max: " << (int) numeric_limits<wchar_t> :: max() << endl;
cout << "taglia " << sizeof(wchar_t) << endl;
cout << "\nLimiti per bool:" << endl;
return 0;
}

