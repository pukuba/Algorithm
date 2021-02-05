#include <iostream>
using namespace std;
main(){int w,q,z;float ii,xx;cin>>w;for(int j=0;j<w;j++){ii=0;z=0;xx=0;cin>>q;float y[q];for(int i=0;i<q;i++){cin>>y[i];ii+=y[i];}ii=ii/(float)q;for(int i=0;i<q;i++){if(ii<y[i])z++;}  xx=(float)(((float)z)/((float)q))*(float)100.00;printf("%.3f%%\n", xx);}}