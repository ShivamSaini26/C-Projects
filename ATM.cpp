#include<stdio.h>
#include<conio.h>//password/pin 2601
int user1=10500,opt,user2=20800;
void cash_withdrawl(){
	char ch;
	int output,withdrawl=0,opt;
	
	printf("Enter withdrwal account : user1/user2 \n ");
	scanf("%d",&opt);
	printf("Enter Amount to be Withdrawl \n");
	scanf("%d",&withdrawl);
	
		switch(opt){
				case 1:
				if(withdrawl<user1){
			output=user1-withdrawl;
			printf("\namount has been deducted from your bank account\n");
			printf("\nYour Remaining bank Balance is %d\n ",output);

					}
				else
				printf("insuffient balance\n");
				break;

			case 2:
				if(withdrawl<user2){
					
			output=user2-withdrawl;
			printf("amount has been deducted from your bank account\n");
			printf("Your Remaining bank Balance is %d \n",output);
						
				}
				else
				printf("insuffient balance\n");
				break;	
}		}
		
	
			void bal_enq(){
				char ch;
			
				
				printf("enter user no.\n");
					
				scanf("%d",&opt);
				switch(opt){
					case 1:
						printf("Account Balance of User 1 is %d\n",user1);
						break;
						case 2:
						printf("Account Balance of User 1 is %d\n",user2);
						break;
				}
				
		
			}
void deposite(){
	int opt,amt,output;
	printf("Enter account no. to be deposite 1 or 2 \n");
	scanf("%d",&opt);
	printf("Enter amount to be deposite\n");
	scanf("%d",&amt);
	switch(opt){
		case 1:
			output=user1+amt;
			printf("\nNow Available Bank Balance is %d\n",output);
			break;
				case 2:
			output=user2+amt;
			printf("\nNow Available Bank Balance is %d\n",output);
			break;
			}
}
int main(){
	int pin;
		printf("***Welcome to Bank of India ATM***\n\n");

	printf("Enter your PIN-");
	scanf("%d",&pin);
	if(pin==2601)
	{
	printf("\nenter your choice\n 1.Cash Withdrawl\n 2.Balance Enquiry\n 3.Deposite Money to an account\n 4.Exit\n")	;
	scanf("%d",&opt);
	
		switch(opt){
			case 1:
				cash_withdrawl();
				break;
			case 2:
				bal_enq();
				break;
				case 3:
					deposite();
					break;
		}
		
	printf("Thankyou for using Bank of India ATM service\n");
	}
	else
	printf("\nInvalid pin... enter correct Pin NO.");
	return 0;
}
