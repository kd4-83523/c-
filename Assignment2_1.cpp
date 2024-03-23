

#include<iostream>
using namespace std;

class Box
{
    private :
    float length;
    float breadth;
    float height;
    float v;

    public :

    Box()
    {
        length = 5;
        breadth = 3;
        height = 6;
    }
    
    Box(float length,float breadth,float height)
    {
        this-> length = length;
        this-> breadth = breadth;
        this -> height = height;
    }
    Box(float value)
    {
        length = value;
        breadth = value;
        height = value;
    }
     void volume()
     {
        v = length*breadth*height;
        cout<<"VOLUME OF A BOX = "<< v << endl;
     }
};

int main()
{
    Box b1;
    b1.volume();
    Box b2(8,7,6) ;
    b2.volume();
    Box b3(5);
    b3.volume();
}
