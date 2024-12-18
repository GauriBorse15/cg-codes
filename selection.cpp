#include<iostream>
#define size 10
using namespace std;
int n;
template <class T>
void sel(T A[size])
{
    int i, j, min;
    T temp;
    for(i=0; i<n-1; i++)
    {
        min=i;
        for(j=i+1; j<n; j++){
            if (A[j]<A[min])
                min=j;
    }
    temp = A[i];
    A[i] = A[min];
    A[min]=temp;
    }cout<<"Sorted Array";
    for(i=0; i<n; i++)
    {
        cout<<" "<<A[i];
    }

}
int main()
{
    int A[size];
    int B[size];
    int i;
    int ch;
    do
    {
      cout<<"*****Selection sort system******";
      cout<<"\n1. Enter int value: ";
      cout<<"\n2. Enter float value: ";
      cout<<"\n3. Exit";
      cout<<"Enter your choice";
      cin>>ch;
      switch(ch)
      {
        case 1:
            cout<<"Enter the total no. of int:";
            cin>>n;
            cout<<"Enter integer:";
            for(i=0; i<n; i++)
            {
                cin>>A[i];
            }
            sel(A);
            break;
        case 2:
            cout<<"Enter the total no. of float:";
            cin>>n;
            cout<<"Enter the float elements";
            for(i=0; i<n; i++)
            {
                cin>>B[i];
            }
            sel(A);
            break;

        case 3:
            cout<<"End of the program"<<endl;
            break;

        default:
            cout<<"\nInvalid choice"<<endl;
            

      }
    } while (ch!=3);
        return 0;
    
}
