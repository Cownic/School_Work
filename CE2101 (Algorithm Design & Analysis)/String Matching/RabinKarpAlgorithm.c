#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define q 7 //prime number used in the hashing of values
#define d 101 // base of the numbers in the array


//m is the length of the pattern
//n is the length of the text
int RKScan(char *P , char *T);
int hash(char *T , int m , int dd); 
int rehash(char *T , int j , int m , int ht , int dm);
int equalString(char *P , char *T , int zero , int j , int m);
int main()
{
    int result;
    char *P = "BAC";
    char *T = "ABABACBCCAC";


    result = RKScan(P , T);
    if (result == -1){
        printf("The pattern is not in the text!");
    }
    else {
        printf("The pattern is in the text starting from index %d\n" , result);
    }
    return 0;
}

int hash(char *T , int m , int dd)
{
    int i;
    int h = T[0] % q;
    for (i = 1 ; i < m ; i++){
        h = ((h * d) + T[i]) % q; 
    }
    return h;
}

int rehash(char *T , int j , int m , int ht , int dm)
{
    int oldest; // will get the value of the element at the j position 
    int oldest_removed;  // will contain the value with the element at position j being removed
    oldest = (T[j] * dm) % q;
    oldest_removed = ((ht + q) - oldest) % q;

    return (oldest_removed * d + T[j + m]) % q; 
}

int equalString(char *P , char *T , int zero , int j , int m)
{
    int i = zero;
    while (m > 0){
        if (T[j] != P[i]){
            return 0;
        }
        else {
            j++;
            i++;
        }
        m--;
    }
    return 1;
}

int RKScan(char *P , char *T)
{
    int track;
    //length of the pattern
    int m = strlen(P);
    //length of the text
    int n = strlen(T);
    int k; //pointer used in transversing thru the pattern array
    int j; //pointer used in transversing thru the text array
    
    

    int ht; // store the hash value of text
    int hp; // store the hash value of the pattern
    
    int dm = 1;
    //calculated to be used in the rehashing function
    for (j = 1 ; j < m ; j++){
        dm = (dm * d) % q;
    }

    ht = hash(T , m , d);
    hp = hash(P , m , d);

    printf("hp = %d , ht = %d\n" , hp , ht);

    //main part doing the dirty work of finding the matching pattern in the text
    for (j = 0 ; j <= (n-m) ; j++){
        //if the hashing value matches and the comparision of the string is same
        //return j , which is the start of the pattern in the text;
        
        if (hp == ht){
            track = equalString(P , T , 0 , j , m );
            if (track){
                return j;
            }
        }
        ht = rehash(T , j , m , ht , dm);
        printf("ht = %d\n" , ht);
    }
    //pattern is not found in the text given
    return -1;
}