#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
int main(){
	char a[600000];
	int t;
	scanf("%s",&a);
	int n = strlen(a);
	stack<int> left,right;
	for(int i=0; i<n; i++){
		left.push(a[i]);
	}
	scanf("%d",&t);
	while(t--){
		char what;
		scanf(" %c",&what);
		if(what=='L'){
			if(!left.empty()){
				right.push(left.top());
				left.pop();
			}
		}
		else if(what=='D'){
			if(!right.empty()){
				left.push(right.top());
				right.pop();
			}
		}else if(what=='B'){
			if(!left.empty()){
				left.pop();
			}
		}
		else if(what=='P'){
			char c;
			scanf(" %c",&c);
			left.push(c);
		}
	}	
	while(!left.empty()){
		right.push(left.top());
		left.pop();
	}
	while(!right.empty()){
		printf("%c",right.top());
		right.pop();
	}
	printf("\n");
	}
	