class Pair{
public:
    int value;
    int span;
};
class StockSpanner {
public:
    stack<Pair> s;
    StockSpanner() {
        // s.push({price, currentspan});
    }
    
    int next(int price) {
        int currentspan=1;
        // if(s.empty()){
        //     StockSpanner(price, currentspan);
        // }

        while(!s.empty() and s.top().value<=price){
            currentspan+=s.top().span;
            s.pop();
        }

        Pair p;
        p.span=currentspan;
        p.value=price;
        s.push(p);

        return currentspan;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */ 