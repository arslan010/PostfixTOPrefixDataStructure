//By M A Hafeez Roll No 528
//BSCS 3rd IUB-RYK
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stack>
using namespace std;

bool isOperator(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/' || c=='$')
		return true;
	return false;
}

int main()
{
	string prefix;
	cout <<"Enter a valid Prefix String: "<<endl;
	cin >> prefix;
	
	stack<string> st;
	string t1, t2, t3, t4;
	
	int l = prefix.length();
	for (int i = l-1 ; i >= 0; i--)
	{
		if (isOperator(prefix[i]))
		{
			t1 = "(";
			t2 = ")";
			t3 = st.top();   st.pop();
			t3 += prefix[i];
			t4 = st.top();   st.pop();
			st.push(t1 + t3 + t4 + t2);
		}
		else
		{
			t1 = prefix[i];
			st.push(t1);
		}
	}
	
	string infix = st.top();	 st.pop();
	cout <<"infix String: " << infix << endl;
	getch();
}
