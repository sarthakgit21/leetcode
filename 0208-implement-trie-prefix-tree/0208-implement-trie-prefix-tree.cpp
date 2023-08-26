class Trie {
public:
    
    struct trienode{
        bool isEnd;
        trienode* children[26];
    };
    
    trienode* getnode()
    {
        trienode* newnode=new trienode();
        newnode->isEnd=false;
        for(int i=0;i<26;i++)
        {
            newnode->children[i]=NULL;
        }
        return newnode;
    }
    
    trienode* root;
    Trie() {
        root=getnode();
    }
    
    void insert(string word) {
        int ind=0;
        trienode *node=root;
        for(auto x:word)
        {
            if(node->children[x-'a']==NULL)
            {
                node->children[x-'a']=getnode();
            }
            node=node->children[x-'a'];
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        int ind=0;
        trienode *node=root;
        for(auto x:word)
        {
            if(node->children[x-'a']==NULL)
            {
                return false;
            }
            node=node->children[x-'a'];
        }
        return node->isEnd==true;
    }
    
    bool startsWith(string prefix) {
        // return true;
         int ind=0;
        trienode *node=root;
        for(auto x:prefix)
        {
            if(node->children[x-'a']==NULL)
            {
                return false;
            }
            node=node->children[x-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */