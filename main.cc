#include <cmath>
#include <vector>
#include <limits>
#include <iostream>

#include "random.hh"

using namespace std;

int main()
{
    librandom::Random rnd;
    vector<unsigned int> codevirtuali(12);
    vector<double> weight(12);
    vector<double> CIDassignation(12);
    unsigned int avg_pkt_size = 100;
    
    typedef vector<unsigned int>::iterator cit;

    for(cit coda = codevirtuali.begin(); coda != codevirtuali.end(); coda++)
    {
	*coda = rnd.integer(100,1000);
	cout  << "La coda ha " << *coda << " bytes." << endl;
    }

    typedef vector<double>::iterator wit;
    for(wit w = weight.begin(); w != weight.end(); w++)
    {
	*w = rnd.integer(1, 9);
	cout  << "La coda ha peso " << *w << endl;
    }
    
    // Realizza il WRR
    typedef vector<double>::const_iterator cwit;
    double min_weight = numeric_limits<double>::max();
   
    for(cwit it=weight.begin(); it != weight.end(); it++)
	if(*it < min_weight)
	    min_weight = *it;

    cout  << "Il peso minore è " << min_weight << endl;

    for(unsigned int i=0;i<CIDassignation.size();i++)
	if(codevirtuali[i] != 0)
	{
	    unsigned int assignation = int((weight[i]/min_weight) * avg_pkt_size);
	    if(assignation > codevirtuali[i])
		assignation = codevirtuali[i];
	    cout << assignation << endl;
	}
    
}
