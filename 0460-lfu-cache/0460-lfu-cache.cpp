struct Node {
    int key, value, cnt;
    Node* next;
    Node* prev;
    Node(int _key, int _value) {
        key = _key;
        value = _value;
        cnt = 1;
    }
};
struct List {
    Node* head;
    Node* tail;
    int size;
    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        size = 0;
        head->next = tail;
        tail->prev = head;
    }
    void addFront(Node* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        size++;
    }
    void remove(Node* node) {
        Node* back = node->prev;
        Node* front = node->next;
        back->next = front;
        front->prev = back;
        size--;
    }
};

class LFUCache {
    unordered_map<int, Node*> mpp;
    unordered_map<int, List*> freq;
    int maxSize;
    int minFreq;
    int currSize;
public:
    LFUCache(int capacity) {
        maxSize = capacity;
        minFreq = 0;
        currSize = 0;
    }
    void updateFreq(Node* node){
        mpp.erase(node->key);
        freq[node->cnt]->remove(node);
        if(node->cnt == minFreq && freq[node->cnt]->size==0) minFreq++;
        List *list = new List();
        if(freq.find(node->cnt+1)!=freq.end()) list = freq[node->cnt+1];
        node->cnt += 1;
        list->addFront(node);
        freq[node->cnt] = list;
        mpp[node->key] = node;
    }
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node *node = mpp[key];
            int val = node->value;
            updateFreq(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if(maxSize == 0) return;
        if(mpp.find(key)!=mpp.end()){
            Node* node = mpp[key];
            node->value = value;
            updateFreq(node);
        }
        else{
            if(currSize == maxSize){
                List *list = freq[minFreq];
                mpp.erase(list->tail->prev->key);
                freq[minFreq]->remove(list->tail->prev);
                currSize--;
            }
            currSize++;
            // new value
            minFreq = 1;
            List *newList = new List();
            if(freq.find(minFreq) != freq.end()) newList = freq[minFreq];
            Node *node = new Node(key,value);
            newList->addFront(node);
            mpp[key] = node;
            freq[minFreq] = newList;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */