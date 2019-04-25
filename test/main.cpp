#include <iostream>
#include<graphics.h>
using namespace std;
class point
{
public:
    int x,y;
};
point p[20];
void s_fill(point p[],int n,int f_c,int b_c)
{
    int xmin,xmax,ymin,ymax,i;
    xmin=xmax=p[0].x;
    ymin=ymax=p[0].y;
    for(i=0;i<n;i++)
    {
        if(p[i].x<xmin)
            xmin=p[i].x;
        if(p[i].x>xmax)
            xmax=p[i].x;
        if(p[i].y<ymin)
            ymin=p[i].y;
        if(p[i].y>ymax)
            ymax=p[i].y;
    }
    int xint[n],sl=ymin;
    int gm,gd=DETECT;
    initgraph(&gd,&gm, NULL);
    while(sl<=ymax)
    {
        int c=0;
        for(i=0;i<n;i++)
        {
            int x1,x2,y1,y2,x;
            x1=p[i].x,y1=p[i].y,x2=p[i+1].x,y2=p[i+1].y;
            if(y1>y2)
            {
                int t=x1;
                x1=x2;
                x2=t;
                t=y1;
                y1=y2;
                y2=t;
            }
            if((y1-y2)==0)
                x=x1;
            else
            {
                x=((x2-x1)*(sl-y1))/(y2-y1);
                x=x+x1;
            }
            if(x<=xmax && x>=xmin)
                xint[c++]=x;
        }
        setcolor(f_c);
        for(i=0;i<n;i++)
        {
            line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
        }
        setcolor(b_c);
        for(i=0;i<c-1;i+=2)
        {
            line(xint[i],sl,xint[i+1],sl);
        }
        sl++;
    }
    getch();
    closegraph();
}
int main()
{
    char op;
    do
    {
        int n,i,f_c,b_c;
        cout<<"Enter the number of vertices\n";
        cin>>n;
        cout<<"Start entering\n";
        for(i=0;i<n;i++)
        {
            cout<<"x"<<i+1<<": ";
            cin>>p[i].x;
            cout<<"y"<<i+1<<": ";
            cin>>p[i].y;
            cout<<"\n\n";
        }
        cout<<"Enter polygon colour(0-15): ";
        cin>>f_c;
        cout<<"Enter fill colour(0-15): ";
        cin>>b_c;
        p[i].x=p[0].x;
        p[i].y=p[0].y;
        s_fill(p,n,f_c,b_c);
        cout<<"Do you wish to continue?\n";
        cin>>op;
    }while(op=='Y' || op=='y');
    return 0;
}
