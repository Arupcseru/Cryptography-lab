// Department of Computer Science & Engineering
#include<bits/stdc++.h>
using namespace std;

string encrypt(string text, int m){
	string result;
	int length=text.size();
	for(int i=0;i<m;i++){
    	for(int j=i;j<length;j+=m){
        	result+=text[j];
    	}
	}
	return result;
}

string decrypt(string text, int m){
	string result;
	int length=text.size();
	int n=length%m;
	int w=length/m;
	if(n!=0){
    	w+=1;
	}
	int d=w;
	for(int i=0;i<w;i++){
        int count=-1;
    	for(int j=i;j<length;j+=d){
        	result+=text[j];
        	//cout<<i<<" "<<j<<endl;
            count++;
        	if(i+1 == w && count+1==n){
                break;
        	}
        	if(count==n){
            	d--;
        	}
    	}
    	count=-1;
    	if(n!=0) d+=1;
	}
	return result;
}
int main(){
	int i,j,k,m,n,length;
	string text,result;
	cout<<"Enter Table width:\n";
	cin>>m;
	getchar();
	cout<<"Enter Text String:\n";
	getline(cin,text);

	result=encrypt(text,m);
	cout<<"Encrypted Text:"<<result<<endl;

	result=decrypt(result,m);
	cout<<"Decrypted Text:"<<result<<endl;

	return 0;
}
