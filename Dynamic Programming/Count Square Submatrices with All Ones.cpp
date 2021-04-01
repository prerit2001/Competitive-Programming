class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        vector<vector<int>> pre_mat;
        for(int i=0;i<a.size();i++){
        	vector<int> v(a[i].size(),0);
        	pre_mat.push_back(v);
        	pre_mat[0][0] = a[0][0];
        	for(int j=0;j<a[i].size();j++){
                if(i>0 and j>0 and a[i][j])pre_mat[i][j]=a[i][j]+min({pre_mat[i-1][j],pre_mat[i][j-1],pre_mat[i-1][j-1]});
        		else pre_mat[i][j]=a[i][j];
        	}
        }

        int ans[a.size()+2];
        memset(ans,0,sizeof(ans));
        for(auto it : pre_mat){
        	for(auto i : it){
        		ans[i]++;
        	}
        }
        ans[a.size()+1]=0;
        ans[0]=0;
        sort(ans,ans+a.size()+2);
        for(int i=1;i<a.size()+2;i++){
        	ans[i]+=ans[i-1];
        }
        return accumulate(ans,ans+a.size()+2,0);
    }
};