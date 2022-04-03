

#include <iostream>

using namespace std;
#include <string>

class Student{
    string surname;
    string name;
    string middlename;
    int year, a,b,c,d,e;
public:
    string gets(){
        return surname;
    }
    string getn(){
        return name;
    }
    string getm(){
        return middlename;
    }
    int gety(){
        return year;
    }
    void read(){
        cin>>surname>>name>>middlename>>year>>a>>b>>c>>d>>e;
    }
    void print(){
        cout<<surname<<" "<<name<<" "<<middlename<<" "<<year<<" "<<a<<" "<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
    }
    double avrg(){
        return (a+b+c+d+e)/5.;
    }
    
};

bool gr1ter(Student a, Student b){
    if (a.avrg() != b.avrg()){
        return a.avrg()>b.avrg();
    }
    if (a.gety() != b.gety()){
        return a.gety()>b.gety();
    }
    if (a.gets() != b.gets()){
        return a.gets()<b.gets();
    }
    if (a.getn() != b.getn()){
        return a.getn()<b.getn();
    }

    return a.getm()<b.getm();
    
    
}

void sort1(Student *a, int n){
    Student temp;
   Student lowkey;
   int lowindex;
   for (int i=0; i<n-1; i++){
       lowindex = i;
       lowkey = a[i];
   
       for (int j=i+1; j<n;j++)
           if (gr1ter(a[j],lowkey) ){
               lowkey=a[j];
               lowindex=j;
           }
           
           temp = a[i];
           a[i]=a[lowindex];
       a[lowindex]=temp;
       }
   
}

int main() {
    int n;
    cin>>n;
    Student* m =new Student[n];
    for (int i = 0; i < n; i++){
            m[i].read();
    }
    sort1(m,n);
    for (int i = 0; i < n; i++)
        m[i].print();
    return 0;
}
