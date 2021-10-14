class WordDictionary {
public:
    
    struct TrieNode {
        struct TrieNode *children[26] = {NULL};
        bool isEndOfWord = false;
    };
    
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode;
    }
    
    void addWord(string word) {
        int len = word.size();
        TrieNode *crawl = root;
        for(char c :word){
            int idx = c - 'a';
            if(crawl->children[idx] == NULL){
                crawl->children[idx] = new TrieNode;
            }
            crawl = crawl->children[idx];
        }
        crawl->isEndOfWord = true;
    }
    
    bool searchUtil(string word, int idx, TrieNode *curr){
        int id;
 
        if(curr == NULL)
            return false;
        
        if(idx == word.size() - 1){
            id = word[idx] - 'a';
            if(id>=0 && id <=25){
                return curr->children[id] && curr->children[id]->isEndOfWord;
            }
            else{
                for(int i = 0; i < 26; i++){
                    if(curr->children[i] && curr->children[i]->isEndOfWord)
                        return true;
                }
            }
            return false;
        }
        
        id = word[idx] - 'a';
        if(id>=0 && id <=25)
            return searchUtil(word, idx + 1, curr->children[id]);
        
        for(int i = 0; i < 26; i++){
            if(searchUtil(word, idx + 1, curr->children[i]))
                return true;
        }
        
        return false;
    }
    
    bool search(string word) {
        return searchUtil(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */