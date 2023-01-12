class Solution {
public:
    
    struct MinHeap{
        vector <int> a;
        
        int left(int i){
            return 2*i + 1;
        }
        int right(int i){
            return 2*i + 2;
        }
        int parent(int i){
            return (i-1) / 2;
        }
        
        void siftUp(int i){
            if(i > 0 && a[parent(i)] > a[i]){
                swap(a[parent(i)], a[i]);
                siftUp(parent(i));
            }
        }
        
        void siftDown(int i){
            int minPos = i;
            
            if(left(i) < a.size() && a[left(i)] < a[minPos])
                minPos = left(i);
            if(right(i) < a.size() && a[right(i)] < a[minPos])
                minPos = right(i);
            
            if(minPos != i){
                swap(a[i], a[minPos]);
                siftDown(minPos);
            }
        }
        
        void insert(int val){
            a.push_back(val);
            
            siftUp(a.size()-1);
        }
        
        int extractMin(){
            int min = a[0];
            swap(a[0], a[a.size()-1]);

            a.pop_back();

            siftDown(0);

            return min;
        }
    };
    
    bool baseCase(vector<int> &nums){
        for(int num : nums)
            if(num != 0)
                return true;
        return false;
    }
    
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;

        while(true){
            MinHeap hp;

            for(auto num : nums){
                if(num != 0)
                hp.insert(num);
            }

            if(hp.a.size() == 0)
                break;

            int min = hp.extractMin();
            for(auto num : nums)
                num -= min;

            cnt++;
        }

        return cnt;
    }
};