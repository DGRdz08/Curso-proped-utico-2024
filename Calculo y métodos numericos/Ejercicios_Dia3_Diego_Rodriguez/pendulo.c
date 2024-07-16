#include<stdio.h>
#include<math.h>

float miFuncion1(float t, float y1, float y2) {
    return y2;
}

float miFuncion2(float t, float y1, float y2) {
    return - 4 * sin(y1);
}

int main() {
    printf("x\t\t y1\t\t y2 \t\t y1 grados\n");

    float x0, y1, y2, xn, h, k1, k2, k3, k4, l1, l2, l3, l4;
    int n, i=0;

    x0 = 0;
    y1 = 0.1745;  
    y2 = -0.4;    
    xn = 10;      
    h = 0.5;      
    printf("%f\t %f\t %f \t %f\n", x0, y1, y2, y1*(180/3.1416));

    n = (xn - x0) / h; 

    do{
        k1 = h * miFuncion1(x0, y1, y2);
        l1 = h * miFuncion2(x0, y1, y2);
        
        k2 = h * miFuncion1(x0 + h/2, y1 + k1/2, y2 + l1/2);
        l2 = h * miFuncion2(x0 + h/2, y1 + k1/2, y2 + l1/2);
        
        k3 = h * miFuncion1(x0 + h/2, y1 + k2/2, y2 + l2/2);
        l3 = h * miFuncion2(x0 + h/2, y1 + k2/2, y2 + l2/2);
        
        k4 = h * miFuncion1(x0 + h, y1 + k3, y2 + l3);
        l4 = h * miFuncion2(x0 + h, y1 + k3, y2 + l3);
        
        y1 = y1 + (k1 + 2*k2 + 2*k3 + k4) / 6;
        y2 = y2 + (l1 + 2*l2 + 2*l3 + l4) / 6;
        x0 = x0 + h;
        i++;
        printf("%f\t %f\t %f \t %f\n", x0, y1, y2, y1*(180/3.1416));
    }while(i<n);

    return 0;
}
