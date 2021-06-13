#include <iostream>

using namespace std;


struct element
{
    int r , c , *p;
};



void initialize_array(int r,int c,int *matrix)
{
    for(int i = 0; i < r*c; i++)
    {
            cout<<"Enter the value:";
            cin>>*(matrix + i);
    }
}







void print_array_using_pointers(int r,int c,int *ptr)
{
    int i,j;
    cout<<endl;
    for (i=0; i<r; i++)
    {
        cout<<"[";
        for (j=0; j<c; j++)
        {
            cout<<" "<<*ptr;
            ptr = ptr + 1;
        }
        cout<<" ]"<<endl;
    }
    return;
}






element addition_matrices(int r1, int c1, int r2, int c2, int *p1, int *p2)
{
    element matrix;
    try
    {
        if((r1 == r2) && (c1 == c2))
        {
            cout<<"\n \n Addition is possible\n \n";
            matrix.c = c1;
            matrix.r = r1;
            matrix.p = new int[c1*r1];

            int i, j, a, b, c ;

            for(i=0; i< r1; i++)
            {
                for(j = 0; j < c1; j++)
                {
                    a = *(p1 + i*c1 + j);
                    b = *(p2 + i*c1 + j);
                    c = a + b;
                    *(matrix.p + i*c1 + j) =  c;
                }
            }
        }
        else throw ( c1 );
    }
    catch( ... )
    {
        cout<<"Addition not possible";
        matrix.c = 0;
        matrix.r = 0;
        matrix.p = 0;
    }
    return matrix;

}


int main()
{
    int r1,c1,r2,c2, *matrix_1, *matrix_2;
    cout<<"Matrix 1: \n Enter number of rows:";
    cin>>r1;
    cout<<"Enter number of Columns:";
    cin>>c1;

    matrix_1 = new int[r1*c1];

    initialize_array(r1, c1, matrix_1);
    print_array_using_pointers(r1, c1, matrix_1);

    cout<<"Matrix 2: \n Enter number of rows:";
    cin>>r2;
    cout<<"Enter number of Columns:";
    cin>>c2;

    matrix_2 = new int[r2*c2];

    initialize_array(r2, c2, matrix_2);
    print_array_using_pointers(r2, c2, matrix_2);

    element matrix;

    matrix = addition_matrices(r1,c1,r2,c2,matrix_1,matrix_2);
    print_array_using_pointers(matrix.r,matrix.c, matrix.p);
}
