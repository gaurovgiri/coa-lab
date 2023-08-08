
#include <iostream>

using namespace std;

void ellipseMidPoint()
{
    int xCenter = 19;
    int yCenter = 10;
    int rx = 12;
    int ry = 7;
    int k = 0;

    //plotting for 1st region of 1st quardant and the slope will be < -1
     //----------------------Region-1------------------------//
    float x = 0;
    float y = ry;//(0,ry) ---
    float p1 = ry * ry - (rx * rx)* ry + (rx * rx) * (0.25) ;
    //slope
    float dx = 2 * (ry * ry) * x;
    float dy = 2 * (rx * rx) * y;
    
    cout << "Region 1" << endl;
    cout << "k\t p1k\t xK+1,yK+1\t dx\t dy\t" << endl;
    while(dx < dy)
    {
        //plot (x,y)

        cout << (k++) << "\t" << p1 << "\t    ";
        cout << x << " " << y << "\t\t" ;
        
        if(p1 < 0)
        {
            x = x + 1;
            dx = 2 * (ry * ry) * x;
            p1 = p1 + dx + (ry * ry);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dx =  2 * (ry * ry) * x;
            dy =  2 * (rx * rx) * y;
             p1 = p1 + dx - dy +(ry * ry);
        }
        cout << dx << "\t" << dy << endl;
    }
    //ploting for 2nd region of 1st quardant and the slope will be > -1
     //----------------------Region-2------------------------//
    float p2 = (ry * ry )* ( x +  0.5) * ( x +  0.5) +  ( rx * rx) * ( y - 1) * ( y - 1) - (rx * rx )* (ry * ry);
    k = 0;
    cout << endl << "Region 2" << endl;
    cout << "k\t p2k\t xK+1,yK+1\t dx\t dy\t" << endl;
    while(y > 0)
    {
        //plot (x,y)
        
         cout << k++ << "\t" << p2 << "\t    ";
        cout << x << " " << y << "\t\t" ;
        if(p2 > 0)
        {
            x = x;
            y = y - 1;
            dy = 2 * (rx * rx) * y;
            //dy = 2 * rx * rx *y;
            p2 = p2 - dy + (rx * rx);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dy = dy - 2 * (rx * rx) ;
            dx = dx + 2 * (ry * ry) ;
            p2 = p2 + dx -
            dy + (rx * rx);
        }
    cout << dx << "\t" << dy << endl;

    }

}


int main(){
    ellipseMidPoint();
    return 0;
}