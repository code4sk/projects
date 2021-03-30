#include <bits/stdc++.h>

using namespace std;

struct duo{
    int a, b;
    bool operator<(const duo &k) const
    {
        return a < k.a;
    }
};
struct MyComparator{
bool operator()(duo d1, duo d2)const{
    return (d1.b < d2.b);
}
};

bool comparator(duo a, duo b) {
    return a.b < b.b;
}


int main()
{
    //priority_queue <duo > pq;
    priority_queue <duo, vector<duo>, comparator> pq;
    //priority_queue<int, map<int>, greater<int>> pq;
    //pq.push({1, 2});
    pq.push({1, 2});
    pq.push({3, -1});
    cout<<pq.top().a<<" "<<pq.top().b<<endl;
    pq.pop();
    cout<<pq.top().a<<" "<<pq.top().b<<endl;

    return 0;
}
