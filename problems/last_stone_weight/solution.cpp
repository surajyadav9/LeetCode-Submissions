class Solution {
public:
    int stones_left;
    int lastStoneWeight(vector<int>& stones) {
        
        int n = stones.size();
        int i,j;
        
        cout << n << endl;
        stones_left = n; // varying stones in the array
        build_max_heap(stones);
        
        while(stones_left>1)
        {
           for(int i=0;i<stones_left;i++)
               cout << stones[i] << " ";
            i = extract_max(stones);
            j = extract_max(stones);
            cout << '\n'<<i <<" " << j<<endl;
            
            if(i != j)
            {
                insert(stones , i-j);
            }   
        }
        
        if(stones_left == 1)
        {
            cout << stones[stones_left-1] << endl;
            return stones[stones_left-1];            
        }
        else
            return 0;  
    }
    
    void build_max_heap(vector<int> &stones)
    {
        int i;
        if(stones_left%2 == 0)
            i = stones_left/2 -1;
        else
            i = stones_left/2;
        
        for(; i>= 0 ; i--)
        {
            max_heapify(stones , i);
        }
    }
    
    void max_heapify(vector<int> &stones , int i )
    {
        int Lchild;
        int Rchild;
        int largest,temp;
        
        if(i==0)
        {
            Lchild = 1;
            Rchild = 2;
        }
        else
        {
            Lchild = 2*i;
            Rchild = 2*i+1;
        }
        
        if(Lchild < stones_left && stones[Lchild] > stones[i])
            largest = Lchild;
        else
            largest = i;
        
        if(Rchild < stones_left && stones[Rchild] > stones[largest])
            largest = Rchild;
        
        if(largest != i)
        {
            temp = stones[i];
            stones[i] = stones[largest];
            stones[largest] = temp;
            
            max_heapify(stones , largest);
        }
    }
    
    int extract_max(vector<int>&stones)
    {
        int max = stones[0];
        stones[0] = stones[--stones_left];
        max_heapify(stones,0);
        return max;
    }
        
        
    void insert(vector<int>&stones , int new_weight)
    {
        stones[stones_left++] = new_weight;
        build_max_heap(stones);
    }
    
   
        
};