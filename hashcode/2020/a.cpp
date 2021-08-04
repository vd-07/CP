#include <bits/stdc++.h>
using namespace std;
struct givenLibraries{
    int N, T, M, id;
    bool books[100001];
};
bool comparator(givenLibraries a, givenLibraries b){
    return (a.T>b.T);
}
int main(){
    ifstream fin;
    fin.open("a_example.txt");
    int B, L, D, ids;
    fin>>B>>L>>D;
    int scores[B];
    //Taking scores of books as input in scores array
    for(int i=0;i<B;i++)
        fin>>scores[i];
    givenLibraries Libraries[L];
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
    fout.open("Submission_a.txt");
    fout<<L<<"\n";
    int booksScanned[B];
    int count=0;
    memset(booksScanned,false,sizeof(booksScanned));
    for(int l=0;l<L;l++){
        count=0;
        for(int i=0;i<B;i++){
            if((!booksScanned[i])&&Libraries[l].books[i])
                {
                    count++;
                    booksScanned[i]=true;
                }
            else if((booksScanned[i])&&Libraries[l].books[i])
                Libraries[l].books[i]=false;
        }
        fout<<Libraries[l].id<<" "<<count<<"\n";
        for(int i=0;i<B;i++)
            if(Libraries[l].books[i])
                fout<<i<<" ";
        fout<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}