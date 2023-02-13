#include <iostream>
#include <fstream>
#include <stdlib.h> 


using namespace std;

class nvec
{
	protected:
	double *a;
	int len;
	
	public:
	//Konstruktor aus Zeiger und Laenge
	//Falls p==0, l Werte mit 0 initialisieren
	nvec(const double *p=0, int l=0);
	
	//Destruktor
	~nvec();

	//Laenge des Arrays
	int Len(void) {return len;};
	
	//ersetzt Get() und Set()
	double &operator[](int n);  
	
	// Sucht Minimum
	double Min(void);

	// Sucht Maximum
	double Max(void);
	
	//ersetzt Mult()
	void operator*=(double f);       
	               
	// Ab hier nicht Pflicht
	double Mean(void); //Mittelwert berechnen
	void Read(istream &f); // Von Datei Lesen
	void Append(double v); //Hinten anhaengen

	//Kopierkonstruktor
	nvec(const nvec &s);

	//Zuweisungsoperator
	nvec& operator=(const nvec& s);
};

ostream& operator<<(ostream& out, nvec& x);
