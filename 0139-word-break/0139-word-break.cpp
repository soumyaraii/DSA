class Solution {
public:
string s;
vector<string> words;
    // bool rec(int x){
    //     //base case
    //     if(x<0){
    //         return true;
    //     }
    //     //rec case
    //     for(int w=words.size()-1; w>=0; w--){
    //         string word=words[w];
    //         int l=word.size()-1;
    //         int i=x;
    //         while(i>=0 and l>=0 and s[i]==word[l]){
    //             i--;
    //             l--;
    //         }
    //         //entire word has matched
    //         if(l<0){
    //             //all should match
    //             if(rec(i)){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;  
    // }
int arr[321];
//     bool dp(int x){
//         //base case
//         if(x<0){
//             return true;
//         }
//         //rec case

//         if(arr[x]!=-1){
//             return arr[x];
//         }

//         for(int w=words.size()-1; w>=0; w--){
//             string word=words[w];
//             int l=word.size()-1;
//             int i=x;
//             while(i>=0 and l>=0 and s[i]==word[l]){
//                 i--;
//                 l--;
//             }
//             //entire word has matched
//             if(l<0){
//                 //all should match
//                 if(dp(i)){
//                     arr[x]=true;
//                     return arr[x];
//                 }
//             }
//         }
//         return arr[x]=false;  
//     }

    bool wordBreak(string str, vector<string>& wordDict) {
        //start from back, go in words, match end of word with str[x]
        s=str;
        words=wordDict;
        int n=str.size();
        // memset(arr, -1, sizeof(arr));
        memset(arr, 0, sizeof(arr));

        arr[0]=true;
        for(int i=0; i<n; i++){
            if(arr[i]==false){
                continue;
            }
            for(string word: words){
                int l=0;
                int j=i;
                while(j<n and l<word.size() and s[j]==word[l]){
                    j++;
                    l++;
                }
                //one word match
                if(l==word.size()){
                    arr[j]=true;
                }
            }
        }

        //output at last index
        return arr[n];
        // return dp(n-1);
    }
};