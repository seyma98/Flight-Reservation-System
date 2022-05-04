#include<stdio.h>

#include<stdlib.h>

struct FlightInfo{
int FlightNumber;
char DepartureCity[15];
char ArrivalCity[15];
char Dday[20];
char Aday[20];
char Dtime[20];
char Atime[10];

};

struct PassangerInfo{
char Fname[15];
char Lname[15];
char DepartureCity[15];
char ArrivalCity[15];
int reservation;
char Dday[20];
int FlightNumber;
};


int compare(char *str1,char *str2){
int flag;

while(*str1!='\0'||*str2!='\0'){

if(*str1==*str2){flag=1;
str1++;
str2++;
}

else{
flag=0;
break;
}
}
return flag;
}//the end of compare function




int main(){

int numOfFlight,numOfPassangers;
int number,control;
struct FlightInfo *f;
struct PassangerInfo *p;

//****************flight info********************************

scanf("%d",&numOfFlight);
f=(struct FlightInfo *)malloc(numOfFlight*sizeof(struct FlightInfo));
int i,j;

for(i=0;i<numOfFlight;i++){
scanf("%d%s%s",&(f+i)->FlightNumber,(f+i)->DepartureCity,(f+i)->ArrivalCity);
scanf("%s",(f+i)->Dday);//departure day         
scanf("%s",(f+i)->Dtime);//departure time
scanf("%s",(f+i)->Aday);////arrival day
scanf("%s",(f+i)->Atime);//arrival time


}

//****************passanger info********************************

scanf("%d",&numOfPassangers);

p=(struct PassangerInfo *)malloc(numOfPassangers*sizeof(struct PassangerInfo));

for(i=0;i<numOfPassangers;i++){control=0;
scanf("%s%s%s%s",(p+i)->Fname,(p+i)->Lname,(p+i)->DepartureCity,(p+i)->ArrivalCity);
scanf("%s",(p+i)->Dday);
//departure day
for(j=0;j<numOfFlight;j++){

if(compare((p+i)->DepartureCity,(f+j)->DepartureCity)&&compare((p+i)->ArrivalCity,(f+j)->ArrivalCity)&&compare((p+i)->Dday,(f+j)->Dday)){
control++;
(p+i)->FlightNumber=(f+j)->FlightNumber;}

}
if(control==0){printf("%s %s %s %s %s No reservation\n",(p+i)->Fname,(p+i)->Lname,(p+i)->DepartureCity,(p+i)->ArrivalCity,(p+i)->Dday);
printf("\n");
(p+i)->reservation=0;}
else {(p+i)->reservation=1;}
}



//*******************search-print command******************************

char command[20];
char SECONDcommand[20];
char LastN[15];
char FirstN[15];
char DEPARTURE[15];
char ARRIVAL[15];
while(1){

scanf(" %s",command);

if(compare("END",command)){break;}//quit command



else if(compare("search",command)){

scanf(" %s",SECONDcommand);


if(compare("flightNumber",SECONDcommand)){
i=0,control=0;
scanf("%d",&number);
while(i<numOfFlight){
if(((f+i)->FlightNumber)==number){control++;
printf("%d %s %s %s %s %s %s\n",(f+i)->FlightNumber,(f+i)->DepartureCity,(f+i)->ArrivalCity,(f+i)->Dday,(f+i)->Dtime,(f+i)->Aday,(f+i)->Atime);


}

i++;}
if(control==0){printf("No flight with number %d\n",number);}

printf("\n");
}//flightnumber






else if(compare("departure",SECONDcommand)){

i=0,control=0;
scanf(" %s",DEPARTURE);
while(i<numOfFlight){control++;
if(compare(((f+i)->DepartureCity),DEPARTURE)){
printf("%d %s %s %s %s %s %s\n",(f+i)->FlightNumber,(f+i)->DepartureCity,(f+i)->ArrivalCity,(f+i)->Dday,(f+i)->Dtime,(f+i)->Aday,(f+i)->Atime);
}

i++;}
if(control==0){printf("No departure city %s\n",DEPARTURE);}

printf("\n");
}//departure





else if(compare("arrival",SECONDcommand)){


i=0,control=0;
scanf(" %s",ARRIVAL);
while(i<numOfFlight){

if(compare(((f+i)->ArrivalCity),ARRIVAL)){control++;
printf("%d %s %s %s %s %s %s\n",(f+i)->FlightNumber,(f+i)->DepartureCity,(f+i)->ArrivalCity,(f+i)->Dday,(f+i)->Dtime,(f+i)->Aday,(f+i)->Atime);
}

i++;}
if(control==0){printf("No arrival city %s\n",ARRIVAL);}


printf("\n");
}//arrival




}//search command





else if(compare("print",command)){control=0;
scanf("%d",&number);
i=0;
while(i<numOfFlight){

if(number==(f+i)->FlightNumber){

printf("%d %s %s %s %s %s %s",(f+i)->FlightNumber,(f+i)->DepartureCity,(f+i)->ArrivalCity,(f+i)->Dday,(f+i)->Dtime,(f+i)->Aday,(f+i)->Atime);

j=0;
while(j<numOfPassangers){
if(compare((p+j)->DepartureCity,(f+i)->DepartureCity)&&compare((p+j)->ArrivalCity,(f+i)->ArrivalCity)&&compare((p+j)->Dday,(f+i)->Dday)&&(p+j)->reservation==1){control++;}

j++;}

printf(" %d\n",control);
break;
}//while-if
i++;}

printf("\n");
}//print command



else if(compare("printwP",command)){

scanf("%d",&number);
i=0;
while(i<numOfFlight){

if(number==(f+i)->FlightNumber){

printf("%d %s %s %s %s %s %s",(f+i)->FlightNumber,(f+i)->DepartureCity,(f+i)->ArrivalCity,(f+i)->Dday,(f+i)->Dtime,(f+i)->Aday,(f+i)->Atime);

j=0;control=0;
while(j<numOfPassangers){
if(compare((p+j)->DepartureCity,(f+i)->DepartureCity)&&compare((p+j)->ArrivalCity,(f+i)->ArrivalCity)&&compare((p+j)->Dday,(f+i)->Dday)&&(p+j)->reservation==1){control++;}

j++;}

printf(" %d\n",control);
break;
}//while-if
i++;}




i=0;
while(i<numOfFlight){

if(number==(f+i)->FlightNumber){

j=0;
while(j<numOfPassangers){
if(compare((p+j)->DepartureCity,(f+i)->DepartureCity)&&compare((p+j)->ArrivalCity,(f+i)->ArrivalCity)&&compare((p+j)->Dday,(f+i)->Dday)&&(p+j)->reservation==1){printf("%s %s\n",(p+j)->Fname,(p+j)->Lname);}

j++;}

break;
}//while-if
i++;}


printf("\n");
}//printWP command


else if(compare("printR",command)){
scanf("%s%s", FirstN,LastN);

for(i=0;i<numOfPassangers;i++){
if(compare((p+i)->Fname,FirstN)&&compare((p+i)->Lname,LastN)&&(p+i)->reservation==1){
printf("%s %s",FirstN,LastN);

for(j=0;j<numOfFlight;j++){
if(compare((f+j)->DepartureCity,(p+i)->DepartureCity)&&compare((f+j)->ArrivalCity,(p+i)->ArrivalCity)&&compare((p+i)->Dday,(f+j)->Dday))
{
printf(" %d %s %s %s %s %s %s\n",(f+j)->FlightNumber,(f+j)->DepartureCity,(f+j)->ArrivalCity,(f+j)->Dday,(f+j)->Dtime,(f+j)->Aday,(f+j)->Atime);
break;}
}


break;}//if
}//for





printf("\n");

}//printR command









}//while-command


return 0;}

