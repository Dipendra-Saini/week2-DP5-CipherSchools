#include <bits/stdc++.h>
using namespace std;

struct comp {
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.second == p2.second)
            return p1.first < p2.first;
        return p1.second < p2.second;
    }
};

bool compare(pair<int, int> p1, pair<int, int> p2){
    if (p1.second == p2.second)
        return p1.first > p2.first;
    return p1.second > p2.second;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for(int i: nums){
        freq[i]++;
    }
    vector<pair<int,int>> d_freq(freq.begin(),freq.end());
    sort(d_freq.begin(),d_freq.end(), compare);

//    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq(freq.begin(),freq.end());
    vector<int> result;
    for(int i=0;i<k;i++){
        result.push_back(d_freq[i].first);
    }
    return result;
}


int main() {
    vector<int> result;
    vector<int> nums = {1,2,2,3,3,3,3,4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,2};
    result = topKFrequent(nums,1);
    for(auto i : result){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
