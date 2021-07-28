/* ATM System design using C
   - By Manas Ghosh
     UEMK, CSE
  
   - Made using C */

#include<stdio.h>
#include<windows.h>
#include<time.h>


int main(){
	system("color 3F");
	int pin=1234,option,epin,count=0,amount=1; //epin= entered pin
	float balance=5000; //initial balance
	int ctrans=1;  //continue transacttion
	
	time_t now;
	time(&now);
	printf("\n");
	printf("\t\t\t\t\t         %s",ctime(&now));
	printf("\n\t\t\t===================:welcome to ATM System Demo by Manas Ghosh:==================");
	
	while(pin !=epin){
		printf("\nPlease Enter Your pin : ");
		scanf("%d",&epin);
		if(epin != pin){
			//Beep(610,500);
			printf("Invalid Pin !!!");
		}
		count++;
		if(count ==3 && pin != epin){
			exit(0);
		}	
	}
	while(ctrans !=0 ){
		
		printf("\n\t\t\t===================Avaialable Transactions===================");
		printf("\n\n\t\t 1.WithDrawal");
		printf("\n\n\t\t 2.Deposit");
		printf("\n\n\t\t 3.Check Balance");
		printf("\n\n\t\t 4. Please Select an Option : ");
		scanf("%d", &option);
		
		switch(option){
			case 1:
				while(amount%500 !=0){
					printf("\n\t\t Enter the amount : ");
					scanf("%d",&amount);
					if(amount%500 !=0)
					printf("\n\t THe amount should be  multiple of 500");
				}
				if(balance<amount){
					printf("\n\t Sorry Insufficient Balance");
					amount=1; //garbage value generation
					break;
				}
				else{
					balance -= amount;
					printf("\n\t\t You have withdrawn Rs.%d.\nYour new balance is %.2f",amount,balance);
					amount=1;
					break;
				}
				
			case 2:
			printf("\n\t\t\t Enter the amount : ");
			scanf("%d",&amount);
			balance += amount;
			printf("\n\t\t Entered Amount : %d",amount);
			printf("\n\t\t Available Balance : %.2f",balance);
			printf("\n\t\t\t==============Thank You for Banking With Us==========");
			amount=1;
			break;
			
			case 3:
				printf("\n\t\tYour Balance is Rs. %.2f",balance);
				break;
				
			default:
			    printf("\n\t\t Invalid Option !!!");
				break;	
		}
		
	printf("\n\t\t Do You wish to perform another transaction?");
	printf("\n\t\t Press 1[Yes],0[No]");
	printf("\n\t\t");
	scanf("%d",&ctrans);	
	}
	return 0;
}
