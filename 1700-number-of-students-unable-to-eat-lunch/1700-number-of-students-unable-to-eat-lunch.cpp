class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stu;
        stack<int> san;
        for(int i=0; i<students.size(); i++){
            stu.push(students[i]);
        }
        for(int i=sandwiches.size()-1; i>=0; i--){
            san.push(sandwiches[i]);
        }

        int n=stu.size();
        int rotations=0;
        while(!stu.empty() and rotations<=n){
            if(stu.front()==san.top()){
                stu.pop();
                san.pop();
                rotations=0;
            }
            else{
                int temp=stu.front();
                stu.pop();
                stu.push(temp);
                rotations++;
            }
        }
        
        int ans=stu.size();
        return ans;
    }
};