class Solution:
    def checkSorted(self, arr):
        n=len(arr)
        count=0
        for i in range(n):
            if arr[i]!=(i+1) and count<2:
                ele=arr[i]
                arr[i],arr[ele-1]=arr[ele-1],arr[i] 
                count+=1
        
        for i in range(n):
            if arr[i]!=(i+1):
                return False
        return True


#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input().strip())

    for _ in range(t):
        arr = list(map(int, input().split()))

        sol = Solution()
        result = sol.checkSorted(arr)
        if result:
            print("true")
        else:
            print("false")

# } Driver Code Ends