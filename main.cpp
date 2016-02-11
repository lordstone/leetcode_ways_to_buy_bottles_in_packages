class waysToBuy{

public:
    vector<vector<int>> findWaysToBuy(vector<int>& myList, int n){
        //output the different way to buy n bottles with packages
        //no duplicate allowed
        vector<vector<int>> res;
        if(n == 0) return res;
        vector<int> out;
        DFS(myList, n, res, out, 0);
        return res;
    }

    void DFS(vector<int>& myList, int n,vector<vector<int>>& res,vector<int> out, int start){
        if(n < 0) return;
        if(n == 0){
            res.push_back(out);
            return;
        }
        if(start > myList.size() - 1) {
            return;
        }
        int curAmount = 0;
        DFS(myList, n , res, out, start + 1);
        while(curAmount <= n){
            out.push_back(myList[start]);
            curAmount += myList[start];
            DFS(myList, n - curAmount, res, out, start + 1);
            //out.pop_back();
        }
    }
};
