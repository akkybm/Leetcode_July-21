#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;



typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
class MedianFinder {
public:
    
    vector<int> median;
    ordered_set s;
    MedianFinder() {
    }
    
    void addNum(int num) {
        median.push_back(num);
        s.insert(num);
    }
    
    double findMedian() {
        double med = 0.0;
        int n=median.size();
        if(n%2==0){
            med = ((double)(*(s.find_by_order(n/2))+(*(s.find_by_order(n/2-1)))))/2.0;
        }else{
            med = (*(s.find_by_order(n/2)))*1.0;
        }
        return med;
    }
};
