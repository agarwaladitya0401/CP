// https://leetcode.com/contest/weekly-contest-293/problems/count-integers-in-intervals/

// Use set to keep intervals in sorted order.
// Find the overlapping intervals and remove them.
// Add the new intervals
// Keep track of number of elements.

class CountIntervals {
public:
    
    set<pair<int,int>>st;
    int cnt = 0;
    
    CountIntervals() {
                
    }
    
    void add(int left, int right) {
        auto it = st.lower_bound({left,-1});
        
        if(it!=st.begin() and (--it)->second<left){
            ++it;
        }
        
        while(it!=st.end() and (it->first)<=right){
            left = min(left,it->first);
            right = max(right, it->second);
            
            cnt -= it->second - it->first +1;
            
            it = st.erase(it);
        }
        
        st.insert({left,right});
        cnt += right - left +1;
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
