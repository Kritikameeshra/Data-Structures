#User function Template for python3

class Solution:
    def pattern (self, arr):
        res = ''
        for i in range(n):
            s = ''.join(str(j) for j in arr[i])
            if s == s[::-1]:
                res = str(i)+" R"
                break
            # s = ''.join(str(arr[i][l]) for l in range(k))
            col = ''
            for k in range(n):
                col+=str(arr[k][i])
            if col == col[::-1] and res == '':
                res = str(i)+" C"
        if res == '':
            return -1
        return res


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    ob = Solution()
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        a = list()
        c = 0
        for i in range(0, n):
            X = list()
            for j in range(0, n):
                X.append(arr[c])
                c += 1
            a.append(X)
        ans = ob.pattern(a)
        print(ans)

# } Driver Code Ends