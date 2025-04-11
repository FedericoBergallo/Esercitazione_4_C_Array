#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"
using namespace std;
bool Raccoglitore_dati(const string& inputFileName,
                   double &S,
				   size_t& n,
                   long double*& w,
                   long double*& r)
{
    ifstream file;  //creo un oggetto di tipo "input da file"
    file.open(inputFileName); //Quindi apro il file

    if (file.fail()) //controllo che il file sia aperto correttamente
    {
        cerr<< "file open failed"<< endl;
        return false;
    }
//Salviamo il valore della variabile S
//getline necessita di due input: il nome che ho dato al file, una stringa in cui memorizzare quello che ho letto
	
	string line; //stringa che memorizza quello che ho letto 
	getline(file,line,';');   //il terzo parametro è per prendere il numero che sta davanti al ";"
	getline(file,line,';');
	//a questo punto voglio memorizzare il numero nella mia variabile S
	istringstream convertS;  //definisco lo stream di tipo input (su quale posso solo fare >>)
	convertS.str(line);   //ottengo la stringa definita nella variabile line 
	convertS >> S;	
 //Allo stesso modo salviamo il valore della variabile n che mi dice quanto è lungo il mio vettore
	getline(file,line,';');   
	istringstream convertn;  //definisco lo stream di tipo input (su quale posso solo fare >>)
	convertn.str(line);   //ottengo la stringa definita nella variabile line 
	convertn >> n;
//Adesso voglio saltare la terza riga, che tanto non mi serve
	getline(file, line); //non ho messo;
//Adesso memoriziamo i contenuti del file all'interno dei due vettori
	w= new long double[n];
	r= new long double[n];
	unsigned int i=0;
	unsigned int j=0;
	unsigned int k=0;
	while (!file.eof())
	{
		
		if (i==0)
		{
			getline(file, line,';');
			istringstream convertw;
			convertw.str(line);
			convertw >> w[j];
			j++;
			i++;
			
		}
		else
		{
			getline(file, line);
			istringstream convertr;
			convertr.str(line);
			convertr >> r[k];
			k++;
			i--;
		}
    }

	return true;
}

long double rate_portafoglio(const size_t& n,
                        const long double* const& w,
                        const long double* const& r)
{
    long double r_finale = 0;
    for (unsigned int i = 0; i < n; i++)
        r_finale += w[i] * r[i];

    return r_finale;
}
long double calcolatore_livello_portafoglio(const long double &rate,const double &S)
{
	long double V=0;
	V=(1+rate)*S;
	return V;
}

bool Stampa_risultati_result(const string &outputFileName,
					const size_t&n,
					double &S,
					const long double* const& w,
					const long double* const&r,
					const long double &rate,
					const long double &livello_portafoglio)
					{
						//apro il file di output
						ofstream ofs;//come al solito prendo una variabile con cui potrò lavorare sul file
						ofs.open(outputFileName);
					
						if (ofs.fail())
						{
							cerr<< "Il file non è stato aperto"<< endl;
							return false;
						}
						ofs<<"S = "<<fixed<<setprecision(2)<<S<<','<<" n = "<<n<<endl;
						ofs<<"w = "<<fixed<<setprecision(2)<< ArrayToString(n,w)<<endl;
						ofs<<"r = "<<fixed<<setprecision(2)<< ArrayToString(n,r)<<endl;
						ofs<<"Rate of return of the portfolio: "<<fixed<<setprecision(4)<<rate<<endl;
						ofs<<"V: "<<fixed<<setprecision(2)<<livello_portafoglio<<endl;
					
						ofs.close();
						return true;
					}		
bool Stampa_risultati_schermo(const size_t&n,
					double &S,
					const long double* const& w,
					const long double* const&r,
					const long double &rate,
					const long double &livello_portafoglio)
					{

						cout<<"S = "<<fixed<<setprecision(2)<<S<<','<<" n = "<<n<<endl;
						cout<<"w = "<<fixed<<setprecision(2)<< ArrayToString(n,w)<<endl;
						cout<<"r = "<<fixed<<setprecision(2)<< ArrayToString(n,r)<<endl;
						cout<<"Rate of return of the portfolio: "<<fixed<<setprecision(4)<<rate<<endl;
						cout<<"V: "<<fixed<<setprecision(2)<<livello_portafoglio<<endl;
					

						return true;
					}		
string ArrayToString(const size_t& n,
                     const long double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}
