#include<stdio.h>
#include<stdlib.h>

int display ();
void vote();
void result ();
void exit_program();

FILE *fp;
int ranil = 0;
int anura=0;
int namal=0;
int dilith=0;
int seelarathne=0;

int n2;

int main(){
    
    printf("-------------MAIN MENU----------------\n");
    printf("\t1.Display candidates\n");
    printf("\t2.Vote\n");
    printf("\t3.Show results\n");
    printf("\t4.EXIT\n");
    printf("\n");
    
    int n1;
    
    printf("Enter option number: ");
    scanf("%d",&n1);
    
    switch(n1){
        
        case 1:
             display(); 
             break;  
        case 2:
             vote();
             break;  
        case 3:
             result();
             break;  
        case 4:
             exit_program();
             break;
             
        default: 
               printf("please Enter only 1 or 2 or 3 or 4 number.");                
    }
      
}

//-----------------------------DISPLAY FUNCTION-----------------------------

int display () {
    
    char *arr[5]={"Ranil","Anura","Namal","Dilith","Seelarathne"};
    
    printf("\n");
    
    for(int i=0; i<5; i++){
         printf("\t%s \n",arr[i]);
    }
    
    printf("\n 20. Back");
    
    
    
    printf("\n Do you want to back, enter 20: ");
    scanf("%d",&n2);
    
    switch (n2){
        case 20: 
                main();
                break;
              
    }
    return 0;
}

//--------------------------------VOTE FUNCTION-----------------------

void vote () {
    
    
    int num1;
    
    fp = fopen("vote.txt", "w");
    
    for(int i=0; i<100; ++i){
    
       printf("Enter vote number %d: ",i+1);
       scanf("%d",&num1);
       
       if(num1==1){
           ranil += 1;
       }
       else if(num1 == 2){
           anura += 1;
       }
       else if(num1 == 3){
           namal += 1;
       }
       else if(num1 == 4){
           dilith += 1;
       }
       else if(num1 == 5){
           seelarathne += 1;
       }
      else if(num1 == 0){
            break;
            }
     
      
    }
    fprintf(fp,"ranil=%d \n anura=%d \n namal=%d \n dilith=%d \n seelarathne=%d \n ",ranil,anura,namal,dilith,seelarathne);
    
    
    fclose(fp);
   
   printf("\n"); 
   
    printf("\n Do you want to back, enter 20: ");
    scanf("%d",&n2);
    
    switch (n2){
        case 20: 
                main();
                break;
              
    }
    
      
}

//----------------------RESULT FUNCTION----------------------------------

void result() {
    FILE *fpr;
    ranil = 0, anura = 0, namal = 0, dilith = 0, seelarathne = 0;

    fpr = fopen("vote.txt", "r");

    if (fpr == NULL) {
        printf("Error opening file!\n");
        return;
    }

   
    fscanf(fpr, "ranil=%d\nanura=%d\nnamal=%d\ndilith=%d\nseelarathne=%d\n", &ranil, &anura, &namal, &dilith, &seelarathne);

    float mark = ranil + anura + namal + dilith + seelarathne ;
    
   float r = (ranil/mark)*100;
   float a = (anura/mark)*100;
   float n = (namal/mark)*100;
   float d = (dilith/mark)*100;
   float s = (seelarathne/mark)*100;
  
    printf("\nResults:\n");
    printf("Ranil: %.2f %% \n", r);
    printf("Anura: %.2f %% \n", a);
    printf("Namal: %.2f %% \n", n);
    printf("Dilith: %.2f %% \n", d);
    printf("Seelarathne: %.2f %% \n",s);

    fclose(fpr);
    
    printf("\n");
    
   printf("\n");
   
    printf("\n Do you want to back, enter 20: ");
    scanf("%d",&n2);
    
    switch (n2){
        case 20: 
                main();
                break;
              
    }
}

//----------------EXIT FUNCTION-------------------------------------

void exit_program() {
    printf("Exit programe!!!");
    exit(0);
}