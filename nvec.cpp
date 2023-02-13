#include "poly.h"
#include <math.h>
#include <new>

nvec::nvec(const double *p, int l)
{	
	int i;
	len = l;
	try
	{
		a = new double [len];
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr<<"bad_alloc cought: " << ba.what() << endl;
		exit(EXIT_FAILURE);
	}
	
	if(p==0)	for(i=0; i<len; i++)	a[i]=0;
	else		for(i=0; i<len; i++)	a[i]=p[i];

}


nvec::~nvec()
{
	delete [] a;
}

ostream& operator<<(ostream& out, nvec& x)
{
	int i;
	int len=x.Len();
	if(!len)
	{
		out << "Array empty" << endl;
	}
	else
	{	
		out << "Länge=" << len << endl;
		for(i=0; i<len; i++)
		{
			out << x[i] << endl;
		}
	}
	return out;
}

double& nvec::operator[](int n)
{
	if(n>=len || n<0)
	{
		cout << "Index" << n << " out of range (0 ... " << len-1 <<")"<<endl;
		return a[0];
	}
	else return a[n];
}

double nvec::Min()
{
	int i;
	double Min=a[0];
	for(i=0; i<len; i++)
	{
		if(a[i]<Min) Min=a[i];
	}
	return Min;
}

double nvec::Max()
{
	int i;
	double Max=a[0];
	for(i=0; i<len; i++)
	{
		if(a[i]>Max) Max=a[i];
	}
	return Max;
}

void nvec::operator*=(double f)
{
	int i;
	for(i=0; i<len; i++)
	{
		a[i] = f*a[i];
	}
}

double nvec::Mean()
{
	int i;
	double Mean=0;
	for(i=0; i<len; i++)
	{
		Mean=Mean+a[i];
	}
	Mean=Mean/len;
	return Mean;
}

void nvec::Read(istream &f)
{
	int i;
	double b;
	double *hilf;

	for(i=0; !f.eof(); i++) f >> b;
	len=i-1;
	
	try
	{
		hilf = new double [len];
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr<<"bad_alloc cought: " << ba.what() << endl;
		exit(EXIT_FAILURE);
	}
			
	f.clear();
	f.seekg(0, ios::beg);
	for(i=0; i<len; i++) f >> hilf[i];
	delete [] a;
	a=hilf;

}

void nvec::Append(double v)
{
	int i;	
	double *hilf;
	
	try
	{	
		hilf = new double [len+1];
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr<<"bad_alloc cought: " << ba.what() << endl;
		exit(EXIT_FAILURE);
	}

	for(i=0; i<len; i++)
	{
		hilf[i]=a[i];	
	}
	hilf[len]=v;
	len=len+1;
	delete [] a;
	a=hilf;
}

//Kopierkonstruktor
nvec::nvec(const nvec &s)
{	
	int i;
	len=s.len;
	try
	{
		a = new double [len];
	}
	catch (std::bad_alloc& ba)
	{
		std::cerr<<"bad_alloc cought: " << ba.what() << endl;
		exit(EXIT_FAILURE);
	}
	
	for(i=0; i<len; i++)
	{
		a[i] = s.a[i];
	}
}

//Zuweisungsoperator
nvec& nvec::operator=(const nvec& s)
{	
	int i;
	if(this != &s)
	{
		delete [] a;
		try
		{			
			a = new double [len=s.len];
		}
		catch (std::bad_alloc& ba)
		{
			std::cerr<<"bad_alloc cought: " << ba.what() << endl;
			exit(EXIT_FAILURE);
		}		
		
		for(i=0; i<len; i++)
		{
			a[i] = s.a[i];
		}
	}
	return *this;
}
