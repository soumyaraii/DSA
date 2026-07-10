class node{
public:
        string url;
        node* prev;
        node* next;

        node(string x){
            url=x;
            prev=NULL;
            next=NULL;
        }
    };

class BrowserHistory {
public:
    node* curr;
    BrowserHistory(string homepage) {
        curr=new node(homepage);
    }
    
    void visit(string url) {
        curr->next=NULL; 

        node* temp=new node(url);
        temp->prev=curr;
        curr->next=temp;
        curr=temp;
    }
    
    string back(int steps) {
        while(steps>0 and curr->prev!=NULL){
            curr=curr->prev;
            steps--;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps>0 and curr->next!=NULL){
            curr=curr->next;
            steps--;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */