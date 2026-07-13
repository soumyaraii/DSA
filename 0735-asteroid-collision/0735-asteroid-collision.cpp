class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int i=0; i<asteroids.size(); i++){
            if(s.empty()){
                s.push(asteroids[i]);
            }

            else if(s.top()>0 and asteroids[i]<0){
                bool alive =true;
                while(!s.empty() and s.top()>0){
                    if(abs(s.top())<abs(asteroids[i])){
                        s.pop();
                        alive=true;
                    }
                    else if(abs(s.top())==abs(asteroids[i])){
                        s.pop();
                        alive=false;
                        break;
                    }
                    else if(abs(s.top())>abs(asteroids[i])){
                        alive=false;
                        break;
                    }
                    else{
                        break;
                    }
                }

                if(alive==true){
                    s.push(asteroids[i]);
                } 
            }

            else if(s.top()<0 and asteroids[i]>0){
                s.push(asteroids[i]);
            }

            else{
                s.push(asteroids[i]);
            }
        }

        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};