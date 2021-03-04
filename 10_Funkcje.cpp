// Funkcje
//

#include <iostream>
using namespace std;
//typ_zwracany nazwa(parametry) {
//
//}
int dodawanie(int a, int b) {
    return a + b;
}

void fun1(int x, int y) {
    cout << dodawanie(x, y) << endl;
}
bool testPrime(int n) {
		bool p = true;
		if (n < 2) p = false;
		if ((n != 2) && (n % 2 == 0)) p = false;
		if (n != 2) {//wszystkie i>2
			for (int dzielnik=3; dzielnik< ceil(sqrt(n)); dzielnik+=2){
				if (n % dzielnik == 0) {
					p = false;
					break;
				}
			}
		}
		if (p) return true;
		else false;
}

int main()
{
    //cout << dodawanie(2, 3) << endl;
    //int w = 2, z = 3;
    //fun1(w, z);

	//int x = 102;
	//cout << testPrime(x) << endl;
	//x = 1011;
	//cout << testPrime(x) << endl;

	for (int i = 1001; i < 2000; i += 2) {
		if (testPrime(i)) cout << i << " ";
	}
	cout << endl;
    return 0;
}
