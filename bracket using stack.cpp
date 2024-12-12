
#include <iostream>
#include <string>
using namespace std;

char stack[1000];
int top=-1;
void push(char t)
{
  top++;
  stack[top]=t;
  cout<<"\npushed:"<<stack[top];
}
int stackEmpty()
{
  if(top==-1)
  return(1);
  return(0);
}
char pop()
{ char t='\0';
  if(!stackEmpty())
    {
      t=stack[top];
      top--;
    }
    return(t);
}
int validator(string s1) 
{ 
  char t;
  int t1=0;
	int i=0;
	char ch;
	while(s1[t1]!='\0')
	{
	  t=s1[t1];
	switch(t)
	{
	  case '[': push(t);
	            i++;
	            break;
	  case '{': push(t);
	            i++;
	            break;
	  case '(': push(t);
	            i++;
	            break;
	  case ']': ch=pop();
	  cout<<"\nComparing: ]";
	            if(ch=='[')
	            i--;
	            break;
	  case '}': ch=pop();
	  cout<<"\nComparing: }";
	            if(ch=='{')
	            i--;
	            break;
	 case ')': ch=pop();
	 cout<<"\nComparing: )";
	            if(ch=='(')
	            i--;
	            break;
	 }
	 t1++;
	}
	cout<<"\ni:"<<i;
	 return(i);
 }
 
int main()
{
string s1="int arr[10];{(a+b*)(c*d)}";
string s2;
cout<<"\nOriginal String:"<<s1;
int t=validator(s1);
if(t==0)
{ 
  cout<<"\nCode is validated, no syntax Error";
}
else{
  cout<<"\nSyntax Error/Missing Delimiter";
}

return (0);
}