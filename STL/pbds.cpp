#include<bits/stdc++.h>

using namespace std;

#include<ext/pb_ds/assoc_container.hpp> // common file
#include<ext/pb_ds/tree_policy.hpp> // including tree_order_statistics_node_update

using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int> , rb_tree_tag, tree_order_statistics_node_update>


int main(){
    ordered_set st;

    st.insert(1);
    st.insert(3);
    st.insert(5);
    st.insert(5);
    st.insert(7);
    st.insert(8);

    for(auto x: st){
        cout << x << ' ';
    }
    cout << endl;

    cout << st.order_of_key(10) << endl; // st.order_of_key(x) returns the number of elements less than x ;

    auto it = st.find_by_order(10); // returns an iterator pointing to the 3rd index element [0-based indexing]

    cout << *it << endl;

    return 0;
}
