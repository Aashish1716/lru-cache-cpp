#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
    int cap;
    list<pair<int,int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        auto it = mp[key];
        int val = it->second;
        l.erase(it);
        l.push_front({key,val});
        mp[key] = l.begin();
        return val;
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()) l.erase(mp[key]);
        l.push_front({key,value});
        mp[key] = l.begin();
        if(l.size() > cap) {
            auto last = l.back();
            mp.erase(last.first);
            l.pop_back();
        }
    }

    void display() {
        cout << "Cache: ";
        for(auto x : l){
            cout << "(" << x.first << "," << x.second << ") ";
        }
        cout << endl;
    }
};

int main() {

    LRUCache cache(2);
    cache.put(1,10);
    cache.put(2,20);
    cache.display();
    cout << "get(1): " << cache.get(1) << endl;
    cache.put(3,30);
    cache.display();
    cout << "get(2): " << cache.get(2) << endl;
    cache.put(4,40);
    cache.display();
    cout << "get(1): " << cache.get(1) << endl;
    cout << "get(3): " << cache.get(3) << endl;
    cout << "get(4): " << cache.get(4) << endl;

    return 0;
}
