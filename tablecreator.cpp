#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <math.h>

#define size 256

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

struct position	//	structure of position, used for specifying the cursor position
{
	int x,y;
};

void gotoxy(position pos)
{	CursorPosition.X = pos.x; // Locates column
	CursorPosition.Y = pos.y; // Locates Row
	SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed
}

//  enumerated data-type for the borders
/*
    STD     -   Standard Single Borders
    DOUB    -   Double throughout Borders
    EXT     -   Double External Borders
*/
enum borders
{
    STD=0, DOUB, EXT
};

/*  this function is used to draw a table with the given specifications using the standard borders  */
void drawtable_stdborder(position start,int collen[size],int colnum, int rownum)
{
    position d;

    d=start;

    gotoxy(start);
     /*drawing first row*/
    cout<<(char)218;
    for(int i=0; i<colnum; i++)
    {
        for(int j=0; j<collen[i]; j++)
            cout<<(char)196;
        cout<<(char)194;
    }

    cout<<"\b \b"<<(char)191;
    cout<<endl;
    d.y+=1;
    gotoxy(d);


    cout<<(char)179;
    for(int i=0; i<colnum; i++)
    {
        for(int j=0; j<collen[i]; j++)
            cout<<" ";
        cout<<(char)179;
    }
    cout<<endl;
    d.y+=1;
    gotoxy(d);


    /*drawing intermediate row(s)*/
    for(int k=0; k<rownum-1; k++)
    {
        cout<<(char)195;
        for(int i=0; i<colnum; i++)
        {
            for(int j=0; j<collen[i]; j++)
                cout<<(char)196;
            cout<<(char)197;
        }
        cout<<"\b \b"<<(char)180;
        cout<<endl;
        d.y+=1;
        gotoxy(d);

        cout<<(char)179;
        for(int i=0; i<colnum; i++)
        {
            for(int j=0; j<collen[i]; j++)
                cout<<" ";
            cout<<(char)179;
        }
        cout<<endl;
        d.y+=1;
        gotoxy(d);
    }


    /*drawing last row*/
    cout<<(char)192;
    for(int i=0; i<colnum; i++)
    {
        for(int j=0; j<collen[i]; j++)
            cout<<(char)196;
        cout<<(char)193;
    }

    cout<<"\b \b"<<(char)217;
    cout<<endl;
    d.y+=1;
    gotoxy(d);

    position stop;

    stop.x=start.x;
    stop.y=(rownum*2)+1+start.y;
    gotoxy(stop);
}

/*  this function is used to draw a table with the given specifications using double borders throughout  */
void drawtable_doubleborder(position start,int collen[size],int colnum, int rownum)
{
    position d;

    d=start;

    gotoxy(start);
     /*drawing first row*/
    cout<<(char)201;
    for(int i=0; i<colnum; i++)
    {
        for(int j=0; j<collen[i]; j++)
            cout<<(char)205;
        cout<<(char)203;
    }

    cout<<"\b \b"<<(char)187;
    cout<<endl;
    d.y+=1;
    gotoxy(d);


    cout<<(char)186;
    for(int i=0; i<colnum; i++)
    {
        for(int j=0; j<collen[i]; j++)
            cout<<" ";
        cout<<(char)186;
    }
    cout<<endl;
    d.y+=1;
    gotoxy(d);


    /*drawing intermediate row(s)*/
    for(int k=0; k<rownum-1; k++)
    {
        cout<<(char)204;
        for(int i=0; i<colnum; i++)
        {
            for(int j=0; j<collen[i]; j++)
                cout<<(char)205;
            cout<<(char)206;
        }
        cout<<"\b \b"<<(char)185;
        cout<<endl;
        d.y+=1;
        gotoxy(d);

        cout<<(char)186;
        for(int i=0; i<colnum; i++)
        {
            for(int j=0; j<collen[i]; j++)
                cout<<" ";
            cout<<(char)186;
        }
        cout<<endl;
        d.y+=1;
        gotoxy(d);
    }


    /*drawing last row*/
    cout<<(char)200;
    for(int i=0; i<colnum; i++)
    {
        for(int j=0; j<collen[i]; j++)
            cout<<(char)205;
        cout<<(char)202;
    }

    cout<<"\b \b"<<(char)188;
    cout<<endl;
    d.y+=1;
    gotoxy(d);

    position stop;

    stop.x=start.x;
    stop.y=(rownum*2)+1+start.y;
    gotoxy(stop);
}

