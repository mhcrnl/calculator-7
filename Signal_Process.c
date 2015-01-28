#include <gtk/gtk.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Binary_Operator() /*双目运算*/
{
 char num[20];
 strcpy(num, gtk_entry_get_text(GTK_ENTRY(entry))); /*取得文本框的内容*/
 if(a == 0)                    /*如果没有第一个数，则存储为第一个数*/
 {
 if(principle == 16)
 {
 Conversion (num, 16, 10); /*将输入的十六进制数转换为十进制*/
 a = p;
 }
 if(principle == 10)
 {
 a = atof(num);         /*直接转换成浮点型*/
 }
 if(principle == 8)
 {
 Conversion (num, 8, 10);   /*将输入的八进制数转换为十进制数*/
 a = p;
 }
 if(principle == 2)
 {
 Conversion (num, 2, 10);      /*将输入的二进制数转换为十进制*/
 a = p;
 }
 gtk_entry_set_text(GTK_ENTRY(entry), "");  /*清空文本框*/
 }
 else                          /*如果已有第一个数，则垠存储为第二个数*/
 {
 if(principle == 16)
 {
 Conversion(num, 16, 10);  /*将输入的十六进制数转换为十进制*/
 b = p;
 }
 if(principle == 10)
 {
 b = atof(num);          /*直接转换成浮点型*/
 }
 if(principle == 8)
 {
 Conversion(num, 8, 10);  /*将输入的八进制数转换为十进制*/
 b = p;
 }
 if(principle == 2)
 {
 Conversion(num, 2, 10);  /*将输入的二进制数转换为十进制*/
 b = p;
 }
}
 hasdot = 0;              /*表示已经没有小数点*/
}
void Right_output()
{
 char num[20];
 gcvt(a, 32, num);      /*运算结果转换成字符串*/
 if(principle == 16)
 {
 Conversion(num, 10, 16);  /*将运算结果（十进制字符串）转换成十六进制数*/
 gtk_entry_set_text(GTK_ENTRY(entry), out);   /*显示结果*/
 }
 if(principle == 10)
 {
 gtk_entry_set_text(GTK_ENTRY(entry), num);  /*直接显示结果*/
 }
 if(principle == 8)
 {
 Conversion(num, 10, 8); /*将运算结果（十进制字符串）转换成八进制数*/
 gtk_entry_set_text(GTK_ENTRY(entry), out);     /*显示结果*/
 }
 if(principle == 2)
 {
 Conversion(num, 10, 2); /*将运算结果（十进制字符串）转换成二进制数*/
 gtk_entry_set_text(GTK_ENTRY(entry), out);    /*显示结果*/
 }
 a = 0;
 b = 0;
 method = 0;
 }
 float fun(int c) /*递归函数求阶乘*/
 {
 float d;
 if(c == 0 || c == 1) d = 1;
 else d = fun(c - 1)*c;
 return d;
 }
 void output()
{
 char num[20] = "0";
 strcpy(num, gtk_entry_get_text(GTK_ENTRY(entry))); /*取得文本框输入的内容*/
 if(principle == 16)
 {
 Conversion(num, 16, 10);  /*将输入的十六进制数转换为十进制数*/
 b = p;
 }
 if(principle == 10)
 {
 b = atof(num);             /*直接转换成浮点型*/
 }
 if(principle == 8)
 {
 Conversion(num, 8, 10); /*将输入的八进制数转换为十进制数*/
 b = p;
 }
 if(principle == 2)
 {
 Conversion(num, 2, 10); /*将输入的二进制数转换为十进制数*/
 b = p;
 }
 switch(method)
{
 case 0:
 a = a + b; Right_output (); break;
 case 1:
 a = a - b; Right_output (); break;
 case 2:
 a = a * b; Right_output (); break;
 case 3:
 if(b == 0)
 {
 a = 0; b = 0; method = 0;
     gtk_entry_set_text (GTK_ENTRY(entry),
 g_locale_to_utf8("除数不能为零", -1, NULL, NULL, NULL)); /*显示出错信息*/
 }
 else
 {
 a = a / b;
 Right_output ();
 } break;
 case 4:
 a = pow(a, b); Right_output (); break;
 case 5:
 a = ((int) a) & ((int) b); Right_output (); break;
 case 6:
 a = ((int) a) | ((int) b); Right_output (); break;
 case 7:
 a = ((int) a) ^ ((int) b); Right_output (); break;
 case 8:
 if(b == 0)
   {
  a = 0; b = 0; method = 0;
  gtk_entry_set_text (GTK_ENTRY (entry),
    g_locale_to_utf8("除数不能为零", -1, NULL, NULL, NULL)); /*显示出错信息*/
    }
 else
 {
 a = ((int) a) % ((int) b);
 Right_output ();
 } break;
 case 9:
 a = sin(b); Right_output (); break;
 case 10:
 a = cos(b); Right_output (); break;
 case 11:
 a = tan(b); Right_output (); break;
 case 12:
 a = exp(b); Right_output (); break;
 case 13:
 a = b*b*b; Right_output (); break;
 case 14:
 a = b*b;   Right_output (); break;
 case 15:
 if (b <= 0)
 {
 a = 0; b = 0; method = 0;
 gtk_entry_set_text (GTK_ENTRY(entry),
 g_locale_to_utf8("对数必须为正数", -1, NULL, NULL, NULL)); /*显示出错信息*/
 }
 else
 {
 a = log(b);
    Right_output ();
 } break;
 case 16:
 if (b <= 0)
 {
 a = 0; b = 0; method = 0;
 gtk_entry_set_text (GTK_ENTRY(entry),
 g_locale_to_utf8("对数必须为正数", -1, NULL, NULL, NULL)); /*显示出错信息*/
 }
 else
 {
 a = log10(b);
   Right_output ();
 } break;
 case 17:
 if(b < 0)
 {
 a = 0; b = 0; method = 0;
     gtk_entry_set_text (GTK_ENTRY (entry),
     g_locale_to_utf8("函数输入无效", -1, NULL, NULL, NULL)); /*显示出错信息*/
 }
 else
 {
 a = fun((int) (b));
   Right_output ();
 } break;
 case 18:
 if (b == 0)
 {
 a = 0; b = 0; method = 0;
 gtk_entry_set_text (GTK_ENTRY(entry),
 g_locale_to_utf8("除数不能为零", -1, NULL, NULL, NULL)); /*显示出错信息*/
 }
 else
 {
 a = 1/b;
 Right_output ();
 } break;
 case 19:
 a = ~((int) b); Right_output (); break;
 case 20:
 a = floor(b); Right_output (); break;
 default: break;
 }
}

