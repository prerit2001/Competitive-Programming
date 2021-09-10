class Solution{   
public:
    struct node{
        node* next[2];
        node(){
            next[0] = NULL;
            next[1] = NULL;
        }
    };
    void insert(int val, node *root){
        for(int i = 31; i >= 0; i --){
            bool bit = (val & (1 << i));
            if(root -> next[bit] == NULL){
                root -> next[bit] = new node();
            }
            root = root -> next[bit];
        }
    }
    int endAt(int val, node *root){
        int ans = 0;
        for(int i = 31; i >= 0; i --){
            bool bit = (val & (1 << i));
            if(root -> next[1 ^ bit] != NULL){
                root = root -> next[1 ^ bit];
                ans += (1 << i);
            }
            else{
                root = root -> next[bit];
            }
        }
        return ans;
    }
    int maxSubarrayXOR(int N, int arr[]){    
        node *root = new node();
        int curr = 0;
        insert(curr, root);
        int ans = 0;
        for(int i = 0; i < N; i ++){
            curr ^= arr[i];
            ans = max(ans, endAt(curr, root));
            insert(curr, root);
        }
        return ans;
    }
};