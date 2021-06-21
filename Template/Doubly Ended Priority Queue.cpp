class DblEndedPQ {
public:
    multiset<pair<int,int>> s;
    int size(){
       return s.size();
    }
  
    bool isEmpty(){
       return (s.size() == 0);
    }
  
    void insert(int x, int y){
        s.insert({x,y});
    }
  
    pair<int,int> getMin(){
        return *(s.begin());
    }

    pair<int,int> getMax(){
        return *(prev(s.end()));
    }

    void deleteMin(){
        if (s.size() == 0)
            return;
        s.erase(s.begin());
    }
  
    void deleteMax(){
        if (s.size() == 0)
            return;
        s.erase(prev(s.end()));
    }
    void print(){
        for(auto it : s){
            cout << it.first << " " << it.second << '\n';
        }
    }
};
