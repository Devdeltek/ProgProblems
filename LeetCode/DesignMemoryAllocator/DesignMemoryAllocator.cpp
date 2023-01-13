class Allocator {
public:
    int *mem;
    int tot;
    Allocator(int n) {
        mem = new int[n]();
        tot = n;
    }
    
    int allocate(int size, int mID) {
        int currblock = 0;
        int spot = 0;
        for(int i = 0; i < tot; i++){
            if(mem[i] != 0){
                currblock = 0;
                continue;
            }
            else if(currblock == 0){
                spot = i;
                currblock++;
            }
            else{
                currblock++;
            }
            if(currblock == size){
                while(currblock > 0){
                    mem[i] = mID;
                    i--;
                    currblock--;
                }
                return spot;
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int num = 0;
        for(int i = 0; i < tot; i++){
            if(mem[i] == mID){
                mem[i] = 0;
                num++;
            }
        }
        return num;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */