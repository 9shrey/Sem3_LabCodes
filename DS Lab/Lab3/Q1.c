#include<stdio.h>

struct complex{
    double real;
    double img;
};
typedef struct complex cmp;

cmp add (cmp a, cmp b){
    cmp sum;
    sum.real=a.real+b.real;
    sum.img=a.img+b.img;
    return sum;
}

cmp subtract(cmp a, cmp b){
    cmp difference;
    difference.real=a.real-b.real;
    difference.img=a.img-b.img;
    return difference;
}

cmp multiply(cmp a, cmp b){
    cmp product;
    product.real=(a.real*b.real)-(a.img*b.img);
    product.img=(a.real*b.img)+(a.img*b.real);
    return product;
}

int main(){
    cmp a, b;
    printf("Enter real and imaginary part of first complex number: ");
    scanf("%lf %lf", &a.real, &a.img);

    printf("Enter real and imaginary part of second complex number: ");
    scanf("%lf %lf", &b.real, &b.img);

    cmp sum= add(a, b);
    printf("Sum: %0.2lf + %0.2lfi \n", sum.real, sum.img);

    cmp difference= subtract(a, b);
    printf("Difference: %0.2lf + %0.2lfi \n", difference.real, difference.img);

    cmp product= multiply(a, b);
    printf("Product: %0.2lf + %0.2lfi \n", product.real, product.img);

    return 0;
}