/*
Example of fprintf() and fscanf()
to maintain student details like roll,name and age
MADE BY SHIVAM SAINI
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	FILE *fp,*tfp;
	int roll,age,op=0,tr,z=0;
	char name[20],tn[20];
	while(op!=7)
	{
		system("cls");
		system("color 4E");
		printf("main Menu \n");
		printf("1. Add a record \n");
		printf("2. Display all the records\n");
		printf("3. Search a record by roll number  \n");
		printf("4. search by name \n");
		printf("5. delete a record \n");
		printf("6. modify a record\n");
		printf("7. Exit \n");
		printf("Enter your choice ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
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
				printf("Enter the roll number ");
				scanf("%d",&roll);
				printf("Enter the name ");
				fflush(stdin);
				scanf("%s",name);
				strupr(name);
				printf("Enter the age ");
				scanf("%d",&age);
				fprintf(fp,"%d %s %d\n",roll,name,age);
				fclose(fp);
				break;
			case 2:
				fp=fopen("stud.dat","r");
				if (fp==NULL)
				{
					printf("Unable to open the file \n");
				}
				else
				{
					printf("roll  \t  name \t age \n");
					while((fscanf(fp,"%d %s %d",&roll,name,&age))!=EOF)
					{
						printf("%d  \t %s  \t %d\n",roll,name,age);
					}
				}
				fclose(fp);
				break;
			case 3:
				z=0;
				printf("Enter the roll number of the record to search ");
				scanf("%d",&tr);
				fp=fopen("stud.dat","r");
				if (fp==NULL)
				{
					printf("Unable to open the file \n");
					break;
				}
				printf("roll  \t  name \t age \n");
				while((fscanf(fp,"%d %s %d",&roll,name,&age))!=EOF)
				{
					if (tr==roll)
					{
						z=1;
						printf("%d  \t %s  \t %d\n",roll,name,age);
						//break;
					}
				}
				fclose(fp);
				if (z==0)
				printf("Record is not present\n");
				break;
			case 4:
				z=0;
				printf("Enter the name  to search ");
				scanf("%s",tn);
				strupr(tn);
				fp=fopen("stud.dat","r");
				if (fp==NULL)
				{
					printf("Unable to open the file \n");
					break;
				}
				printf("roll  \t  name \t age \n");
				while((fscanf(fp,"%d %s %d",&roll,name,&age))!=EOF)
				{
					if (strcmpi(tn,name)==0)
					{
						z=1;
						printf("%d  \t %s  \t %d\n",roll,name,age);
					}
				}
				fclose(fp);
				if (z==0)
				printf("Record is not present\n");
				break;
			case 5:
				z=0;
				printf("Enter the roll number of the record to delete ");
				scanf("%d",&tr);
				fp=fopen("stud.dat","r");
				tfp=fopen("temp","w");
				if (fp==NULL)
				{
					printf("Unable to open the file \n");
					break;
				}
				printf("roll  \t  name \t age \n");
				while((fscanf(fp,"%d %s %d",&roll,name,&age))!=EOF)
				{
					if (tr==roll)
					{				
						z=1;
						printf("%d  \t %s  \t %d\n",roll,name,age);
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
					remove("stud.dat");
					rename("temp","stud.dat");
				}
				break;
			case 6:
				z=0;
				printf("Enter the roll number of the record to modify ");
				scanf("%d",&tr);
				fp=fopen("stud.dat","r");
				tfp=fopen("temp","w");
				if (fp==NULL)
				{
					printf("Unable to open the file \n");
					break;
				}
				printf("roll  \t  name \t age \n");
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
					remove("stud.dat");
					rename("temp","stud.dat");
				}
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
