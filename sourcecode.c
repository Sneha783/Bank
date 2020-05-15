# Bank
Banking project in C
#include<stdio.h>
#include<unistd.h>
#include<string.h>
struct date
{
int d;
int m;
int y;
};
struct at
{
int atn;
int bal;
int pass;
};
struct user 
{
int id;
char name[20];
struct date dob;
struct at atm;
};

////////////////////////////////////////////////////////
void opacc();
void atm();
void atmac(int );
void print();
static int tp,gid=1000,at=5000,f=0;
struct user a[20];
// a.atm.bal=0;
//////////////////////////////////////////////////////////
main()
{
	int m,k,op,c=0,t;
	char ch;
l:c++;
  system("clear");

  printf("\n\n\t\t*********Welcome to Virtual Banking**********\n\n");
  printf("\t\t\t\tMAIN MENU\n\n\t\t\t1)Open Account\n\t\t\t2)ATM\n\t\t\t3)Display\n\t\t\t4)Exit\n");
  printf("\n\t\t***********************************************\n\n\t\t\tEnter option :");
  scanf("%d",&op);
  switch(op)
  {
	  case 1:opacc();
		 break;
	  case 2:atm();
		 //goto l;
		 break;
	  case 3:print();
		 break;
	  case 4:goto t;
		 break;
	  default:printf("Unknown option \nPlease enter valied option.....\n");
		  if(c<3)
			  goto l;
  }
  ////////////////////////////////////////////////
l2:m++;
   printf("____________________________________________\n\n\n");
   printf("Want to go in main menu??(y/n)   :  ");
   scanf(" %c",&ch);
   switch(ch)
   {
	   case 'y':goto l;
		    break;
	   case 'n':goto t;
	   default:printf("Please enter only 'y' or 'n'\n");
		   if(m<2)
			   goto l2;
   }         
t:
   system("clear");
   printf("\n\n\n\n\t\t\t\t****Thank you Visit Again*****\n\n\n\n\n\t\t\t\t\t\t\t\t\t@sneha_shinde\n\n\n\n");
}
/////////////////////////////////////////////////////////////////////////
void opacc()
{
	int x;
	char ch;
	system("clear");
	printf("\n\n\t\t\tYour Bank id : %d",gid);
	a[f].id=gid;
	printf("\n\n\t\t\tEnter name: ");
	scanf("%s",a[f].name);
	printf("\n");

	//-------DOB------------
	printf("\t\t\tEnter DOB : ");
	scanf("%d%d%d",&a[f].dob.d,&a[f].dob.m,&a[f].dob.y);
	printf("\n\n\t\t\twant ATM service? (y/n) \n");
	scanf(" %c",&ch);
	system("clear");
	printf("\n------- ATM service---------\n"); 
	switch(ch)
	{
		case 'y': system("clear");
			  a[f].atm.atn=at;
			  printf("\t\t_____________________________________________\n");
			  printf("\n\n\t\t\t\tWelcome %s \n\n",a[f].name);
			  printf("\n\n\n\t\tYour ATM no.=%d\n\n",a[f].atm.atn);
			  printf("\t\tNote : Remember your ATM no'\n\n");
			  printf("\n\t\tCreate password.....\n\n\t\tNote : password must be 4 bits\n\t\tIt must be Digit\n\n\t\t\t");
			  printf("Enter Password: ");
			  scanf("%d",&a[f].atm.pass);
			  printf("\n\n\t\t\t\tWait\t");

			  for(x=0;x<3;x++)
			  {
				  printf(".");
				  sleep(1);
				  fflush(stdout);
			  }
			  printf("\n\t\t\tPassword created successfully.....\n\n\n\t\t");
			  break;
		case 'n':break;
	}
	++f;
	gid=gid+4;
	at=at+4;
}
//////////////////////////////////////////////////////////////////////////
void atm()
{
	static c;
	int m,n=0,s;
	system("clear");
	printf("\n\t\t\t---------ATM service------------\n");
k3:n++;
   printf("\n\tEnter ATM no. :");
scanf("%d",&m);
printf("\n\tEnter Password : ");
scanf("%d",&s);
printf("\n\t--------------------------------------\n");
//--------------------------------------------
for(c=0;c<f;c++)//////
{
if((m==a[c].atm.atn) && (s==a[c].atm.pass))
{
atmac(c);
return;
} 
}

if((m!=a[c].atm.atn) || (s!=a[c].atm.pass))
{
printf("\n\n\t\tInvalied ATM no. or password\n");
if(n<2)
goto k3;
}
}

