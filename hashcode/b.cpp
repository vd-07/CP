#include <bits/stdc++.h>
using namespace std;
struct givenLibraries{
    int N, T, M, id;
    bool books[100001];
};
bool comparator(givenLibraries a, givenLibraries b){
    // return (a.M*a.N*b.T*b.T)>(b.M*b.N*a.T*a.T);
    return (a.T<b.T&&(a.N>b.N||a.M>b.M))||(a.N>b.N*b.N*b.N*b.N&&a.M>b.M&&a.T<b.T*b.T);
    // return a.T<b.T;
}
int main(){
    ifstream fin;
    fin.open("e_so_many_books.txt");
    int B, L, D, ids;
    fin>>B>>L>>D;
    int scores[B];
    //Taking scores of books as input in scores array
    for(int i=0;i<B;i++)
        fin>>scores[i];
    givenLibraries *Libraries= new givenLibraries[L];
    for(int i=0;i<L;i++){
        fin>>Libraries[i].N>>Libraries[i].T>>Libraries[i].M;
        Libraries[i].id=i;
        // cout<<Libraries[i].N;
        //Libraries[i].books = new int[B];
        memset(Libraries[i].books,false,sizeof(Libraries[i].books));
        for(int j=0;j<Libraries[i].N;j++)
            {
                fin>>ids;
                Libraries[i].books[ids]=true;
            }
    }
    sort(Libraries, Libraries + L, comparator);
    ofstream fout;
    fout.open("Submission_e.txt");
    int booksScanned[100001];
    int count=0, sum=0;
    for(int i=0;i<L;i++){
        sum+=Libraries[i].T;
        if(sum>D)
        {
            break;
            L=i;
        }
    }
    fout<<L<<"\n";
    memset(booksScanned,false,sizeof(booksScanned));
    for(int l=0;l<L;l++){
        count=0;
        int temp;
        for(int i=0;i<B;i++){
            if(Libraries[l].books[i])
            temp=i;
            if((!booksScanned[i])&&Libraries[l].books[i])
                {
                    count++;
                    booksScanned[i]=true;
                }
            else if((booksScanned[i])&&Libraries[l].books[i])
                Libraries[l].books[i]=false;
        }
        if(count==0)
        {
            fout<<Libraries[l].id<<" "<<count+1<<"\n";    
            fout<<temp<<"\n";
        }
        else{
            fout<<Libraries[l].id<<" "<<count<<"\n";
        for(int i=0;i<B;i++)
            {
                if(Libraries[l].books[i])
                fout<<i<<" ";
            }
        fout<<"\n";
        }
    }
    fin.close();
    fout.close();
    return 0;
}