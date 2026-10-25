struct Node{
    Node* next;
    Node* prev;
    int key;
    int val;
    Node(int k, int v){
        key = k;
        val = v;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
    unordered_map<int, Node*> mpp;
    int capacity;
    Node* head;
    Node* tail;
public:
    void deleteNode(Node* N){
        N->prev->next = N->next;
        N->next->prev = N->prev;
    }
    void insertAfterHead(Node* N){
        N->prev = head;
        N->next = head->next;
        head->next->prev = N; 
        head->next = N;
    }
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;

    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        else{
            Node* node = mpp[key];
            deleteNode(node);
            insertAfterHead(node);
            return node->val;
        }
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node *node = mpp[key];
            node->val = value;
            //node->key = key;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            if(mpp.size()==capacity){
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
                delete node;
            }
            Node* node = new Node(key, value);
            mpp[key] = node;
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */