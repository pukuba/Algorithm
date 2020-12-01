#include "bogoSort.h"
#include <bits/stdc++.h>

using namespace std;
void sort_array(int N){	
    int s = 0, e = N-1;
//	shuffle_array(s.first,e.first);
	std::vector<int> v = copy_array();
	while(1){
		bool stop = 1;
		for(int i=0; i<v.size(); i++) if(v[i] != i) stop = 0;
		//std::cout<<'\n';
		//for(int i : v) std::cout<<i<<' ';
		if(stop) break; 
		if(v[s] == s){
			s++;
			continue;
		}
		for(int i = s; i<N; i++) if(v[i] == s) e=i;
		shuffle_array(s,e);
		v = copy_array();
	}
}