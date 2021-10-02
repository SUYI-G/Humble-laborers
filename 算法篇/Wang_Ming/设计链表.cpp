class MyLinkedList {

public:
    struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val),next(NULL){}
    };
    MyLinkedList() {
       _dummyHead = new LinkedNode(0);
       _size = 0;

    }
    
    int get(int index) {
        if (index > ( _size - 1) || index < 0) return -1;
        LinkedNode*cur = _dummyHead -> next;
        while(index > 0){
            cur = cur->next;
            index--;
        }
        return cur -> val;

    }
    
    void addAtHead(int val) {
        LinkedNode*newNode = new LinkedNode(val);
        newNode -> next = _dummyHead -> next;
        _dummyHead -> next = newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedNode*newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(cur->next != nullptr){
            cur = cur -> next;
        }
        cur -> next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index <= 0) addAtHead(val);
        else if (index == _size) addAtTail(val);
        else if (index > _size) return;
        else {
            LinkedNode*cur = _dummyHead;
            LinkedNode*NewNode = new LinkedNode(val);
            while(index){
                cur = cur -> next;
                index--;
            }
            NewNode -> next = cur -> next;
            cur -> next = NewNode; 
            _size++;
        }


    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= _size) return;
        LinkedNode* cur = _dummyHead;
        while (index){
            cur = cur -> next;
            index--;
        }
        LinkedNode*tmp = cur -> next;
        cur -> next = tmp -> next;
        delete tmp;
        _size--;

    }
private:
    int _size;
    LinkedNode* _dummyHead;
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