/*  this function is used to draw a table with the given specifications using double external borders only  */
void drawtable_extborder(position start,int collen[size],int colnum, int rownum)
{
    position d;

    d=start;

    gotoxy(start);
     /*drawing first row*/
    cout<<(char)201;
    for(int i=0; i<colnum; i++)
    {
        for(int j=0; j<collen[i]; j++)
            cout<<(char)205;
        cout<<(char)209;
    }

    cout<<"\b \b"<<(char)187;
    cout<<endl;
    d.y+=1;
    gotoxy(d);


    cout<<(char)186;
    for(int i=0; i<colnum; i++)
    {
        for(int j=0; j<collen[i]; j++)
            cout<<" ";
        cout<<(char)179;
    }
    cout<<"\b \b"<<(char)186;
    cout<<endl;
    d.y+=1;
    gotoxy(d);


    /*drawing intermediate row(s)*/
    for(int k=0; k<rownum-1; k++)
    {
        cout<<(char)199;
        for(int i=0; i<colnum; i++)
        {
            for(int j=0; j<collen[i]; j++)
                cout<<(char)196;
            cout<<(char)197;
        }
        cout<<"\b \b"<<(char)182;
        cout<<endl;
        d.y+=1;
        gotoxy(d);

        cout<<(char)186;
        for(int i=0; i<colnum; i++)
        {
            for(int j=0; j<collen[i]; j++)
                cout<<" ";
            cout<<(char)179;
        }
        cout<<"\b \b"<<(char)186;
        cout<<endl;
        d.y+=1;
        gotoxy(d);
    }


    /*drawing last row*/
    cout<<(char)200;
    for(int i=0; i<colnum; i++)
    {
        for(int j=0; j<collen[i]; j++)
            cout<<(char)205;
        cout<<(char)207;
    }

    cout<<"\b \b"<<(char)188;
    cout<<endl;
    d.y+=1;
    gotoxy(d);

    position stop;

    stop.x=start.x;
    stop.y=(rownum*2)+1+start.y;
    gotoxy(stop);
}

void drawtable(position start,int collen[size],int colnum, int rownum, borders b)
{
    switch(b)
    {
    case STD:
        drawtable_stdborder(start, collen, colnum, rownum);
        break;

    case DOUB:
        drawtable_doubleborder(start, collen, colnum, rownum);
        break;

    case EXT:
        drawtable_extborder(start, collen, colnum, rownum);
        break;
    }
}

/*  this function is used to fill a row with string values in each cell */
void fillrow(position start, char fills[size][size], int collen[size], int colnum, int rownum, int rowid)
{
    position p;

    p.x=start.x+1;
    p.y=start.y+1;


    for(int i=0; i<rowid; i++)
        p.y+=2;


    /*filling cells in each row*/
    for(int i=0; i<colnum; i++)
    {
        gotoxy(p);
        cout<<std::setw(collen[i]-1)<<fills[i];
        p.x+=(collen[i]+1);
    }

    position stop;

    stop.x=start.x;
    stop.y=(rownum*2)+1+start.y;
    gotoxy(stop);
}

/*  this function is used to fill a row with integer values in each cell */
void fillrow(position start, int fills[size], int collen[size], int colnum, int rownum, int rowid)
{
    position p;

    p.x=start.x+1;
    p.y=start.y+1;


    for(int i=0; i<rowid; i++)
        p.y+=2;


    /*filling cells in each row*/
    for(int i=0; i<colnum; i++)
    {
        gotoxy(p);
        cout<<std::setw(collen[i]-1)<<fills[i];
        p.x+=(collen[i]+1);
    }

    position stop;

    stop.x=start.x;
    stop.y=(rownum*2)+3+start.y;
    gotoxy(stop);
}

/*  this function is used to fill a row with float point double precision values in each cell */
void fillrow(position start, double fills[size], int collen[size], int colnum, int rownum, int rowid)
{
    position p;

    p.x=start.x+1;
    p.y=start.y+1;


    for(int i=0; i<rowid; i++)
        p.y+=2;


    /*filling cells in each row*/
    for(int i=0; i<colnum; i++)
    {
        gotoxy(p);
        cout<<std::setw(collen[i]-1)<<fills[i];
        p.x+=(collen[i]+1);
    }

    position stop;

    stop.x=start.x;
    stop.y=(rownum*2)+3+start.y;
    gotoxy(stop);
}

