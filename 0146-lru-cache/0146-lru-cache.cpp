struct Node{
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k,int v){
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int,Node*>mpp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            removeNode(mpp[key]);
            addToFront(mpp[key]);
            return mpp[key]->val;
        }
        return -1;
    }

    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToFront(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            mpp[key]->val = value;
            removeNode(mpp[key]);
            addToFront(mpp[key]);
        }else{
            Node* node = new Node(key,value);
            addToFront(node);
            mpp[key]= node;
            if(mpp.size() > capacity){
                Node* lru = tail->prev;
                removeNode(lru);
                mpp.erase(lru->key);
                delete(lru);   
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */