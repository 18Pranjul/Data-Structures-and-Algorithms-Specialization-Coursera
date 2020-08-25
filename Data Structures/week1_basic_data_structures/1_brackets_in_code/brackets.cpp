#include<bits/stdc++.h>

using namespace std;

bool ispair(char a,char b)
{
	if(a == '(' && b == ')') return true;
	else if(a == '{' && b == '}') return true;
	else if(a == '[' && b == ']') return true;
	return false;
}
int isBalanced(string exp)
{
	stack <char>  S;
	int w;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
		{
			if(S.empty())
			 w=i+1;
			S.push(exp[i]);
		}
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(S.empty() || !ispair(S.top(),exp[i]))
				return i+1;
			else
				S.pop();
		}
	}
	return S.empty() ? -1:w;

}

int main()
{
	
	string expression; 
	cin>>expression;
	int c=isBalanced(expression);
	if(c==-1)
	 cout<<"Success";
	else
	 cout<<c;
}
