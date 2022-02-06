class Bitset {
    unordered_set<int> ones , zero;
    int sz;
    bool flipped = false;
public:
    Bitset(int size) {
        sz = size;
        for(int i=0;i<size;i++)
            zero.insert(i);
    }
    
    void fix(int idx) {
        if(flipped)
        {
            if(zero.count(idx))
                return;
            else
            {
                zero.insert(idx);
                ones.erase(ones.find(idx));
            }
        }
        else
        {
            if(ones.count(idx))
                return;
            ones.insert(idx);
            zero.erase(zero.find(idx));
        }
    }
    
    void unfix(int idx) {
        if(flipped)
        {
            if(ones.count(idx))
                return;
            ones.insert(idx);
            zero.erase(zero.find(idx));
        }
        else
        {
            if(zero.count(idx))
                return;
            zero.insert(idx);
            ones.erase(ones.find(idx));
        }
    }
    
    void flip() {
        flipped = flipped ? false : true;
    }
    
    bool all() {
        if(flipped) return size(ones) == 0;
        else return size(zero) == 0;
    }
    
    bool one() {
        if(flipped) return size(zero) > 0;
        else return size(ones) > 0;
    }
    
    int count() {
        if(flipped) return size(zero);
        else return size(ones);
    }
    
    string toString() {
        
        string str = "";
        
        if(flipped)
        {
            for(int i=0;i<sz;i++)
            {
                if(zero.count(i))
                    str += '1';
                else
                    str += '0';
            }
        }
        else
        {
            for(int i=0;i<sz;i++)
            {
                if(zero.count(i))
                    str += '0';
                else
                    str += '1';
            }
        }
        
        return str;
    }
};

/***
class Bitset {
public:
    vector<int> v;
    int c;// count of flips
    int cc;// count of set bits
    int n;//size
    Bitset(int size) {
        n=size;
        v=vector<int>(size,0);
        c=0;
        cc=0;
    }
    
    void fix(int idx) {
        if(c%2==0){
            if(v[idx]==0){
                v[idx]=1;
                cc++;
            }
        }
        else{
            if(v[idx]==1){
                v[idx]=0;
                cc++;
            }
        }
    }
    
    void unfix(int idx) {
          if(c%2==0){
            if(v[idx]==1){
                v[idx]=0;
                cc--;
            }
        }
        else{
            if(v[idx]==0){
                v[idx]=1;
                cc--;
            }
        }
    }
    
    void flip() {
        c++;
        cc=(n-cc);
    }
    
    bool all() {
       if(cc==n) return true;
        return false;
    }
    
    bool one() {
       if(cc>0) return true;
        return false;
    }
    
    int count() {     
        return cc;
    }
    
    string toString() {
        string ans="";
            for(int i=0;i<v.size();i++){
            if(c%2==0){
                if(v[i]==1) ans+='1';
                else ans+='0';
            }
            else{
                if(v[i]==0) ans+='1';
                else ans+='0';
            }
          }
        return ans;
    }
};
**/

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */