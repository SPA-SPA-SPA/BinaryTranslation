# 二进制翻译器

其实就是读取8位二进制，然后返回它表示ASCII符号。

遇到0或1，进栈；遇到其他符号，先出栈并计算数值，再输出其他符号。