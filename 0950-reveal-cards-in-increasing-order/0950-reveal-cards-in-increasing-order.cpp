class Solution {
public:
//dequeue is used 
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        
        int n=deck.size();
        vector<int> result (n,0);

        deque<int> indices;
        for(int i=0; i<n; i++){
            indices.push_back(i);
        }

        for(int card:deck){
            int idx=indices.front();
            indices.pop_front();
            result[idx]=card;
            if(!indices.empty()){
                indices.push_back(indices.front()); // Move the used index to the end of deque
                indices.pop_front(); // Remove the index from the front
            }
        }
        return result;

    }
};