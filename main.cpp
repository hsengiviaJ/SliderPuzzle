#include<iostream>
using namespace std;

class board{
public:
    int matrix[3][3] = {{0,1,2},{5,6,3},{4,7,8}};
    int* neighbours;
    void disp(){
        for(auto & i : matrix) {
            cout<<'[';
            for (int j = 0; j < 3; j++) {
                if(i[j] == 0)
                    cout <<' '<< ' ' <<' ';
                else
                    cout <<' '<< i[j]<<' ';
            }
            cout<<"]\n";
        }
    }
    void nei(){
        int* neis = new int[4];
        for(int _ = 0; _<4; _++){
            *(neis+_) = 0;
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0 ; j < 3; j++){
                if (matrix[i][j] == 0){
                    for(int k= 0; k<4; k++){
                        try {
                            switch (k) {
                                case 0:{
                                    neis[k] = matrix[i+1][j];
                                    break;
                                }
                                case 1:{
                                    if (i == 0) throw out_of_range("");
                                    neis[k] = matrix[i-1][j];
                                    break;
                                }
                                case 2:{
                                    if(matrix[i][j+1] == matrix[i+1][0]) throw out_of_range("");
                                    neis[k] = matrix[i][j+1];
                                    break;
                                }
                                case 3:{
                                    if(j==0) throw out_of_range("");
                                    neis[k] = matrix[i][j-1];
                                    break;
                                }
                            }
                        }catch (out_of_range) {
                            continue;
                        }
                    }
                }
            }
        }
        neighbours = neis;
        for(int i = 0; i <4; i++){
            if(neighbours[i]<0 || neighbours[i]>8)
                neighbours[i] = 0;
        }
    }
    void move(int a){
        int zero[2], swapper[2];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if(matrix[i][j] == 0){
                    zero[0] = i;
                    zero[1] = j;
                }
                if(matrix[i][j] == a) {
                    swapper[0] = i;
                    swapper[1] = j;
                }
            }
        }
        matrix[swapper[0]][swapper[1]] = 0;
        matrix[zero[0]][zero[1]] = a;
    }
    void getmove(){
        int to;
        cout<<"which tile do you want to move: ";
        for(int i = 0; i<4; i++){
            if(neighbours[i] == 0)
                continue;
            else
                cout<<neighbours[i]<<' ';
        }
        cin>>to;
        move(to);
    }
    bool isover(){
        int solved[3][3] = {{1,2,3},{4,5,6},{7,8,0}};
        for(int i = 0; i<3 ; i++){
            for(int j = 0; j<3; j++){
                if(matrix[i][j] != solved[i][j])
                    return true;
            }
        }
        return false;
    }
};
int main(){
    board d;
    int num = 0;
    bool flag = true;
    d.disp();
    while(flag) {
        d.nei();
        d.getmove();
        flag = d.isover();
        num++;
        if(num) system("cls");
        d.disp();
    }
    cout<< " congratulations You won!";
    cout<<"\n You took "<<num<<" moves";
    return 0;
}