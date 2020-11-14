#include<stdio.h>
struct subject{
int slno;
char course_code[30];
char course[100];
int num;
int credit_ass;
int credit_earn;
char letter_grade;
int grade_points;
}s1[5];
void grade(int num,int n);
void credits(int num,int n);
void points(int num,int n);
void total_credit();
int total_credits_earned=0, total_summation=0;
float sgpa=0,cgpa=0,a,b,c;
main()
{
    int i;
    char name[50],f_name[50];
    char USN[30];
    printf("enter the name:\n");
    gets(name);
    printf("enter father/mother name:\n");
    gets(f_name);
    printf("enter the USN:\n");
    gets(USN);
    printf("enter previous semester sgpa\n");
    scanf("%f%f%f",&a,&b,&c);
    for(i=0;i<4;i++)
    {
	printf("enter the serial no:\n");
	scanf("%d",&s1[i].slno);
	printf("enter the course code:\n");
	scanf("%s",s1[i].course_code);
	printf("enter the subject name:\n");
	scanf("%s",s1[i].course);
	printf("enter the marks:\n");
	scanf("%d",&s1[i].num);
    }
    for(i=0;i<4;i++)
    {
	grade(s1[i].num,i);
	credits(s1[i].num,i);
	points(s1[i].num,i);
    }
    total_credit();
    printf("\t\t\t VISVESHVARAYA TECHNOLOGICAL UNIVERSITY,BELAGAVI\t\t\n");
    printf("\t\t\t\t\tEXTRACT OF GRADE CARD\t\n");
    printf("\t\t\tBE-Computer Science & Engineering-July_2020\n");
    printf("Name of the student:%s\t\t\t\t\t\tUSN:%s\n",name,USN);
    printf("Father/Mother name:%s\n",f_name);
    printf("Name of the college:BALLARI INSTITUTE OF TECHNOLOGY AND MANAGEMENT\n\n");
    printf("slno CourseCode CourseApplied \tcredits    credits  letter  gradepoint \n");
    printf("                               assigned     earned  grade\n");
    for(i=0;i<4;i++)
    {
	printf("%d\t%s\t%s\t\t4\t\t%d\t%c\t  %d\t\n",s1[i].slno,s1[i].course_code,s1[i].course,s1[i].credit_earn,s1[i].letter_grade,s1[i].grade_points);
	printf("\n");
    }
    printf("\nCredits\t\t Credits\t Cumulative\t\tSum(ci*gi)\t SGPA      CGPA\n");
    printf("registered    \tearned\t credit earned\n");
    printf(" 16\t        %d\t      40\t\t          %d\t        %f    %f",total_credits_earned,total_summation,sgpa,cgpa);
}
void grade(int num,int n)
{
	if(num>=90&&num<=100)
	{
	    s1[n].letter_grade='O';
	}

	else if(num>=80&&num<90)
	{
	    s1[n].letter_grade='S';
	}
	else if(num>=70&&num<80)
	{
	    s1[n].letter_grade='A';
	}
	else if(num>=60&&num<70)
	{
	    s1[n].letter_grade='B';
	}
	else if(num>=50&&num<60)
	{
	    s1[n].letter_grade='C';
	}
	else if(num>=45&&num<50)
	{
	    s1[n].letter_grade='D';
	}
	else if(num>=40&&num<45)
	{
	    s1[n].letter_grade='E';
	}
	else
	{
	    s1[n].letter_grade='F';
	}
}
void credits(int num,int n)
{
	if(num>=28&&num<=100)
	    s1[n].credit_earn=4;
	else
	    s1[n].credit_earn=0;
}
void points(int num,int n)
{
	if(num>=90&&num<=100)
	    s1[n].grade_points=10;
	else if(num>=80&&num<90)
	    s1[n].grade_points=9;
	else if(num>=70&&num<80)
	    s1[n].grade_points=8;
	else if(num>=60&&num<70)
	    s1[n].grade_points=7;
	else if(num>=50&&num<60)
	    s1[n].grade_points=6;
	else if(num>=45&&num<50)
	    s1[n].grade_points=5;
	else if(num>=40&&num<45)
	    s1[n].grade_points=4;
	else
	    s1[n].grade_points=0;
}
void total_credit()
{
	for(int i=0;i<4;i++)
	{
	if(s1[i].num>=0&&s1[i].num<=100)
		{
			total_credits_earned=total_credits_earned+s1[i].credit_earn;
			total_summation=total_summation+(s1[i].credit_earn*s1[i].grade_points);
		}
	}
	sgpa=total_summation/(float)16;
	cgpa=(a+b+c+sgpa)/(float)4;
}
