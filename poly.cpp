#include "poly.h"
#include <math.h>

double polynom::operator()(const double x)
{
	int i;
	double y=0;
	for(i=0; i<len; i++)
	{	
		y = y + a[i] * pow(x,i);
	}
	return y;
}

double polynom::fast(const double x)
{
	int i;
	double y=0;
	for(i=len-1; i>=0; i--)
	{	
		y = y*x + a[i];
	}
	return y;
}


polynom operator+(polynom &a, polynom &b)
{
	int i;
	int maxlen;
	int minlen;
	double *c;
	if(a.Len() > b.Len())
	{	
		maxlen = a.Len();
		minlen = b.Len();	
	}
	else
	{
		maxlen = b.Len();
		minlen = a.Len();
	} 
	
	try
	{
		c = new double [maxlen];
	}
	catch (std::bad_alloc& ba)
	{
		cout<<"bad_alloc cought: " << ba.what() << endl;
		exit(EXIT_FAILURE);
	}

	for(i=0; i < minlen; i++)
	{
		c[i] = a[i] + b[i];
	}

	if(a.Len() > b.Len())	for(i=minlen; i < maxlen; i++)	c[i] = a[i];
	else			for(i=minlen; i < maxlen; i++)	c[i] = b[i];

	return polynom(c,maxlen);
}

