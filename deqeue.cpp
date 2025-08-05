#include "iostream"

using namespace std;

class Deque {
    private:
        int *arr;
        int f,r,max;
    public:
        Deque(int k){
            max = k+1;
            arr = new int[max];
            r=0;
            f=0;
        }
        ~Deque(){
            delete[] arr;
        }
        bool isful(){
            return ((r+1)%max == f);
        }
        bool isemty(){
            return (r==f);
        }
        void inf(int v){
            if(isful()){
                cout<<"Qeue is full";
                return;
            }
            f = (f-1+max)%max;
            arr[f] = v;
        }
        void inr(int v){
            if(isful()) return;
            arr[r]=v;
            r=(r+1)%max;
        }
        int getf(){
            if(isemty()) return -1;
            int v = arr[f];
            f = (f+1)%max;
            return v;
        }
        int getr(){
            if(isemty()) return -1;
            int v = arr[(r-1+max)%max];
            r = (r-1+max)%max;
            return v;
        }
        void display(){
            for(int i=f;i!=r;i=(i+1)%max){
                cout<<arr[i];
            }
        }
};