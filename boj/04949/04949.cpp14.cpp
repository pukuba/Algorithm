#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
int main(){
	string str;
	while(1){
		getline(cin,str);
		if(str==".") break;
		int size = str.size();
		bool check = 1;
		stack<char> st;
		for(int i=0; i<size; i++){
			if(str[i]=='(') st.push(str[i]);
			else if(str[i]=='[') st.push(str[i]);
			else if(str[i]==')'){
				if(st.empty()){
					check=false;
					break;
				}
				if(st.top()=='(') st.pop();
				else{
					check = false;
					break;
				}
			}
			else if(str[i]==']'){
				if(st.empty()){
					check=false;
					break;
				}
				if(st.top()=='[') st.pop();
				else{
					check = false;
					break; 
				}
			}
		}
		(check&&st.empty())?cout<<"yes\n":cout<<"no\n";
	}
}