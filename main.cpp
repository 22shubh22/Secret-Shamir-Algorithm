#include "ShamirSSScheme.h"  
    
#include <iostream>
using namespace std;
    
int main()
{   
    // Input bytearray
    // Store all Shamir Share for 32 byte.

    cout << "Enter M, the number of byte array applet should take\n";
    int m;
    cin >> m;

    while(m--)
    {
        vector<ShamirSSScheme> store;
        
        unsigned char arr[5];
        cout << "Input phrase less than 32 words\n";
        for(int i=0;i<5;i++)
        {
            cin >> arr[i];
            ShamirSSScheme shamir(4,2,arr[i]);
            store.push_back(shamir);
        }
        
        //display phrase
        cout << "secret phrase is: ";
        for(int i=0;i<5;i++)
        {
            cout << arr[i];
        }
        cout << '\n';

        //share secrets with people
        ShamirSSScheme::BigNrVec peopleSecrets[5];
        for(int i=0;i<5;i++)
        {
            peopleSecrets[i] = store[i].GetSecretParts();
        }
        
        // test 
        int nr = 4;  
        vector<ShamirSSScheme::UInt> people(nr);   
        people[0] = 0;   
        people[1] = 1;   
        people[2] = 2;   
        people[3] = 3;   
        
        
        /*for (int i = 0; i < nr; i++)   
            secrets[i] = peopleSecrets[i][people[i]]; */
        bool flag=0;
        //access secret
        for(int i=0; i<5; i++)
        {
            ShamirSSScheme::BigNrVec secrets(nr);
            for (int j = 0; j < nr; j++)   
                secrets[j] = peopleSecrets[i][people[j]];

            /*cout <<"\nvalue of i: " <<  i << '\n';
            for(int i=0;i<nr;i++)
            {
                cout << secrets[i] << '\t';
            }

            cout << "people";
            for(int i=0;i<nr;i++)
            {
                cout << people[i] << '\t';
            }*/

            bool byte_match = store[i].AccesSecret(people, secrets);
            if (byte_match == false)
            {
                cout << " Failure at matching " << i << " byte\n";
                flag=1;
                break;
            }
            else
            {
                cout << " \nbyte " << i << " matched\n";
            }
        }
        if(flag == 0)
            cout << "\n\nByte array successfully macthed\n";  
        
        cout << "\n===============2nd Test==============\n";
        vector<ShamirSSScheme::UInt> people2(1);   
        people2[0] = 0;
        ShamirSSScheme::BigNrVec secrets2(1);   
        for (int i = 0; i < 1; i++)   
            secrets2[i] = peopleSecrets[i][people[i]];   
            
        if(!store[0].AccesSecret(people2, secrets2))
        {
            cout << "Access Denied!\n"; 
        }   
    }
    return 0;  
}  