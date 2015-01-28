#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int Conversion(char num[20], int t, int n)
{
 int i,ii,j,k,m,x,b[30],h[30],c;
 double d,r;
 ii = 0;
 p = 0;                /*每次调用函数时，先将用于存储转换结果的全局变量p清零*/
 memset (out, 0, 20);  /*将用于存储转换结果的全局变量数组out清零*/
 m = strlen(num);      /*求字符串的长度*/
 x= m;
 for(k = 0, j = 0; k < m; k ++)  /*对字符串进行分段， 以小数点为界限，分为整数部分和小数部分*/
 {
  if(num[k] == '.')
  {
  x = k;
  break;
  }
 }       /*x表示小数点所在的位置*/
 for(j = x - 1;j >= 0; j --)
 {
 if(num[j] == '-') break; /*符号的处理*/
 if(num[j] == 'A') r = 10;
 else if (num[j] == 'B')
   r = 11;
 else if (num[j] == 'C')
   r = 12;
 else if (num[j] == 'D')
   r = 13;
 else if (num[j] == 'E')
   r = 14;
  else if (num[j] == 'F')
   r = 15;
 else
  r = num[j] - '0';   /*将字符1，2，3等转换为数字*/
 p = p + r*(pow ((double)t,(double)(x-j-1))); /*计算结果，整数部分，t表示位权,x-j-1,表示位阶*/
 }
if(num[x] == '.')      /*小数部分的转换*/
{
 for(j = x + 1; j < m; j ++)
 {
 if(num[j] == 'A') r = 10;
 else if(num[j] == 'B')
   r = 11;
 else if(num[j] == 'C')
   r = 12;
 else if(num[j] == 'D')
   r = 13;
 else if(num[j] == 'E')
   r = 14;
  else if(num[j] == 'F')
   r = 15;
 else
  r = num[j] - '0';            /*将字符转换为数字*/
 p = p + r*(pow ((double)t, (double) (x - j))); /*小数部分的转换*/
 }
}

if (n == 10) /*如果要转换成十进制*/
{
 if(num[0] == '-') /*如果字符串前面有负号，则树脂取反，使其变为负数*/
 {
 p = -p;
 }
 return 0;
}              /*程序返回*/

else /*如果要转换成其他进制，如十六进制、八进制、二进制中*/
{
 k = (int)p;
 i = 0;
 while(k) /*判定需要转换的数是否变为0*/
 {
 h[i ++] = k%n; /*取余，进行进制转换，但是存储的顺序与正确值相反*/
 k/=n;          /*转换一位之后进行相应的变化，即k值减少了一位*/
 }
if(p!=(int)p) /*选择性计算， 如果是正整数就不用进行这一步的计算了*/
{
 d = p - (int)p;   /*取小数部分*/
 while(d!=0)
 {
 b[c] = (int) (d*n); /*算法为*N取整*/
 d = d*n-b[c];
 c ++;
 if(c>=10)
   break;    /*主要是控制小数后面出现无限循环计算， 跳出循环以免出现死循环*/
 }
}
if(num[0] == '-') /*负数的情况*/
{
 out[0] = '-';
 ii++;
}
for(j = i - 1;j >= 0;j --, ii ++)  /*反序输出，大于10的数字进行相应的变化*/
{
 if(h[j] == 10) out[ii] = 'A';
 else if(h[j] == 11) out[ii] = 'B';
 else if(h[j] == 12) out[ii] = 'C';
 else if(h[j] == 13) out[ii] = 'D';
 else if(h[j] == 14) out[ii] = 'E';
 else if(h[j] == 15) out[ii] = 'F';
 else if(h[j] == 9)  out[ii] = '9';
 else if(h[j] == 8)  out[ii] = '8';
 else if(h[j] == 7)  out[ii] = '7';
 else if(h[j] == 6)  out[ii] = '6';
 else if(h[j] == 5)  out[ii] = '5';
 else if(h[j] == 4)  out[ii] = '4';
 else if(h[j] == 3)  out[ii] = '3';
 else if(h[j] == 2)  out[ii] = '2';
 else if(h[j] == 1)  out[ii] = '1';
 else out[ii] = '0';
 }
if(p!=(int)p)     /*选择性输出,这样可以节约输出时间和程序的运行时间*/
{
 out[ii++] = '.';
 for(j = 0;j < c;j ++)  /*小数部分转换后的结果正序存储在全局字符数组变量out中*/
 {
 if(b[j] == 10) out[ii] = 'A';
 else if(b[j] == 11) out[ii] = 'B';
 else if(b[j] == 12) out[ii] = 'C';
 else if(b[j] == 13) out[ii] = 'D';
 else if(b[j] == 14) out[ii] = 'E';
 else if(b[j] == 15) out[ii] = 'F';
 else if(b[j] == 9)  out[ii] = '9';
 else if(b[j] == 8)  out[ii] = '8';
 else if(b[j] == 7)  out[ii] = '7';
 else if(b[j] == 6)  out[ii] = '6';
 else if(b[j] == 5)  out[ii] = '5';
 else if(b[j] == 4)  out[ii] = '4';
 else if(b[j] == 3)  out[ii] = '3';
 else if(b[j] == 2)  out[ii] = '2';
 else if(b[j] == 1)  out[ii] = '1';
 else out[ii] = '0';
 ii ++;
 }
}
return 0;  /*程序返回*/
}
}
 
