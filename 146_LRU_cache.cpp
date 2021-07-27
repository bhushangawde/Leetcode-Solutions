class LRUCache {
public:
    int capacity_;
    unordered_map<int , list<pair<int,int>>::iterator> umap;
    list<pair<int,int>> queue;
    
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        
        if(umap.find(key) == umap.end())
            return -1;
        else{
            list<pair<int,int>>::iterator it = umap[key];
            int k = it->first;
            int v = it->second;
            queue.erase(it);
            queue.push_front(make_pair(k,v));
            umap[key] = queue.begin();
            
			
			// You can also use the splice function instead.
			// splice() function here takes the element at the umap[key] and places it at the beginning of the list.
			// queue.splice(queue.begin(), queue, umap[key);
			// return umap[key]->second;
			
			
            return v;
        }
    }
    
    void put(int key, int value) {
        if(umap.find(key) == umap.end()){
            if(queue.size() == capacity_){
                pair<int,int> p = queue.back();
                queue.pop_back();
                umap.erase(p.first);
            }
            queue.push_front(make_pair(key,value));
            umap[key] = queue.begin();
        }
        else {
            queue.erase(umap[key]);
            queue.push_front(make_pair(key,value));
			umap[key] = queue.begin();
			
			// You can also use the splice function instead.
			// splice() function here takes the element at the umap[key] and places it at the beginning of the list.
			// queue.splice(queue.begin(), queue, umap[key);
			// umap[key]->second = value;
			
            
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */