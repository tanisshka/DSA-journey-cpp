#include <iostream>
#include <vector>
using namespace std;

struct Terms{
    int row;
    int col;
    int val;
};
class Sparce{
    private:
    int rows;
    int cols;
    int numTerms;
    vector <Terms> terms;

    public:
    //contructor
    Sparce(int r,int c,int n){
        rows=r;
        cols=c;
        numTerms=n;
        terms.resize(n);
    }

    void input(){
        cout<<"Enter (row col value) for non-zero elements:";
        for(int i=0;i<numTerms;i++){
            cin>>terms[i].row>>terms[i].col>>terms[i].val;
        }
    }

    void display(){
        cout<<"Sparce Matrix (row col value format):";
        //Why auto?auto automatically deduces the data type based on the value it is assigned.
        for (auto &t : terms){
             cout << t.row << " " << t.col << " " << t.val << endl;
        }
    }

    int get(int i,int j){
        for(auto &t:terms){
            if(t.row==i && t.col==j)
                return t.val;
        }
        return 0;
    }

    void displayFullMatrix() {
        cout << "\nFull Matrix Representation:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                cout << get(i, j) << " ";

            }
            cout << endl;
        }
    }

    //Destructor is not needed why?
    //When your Sparse object goes out of scope, the vector’s own destructor runs and cleans up the heap memory it used.
    //So you do NOT need to write your own destructor.
};

int main(){
    int r,c,n;
    cout<<"Enter total number of rows,cols,non-zero count of Matrix A:";
    cin>>r>>c>>n;
    Sparce A(r,c,n);
    A.input();

    cout<<"\nSparce Matrix A:";
    A.display();
    A.displayFullMatrix();

    return 0;
}