/*  this function is used to fill a column with string values in each cell */
void fillcol(position start, char fills[size][size], int collen[size], int colnum, int rownum, int colid)
{
    position p;

    p.x=start.x+1;
    p.y=start.y+1;


    int sum=0;
    for(int i=0; i<colid; i++)
    {
        sum+=collen[i];
    }
    sum+=(colid);
    p.x+=sum;


    /*filling cells in each column*/
    for(int i=0; i<rownum; i++)
    {
        gotoxy(p);
        cout<<std::setw(collen[colid]-1)<<fills[i]; //look into it
        p.y+=2;
    }

    position stop;

    stop.x=start.x;
    stop.y=(rownum*2)+3+start.y;
    gotoxy(stop);
}

/*  this function is used to fill a column with integer values in each cell */
void fillcol(position start, int fills[size], int collen[size], int colnum, int rownum, int colid)
{
    position p;

    p.x=start.x+1;
    p.y=start.y+1;


    int sum=0;
    for(int i=0; i<colid; i++)
    {
        sum+=collen[i];
    }
    sum+=(colid);
    p.x+=sum;


    /*filling cells in each column*/
    for(int i=0; i<rownum; i++)
    {
        gotoxy(p);
        cout<<std::setw(collen[colid]-1)<<fills[i]; //look into it
        p.y+=2;
    }

    position stop;

    stop.x=start.x;
    stop.y=(rownum*2)+3+start.y;
    gotoxy(stop);
}

/*  this function is used to fill a column with float point double precision values in each cell */
void fillcol(position start, double fills[size], int collen[size], int colnum, int rownum, int colid)
{
    position p;

    p.x=start.x+1;
    p.y=start.y+1;


    int sum=0;
    for(int i=0; i<colid; i++)
    {
        sum+=collen[i];
    }
    sum+=(colid);
    p.x+=sum;


    /*filling cells in each column*/
    for(int i=0; i<rownum; i++)
    {
        gotoxy(p);
        cout<<std::setw(collen[colid]-1)<<fills[i]; //look into it
        p.y+=2;
    }

    position stop;

    stop.x=start.x;
    stop.y=(rownum*2)+3+start.y;
    gotoxy(stop);
}

/* this function calculates the number of digits in a integer number    */
int num_digits(int num)
{
    return ceil(log10(num));
}

/*  this function calculates the number of digits in a float point double precision number  */
int num_digits(double num)
{
    char buffer[64];
    int ret = snprintf(buffer, sizeof (buffer), "%2.10f", num);

    int steps=0;
    for(int i=strlen(buffer)-1; i>0; i--)
    {
        if(buffer[i]=='0')
            steps++;
        else
            break;
    }

    return strlen(buffer) - steps;
}

/*  this function gets the collen values in a row with string values  */
void get_collen_rowfill(char fills[size][size], int colnum, int collen[size])
{
    for(int i=0; i<colnum; i++)
    {
        if((strlen(fills[i])+2)>collen[i])
            collen[i]=strlen(fills[i])+2;
    }

}

/*  this function gets the collen values in a row with integer values  */
void get_collen_rowfill(int fills[size], int colnum, int collen[size])
{
    for(int i=0; i<colnum; i++)
    {
        if((num_digits(fills[i])+2)>collen[i])
            collen[i]=num_digits(fills[i])+2;
    }
}

/*  this function gets the collen values in a row with float point double precision values  */
void get_collen_rowfill(double fills[size], int colnum, int collen[size])
{
    for(int i=0; i<colnum; i++)
    {
        if((num_digits(fills[i])+2)>collen[i])
            collen[i]=num_digits(fills[i])+2;
    }
}

/*  this function gets the collen values in a column with string values  */
void get_collen_colfill(char fills[size][size], int rownum, int &collen)
{
    for(int i=0; i<rownum; i++)
    {
        if((strlen(fills[i])+2)>collen)
            collen=strlen(fills[i])+2;
    }

}

/*  this function gets the collen values in a column with integer values  */
void get_collen_colfill(int fills[size], int rownum, int &collen)
{
    for(int i=0; i<rownum; i++)
    {
        if((num_digits(fills[i])+2)>collen)
            collen=num_digits(fills[i])+2;
    }
}

/*  this function gets the collen values in a column with float point double precision values  */
void get_collen_colfill(double fills[size], int rownum, int &collen)
{
    for(int i=0; i<rownum; i++)
    {
        if((num_digits(fills[i])+2)>collen)
            collen=num_digits(fills[i])+2;
    }
}

