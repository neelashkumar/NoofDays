#include<iostream>
using namespace std;
class date
{
    int day,month,year,nd=0,nw=0;

public:
    void getdate();
    int valid(date);
    void diffdate(date,date);
    void cal(int,int);
    void cal(int,int,int);
    void pcal(int,int,int);
    void display();
    string day_in_the_week(int,int,int);
};
string date::day_in_the_week(int day,int month, int year)
{
    int oddDays,presentYear=year;
    oddDays=day%7;
    switch(month)
    {
        case 1:oddDays+=0;break;
        case 2:oddDays+=3;break;
        case 3:oddDays+=3;break;
        case 4:oddDays+=6;break;
        case 5:oddDays+=1;break;
        case 6:oddDays+=4;break;
        case 7:oddDays+=6;break;
        case 8:oddDays+=2;break;
        case 9:oddDays+=5;break;
        case 10:oddDays+=0;break;
        case 11:oddDays+=3;break;
        case 12:oddDays+=5;break;
    }
    if(year>=1800 && year<=1899)
    {
        oddDays+=2;
        year=year-1800;
    }
    else if(year>=1900 && year<=1999)
    {
        oddDays+=0;
        year=year-1900;
    }
    else if(year>=2000 && year<=2099)
    {
        oddDays+=6;
        year=year-2000;
    }
    int countOdd=year+(year/4);
    oddDays+=(countOdd%7);
    if(presentYear%4==0){
        oddDays=oddDays-1;
    }
    else{
        oddDays=oddDays;
    }
    oddDays=oddDays%7;
    switch(oddDays)
    {
        case 0:return "Sunday";break;
        case 1:return "Monday";break;
        case 2:return "Tuesday";break;
        case 3:return "Wednesday";break;
        case 4:return "Thursday";break;
        case 5:return "Friday";break;
        case 6:return "Saturday";break;
    }
}
void date::getdate()
{
    cout<<"\nEnter the day in 2 digit\t";
    cin>>day;
    cout<<"\nEnter the month in 2 digits\t";
    cin>>month;
    cout<<"\nEnter the year in 4 digits\t";
    cin>>year;
}
int date::valid(date d2)
{
    int p=0;
    if((d2.day<=31)&&(d2.month<=12)&&(d2.year>0)&&(d2.year<=9999)&&(d2.day>0)&&(d2.month>0))
    {
         if(((d2.year%4==0)&&(d2.month==2)&&(d2.day<=29))||((d2.month==1)&&(d2.day<=31))||((d2.month==3)&&(d2.day<=31))||((d2.month==4)&&(d2.day<=30))||((d2.month==5)&&(d2.day<=31))||((d2.month==6)&&(d2.day<=30))||((d2.month==7)&&(d2.day<=31))||((d2.month==8)&&(d2.day<=31))||((d2.month==9)&&(d2.day<=30))||((d2.month==10)&&(d2.day<=31))||((d2.month==11)&&(d2.day<=30))||((d2.month==12)&&(d2.day<=31)))
           {
                p=1;
            }
         else if((d2.month==2)&&(d2.day<=28))
            p=1;
            else if((d2.month%4!=0)&&(d2.month==2)&&(d2.day==29))
                p=0;

    }
    else
    {
        p=0;
    }
    if(p==0)
    {
        cout<<"\nThe entered date is not valid";
        return p;
    }
    else
    {
        cout<<"\nThe entered date is  valid";
        return p;
    }
}
void date::diffdate(date d1,date d2)
{
    int j,k=0;
    year=d2.year-d1.year;
    month=d2.month-d1.month;
    day=d2.day-d1.day;
    if(month<0)
        month=-1*month;
    if(day<0)
        day=-1*day;
    if(year>=0)
    {
        if(d1.year!=d2.year)
        {
            nd=(year-1)*365;
            for(int i=d1.year+1;i<d2.year;i++)
            {
                if((i%4)==0)
                    nd++;
            }
        }
        if(d1.year==d2.year)
        {
                for(int i=d1.month+1;i<d2.month;i++)
                {
                    j=d1.year;
                    cal(i,j);
                }
                if(d1.month!=d2.month)
                {
                    cal(d1.day,d1.month,d1.year);
                    pcal(d2.day,d2.month,d1.year);
                }
                else
                {
                    nd=d2.day-d1.day;
                }

        }
        else
        {
            for(int i=d1.month+1;i<=12;i++)
            {
                    j=d1.year;
                    cal(i,j);
            }
            cal(d1.day,d1.month,d1.year);
            for(int i=1;i<d2.month;i++)
            {
                    j=d2.year;
                    cal(i,j);
            }
            pcal(d2.day,d2.month,d2.year);
        }
    }
    d1.display();
    d2.display();
    cout<<"\nThe total number of days is: "<<nd<<" days";
    for(int i=1;i<=nd;i++)
    {
        if(i%7==0)
        {
            k=0;
            nw++;
        }
        ++k;
    }
    cout<<"\nThe total number of weeks is :"<<nw<<" weeks and "<<k-1<<" days";
}
void date::pcal(int k,int i,int j)
{
    if(i==2&&j%4==0)
    {
        nd=nd+k;
    }
    else if(i==2&&j%4!=0)
    {
        nd+=k;
    }
    else if(i==3||i==5||i==7||i==8||i==10||i==12||i==1)
    {
        nd+=k;
    }
    else
    {
        nd+=k;
    }
}
void date::cal(int k,int i,int j)
{
    int temp=0;
    if(i==2&&j%4==0)
    {
        temp=29-k;
        nd=nd+temp;
    }
    else if(i==2&&j%4!=0)
    {
        temp=28-k;
        nd+=temp;;
    }
    else if(i==3||i==5||i==7||i==8||i==10||i==12||i==1)
    {
        temp=31-k;
        nd+=temp;
    }
    else
    {
        temp=30-k;
        nd+=temp;
    }
}
void date::cal(int i,int j)
{
    if(i==2&&j%4==0)
        nd=nd+29;
    else if(i==2&&j%4!=0)
        nd+=28;
    else if(i==3||i==5||i==7||i==8||i==10||i==12||i==1)
        nd+=31;
    else
        nd+=30;
}
void date::display()
{
        cout<<"\nThe date you entered is:"<<day<<"/"<<month<<"/"<<year<<"-"<<day_in_the_week(day,month,year);
}
int main()
{
    date d1,d2,d3;
    int p1=0,p2=0;
    d1.getdate();
    p1=d1.valid(d1);
    d2.getdate();
    p2=d2.valid(d2);
    if(p1==1&&p2==1){
        d3.diffdate(d1,d2);
    }
    return 0;
}

