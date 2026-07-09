class MyLinkedList {
public:
    class Node {
    public:
        int val;
        Node* prev;
        Node* next;

        Node(int x) {
            val = x;
            prev = NULL;
            next = NULL;
        }
    };
    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if (index<0 || index>=size){
            return -1;
        }

        Node* temp=head;
        while(index--){
            temp=temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);

        if (head==NULL) {
            head=tail=node;
        } 
        else {
            node->next=head;
            head->prev=node;
            head = node;
        }

        size++;
    }
    
    void addAtTail(int val) {
        Node* node = new Node(val);

        if (tail==NULL) {
            head=tail=node;
        } else {
            tail->next=node;
            node->prev=tail;
            tail = node;
        }

        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size)
            return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* temp = head;
        while (index--) {
            temp = temp->next;
        }

        Node* node = new Node(val);

        node->prev = temp->prev;
        node->next = temp;

        temp->prev->next = node;
        temp->prev = node;

        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;

        if (size == 1) {
            delete head;
            head = tail = NULL;
            size--;
            return;
        }

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            size--;
            return;
        }

        if (index == size - 1) {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
            size--;
            return;
        }

        Node* temp = head;
        while (index--) {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
        size--;

    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */