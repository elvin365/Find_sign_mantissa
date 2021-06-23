#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
union
{
	float num;
	unsigned int a;//через беззнаковый целый гораздо меньше проблем с побитовыми сдвигами, так как не приходится лезть к раззным элементам массива
}union1;
int main()
{
	
	scanf("%f",&union1.num);
	unsigned int mantissa = union1.a & 0x7FFFFF; //0x7FFFFF - 11111111111111111111111, или 23 бита, длина мантиссы, смещение не требуется
	unsigned int exp = (union1.a >> 23) & 0xFF; //0xFF - 11111111, или 8 бит, длиина экспоненты, смещение на мантиссу вправо 
	unsigned int sgn = (union1.a >> 31) & 0x1; //Знак, смещение на мантиссу и экспоненту вправо
	printf("\n\n\n%d", sgn);
	printf("\n\n\n%d", exp);
	printf("\n\n\n%d", mantissa);
	_getch();
	return 0;
}