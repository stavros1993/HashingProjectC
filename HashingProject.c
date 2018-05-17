#define NULL 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 20

     struct element { //struct pou periexei ta stoixeia gia ton pinaka tou katakermatismou
       char data[MAX_SIZE];
       int key;
     };
      struct element* A;  
      struct element temp; 
       
void insert(int key, char* data,int m){ //sunarthsh eisagwghs stoixeiou
         int j=0;int hash=key%m;
         
         for (j = 0 ; j < m ; j++)  //elegxos upakshs tou idiou kleidiou apo prin
             if (A[j].key == key) return;
             
         while (hash < m && A[hash].key != -1) {
               hash++;
               if (hash == m) hash = 0;
         }
         
         A[hash].key = key;
         strcpy(A[hash].data,data);               
         
         printf("((%d, %d, %s))\n", A[hash].key, hash, A[hash].data);
}
     
void search(int m,int key) { //sunarthsh anazhthshs stoixeiou mafto to kleidi
     int j=0;int hash=key%m, tries=1;
     

             
         while (hash < m && A[hash].key != key && A[hash].key != -1) {
               hash++;
               tries++;
               if (hash == m) hash = 0;
         }
     
     
     if (A[hash].key == key) printf("found %s, tries %d\n", A[hash].data, tries); 
     else printf("not found , tries %d\n", tries);
}
     
     void print(struct element *A, int m) { //synarthsh emfanishs 
          int ii;
          //printf("_______");
          for(ii=0;ii<m;ii++) {
              printf("%d. ", ii);
              if(A[ii].key != -1){
                 printf("%s-",A[ii].data);
                 printf("%d ",A[ii].key);
                 
                 }
                 //printf("-----\n");
          }
     }

int main() {
    
     int n=0;int m=0;int hash;int i=0;int sum=0;int key;char l=0;
     char data[20];
     scanf("%d",&m); //mege8os
     scanf("%d",&n); //plh8os stoixeiwn pou 8a eisax8oun
     A = (struct element*)malloc(m*sizeof(struct element));
     for (i = 0 ; i < m ; i++) A[i].key = -1;
     
     for(i=0;i<n;i++) {
       scanf("%d",&key);
       scanf("%s",&data);
       fflush(stdin);
       insert(key, data ,m);
     }
     
       for(i=0;i<m;i++) {
          if (A[i].key != -1) {
                       printf("%d ", A[i].key);
                       sum++;
          }
       }

       printf("total items:%d\n",sum);
       //print(A, m);
       fflush(stdin);
       scanf("%d",&key);
       while(key!=0) {
         search(m,key);
         scanf("%d",&key);
       }
      free(A);
      exit(0);
}
