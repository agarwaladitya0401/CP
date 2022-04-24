// https://codeforces.com/contest/1672/problem/F1

// see sol at: https://www.youtube.com/watch?v=v_XvzqFEgPQ&t=3540s ( see only the explanation, not code)

// here we make a map of all the entries and indices at which they are present and then sort according to the size of vector of their indices
// and if the size of vector is same we see the relative order as explained in above video. and doing the left shift of our vector. 

// https://codeforces.com/contest/1672/submission/154808244 (submission)

  void solve() {
    int n, m;
    cin >> n;

    int a[n];
    map<int, vector<int>> ids;
    fo(i, 0, n) {
        cin >> a[i];
        ids[a[i]].push_back(i);
    }
    vector<pair<pair<int, int>, int>> v;

    for (auto i : ids) {
        // int tt = (i.second[0]);
        v.push_back({{i.second.size(), i.second[0]}, i.first});
    }

    // sort according to the size of vector of their indices and if the size of vector is same we see the relative order
    sort(all(v));

    vector<int> old, nw;
    for (auto i : v) {
        // watch(i.second);
        for (auto j : ids[i.second]) {
            old.push_back(j);
        }
    }

    auto it = v.back();

    int vn = v.size();

    // doing the left shift of our vector.
    rfo(i, vn - 1, 1) {
        v[i] = v[i - 1];
    }

    v[0] = it;

    int b[n];

    for (auto i : v) {
        for (auto j : ids[i.second]) {
            nw.push_back(j);
        }
    }

    fo(i, 0, n) {
        b[old[i]] = a[nw[i]];
    }

    fo(i, 0, n) {
        cout << b[i] << " ";
    }
    hh;
    return;
}
