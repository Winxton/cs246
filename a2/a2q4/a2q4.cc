#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

bool containsNumber(string s) 
{
    for (int i=0; i<s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            return true;
    }

    return false;
}


int main() 
{
    //since there are a maximum of 10 candidates
    int results[10] = {0};
    string candidateList[10];
    int candidates = 0;
    int voters =0;
    int validvotes =0;
    string s;
    
    while (getline(cin,s)) {
        //read in candidates
        int vote;
        int n;

        if (containsNumber(s)) {
            istringstream iss(s);
        
            while (iss >> n) {
                if (n > 0 && n <= candidates) {
                    validvotes ++;
                    results[n-1] ++;
                }     
                voters ++;
            }
            
        }
        else {
            candidateList[candidates] = s;
            candidates ++;
        }
    }

    cout << "Number of voters: " << voters << endl;
    cout << "Number of valid votes: " << validvotes << endl;
    cout << "Number of spoilt votes: " << voters-validvotes << endl;
    cout << endl;
    cout << "Candidate      Score" << endl;
    cout << endl;
    
    for (int i =0; i< candidates; i++) {
        cout << setw(15) << left << candidateList[i]
             << setw(3) << right << results[i] << endl;    
    }

}

