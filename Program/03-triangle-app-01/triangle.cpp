#include <iostream>
#include "triangle.h"
#include <math.h>
using namespace std;

int validate_triangle(const Triangle &t){
    // sum of every two sides is greater than the third 
    // need to check Ideally the above object shouldn't even exist.
    if ((t.s1 > (t.s2 + t.s3)) || (t.s2 > (t.s1 + t.s3)) || (t.s3 > (t.s1 + t.s2)))
        return 1;

    if ((t.s1 > 0) || (t.s2 > 0) || (t.s3 >  0))
        // For negative numbers it should not be valid triangle
        return 1;

    return t.s1+t.s2+t.s3;
}

int perimeter(const Triangle &t){
    int ret_value;
    //t.s1=0; //can modify the actual object

    ret_value = validate_triangle(t);
    if (ret_value == 1)
    {
        cout<< "Not a valid triangle\n";
        return 1;
    }

    return t.s1+t.s2+t.s3;
}

double area(const Triangle &t){
    double s;
    int ret_value;
   
    s = perimeter(t)/2.0;
    if (s == 1) 
        return 1; // error case

    return sqrt(s*(s-t.s1)*(s-t.s2)*(s-t.s3));
}

void show(const Triangle &t, const char * prefix){
    cout<<prefix<<" : <"
                << t.s1<<","
                << t.s2<<","
                << t.s3 <<">\n";
}