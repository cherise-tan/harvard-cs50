# include <cs50.h>
# include <stdio.h>

bool valid_triangle(float a, float b, float c);

bool valid_triangle(float a, float b, float c){
    if (a <= 0 || b <= 0 || c <= 0){
        return false;
    }
    if (a + b <= c || a + c <= b || b + c <= a){
        return fa;se;
    } 
    return true;
}