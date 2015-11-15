// Solution to https://www.hackerrank.com/challenges/abstract-classes-polymorphism
// there are several things i would have wanted to change mostly moving all the functionality
// of node removing  to the node structure. Since the Node and Cache class are provided by the 
// question i had to live with changing most of the arrays outside.

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache: public Cache
{    
    public:
        LRUCache(int cap){
            cp = cap;
            head = 0;
            tail = 0;
        }
        void set (int , int);
        int get (int);
    
    private:
        void AddToMap(int key, int value);
        void moveNodeToHead(Node *node);
        void removeTail();
};
 

void LRUCache::set(int key, int value)
{
    
    map<int,Node*>::iterator it = mp.find(key);
    if (it == mp.end()){ 
        AddToMap(key,value);
    } else {
        it->second->value = value;
        // update the value
        moveNodeToHead(it->second);
    }
    
    if (mp.size() > cp){
        // remove the tail element from map.
        mp.erase(tail->value);
        // remove the tail element.
        removeTail();
    }
}

int LRUCache::get(int key)
{
    
    map<int,Node*>::iterator it = mp.find(key);
    if (it == mp.end()) { 
        return -1;
    }

    moveNodeToHead(it->second);
    return it->second->value;
}

void LRUCache::moveNodeToHead(Node *node)
{
    // remove the element from the list
    if (node->prev){
        node->prev->next = node->next;
    }
    if (node->next){
        node->next->prev = node->prev;
    }
    
    node->prev = NULL;
    node->next = head;
    head->prev = node;
    head = node;
}

void LRUCache::removeTail()
{
    Node *temp = tail;
   
    tail = tail->prev; 
    if (tail) {
        tail->next = NULL;
    } else {
        head = NULL;
    }
    
    delete(temp);

}

void LRUCache::AddToMap(int key, int value)
{
    
    Node *node = new Node(NULL, head, key, value);   
    if (head == NULL){
        tail = node;
    } else {
        head->prev = node;
    }
    
    head = node;
    mp[key] = node;
}


int main() {

   LRUCache l(5);
   
   l.set(1, 4);
   l.set(1,5);

   assert(l.get(1) == 5);
   cout << l.get(1);

   return 0;
}
