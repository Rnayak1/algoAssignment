#include<iostream>
using namespace std;
int count = 0;
void printsol(int **arr,int n)
{
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}
bool issafe(int **arr, int n, int row, int col)
{ //cout<<"\n inside safe row = "<<row<<" col = "<<col;
    int i,j;
    if(row >=n || col >= n)
    {
        cout<<" fault occue";
        return true;
    }
    for(j=0;j<col;j++)
        if(arr[row][j])
            return false;
    for(i=row,j=col; i>=0&&j>=0; i--,j--)
        if(arr[i][j])
            return false;
    for(i=row,j=col;i<n&&j>=0; i++,j--)
        if(arr[i][j])
            return false;
    //cout<<"\n safe true solve nect";
    return true;
}

bool solve(int **arr, int n, int col)
{ //cout<<"\n inside solve col = "<<col;
    if(col >= n){
        printsol(arr,n);
        ::count++;
        return true;
    }
    bool res = false;
    int i;
    for(i=0;i<n;i++)
    {
        if(issafe(arr,n,i,col))
        {
            arr[i][col] = 1;
            //cout<<"\n calling sove agan ";
            res = solve(arr,n,col+1) || res;
            arr[i][col] = 0;
        }
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    int **arr;
    arr = new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
            arr[i][j] = 0;
    }
    printsol(arr,n);
    if(solve(arr,n,0) == false)
        cout<<"\ncant permute"<<endl;
    else
        cout<<" solution is possible "<<::count;
    delete arr;
    return 0;
}