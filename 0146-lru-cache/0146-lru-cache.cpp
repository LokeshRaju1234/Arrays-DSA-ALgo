class LRUCache {
public:
class Node
{
    public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k,int v)
    {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

    int cap;
    unordered_map<int,Node*>map;//for accessing the node in o(1)
    //doubly linked list -> it is used to maintain usage order and support O(1) insertion and deletion.
    //most frequently used will be at front and least frequently used will be at tail
    Node* head;
    Node* tail;
    LRUCache(int capacity)
    {
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAfterHead(Node* node)
    {
        node->next = head->next;
        head->next = node;
        node->prev = head;
        node->next->prev = node;
    }

    int get(int key) 
    {
     if(map.find(key) == map.end())
     {
        return -1;
     }

     Node* node = map[key];
     deleteNode(node);
     insertAfterHead(node);
     return node->value;
    }
    
    void put(int key, int value) 
    {
        
        if(map.find(key) != map.end())
        {
            Node* node = map[key];
            node->value = value;//if the key already exists we will update the value
            deleteNode(node);
            insertAfterHead(node);
        }
        else
        {
            if(map.size() == cap)
            {
            Node* lru = tail->prev;
            deleteNode(lru);
            map.erase(lru->key);
            delete lru;
            }

            Node* newNode = new Node(key,value);
            insertAfterHead(newNode);
            map[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */