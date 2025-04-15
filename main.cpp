#include <iostream>
#include <fstream>
#include <sstream>
#include "src/Utils.hpp"
#include <iomanip>
using namespace std;

int main()
{
	
	string inputFileName = "data.txt"; //dico qual è il file di input
	double S; //inizializzo S 
	size_t n;//dimensione dei vettori
	double V=0;
    long double* w = nullptr;
    long double* r = nullptr;
	
	//adesso chiamo una funzione che mi legge il file e mi sistema i dati che voglio

	if (!Raccoglitore_dati(inputFileName,S,n,w,r))
		{
			cerr<< "Qualcosa è andato storto"<< endl;
			return -1;
		}
	

		
	//adesso invoco una funzione che calcola il livello del mio portafoglio
	long double rate= rate_portafoglio(n,w,r);

	//infine calcoliamo il livello finale del portafoglio
	long double livello_portafoglio= calcolatore_livello_portafoglio(rate,S);

		
	//Non ci resta che esportare i contenuti in un file di output e a schermo
	
	string outputFileName= "result.txt";//dico qual è il file di output
    if (!Stampa_risultati_result(outputFileName,n,S,w,r,rate,livello_portafoglio))
    {
        cerr<< "Qualcosa è andato storto nella stampa dei risultati"<< endl;
        return -1;
    }
    else
        cout<< "Stampa avvenuta con successo"<< endl;
	if (!Stampa_risultati_schermo(n,S,w,r,rate,livello_portafoglio))
		{
			cerr<< "Qualcosa è andato storto nella stampa dei risultati"<< endl;
			return -1;
		}
    else
        cout<< "Stampa avvenuta con successo"<< endl;
	
	delete[] w;
    delete[] r;
    
	return 0;
}