/*  a first hand ready-made function to print an array with integer values in a table   */
void print_array_table(position start, int arr[size][size], int rownum, int colnum, borders b)
{
    gotoxy(start);
    int collen[size]={0};
    for(int i=0; i<rownum; i++)
        get_collen_rowfill(arr[i], colnum, collen);

    switch(b)
    {
    case STD:
        drawtable_stdborder(start, collen, colnum, rownum);
        break;

    case DOUB:
        drawtable_doubleborder(start, collen, colnum, rownum);
        break;

    case EXT:
        drawtable_extborder(start, collen, colnum, rownum);
        break;
    }

    for(int k=0; k<4; k++)
        fillrow(start, arr[k],collen, colnum, rownum, k);
}

/*  a first hand ready-made function to print an array with floating point double precision values in a table   */
void print_array_table(position start, double arr[size][size], int rownum, int colnum, borders b)
{
    gotoxy(start);
    int collen[size]={0};
    for(int i=0; i<rownum; i++)
        get_collen_rowfill(arr[i], colnum, collen);

    switch(b)
    {
    case STD:
        drawtable_stdborder(start, collen, colnum, rownum);
        break;

    case DOUB:
        drawtable_doubleborder(start, collen, colnum, rownum);
        break;

    case EXT:
        drawtable_extborder(start, collen, colnum, rownum);
        break;
    }

    for(int k=0; k<4; k++)
        fillrow(start, arr[k],collen, colnum, rownum, k);
}


/*  SAMPLE MAIN for testing the above functions
int main()
{
    //  declaring the starting position and assigning the required position
    position start;
    start.x=3;
    start.y=5;

    //  declaring and initializing colnum and rownum
    int colnum=8;
    int rownum=5;

    // declaring and initializing fills for a row
    char fills[size][size]={"Apples","Bananas","Grapes","Guava","Potato","Tomato","Ginger","Mango"};

    //  declaring collen and initializing it to 0(zero)
    int collen[size]={0};

    //  getting collen using the function
    get_collen_rowfill(fills, colnum, collen);

    //  declaring and initializing a float-point double precision array
    double cell[size][size]={
        {1,2,3,4,5,6,7,7.99},
        {8,9,10,11,12,13,14,14.99},
        {15,16,17,18,19,20,21,21.99},
        {22,23,24,25,26,27,28,28.99}
    };

    //  loop to get the collen using the function row-by-row
    for(int k=0; k<4; k++)
        get_collen_rowfill(cell[k], colnum, collen);

    // drawing a table with ordinary borders
    drawtable(start, collen, colnum, rownum, STD);
    _getch();

    // drawing a table with double borders
    drawtable(start, collen, colnum, rownum, DOUB);
    _getch();

    // drawing a table with double external borders
    drawtable(start, collen, colnum, rownum, EXT);
    _getch();

    //  printing a row of "fills" at the first row position
    fillrow(start, fills, collen, colnum, rownum, 0);

    // loop to print an array row-by-row from the second row position
    for(int k=0; k<4; k++)
        fillrow(start, cell[k],collen, colnum, rownum-1, k+1);

    _getch();

    //  using a different start for the next example
    start.x=3;
    start.y=17;

    //  using a different colnum and rownum
    colnum=1;
    rownum=8;

    //  declaring and initializing collenc(for a particular column) with 0(zero)
    int collenc=0;

    //  getting collenc using the function
    get_collen_colfill(fills, rownum, collenc);

    //  assigning the collen of a particular column(collenc) to the actual collen array
    //  using the first column, hence collen[0]
    collen[0]=collenc;

    // drawing a table with ordinary borders
    drawtable(start, collen, colnum, rownum, STD);
    _getch();

    // drawing a table with double borders
    drawtable(start, collen, colnum, rownum, DOUB);
    _getch();

    // drawing a table with double external borders
    drawtable(start, collen, colnum, rownum, EXT);
    _getch();

    //  printing a column of "fills" at the first column position
    fillcol(start, fills, collen, colnum, rownum, 0);
    _getch();

    //  using a different start for the next example
    start.x=17;
    start.y=17;

    //  printing array using ready-made functions(Standard borders)
    print_array_table(start, cell, 4, 8, STD);
    _getch();

    //  printing array using ready-made functions(Double borders)
    print_array_table(start, cell, 4, 8, DOUB);
    _getch();

    //  printing array using ready-made functions(External Double borders)
    print_array_table(start, cell, 4, 8, EXT);
    _getch();

    //  declaring the end position, assigning the required position and reaching the same
    position _end;
    _end.x=0;
    _end.y=34;
    gotoxy(_end);

    _getch();
}
*/