void Add(GtkWidget *widget, gpointer data) /*加法运算*/
{
 method = 0;
 Binary_Operator ();
}

void Sub(GtkWidget *widget, gpointer data) /*减法运算*/
{
 method = 1;
 Binary_Operator ();
}

void Mul(GtkWidget *widget, gpointer data) /*乘法运算*/
{
 method = 2;
 Binary_Operator ();
}

void Division(GtkWidget *widget, gpointer data) /*除法运算*/
{
 method = 3;
 Binary_Operator ();
}

void Mathpowxy(GtkWidget *widget, gpointer data) /*乘幂运算*/
{
 method = 4;
 Binary_Operator ();
}

void And(GtkWidget *widget, gpointer data) /*逻辑与运算*/
{
 method = 5;
 Binary_Operator ();
}

void Or(GtkWidget *widget, gpointer data) /*逻辑或运算*/
{
 method = 6;
 Binary_Operator ();
}

void Xor(GtkWidget *widget, gpointer data) /*异或运算*/
{
 method = 7;
 Binary_Operator ();
}

void Mod(GtkWidget *widget, gpointer data) /*求模运算*/
{
 method = 8;
 Binary_Operator ();
}

void Sin(GtkWidget *widget, gpointer data) /*求正弦值运算*/
{
 method = 9;
 output ();
}

void Cos(GtkWidget *widget, gpointer data) /*求余弦值运算*/
{
 method = 10;
 output ();
}

void Tan(GtkWidget *widget, gpointer data) /*求正切值运算*/
{
 method = 11;
 output ();
}

void Exp(GtkWidget *widget, gpointer data) /*求指数运算*/
{
 method = 12;
 output ();
}

void Cube(GtkWidget *widget, gpointer data) /*求立方值运算*/
{
 method = 13;
 output ();
}

void Square(GtkWidget *widget, gpointer data) /*求平方值运算*/
{
 method = 14;
 output ();
}

void Log_e(GtkWidget *widget, gpointer data)  /*求自然对数运算*/
{
 method = 15;
 output ();
}

void Log_10(GtkWidget *widget, gpointer data) /*求以10为底的对数运算*/
{
 method = 16;
 output ();
}

void Factorial(GtkWidget *widget, gpointer data) /*求阶乘运算*/
{
 method = 17;
 output ();
}

void Inverse(GtkWidget *widget, gpointer data) /*求倒数运算*/
{
 method = 18;
 output ();
}

void Not(GtkWidget *widget, gpointer data) /*取反运算*/
{
 method = 19;
 output ();
}

void Floor(GtkWidget *widget, gpointer data) /*取整运算*/
{
 method = 20;
 output ();
}

void dot(GtkButton *widget, gpointer data)
{
 if(hasdot == 0)                        /*没有小数点则添加一个小数点*/
 {
 gtk_entry_append_text (GTK_ENTRY (entry), gtk_button_get_label ( widget ));
 hasdot = 1;                          /*表示有一个小数点*/
 }
}

void Sign()
{
 char num[20];
 float c;
 strcpy(num, gtk_entry_get_text(GTK_ENTRY(entry))); /*取得文本框的内容*/
 c = atof(num);                                     /*转换成浮点型*/
 c=-c;
 gtk_entry_set_text(GTK_ENTRY(entry),num);        /*显示结果*/
}

void clear(GtkWidget *widget, gpointer data)
{
 gtk_entry_set_text(GTK_ENTRY(entry),"");
 hasdot = 0;
 a = 0;
 b = 0;
 method = 0;
}

