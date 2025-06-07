 #include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std; 

class Heap {
    vector<int> vec; // CBT 

public:
    // max heap 
    void push(int val) {
        vec.push_back(val);

        int x = vec.size() - 1;
        int parI = (x - 1) / 2;

        while (parI >= 0 && vec[x] > vec[parI]) {
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x - 1) / 2;
        }
    }

    void heapify(int i) {
        if (i >= vec.size()) return;

        int l = 2 * i + 1;
        int r = 2 * i + 2;

        int maxIdx = i;
        if (l < vec.size() && vec[l] > vec[maxIdx]) maxIdx = l;
        if (r < vec.size() && vec[r] > vec[maxIdx]) maxIdx = r;

        if (maxIdx != i) {
            swap(vec[i], vec[maxIdx]);
            heapify(maxIdx);
        }
    }

    void pop() {
        if (vec.empty()) return;

        swap(vec[0], vec[vec.size() - 1]);
        vec.pop_back();
        heapify(0);
    }

    int top() {
        return vec[0]; // highest priority element 
    }

    bool empty() {
        return vec.size() == 0;
    }
};

struct ComparePair {
    bool operator()(pair<string, int>& p1, pair<string, int>& p2) {
        return p1.second < p2.second;
    }
};

int main() {
    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq;

    pq.push({"AMAN", 500});
    pq.push({"BHUMI", 1000});
    pq.push({"CHTEIN", 100});

    while (!pq.empty()) {
        cout << "top = " << pq.top().first << " , " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}
