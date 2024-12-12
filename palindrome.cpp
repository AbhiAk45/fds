#include <iostream>
#include <string>
using namespace std;

char stack[100];
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
string reverse(string t)
{
  char *s;
  int i=0;
  //use stack
  while(t[i]!='\0')
  {
    push(t[i]);
    i++;
  }
  i=0;
  while(!stackEmpty())
  {
    t[i]=pop();
    i++;
  }
  t[i]='\0';
  cout<<"\n"<<t;
  return(t);
}
int main()
{
string s1="Madam";
string s2;
//cin>>s1;  // use this to accept input from user
cout<<"\nOriginal String:"<<s1;
s2=reverse(s1);
if(s1==s2)
{ 
  cout<<"\nString is a Palindrome";
}
else{
  cout<<"\nString is Not Palindrome";
}

return (0);
}
