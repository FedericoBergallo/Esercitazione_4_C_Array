#pragma once
#include <iostream>

using namespace std;


bool Raccoglitore_dati(const string& inputFileName,
					double &S,
					size_t& n,
					long double*& v1,
					long double*& v2);

string ArrayToString(const size_t& n,
                     const long double* const& v);

long double rate_portafoglio(const size_t& n,
                        const long double* const& w,
                        const long double* const& r);
						
long double calcolatore_livello_portafoglio(const long double &rate,
											const double &S);

bool Stampa_risultati_schermo(const size_t&n,
					double &S,
					const long double* const& w,
					const long double* const&r,
					const long double &rate,
					const long double &livello_portafoglio);
bool Stampa_risultati_result(const string &outputFileName,
					const size_t&n,
					double &S,
					const long double* const& w,
					const long double* const&r,
					const long double &rate,
					const long double &livello_portafoglio);
