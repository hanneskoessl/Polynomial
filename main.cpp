#include "poly.h"

int main(void)
{
	double f;

	double P1[]={7.2, -6.2, 5.2, -4.2, 3.2, -2.2, 1.2};
	polynom p1(P1,7);

	double P2[]={1.1, 2.2, 3.3, 4.4, 5.5};
	polynom p2(P2,5);

	double P3[]={2., 4., -7., 3., 1.};
	polynom p3(P3,5);
	
	polynom a(0,1);
	polynom p3_k(0,1);
	a=p1+p2;
	p3_k=p3;
	p3*=5;

	//Berechnung der Funktionswerte mit dem Operator () und ausgeben in eine Datei
	ofstream OutFile("Polynom.dat");
	if (!OutFile.is_open()) 
	{
		cout<<"OutFile nicht geöffnet!"<<endl; 
		exit(EXIT_FAILURE);
	}
	for(f=-2.; f <= 2.01; f=f+0.1)
	{
		OutFile << f << "\t" << p1(f) << "\t" << p2(f) << "\t";
		OutFile << p3_k(f) << "\t" << p3(f) << "\t" << a(f) << endl;
	}
	OutFile.close();

	//Berechnung der Funktionswerte mit der Funktion polynom::fast() und ausgeben in eine Datei
	OutFile.open("Polynom_fast.dat");
	if (!OutFile.is_open()) 
	{
		cout<<"OutFile nicht geöffnet!"<<endl; 
		exit(EXIT_FAILURE);
	}
	for(f=-2.; f <= 2.01; f=f+0.1)
	{
		OutFile << f << "\t" << p1.fast(f) << "\t" << p2.fast(f) << "\t";
		OutFile << p3_k.fast(f) << "\t" << p3.fast(f) << "\t" << a.fast(f) << endl;
	}
	OutFile.close();
}
