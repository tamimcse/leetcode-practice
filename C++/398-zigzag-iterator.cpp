/*
https://leetcode.com/problems/zigzag-iterator/
*/
class ZigzagIterator {
    int idx1, idx2, m, n;
    bool first;
    vector<int> _v1, _v2;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        idx1 = 0;
        idx2 = 0;
        m = v1.size();
        n = v2.size();
        first = m > 0;
        _v1 = v1;
        _v2 = v2;
    }

    int next() {
        int ret;
        if (first) {
            ret = _v1[idx1++];
            if (idx2 < n)
                first = false;
        } else {
            ret = _v2[idx2++];
            if (idx1 < m)
                first = true;
        }
        return ret;
    }

    bool hasNext() {
        return idx1 < m || idx2 < n;
    }
};
