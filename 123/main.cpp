

#include <iostream>
using namespace std;
#include <string>
class VectorException {
private:
    string str;
public:
    VectorException(string massage) : str(massage) {}
    string what() {
        return str;
    }
};

template <typename type> class SimpleVector{
    int len,ind1x;
    type* m;
public:
    int lentgth(){
        return ind1x;
    }
    SimpleVector(int n): len(n), ind1x(0){
        m=new type[len];
    }
   
  
    void push_back(type a){
        if (ind1x>=len)
        {
            newm();
        }
        
        m[ind1x]=a;
        ind1x++;
        
    }
    int find(type a){
        for (int i =0; i<=ind1x; i++){
            if (m[i]==a)
                return i;
        }
        return -1;
    }
    void newm(){
        type* m1=new type[len*2];
        for (int i =0; i<len;i++){
            m1[i]=m[i];
        }
        type* m=new type[len*2];
        for (int i =0; i<len;i++){
            m[i]=m1[i];
        };
        delete [] m1;
        m1=nullptr;
   
        len=len*2;
    }
    int &operator[] (int i) {
        if (i>=ind1x){
            throw VectorException("index_out_of_range");
        }
        return m[i];
        
    }
   bool remove(type a){
        int k=find(a);
        if (k>-1){
        for (int i = k; i < ind1x - 1; i++) {
                           m[i]=m[i + 1];
                       }
                       ind1x --;
            return true;
    }
        return false;
    }
    bool insert_after(type x, type y){
        int k=find(y);
        if (k>=len)
        {
            newm();
        }
        if (k>-1){
            for (int i = ind1x; i > k; i--) {
                            m[i] = m[i - 1];
                        }
                    
                        m[k+1] = x;

            ind1x ++;
            
            return true;
    }
        return false;
    }
    
    ~SimpleVector<type>(){
        delete[] m;
        m=nullptr;

    }
    
};

int main() {
    try{
        
    
    SimpleVector<int> m(1);

    m.push_back(2);

        
    m.push_back(3);
   
        
    m.push_back(4);

    m.push_back(4);
        m.push_back(4);

        m.push_back(7);
        m.push_back(90);
        m.push_back(15);
        m.push_back(51);
        m.remove(7);
        m.insert_after(5, 51);
        m.insert_after(22, 4);
        m.insert_after(11, 7);
        for (int i=0; i<m.lentgth();i++){
            cout<<m[i]<<endl;
        }
    m.~SimpleVector();
  
    }
    catch(VectorException s){
           cout<<s.what()<<endl;
       }
}
