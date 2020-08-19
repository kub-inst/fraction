//warning!
//There may be some bug in this file!
//please check before you use it!
//I won't be responsible for any trouble of you! 
#include"function.hpp"
#include<iostream>
using namespace std;
using namespace function;
namespace fraction
{
	struct fint
	{
		int a,b;
	};
	struct ufint
	{
		unsigned a,b;
	};
	function1(fint &a)
	{
		if(a.b<0)
		{
			a.b=-a.b,a.a=-a.a;
		}
	}
	fint easy(fint a)
	{
		 if(a.a==0)
		 {
		 	a.b=1;
		 	return a;
		 }
	 	 bool fh=(a.a<0);
	 	 if(fh)a.a=-a.a;
	 	 int g=gcd(a.a,a.b);
	 	 a.a/=g,a.b/=g;
	 	 if(fh)a.a=-a.a;
	 	 return a;
	}
	void function2(fint &a)
	{
		function1(a);
		a=easy(a);
	}
	
	fint operator *(fint a,fint b)
	{
		fint c;
		c.a=a.a*b.a;
		c.b=a.b*b.b;
		function2(c);
		return c;
	}
	fint operator /(fint a,fint b)
	{
		fint c;
		c.a=a.a*b.b;
		c.b=a.b*b.a;
		function2(c);
		return c;
	}
	void fuction3(fint &a,fint &b)
	{
	 	 int a_=a.b,b_=b.b;
	 	 a.a*=b_,b.b*=a_,a.b*=b_,b.a*=a_;
	 	 return;
	} 
	fint operator +(fint a,fint b){
	fuction3(a,b);
		fint c;
		c.b=a.b;
		c.a=a.a+b.a;
		function2(c);
		return c; 
	}
	fint operator -(fint a,fint b)
	{
		b.a=-b.a;
		return a+b;
	}
	bool print(fint a){
		if(a.b==1)
		return cout<<a.a;
		return cout<<a.a<<'/'<<a.b;
	}
	bool scan(fint &a){
		string s;
		cin>>s;
		int t=0,l=s.size();
		bool dd=1;
		for(;t<l;t++)
		{
			if(s[t]=='/')
			{
				if(dd)dd=0;
				else return 0;
			}
			else if(!isdigit(s[t])&&s[t]!='-')
				return 0;
		}
		int b=s.find("/");
		a.a=a.b=t=0;
		bool fh=0; 
		if(s[0]=='-')
			fh=1,t++;
		if(b==-1)
		{
			for(;t<l;t++)
				a.a=a.a*10+s[t]-'0';
			a.b=1;
		}
		else
		{
			for(;t<b;t++)
				a.a=a.a*10+s[t]-'0';
			if(s[b+1]=='-')fh=!fh,b++;
			for(t=b+1;t<l;t++)
				a.b=a.b*10+s[t]-'0';
		}
		function2(a);
		if(fh)a.a=-a.a;
		return 1;
	}
}
