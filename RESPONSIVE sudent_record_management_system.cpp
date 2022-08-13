/*
THIS VERSION IS RESPONSIVE VERSION
 OF PREVIOUS STUDENT RECORD MANAGEMENT SYSTEM
 MADE BY SHIVAM SAINI
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>//for color
void add_record()
{
	FILE *fp;
	int roll,age;
	char name[20];
	printf("%45s","Addtion Of New Record\n");
	printf("%45s","=====================\n");
	

	fp=fopen("stud.dat","r");
	if (fp==NULL)
	{
		printf("File is not present, to be created ");
		fp=fopen("stud.dat","w");
	}
	else
	{
		fclose(fp);
		fp=fopen("stud.dat","a");
	}
	printf("%45s","Enter the roll number ");
	scanf("%d",&roll);
	printf("%45s","Enter the name ");
	fflush(stdin);
	scanf("%s",name);
	strupr(name);
	printf("%45s","Enter the age ");
	scanf("%d",&age);
	fprintf(fp,"%d %s %d\n",roll,name,age);
	fclose(fp);
}
void display_all()
{
	FILE *fp;
	int roll,age,i;
	char name[20];
	fp=fopen("stud.dat","r");
	if (fp==NULL)
	{
		printf("Unable to open the file \n");
	}
	else
	{
		system("color 47");
		printf("%45s","Student Records\n");
		printf("%45s","===============\n");
		for(i=1;i<=75;printf("="),i++);
		printf("\n");
		printf("%15s  %25s  %20s\n","Roll no","Name","Age");
		for(i=1;i<=75;printf("="),i++);
		printf("\n");
		while((fscanf(fp,"%d %s %d",&roll,name,&age))!=EOF)
		{
			printf("%15d  %25s  %20d\n",roll,name,age);
		}
		for(i=1;i<=75;printf("="),i++);
		printf("\n");
	}
	fclose(fp);
}
void search_roll()
{
	FILE *fp;
	int roll,age,tr,z=0,i;
	char name[20];
	z=0;
	printf("%45s","Searching Of Student Record\n");
	printf("%45s","===========================\n");
	printf("\n\n\n\nEnter the roll number of the record to search ");
	scanf("%d",&tr);
	fp=fopen("stud.dat","r");
	if (fp==NULL)
	{
		printf("Unable to open the file \n");
		return;
	}
		system("color 47");
		printf("%45s","Student Records\n");
		printf("%45s","===============\n");
		for(i=1;i<=75;printf("="),i++);
		printf("\n");
		printf("%15s  %25s  %20s\n","Roll no","Name","Age");
		for(i=1;i<=75;printf("="),i++);
		printf("\n");
	while((fscanf(fp,"%d %s %d",&roll,name,&age))!=EOF)
	{
		if (tr==roll)
		{
			z=1;
			printf("%15d  %25s  %20d\n",roll,name,age);
			//break;
		}
	}
	for(i=1;i<=75;printf("="),i++);
		printf("\n");
	fclose(fp);
	if (z==0)
	printf("Record is not present\n");
}

void search_name()
{
	FILE *fp;
	int roll,age,z=0,i;
	char name[20],tn[20];
	z=0;
	printf("%45s","Searching Of Student Record\n");
	printf("%45s","===========================\n");
	printf("\n\n\n\nEnter the name  to search ");
	scanf("%s",tn);
	strupr(tn);
	fp=fopen("stud.dat","r");
	if (fp==NULL)
	{
		printf("Unable to open the file \n");
		return;
	}
	system("color 47");
		printf("%45s","Student Records\n");
		printf("%45s","===============\n");
		for(i=1;i<=75;printf("="),i++);
		printf("\n");
		printf("%15s  %25s  %20s\n","Roll no","Name","Age");
		for(i=1;i<=75;printf("="),i++);
		printf("\n");
	while((fscanf(fp,"%d %s %d",&roll,name,&age))!=EOF)
	{
		if (strcmpi(tn,name)==0)
		{
			z=1;
			printf("%15d  %25s  %20d\n",roll,name,age);
		}
	}
	for(i=1;i<=75;printf("="),i++);
		printf("\n");
	fclose(fp);
	if (z==0)
	printf("Record is not present\n");
}
void delete_rec()
{
	FILE *fp,*tfp;
	int roll,age,tr,z=0,i;
	char name[20];
	printf("%45s","Deletion Of Student Record\n");
	printf("%45s","===========================\n");
	printf("\n\n\n\nEnter the roll number of the record to delete ");
	scanf("%d",&tr);
	fp=fopen("stud.dat","r");
	tfp=fopen("temp","w");
	if (fp==NULL)
	{
		printf("Unable to open the file \n");
		return;
	}
	system("color 47");
		printf("%45s","Student Records\n");
		printf("%45s","===============\n");
		for(i=1;i<=75;printf("="),i++);
		printf("\n");
		printf("%15s  %25s  %20s\n","Roll no","Name","Age");
		for(i=1;i<=75;printf("="),i++);
		printf("\n");
	while((fscanf(fp,"%d %s %d",&roll,name,&age))!=EOF)
	{
		if (tr==roll)
		{
			z=1;
			printf("%15d  %25s  %20d\n",roll,name,age);
		}
		else
		fprintf(tfp,"%d %s %d\n",roll,name,age);
	}
	fclose(fp);
	fclose(tfp);
	if (z==0)
	printf("Record is not present\n");
	else
	{
		for(i=1;i<=75;printf("="),i++);
		printf("\n");
		remove("stud.dat");//stdio.h
		rename("temp","stud.dat"); //stdio.h
	}
}
void modify_rec()
{
	FILE *fp,*tfp;
	int roll,age,tr,z=0,i;
	char name[20];
	printf("%45s","Modification Of Student Record\n");
	printf("%45s","==============================\n");
	printf("\n\n\n\nEnter the roll number of the record to modify ");
	scanf("%d",&tr);
	fp=fopen("stud.dat","r");
	tfp=fopen("temp","w");
	if (fp==NULL)
	{
		printf("Unable to open the file \n");
		return;
	}
	system("color 47");
		printf("%45s","Student Records\n");
		printf("%45s","===============\n");
		for(i=1;i<=75;printf("="),i++);
		printf("\n");
		printf("%15s  %25s  %20s\n","Roll no","Name","Age");
		for(i=1;i<=75;printf("="),i++);
		printf("\n");
	while((fscanf(fp,"%d %s %d",&roll,name,&age))!=EOF)
	{
		if (tr==roll)
		{
			z=1;
			printf("\n Old details are \n");
			printf("%d  \t %s  \t %d\n",roll,name,age);
			printf("Enter New details\n");
			printf("Enter the roll number ");
			scanf("%d",&roll);
			printf("Enter the name ");
			fflush(stdin);
			scanf("%s",name);
			strupr(name);
			printf("Enter the age ");
			scanf("%d",&age);
		}
		fprintf(tfp,"%d %s %d\n",roll,name,age);
	}
	fclose(fp);
	fclose(tfp);
	if (z==0)
	printf("Record is not present\n");
	else
	{
		for(i=1;i<=75;printf("="),i++);
		printf("\n");
		remove("stud.dat");
		rename("temp","stud.dat");
	}
}
void menu()
{
	printf("%45s","Student Management System\n");
		printf("%50s","************\n");
		//for(i=1;i<=75;printf("="),i++);
		printf("\n");
		printf("                      Main Menu \n");
		printf("                     ===========\n");
		printf("                    1. Add a record \n");
		printf("                    2. Display all the records\n");
		printf("                    3. Search a record by roll number  \n");
		printf("                    4. search by name \n");
		printf("                    5. delete a record \n");
		printf("                    6. modify a record\n");
		printf("                    7. Exit \n");
		printf("                    Enter your choice ");
}
int main()
{
	//FILE *fp,*tfp;
	//int roll,age,op=0,tr,z=0,i;
	//char name[20],tn[20];
	int op=0;
	while(op!=7)
	{
		system("cls");
		system("color 4E");//FOR BG AND FG
		menu();
		scanf("%d",&op);
		system("cls");
		switch(op)
		{
			case 1:
				add_record();
				break;
			case 2:
				display_all();
				break;
			case 3:
				search_roll();
				break;
			case 4:
				search_name();
				break;
			case 5:
				delete_rec();
				break;
			case 6:
				modify_rec();
				break;
			case 7:
				printf("End of the program\n");
				break;
			default:
				printf("Invalid option \n");
				break;
		}
	getch();
	}
return(0);
}
