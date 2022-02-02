#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define NAMEBUFF 30

int SIZE_OF_DATABASE =10;
int COUNT_OF_PERSONS = 0;
int COUNT_OF_DELETED =0;

typedef struct{
    char name[NAMEBUFF];
    int age;
    char job[NAMEBUFF];
}Person;

Person** iterator ;
 

int isValidName(char* Note){
        
        unsigned int i=0;
        
        while( i < strlen(Note)  &&  (( Note[i] >= 'A'  &&   Note[i] <='Z') || (Note[i]  >= 'a' && Note[i]  <= 'z') )){
            i++;
        }
        if(i < strlen(Note)){
            return 0 ;
        }
        else{
            return 1;
        }
}





int add_person(){
    if(COUNT_OF_PERSONS >= SIZE_OF_DATABASE){
        
        SIZE_OF_DATABASE += 5;
        iterator = realloc(iterator, SIZE_OF_DATABASE * sizeof(Person*));
        
        for(int i=SIZE_OF_DATABASE -5 ; i<SIZE_OF_DATABASE ; i++){
            iterator[i] = (Person*)malloc(sizeof(Person));
        }
    }   

    printf("Enter the name of the person :\n");
    scanf("%s", iterator[COUNT_OF_PERSONS]->name );
    
    if ((strlen(iterator[COUNT_OF_PERSONS]->name)) > 30){
        printf("The name can't have more than 30 char\n");
        return 1;
    }
    
    if(isValidName(iterator[COUNT_OF_PERSONS]->name) == 0){
        printf("Invalid used of characters\n");
        return 1;
    }

    printf("Enter the age of the person :\n");
    scanf("%d", &iterator[COUNT_OF_PERSONS]->age);
    printf("Enter the job of the person :\n");
    scanf("%s", iterator[COUNT_OF_PERSONS]->job);
    COUNT_OF_PERSONS++;
    if(COUNT_OF_DELETED != 0){
        COUNT_OF_DELETED--;
    }
    return 0;
}

void list_person(){
    if(COUNT_OF_PERSONS == 0){
   
        printf("You have not added any Person yet!\n");
    }
    else{
    
        for(int i=0 ; i<COUNT_OF_PERSONS ; i++){

            printf("%s\t %d\t %s\n",iterator[i]->name, iterator[i]->age , iterator[i]->job);
        }
    
    }
}


void delete_person(){
    if( COUNT_OF_DELETED == 6  ){

        SIZE_OF_DATABASE -= 5;
        printf("size of database %d\n", SIZE_OF_DATABASE);
        iterator = realloc(iterator , SIZE_OF_DATABASE * sizeof(Person*));
        COUNT_OF_DELETED = 0;
    
    }

    char name[30];
    
    printf("Who do you want to delete\n");
    scanf("%s", name);
    
    int j =0 ,k=0;
        while( j<COUNT_OF_PERSONS ){

            if( strcmp(iterator[j]->name, name) == 0 ){
                
                printf("%s deleted successfully\n",iterator[j]->name);
                free(iterator[j]);
                iterator[j] = (Person*)malloc(sizeof(Person));
                COUNT_OF_DELETED++;
                COUNT_OF_PERSONS--;
                k++;
                 
            }
           j++;
        }

        if (k==0)
        {
            printf("%s Not Found\n", name);
        }
}

void Exit(){
    free(iterator);
    for(int i=0 ;i<SIZE_OF_DATABASE ; i++){
        free(iterator[i]);
    }
    printf("Thank you for using our application :)\n");
    exit(0);
}



int main(){

    iterator = (Person**)malloc(SIZE_OF_DATABASE*(sizeof(Person*)));
    
    for(int i=0 ; i<SIZE_OF_DATABASE ; i++){
        iterator[i] = (Person*)malloc(sizeof(Person));
    }
    
    char operator[20];
       
    do{
        printf("\nthe size of the database is %d\n", SIZE_OF_DATABASE);
        printf("---------------------------------------------------------\n");
        printf("There is/are %d person/s in the list\n ", COUNT_OF_PERSONS);
        printf("choose one of the operators :\n");
        printf("\n a : Add a new person to the database\n l : List the whole database.\n x : Exit from the progr\n d : Delete person from the database\n ");
        printf("---------------------------------------------------------\n");
         
         scanf("%s",operator);

        if(strcmp(operator, "a") == 0){
           add_person();
        }

        else if(strcmp(operator, "l") == 0){
            list_person();
        }
        else if(strcmp(operator, "d") == 0){
            delete_person();
        }
        else if(strcmp(operator,"x") != 0){
            printf("invalid operator... please choose one from the list\n");
        }
        
    }while(strcmp(operator,"x") != 0);

    Exit();
    
    return 0;
}
