#include<math.h>
#define ll long long
#define re return 
#define vd void
namespace function
{
	bool isdigit(char c)
	{
		return c>='0'&&c<='9';
	}
	ll jud(ll a)
	{
		re a>0?a:-a;
	}
	ll absolute(ll a)
	{
		re a>0?a:-a;
	}
	vd absolute_done(ll a)
	{
		a=a>0?a:-a;
	}
	bool isprime(ll n)
	{
		if(n<2)
		{
			re 0;
		} 
		if(n==2)
		{
			re 1;
		}if(n%2==0)
		{
			re 0;
		} 
		for(ll t=3;t<=sqrt(n);t+=2)
		{
			if(n%t==0)
			{
				re 0;
			}
		}
		re 1;
	}
	void swap(ll &a,ll &b)
	{
		ll cub=a;a=b,b=cub;
		re;
	}
	void pop_sort(ll a[],ll n)
	{
		for(ll t=0,r;t<n;t++)
		{
			for(ll r=1;r<n;r++)
			{
				if(a[r-1]<a[r])
				{
					swap(a[r-1],a[r]);
				}
			}
		}
	}
	ll gcd(ll a,ll b)
	{
		re b==0?a:gcd(b,a%b);
	}
	ll d_num(ll a)
	{
		ll count=1,r=1;
		if(a<2)return 1;
		while(a>=2&&a%2==0)
		{
			a/=2;
			count++;
		}
		r*=count;
		for(int t=3;a>=t;t+=2)
		{
			count=1;
			while(a%t==0&&a>=t)
			{
				a/=t;
				count++;
			}
			r*=count;
		}return r;
	}
}
