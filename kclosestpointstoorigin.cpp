//https://leetcode.com/problems/k-closest-points-to-origin/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [&points](vector<int>a, vector<int> b) { return (a[0]*a[0]) + (a[1]*a[1])< (b[0]*b[0]) + (b[1]*b[1]);};
        priority_queue<vector<int>,vector<vector<int>>, decltype(comp)> heap(comp);

        for (vector<int> p : points) {
            heap.push(p);
            if (heap.size() > k) heap.pop();
        }
        
        vector<vector<int>> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = heap.top();
            heap.pop();
        }
        return res; 
    }

    bool Compare(vector<int>a, vector<int> b)
    {
        double dist1 = (a[0]*a[0]) + (a[1]*a[1]);
        double dist2 = (b[0]*b[0]) + (b[1]*b[1]);
    return dist1 < dist2;
    }
};