void input (GtkButton *widget, gpointer data)
{
 gtk_entry_append_text (GTK_ENTRY (entry), gtk_button_get_label(widget));
}

void input_pi (GtkWidget *widget, gpointer data)
{
 gtk_entry_set_text (GTK_ENTRY (entry), "3.1415926535897932384626433832795");
}

void addsignal()
{
 /*下面的17个按钮实现数字的输入*/
g_signal_connect (G_OBJECT (button1), "clicked", G_CALLBACK (input_pi), NULL);
g_signal_connect (G_OBJECT (button14), "clicked", G_CALLBACK (input), NULL);
g_signal_connect (G_OBJECT (button15), "clicked", G_CALLBACK (input), NULL);
g_signal_connect (G_OBJECT (button16), "clicked", G_CALLBACK (input), NULL);
g_signal_connect (G_OBJECT (button17), "clicked", G_CALLBACK (input), NULL);
g_signal_connect (G_OBJECT (button18), "clicked", G_CALLBACK (input), NULL);
 /*A*/
g_signal_connect (G_OBJECT (button19), "clicked", G_CALLBACK (input), NULL);
g_signal_connect (G_OBJECT (button20), "clicked", G_CALLBACK (input), NULL);
g_signal_connect (G_OBJECT (button21), "clicked", G_CALLBACK (input), NULL);
g_signal_connect (G_OBJECT (button23), "clicked", G_CALLBACK (input), NULL);
 /*B*/
g_signal_connect (G_OBJECT (button24), "clicked", G_CALLBACK (input), NULL);
g_signal_connect (G_OBJECT (button25), "clicked", G_CALLBACK (input), NULL);
g_signal_connect (G_OBJECT (button26), "clicked", G_CALLBACK (input), NULL);
g_signal_connect (G_OBJECT (button28), "clicked", G_CALLBACK (input), NULL);
 /*C*/
g_signal_connect (G_OBJECT (button33), "clicked", G_CALLBACK (input), NULL);
 /*D*/
g_signal_connect (G_OBJECT (button38), "clicked", G_CALLBACK (input), NULL);
 /*E*/
g_signal_connect (G_OBJECT (button42), "clicked", G_CALLBACK (input), NULL);
 /*F*/
/*下面的按钮实现小数点的输入*/
g_signal_connect (G_OBJECT (button27), "clicked", G_CALLBACK (dot), NULL);
/*下面的按钮实现正负号的输入*/
g_signal_connect (G_OBJECT (button2), "clicked", G_CALLBACK (Sin), NULL);
g_signal_connect (G_OBJECT (button3), "clicked", G_CALLBACK (Cos), NULL);
g_signal_connect (G_OBJECT (button4), "clicked", G_CALLBACK (Tan), NULL);
g_signal_connect (G_OBJECT (button6), "clicked", G_CALLBACK (Exp), NULL);
g_signal_connect (G_OBJECT (button7), "clicked", G_CALLBACK (Mathpowxy), NULL);
g_signal_connect (G_OBJECT (button8), "clicked", G_CALLBACK (Cube), NULL);
g_signal_connect (G_OBJECT (button9), "clicked", G_CALLBACK (Square), NULL);
g_signal_connect (G_OBJECT (button10), "clicked", G_CALLBACK (Log_e), NULL);
g_signal_connect (G_OBJECT (button11), "clicked", G_CALLBACK (Log_10), NULL);
g_signal_connect (G_OBJECT (button12), "clicked", G_CALLBACK (Factorial), NULL);
g_signal_connect (G_OBJECT (button13), "clicked", G_CALLBACK (Inverse), NULL);
g_signal_connect (G_OBJECT (button32), "clicked", G_CALLBACK (Add), NULL);
g_signal_connect (G_OBJECT (button31), "clicked", G_CALLBACK (Sub), NULL);
g_signal_connect (G_OBJECT (button30), "clicked", G_CALLBACK (Mul), NULL);
g_signal_connect (G_OBJECT (button29), "clicked", G_CALLBACK (Division), NULL);
g_signal_connect (G_OBJECT (button35), "clicked", G_CALLBACK (And), NULL);
g_signal_connect (G_OBJECT (button36), "clicked", G_CALLBACK (Or), NULL);
g_signal_connect (G_OBJECT (button37), "clicked", G_CALLBACK (Mod), NULL);
g_signal_connect (G_OBJECT (button39), "clicked", G_CALLBACK (Not), NULL);
g_signal_connect (G_OBJECT (button40), "clicked", G_CALLBACK (Xor), NULL);
g_signal_connect (G_OBJECT (button41), "clicked", G_CALLBACK (Floor), NULL);
/*下面的按钮实现复位功能*/
g_signal_connect (G_OBJECT (button34), "clicked", G_CALLBACK (clear), NULL);
/*下面的按钮实现结果的输出*/
g_signal_connect (G_OBJECT (button5), "clicked", G_CALLBACK (output), NULL);
g_signal_connect (G_OBJECT (window), "delete_envent", gtk_main_quit, NULL);
}






