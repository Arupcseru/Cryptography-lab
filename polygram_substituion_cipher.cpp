#include<stdio.h>
#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

string encrpt(string text){
    replace(text.begin(), text.end(), ' ', '_');
    map <string, string> eDictionary;
	ifstream readFile;
	string msg, cipher;

	readFile.open("dictionary.txt");

	if (readFile.is_open())
	{
		while(readFile >> msg >> cipher)
		{
			eDictionary[msg] = cipher;
		}
		readFile.close();
	}
	else
	{
		cout << "can not open the file" << endl;
	}
	string block;
	int startPos = 0;
	for(int i = 0; i < text.length(); i++)
	{
		block += text[i];

		if(block.length() == 3)
		{
			block = eDictionary[block];

			int x,y;

			for(x = startPos, y = 0; y < 3 ; y++, x++)
			{
				text[x] = block[y];
			}
			startPos = x;
			block.clear();
		}
	}
    return text;
}
string decrypt(string text){
    map <string, string> eDictionary;
	ifstream readFile;
	string msg, cipher;

	readFile.open("dictionary.txt");

	if (readFile.is_open())
	{
		while(readFile >> msg >> cipher)
		{
			eDictionary[msg] = cipher;
		}
		readFile.close();
	}
	else
	{
		cout << "can not open the file" << endl;
	}
	string block;
	int startPos = 0;
	for(int i = 0; i < text.length(); i++)
	{
		block += text[i];

		if(block.length() == 3)
		{
			block = eDictionary[block];

			int x,y;

			for(x = startPos, y = 0; y < 3 ; y++, x++)
			{
				text[x] = block[y];
			}
			startPos = x;
			block.clear();
		}
	}
    return text;
}

int main(){
    string text;
    int key;
    cout<<"Enter Plain Text:\n";
    getline(cin,text);
    cout<<"Encrypted Text:\n";
    string result=encrpt(text);
    cout<<result<<endl;
    /*
    cout<<"Decrypted Text:\n";
    cout<<decrypt(result)<<endl;
    */
}

