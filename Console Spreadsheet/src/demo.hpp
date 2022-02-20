#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include<cstring>
#include<sstream>
using namespace std;
const int LEN = 80;
const int MAX = 40;
class Stack {
private:
    char st[MAX];
    int top;
public:
    Stack()
    {
        top = 0;
    }
    void push(char var)
    {
        st[++top] = var;
    }
    char pop()
    {
        return st[top--];
    }
    int gettop()
    {
        return top;
    }
};
class Express {
private:
    Stack s;
    char* pStr;
    int len;
public:
    Express(char* ptr)
    {
        pStr = ptr;
        len = strlen(pStr);
    }
    void parse();
    int solve();
};
void Express::parse()
{
    char ch;
    char lastval;
    char lastop;
    for (int j = 0; j < len; j++) {
        ch = pStr[j];
        if (ch >= '0' && ch <= '9')
            s.push(ch - '0');
        else if (ch == '+' || ch == '-'
                 || ch == '*' || ch == '/') {
            if (s.gettop() == 1)
                s.push(ch);
            else {
                lastval = s.pop();
                lastop = s.pop();
                if ((ch == '*' || ch == '/')
                    && (lastop == '+' || lastop == '-')) {
                    s.push(lastop);
                    s.push(lastval);
                }
                else {
                    switch (lastop) {
                    case '+':
                        s.push(s.pop() + lastval);
                        break;
                    case '-':
                        s.push(s.pop() - lastval);
                        break;
                    case '*':
                        s.push(s.pop() * lastval);
                        break;
                    case '/':
                        s.push(s.pop() / lastval);
                        break;
                    default:
                        exit(1);
                    }
                }
                s.push(ch);
            }
        }
    }
}
int Express::solve()
{
    char lastval;
    while (s.gettop() > 1) {
        lastval = s.pop();
        switch (s.pop()) {
        case '+':
            s.push(s.pop() + lastval);
            break;
        case '-':
            s.push(s.pop() - lastval);
            break;
        case '*':
            s.push(s.pop() * lastval);
            break;
        case '/':
            s.push(s.pop() / lastval);
            break;
        default:
            exit(1);
        }
    }
    return int(s.pop());
}
     int conversion(string s,int *a)
    {
        string str = s.substr(1,s.length());
        string s1 = "0";
        string s2 = "-1";
        if(s.find(s1) != string::npos)
        {
            return -1;
        }
         if(s.find(s2) != string::npos)
         {
             return -2;
         }
    char ss[LEN];
	strcpy(ss, s.c_str());
    Express* eptr = new Express(ss);
    eptr->parse();
		return eptr->solve();
    }
	int arith(string s,int *a) 
	{
		string s1[10] = {"A1","B1","C1","A2","B2","C2","A3","B3","C3"};
	    string s2="";
	    string s3="";	
	    for(int i=0;i<9;i++) {
	    	if(islower(s[i])) {
	    		s[i] = s[i] - 32;
	    	}
	    }
	    for(int i=1;i<s.length();i++)
	    {
	    	if(s[i]=='+'||s[i]=='/'||s[i]=='*'||s[i]=='-')
	    	{
	    		s2=s.substr(i-2,i-1);
	    	    for(int j=0;j<9;j++) 
	    	    {
					int index=0;
	    	         if(s2.compare(s1[j])==0)
	    	         {
	    		          s3 = to_string(a[j]);
	    		          s.replace(s.find(s1[j]),2,s3);
	    	         }
	    	    }
	    	}
	    }
	    s2=s.substr(s.length()-2,s.length()-1);
    	for(int j=0;j<9;j++) 
    	{
    	    if(s2.compare(s1[j])==0)
    	    {
    		   s3 = to_string(a[j]);
    		   int index;
	    		s.replace(s.find(s1[j]),2,s3);
    	}
	}
	return conversion(s,a);
	}
	 bool num(string s2) 
	{
		try 
		{
           s2 = stoi(s2);
            return true;
        } 
        catch (...) 
        {
        	return false;
        }
	}
    int solution(string s1[9]){
    int a[9];
    for(int i=0;i<9;i++) 
        {
        	string s2=s1[i];
        	if(num(s2)) 
        	{
        		int n = stoi(s2);
        		a[i]=n;
        	}
        	if(!num(s2)) 
        	{
        		if(s2.at(0)=='=') 
        		{
        			a[i]=arith(s2,a);
        		}
        		else if(s2.at(0)==' ')
        		{
        			a[i]=0;
        		}
        	}
        }
        string sa[9];
        for (int i = 0; i < 9; i++) 
        {
            ostringstream str1;
	    	str1<<a[i];
            sa[i] = str1.str();
        }
        for (int i = 0; i < 9; i++) 
        {
        	if(a[i]==-1) 
        	{
        		sa[i]="#NAN";
        	}else if(a[i]==-2) 
        	{
        		sa[i]="#ERROR";
        	}
        	else if(a[i]==0) 
        	{
        		sa[i]=" ";
        	}
        }
      /* for (int i = 0; i < 9; i++)
        {
        	cout<<sa[i]+" ";
        	if(i==2||i==5||i==8) 
        	{
        		cout<<"\n";
        	}
        }*/
        return a[8];
}