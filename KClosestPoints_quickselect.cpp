class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //quick select
        int pivot = -1;
        int left = 0, right = points.size()-1;
        while(1) {
            pivot = partition(left, right, points);
            if(pivot == (k-1)) {
                return vector<vector<int>>(points.begin(), points.begin()+k);
            }
            else if(pivot > (k-1)) {
                right = pivot - 1;
            }
            else { //pivot < k
                left = pivot + 1;
            }
        }
    }
    int partition(int left, int right, vector<vector<int>>& points) {
        int ran = (rand() % (right-left+1)) + left;
        points[left].swap(points[ran]);
        int pivot = left;
        for(int i=left, j=right; i<j;) {
            if(!closer(points[i], points[pivot])) {
                points[i].swap(points[j]);
                j--;
            }
            else {
                i++;
            }
            if(i == j) {
                if(!closer(points[i], points[pivot])) {
                    points[i-1].swap(points[pivot]);
                    return (i-1);
                }
                else {
                    points[i].swap(points[pivot]);
                    return i;
                }
            }
        }
        return pivot;
    }
    bool closer(const vector<int> a, const vector<int> b) {
        return (a[0]*a[0]+a[1]*a[1]) <= (b[0]*b[0]+b[1]*b[1]);
    }
};