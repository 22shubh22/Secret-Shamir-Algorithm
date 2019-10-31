#include "ShamirSSScheme.h"   
    
#include <iostream>
using namespace std;
    
int main()   
{   
    ShamirSSScheme shamir(7,4);   
    ShamirSSScheme::BigNrVec peopleSecrets;   
    
    peopleSecrets = shamir.GetSecretParts();   
    int nr = 4;   
    vector<ShamirSSScheme::UInt> people(nr);   
    people[0] = 0;   
    people[1] = 1;   
    people[2] = 3;   
    people[3] = 2;   
    ShamirSSScheme::BigNrVec secrets(nr);   
    for (int i =0; i < nr; i++)   
        secrets[i] = peopleSecrets[people[i]];   
        
    shamir.AccesSecret(people, secrets);   
    
    vector<ShamirSSScheme::UInt> people2(2);   
    people2[0] = 0;   
    people2[1] = 3;   
    ShamirSSScheme::BigNrVec secrets2(2);   
    for (int i = 0; i < 2; i++)   
        secrets2[i] = peopleSecrets[people[i]];   
        
    shamir.AccesSecret(people2, secrets2);   
    return 0;   
}  