#include <stdio.h>

int binary(int stack[], int t)          // 计算t位二进制的值
{
    int i;
    int ii;
    int j;
    int num = 0;
    int b;

    for(i = t-1, j = 0; i >= 0; i--, j++)
    {
        b = 1;
        for(ii = j; ii > 0; ii--)
        {
            b = b * 2;
        }
        num += stack[i] * b;
    }

    return num;
}

int main(int argc, char const argv[])
{
    int stack[8] = {0,};
    int t = 0;
    int b = 0;
    char c;
    int cc;

    while((c = getchar()) != EOF){      // 程序可以使用重定向读入文件，所以用EOF判断文件结尾
        if(c == 48 || c == 49){         // 如果字符是0或1，进栈
            if(t < 9)
            {
                stack[t] = c - 48;
                t++;
            }else{                      // 如果栈满，先计算数值
                cc = binary(stack, t);
                printf("%c", cc);
                t = 0;                  // 并全部出栈
                stack[t] = c - 48;      // 再进栈
                t++;
            }
        }else{
            if(t > 0)                   // 如果遇到非01字符，先出栈计算，再输出字符
            {
                cc = binary(stack, t);
                printf("%c", cc);
                t = 0;
            }
            printf("%c", c);
        }
    }
    
    return 0;
}