#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define max1 50 
#define max2 100
struct vehicles
{
	time_t t1,t2;
	char *dt_time1;
	char *dt_time2;
	char name[20];
	char intime[25];
	char num_pt[15];
	int toc;
}car[max1],bike[max2];
int calamt(int t)
{
	int hr,min;float amt;
	hr=t/60;
	min=t%60;
	if(hr>3 ||(hr==3 && min>0))
	{
		hr=hr-3;
		hr=hr*60;
		min=min+hr;
		min=(min)/10;
		amt=30+(min*2);
	}
	else
		amt=30;
	return(amt);
}
void bill(char c,int x,float a)
{
	if(c==1)
	{
		printf("\n       BILL");
		printf("\nNAME          : %s",car[x].name);
		printf("\nCAR NUMBER    : %s",car[x].num_pt);
		printf("\nINCOMING TIME : %s",car[x].intime);
		printf("\nOUTGOING TIME : %s",car[x].dt_time2);
		printf("\nTOTAL AMOUNT  : %f",a);
	}
	else
	{
		printf("\n       BILL");
		printf("\nNAME          : %s",bike[x].name);
		printf("\nBIKE NUMBER   : %s",bike[x].num_pt);
		printf("\nINCOMING TIME : %s",bike[x].intime);
		printf("\nOUTGOING TIME : %s",bike[x].dt_time2);
		printf("\nTOTAL AMOUNT  : %f",a);
	}
	printf("\n\nTHANK YOU FOR VISITING :)");
}
int criminal(char *c)
{

	FILE* fp;
	fp=fopen("num.txt","r");
	while(!feof(fp))
	{
		char* d=(char *)calloc(11,1);
		fgets(d,12,fp);
		if(strncmp(c,d,10)==0)
			return 0;
		else return 1;
	}
	fclose(fp);

}
void incoming(int x)
{

	int ch;
	do
	{
	if(x==1)
	{
		for(int i=0;i<max1;i++)
		{
			if(car[i].toc==0)
			{
				car[i].t1=time(NULL);
				//car[i].dt_time1=(char *)calloc(25,1);
				car[i].dt_time1=ctime(&car[i].t1);
				time(&car[i].t1);
				printf("\nCURRENT TIME IS:%s",car[i].dt_time1);
				printf("\nEnter the above format with replacing  spaces with underscore");
				scanf("%s",&car[i].intime);
				printf("\nEnter name vehicle owner:");
				scanf("%s",&car[i].name);
				printf("\nEnter vehicle number:");
				scanf("%s",&car[i].num_pt);
				if(criminal(car[i].num_pt)==0)
				{
					printf("\nREJECTED");
					break;
				}
				else
				{
					printf("\nTocken number: C%d",i);
					car[i].toc=1;
					break;
				}
			}
		}
	}
	else if(x==2)
	{
		for(int i=0;i<max2;i++)
		{
			if(bike[i].toc==0)
			{
				bike[i].t1=time(NULL);
				//bike[i].dt_time1=(char *)calloc(25,1);
				bike[i].dt_time1=ctime(&bike[i].t1);
				time(&bike[i].t1);
				printf("\nCURRENT TIME IS:%s",bike[i].dt_time1);
				printf("\nEnter the above format with replacing spaces with underscore");
				scanf("%s",&bike[i].intime);
				printf("\nEnter name of vehicle owner:");
				scanf("%s",&bike[i].name);
				printf("\nEnter vehicle number:");
				scanf("%s",&bike[i].num_pt);
				if(criminal(bike[i].num_pt)==0)
				{
					printf("\nREJECTED");
					break;
				}
				else
				{
					printf("\nTocken number: B%d",i);
					bike[i].toc=1;
					break;
				}
			}
		}
	}
	else
		printf("\nINVALIDE INPUT");
	printf("\nEnter 1 to continue or 0 to exit with incoming process:");
	scanf("%d",&ch);
	}while(ch!=0);

}
void outgoing(int v)
{
	int n,ch;
	do
	{
	printf("\nEnter the number on the tocken :");
	scanf("%d",&n);
	switch(v)
	{
	case 1:if(car[n].toc!=1)
	       {
		       printf("THIS PARKING SLOT IS EMPTY");
		       break;
	       }
	       else
		{
			car[n].t2=time(NULL);
			car[n].dt_time2=ctime(&car[n].t2);
			int b;float am;
			b=difftime(car[n].t2,car[n].t1);
			am=calamt(b);
			bill(v,n,am);
			car[n].toc=0;
		
		}
		break;
	case 2: if(bike[n].toc!=1)
		{
			printf("THIS PARKING SLOT IS EMPTY");
			break;
		}
		else
		{
			bike[n].t2=time(NULL);
			bike[n].dt_time2=ctime(&bike[n].t2);
			int b;float am;
			b=difftime(bike[n].t2,bike[n].t1);
			am=calamt(b);
			bill(v,n,am);
			bike[n].toc=0;
		}
		break;

	}
		printf("\nEnter 1 to continue or 0 to exit the outgoing process:");
		scanf("%d",&ch);
	}while(ch!=0);
}
int main()
{
	int vh,ch,c;
	do
	{
	printf("\n\t\tMENU\nENTER\n1 for car\n2 for bike");
	scanf("%d",&vh);
	printf("\nENTER\n1 for incoming\n2 for outgoing");
	scanf("%d",&ch); 
printf("\n0 represents empty slots ");
	if(vh==1&&ch==1)
	{
		printf("\nEmpty slots for cars");
		for(int i=0;i<max1;i++)
		{
			if(car[i].toc!=1)
			printf("\t0");
			else
				printf("\t1");
		}
	}
	if(vh==2&&ch==1)
	{
		printf("\nEmpty slots for bikes");
		for(int i=0;i<max2;i++)
		{
			if(bike[i].toc!=1)
				printf("\t0");
			else
				printf("\t1");
		}
	}
switch(ch)
	{
		case 1:incoming(vh);
		       break;
		case 2:outgoing(vh);
		       break;
	}
	printf("\nENTER 1 TO CONTINUE OR 0 TO EXIT THE MENU");
	scanf("%d",&c);
	}while(c!=0);
}

