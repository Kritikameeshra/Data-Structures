#User function Template for python3


class Solution:
    def findMissing(self,a,b,n,m):
    # code here
        b = set(b)
        
        abssent = []
        
        for _ in a:
            if _ not in b:
                abssent.append(_)
        
        return abssent



#{ 
 # Driver Code Starts
#Initial Template for Python 3



t=int(input())
for _ in range(0,t):
   # n=int(input())
    l = list(map(int, input().split()))
    n=l[0]
    m=l[1]
    a = list(map(int,input().split()))
    b = list(map(int, input().split()))
    ob=Solution()
    ans=ob.findMissing(a,b,n,m)
    for each in ans:
        print(each,end=' ')
    print()
# } Driver Code Ends