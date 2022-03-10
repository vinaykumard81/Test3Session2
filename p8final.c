#include<stdio.h>
typedef struct _fraction
{
  int num,den;
}Fraction;
int gcd(int a,int b)
{
  int t;
  while (b != 0)
    {
      t = b;
      b = a%b;
      a = t;
    }
  return a;  
}

Fraction input_n()
{
  int x;
  printf("Enter the value if n\n");
  scanf("%d",&x);
  return x;
}

Fraction input_fraction()
{
  Fraction f;
  printf("input a fraction\n");
  scanf("%d%d",&f.num,&f.den);
  return f;
}
void input_n_fraction(int n, Fraction f[n])
{
  for(int i = 0; i<n;i++)
    f[i] = input_fraction;
}


Fraction add_fraction(Fraction f1 , Fraction f2)
{
  Fraction sum;
  sum.num = (f1.num*f2.den)+(f2.num*f1.den);
  sum.den = f1.den*f2.den;
  int g = gcd(sum.num,sum.den);
  sum.num = sum.num/g;
  sum.den = sum.den/g;
  return sum;
}

Fraction add_n_fractions(int n, Fraction f[n])
{
  Fraction sum;
  sum = f[0];
  for(int i = 0; i<n;i++)
    sum = add_fraction(sum,f[i]);
  return sum;
}

void output(int n, Fraction f[n], Fraction sum)
{
  for(int i=0;i<n-1;i++)
    {
   printf("%d/%d+",f[i].num,f[i].den);
      }
  printf("%d/%d",f[n].num,f[n].den);
  printf("is %d/%d \n",sum.num,sum.den);
}

int main()
{ int n = input_n();
  Fraction f[n];
  sum = add_n_fractions(n,f);
  output(n,f,sum);
  return 0;
}