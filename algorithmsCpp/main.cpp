//
//  main.cpp
//  algorithmsCpp
//
//  Created by Kunle on 11/26/19.
//  Copyright © 2019 KunleBabatunde. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;
/*===================================================================*/
/*----------isPERMUTATION? CLASS/STRUCT---------*/

/*
 ----ALGO 1-----
 1. sort the strings
 2. compare the sorted strings
 -----------ANALYSIS-------
 1. worse case is to use quick sort or bubble sort - O(n^2)
 2. compare sorted string is O(n)
 - assume the string is made with characters A-Z
 */
struct permutationClass {
    void sortQuick( string & _word);
    bool checkPermutation_V1(const string & _word1, const string & _word2);
};

void permutationClass::sortQuick(string &_word){
    sort(_word.begin(), _word.end());
}
bool permutationClass::checkPermutation_V1(const string & _word1, const string & _word2){
   if(_word1.length() != _word2.length())
       return false;
   else {
       for(int i=0; i<_word2.length(); i++){
           if(_word1[i]!=_word2[i])
               return false;
       }
       return true;
   }
}

/*
 -----ALGO 2-------
 1. Create count array of size 256
 2. increment the count array based on each strings
 3. compare both count arrays
 - characters are mapped using using the 8-bit ASCII table.
 - Characters are mapped from 0 to 255.
 -  it is assumed that the characters are stored using
    8 bit and there can be 256 possible characters.
 */

class permutationClass2{
    int chr1[256]={0}, chr2[256]={0},i;
public:
    void mapstring(const string &_s1, const string &_s2);
    bool checkPermutation(const string &_s1, const string &_s2);
};

void permutationClass2::mapstring(const string &_s1, const string &_s2){
    for (i=0; i<_s1[i] && _s2[i]; i++) {
        if(chr1[_s1[i]]){
            chr1[_s1[i]]=1;
        } else chr1[_s1[i]]++;
        
        if(chr2[_s2[i]]){
            chr2[_s2[i]]=1;
        } else chr2[_s2[i]]++;
    }
}
bool permutationClass2::checkPermutation(const string &_s1, const string &_s2){
    if(_s1.length() != _s2.length()) return false;
    else{
        mapstring(_s1,_s2);
        for ( i=0; i<256; i++) {
            if(chr1[i]!=chr2[i]) return false;
        }
        return true;
    }
}

/*===================================================================*/

int main(int argc, const char * argv[]) {
    string word1="jessica", word2="ssiyaje";
    /*---testing version 1-----*/
    permutationClass o1;
    o1.sortQuick(word1); o1.sortQuick(word2);
    cout<<"isPermutation_1="<<o1.checkPermutation_V1(word1, word2)<<"\n";
    /*---testing version 2-----*/
    permutationClass2 oo1;
    cout<<"isPermutation_2="<<oo1.checkPermutation(word1, word2)<<"\n";
    
    return 0;
}


















