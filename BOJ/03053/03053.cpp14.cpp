#include <iostream>
#define M_PI 3.141592653589793238462643383279502884197169

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	double a;
	cout.tie(NULL);
	cin>>a;
	printf("%.6lf\n",a*a*M_PI);
	printf("%.6lf",2*a*a);
}