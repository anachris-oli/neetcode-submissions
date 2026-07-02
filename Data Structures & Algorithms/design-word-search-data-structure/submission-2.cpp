class TrieNode{
public:
    array<unique_ptr<TrieNode>,26> children_;
    bool is_end_=false;
    TrieNode() = default;

}; 
class WordDictionary {
private:
    unique_ptr<TrieNode> root_;

    TrieNode* findWord(string word, TrieNode* root_node)
    {
        auto char_idx = 0;
        TrieNode* node = root_node;
        for(auto c:word)
        {
            if(c=='.') //wildcard
            {
                for(int i=0;i<node->children_.size();i++)
                {
                    TrieNode* child=node->children_[i].get();
                    if(child!=nullptr)
                    {
                        TrieNode* result = findWord(word.substr(char_idx+1),child);
                        if(result!=nullptr) return result;
                    }
                }
                return nullptr;
            }
            else
            {
                auto idx = c-'a';
                if(!node->children_[idx]) return nullptr;
                node = node->children_[idx].get();
            }
            char_idx++;
            
        }
        return node;
    }

public:

    WordDictionary() {
        root_ = make_unique<TrieNode>();
    }
    
    void addWord(string word) {
        
        TrieNode* node = root_.get();
        for(auto c:word)
        {
            auto idx = c-'a';
            if(!node->children_[idx]) 
            {
                node->children_[idx]=make_unique<TrieNode>();
            }
            node = node->children_[idx].get();
        }
        node->is_end_ = true;
    }
    
    bool search(string word) {
        TrieNode* node = findWord(word, root_.get());
        return node!=nullptr and node->is_end_;
    }
};
