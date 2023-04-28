/* TerraGeode
   CSC1710-03
   Lab 3
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int p=17, q=4, r=3;
	double j=3.00, k=5.0;

	cout << "p-q*r= " << p-q*r << endl;// uses only int data type so outputs an int
	cout << "p/r= " << p/r << endl;// uses only int data type so outputs an int
	cout << "p%r= " << p%r << endl;// % only uses and outputs int data types. using non int results in an error.
	cout << "p/q/r= " << p/q/r << endl;// uses only int data type so outputs an int
	cout << "q+r%p= " << q+r%p << endl;// % only uses and outputs int data types. using non int results in an error.
	cout << "q*j/p= " << q*j/p << endl;// out puts a double to compensate for the double used in the equation.
	cout << "p/q/j= " << p/q/j << endl;// out puts a double to compensate for the double used in the equation.
	cout << "p/j/q= " << p/j/q << endl;// out puts a double to compensate for the double used in the equation.
	k/=r/q;// doing this in the actual output statement results in a compilation error.
	cout << "k/=r/q, k= " << k << endl;//outputs inf. probably compensating for a divide by 0 error
	cout << "j/(-q)= " << j/(-q) << endl;// out puts a double to compensate for the double used in the equation.
	cout << "p*r/2= " << p*r/2 << endl;// uses only int data type so outputs an int

	return 0;
}