////////////////////////////////////////////////////////////
void atmac(int c)
{
system("clear");
a[c].atm.bal=0;
char ch2,b,e;
int m1,m2,i,k1=0,s2=0,y;
k7:s2++;
   k1++;
system("clear");
printf("\n\t\t\t-------------------------------------------------------------\n");
printf("\n\t\t\t------------Menu-------------\n\n\t\t\t1)Balance inquiry\n\t\t\t2)Withdraw\n\t\t\t3)Add amount\n\t\t\t4)Logout\n");
printf("\n\t\t\t-------------------------------------------------------------\n");
printf("\n\t\tEnter option : ");
scanf("%d",&m1);
switch(m1)
{      
case 1: system("clear");
	printf("\n\n\n\n\nYour Account Balance \n\n\n");
        printf("Rs %d\n",a[c].atm.bal); 
        break;  
case 2:system("clear");
       printf("\n\n\n\n\t\t\t\tEnter amount = ");
       scanf("%d",&i);
       if(a[c].atm.bal<i)
       {
	printf("\n\t\t\t\t\tLow Balance\n");
     //    if(k1<2);
            goto kl1;
	}
       a[c].atm.bal=a[c].atm.bal-i;
       break;
case 3:system("clear");
       printf("\n\n\n\n\n\n\t\t\t\t\tEnter Amount: ");
       scanf("%d",&m2);
       a[c].atm.bal=a[c].atm.bal+m2;
       break;
case 4:return;
default:printf("Enter valied option\n");
        if(s2<2) 
       goto k7;                 
}
printf("\n\n");
kl1:
printf("\t\tback/exit (press b/e) : ");
scanf(" %c",&ch2);
if(ch2=='b')
goto k7;
else if(ch2=='e')
return;
//return;
else 
{
printf("\n\t\t\tWarning.......press only b or e \n\n");
goto kl1; 
} 
}
//////////////////////////////////////////////////////////////////////////////////
void print()
{
int wr,srn;
char *pss,my_pass[9],m_p[8],adid[10];
system("clear");
printf("\n\t\t\t\t\t\t\t-----@ Virtula Bank------\n");
printf("\tDate : %s\n",__DATE__);
printf("\tTime : %s",__TIME__);
printf("\n\n\n\t\t\t\tAdmin ID : ");
scanf("%s",adid);
pss=getpass("\n\t\t\t\tPassword : ");
strcpy(m_p,pss);
my_pass[9]="sneha31";

if(strstr(my_pass,m_p)!=0)
{
printf("\n\n\t\t\t\t----All Details of Account Holders-------\n\n");
printf("______________________________________________________________________________\n");
printf("No.\tBank ID\t\t ATM no.\tName\t  DOB\t\t    Avl. bal.\n"); 
printf("______________________________________________________________________________\n");
for(srn=1,wr=0;wr<f;wr++,srn++)
{
printf("%d \t %d\t\t  %d \t\t%s\t %d/%d/%d\t  %d \n",srn,a[wr].id,a[wr].atm.atn,a[wr].name,a[wr].dob.d,a[wr].dob.m,a[wr].dob.y,a[wr].atm.bal);
printf("______________________________________________________________________________\n");
////////////////printf("\n\nYour Account created successfully.......\n");////////////////////
}
}
}
