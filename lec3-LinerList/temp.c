#include<stdio.h>//考虑闰年 
int main()
{
 int y,mon,d,h,min;
 int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};//从0到11
 int n;
 scanf("%d",&n);
 while(n--)
 {
  scanf("%d.%d.%d %d:%d",&y,&mon,&d,&h,&min);
  while(min>=60)
  {
   min-=60;
   h++;
  }
  if(h>=24) 
  {
   d+=h/24;
   h%=24; 
  }
  if((mon>12)&&(mon%12!=0))
  {
   y+=mon/12;
   mon%=12;
  }
  else if(mon%12==0)
  {
   y+=((mon/12)-1);
   mon=12;
  }
  while(d>a[mon-1])//解决闰年的问题 
  {
    printf("*\n");
   if(((0==y%400)||((0==y%4)&&(y%100!=0)))&&(2==mon))//判断是否为闰年闰月 
   {
    if(d>29)
    {
     d-=29;
     mon++;
    } 
    continue;
   }
   d-=a[mon-1];
   mon++;
   if(mon>12)   
   {
    mon-=12;
    y++;
   }
   
  }
  
  printf("%04d.%02d.%02d %02d:%02d\n",y,mon,d,h,min); //最后如果有五位数，输出不用纠结   
  
 }
}