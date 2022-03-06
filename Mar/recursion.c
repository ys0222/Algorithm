#순환

순환이랑 알고리즘과 함수가 수행하면서 자신을 다시 호출하는 기법.
  
예를들면 팩토리얼 알고리즘이 있습니다.
  
n이라는 숫자가 n-1씩 n=1일 될때까지 계산하는 알고리즘입니다.
순환에서는 조건이 만족할 때 멈추게 하는것이 매우 중요합니다.


순환 알고리즘

int factorial (int n){
    if (n==1) return (1);
    else return (n*factorial(n-1));
}

반복 알고리즘

while (n != 0){
    num = num * n;
    n--;
}

순환과 반복은 비슷하지만 조금 차이가 있습니다.
순환은 호출을 이용하고 반복은 for문이나 while문을 이용합니다.
  
※팩토리얼 알고리즘

int factorial(int n);

int main() {
    int n,r;
    printf("양의 정수를 입력하세요");
    scanf("%d",&n);
    r = factorial(n);
    printf("결과 값 result = %d \n",r);
    return 0;
    }

int factorial(int n)
{
    int k,v = 1;
    for (k=n ; k>0;k--){
        v=v*k;
        return (v);
    }
  
※거듭제곱 알고리즘

#include <stdio.h>

int exp(int x , int n);

int main(){
    int x,n,r;
    printf("거듭제곱을 위한 정수 x,n을 입력 x^n \n");
    scanf("%d %d",&x,&n);
    r=exp(x,n);
    printf("result = %d \n",r);
    return 0;
}

int exp(int x, int n)
{
    if (n==0) {return (1);}
    else {
        return (x * exp(x,n-1));
    }
}

※피보나치 알고리즘
  
#include <stdio.h>

int fib(int n);

int main() {
    int n,r,i;
    printf("정수 n 입력");
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        r = fib(i);
        printf("%d",r);
    }
        printf("\n");
        return 0;

}

int fib(int n){
    if (n == 0){
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else return (fib(n-2) + fib(n-1));
}
피보나치 알고리즘은 각 숫자가 직전의 두 숫자의 합인 수열이다.
  
※하노이탑 알고리즘
  
하노이탑 알고리즘은 n개의 원판을 a 에서 c 기둥으로 옮기는 것인데,
작은 원판위에 큰 원판이 올라갈 수 없습니다.
  
#include <stdio.h>

void hanoi_tower(int n , char a, char b, char c)
{
if (n == 1)
printf("원판 1을 %c에서 %c으로 옮긴다 \n",a,b );
else{
hanoi_tower(n-1,a,b,c);
printf("원판 %d 를 %c 에서 %c로 옮긴다 \n",n,a,c);
hanoi_tower(n-1,b,c,a);
}
}

int main() {
    int disk_no; //원반 수
    printf("하노이 타워의 원반 수 입력 :");
    scanf("%d",&disk_no);
    printf("하노이 타워를 a에서 b로 옮겨라 \n");
    hanoi_tower ( disk_no, 'A','B','C');
    return 0;
}

참고 : https://letitgo01.tistory.com/57
