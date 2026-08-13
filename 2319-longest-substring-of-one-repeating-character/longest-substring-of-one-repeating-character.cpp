class Solution {
public:

    struct Node {
        int pref, suff, best, len;
        char leftChar, rightChar;

        Node() {
            pref = suff = best = len = 0;
            leftChar = rightChar = '#';
        }
    };

    string s;
    vector<Node> seg;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.pref = a.pref;
        if (a.pref == a.len && a.rightChar == b.leftChar)
            res.pref = a.len + b.pref;

        res.suff = b.suff;
        if (b.suff == b.len && a.rightChar == b.leftChar)
            res.suff = b.len + a.suff;

        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar)
            res.best = max(res.best, a.suff + b.pref);

        return res;
    }

    void build(int idx, int l, int r) {

        if (l == r) {
            seg[idx].len = 1;
            seg[idx].pref = 1;
            seg[idx].suff = 1;
            seg[idx].best = 1;
            seg[idx].leftChar = s[l];
            seg[idx].rightChar = s[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, char ch) {

        if (l == r) {
            s[pos] = ch;

            seg[idx].leftChar = ch;
            seg[idx].rightChar = ch;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * idx, l, mid, pos, ch);
        else
            update(2 * idx + 1, mid + 1, r, pos, ch);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    vector<int> longestRepeating(
        string s_,
        string queryCharacters,
        vector<int>& queryIndices) {

        s = s_;

        int n = s.size();

        seg.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};