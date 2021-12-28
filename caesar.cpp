#include<stdio.h>
#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

string encrpt(string text, int key){
    string result=text;
    int length= text.length();
    for(int i=0; i<length;i++){
        if(text[i]>='A' && text[i]<='Z'){
            result[i]=(text[i]+key-'A')%26 +'A';
        }
        else if(text[i]>='a' && text[i]<='z'){
            result[i]=(text[i]+key-'a')%26 +'a';
        }
        else{
            result[i]=text[i];
        }
    }
    return result;
}
string decrypt(string text, int key){
    string result=text;
    int length= text.length();
    for(int i=0; i<length;i++){
        if(text[i]>='A' && text[i]<='Z'){
            result[i]=(text[i]+26-key-'A')%26 +'A';
        }
        else if(text[i]>='a' && text[i]<='z'){
            result[i]=(text[i]+26-key-'a')%26 +'a';
        }
        else{
            result[i]=text[i];
        }
    }
    return result;
}

int main(){
    string text;
    int key;
    cout<<"Enter Plain Text:\n";
    getline(cin,text);
    cout<<"Enter key:\n";
    cin>>key;
    cout<<"Encrypted Text:\n";
    string result=encrpt(text,key);
    cout<<result<<endl;
    cout<<"Decrypted Text:\n";
    cout<<decrypt(result,key)<<endl;
}
