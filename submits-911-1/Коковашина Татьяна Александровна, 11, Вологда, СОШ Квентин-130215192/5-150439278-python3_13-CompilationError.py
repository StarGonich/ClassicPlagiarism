import copy

def f(ij, nm):
   if ij ==-1:
       return nm -1
    if ij == nm:
        return 0
    return ij

def main():
    n, m, k = map(int, input().split())
    x =[list(input()) for i in range(n)]

    d = {"*": 1, ".": 0}
 
 
 
    matrix = [[0]* m for i in range(n)] 
    for kk in range(k):
        xx = copy.deepcopy(x)
        for i in range(n):
            for j in range(m):
                count = 0 
                count += d[x[f(i-1, n)][f(j-1, m)]]
                count += d[x[f(i-1, n)][f(j+1, m)]]
                count += d[x[f(i, n)][f(j-1, m)]]
                count += d[x[f(i, n)][f(j+1, m)]]
                count += d[x[f(i+1, n)][f(j-1, m)]]
                count += d[x[f(i+1, n)][f(j, m)]]
                count += d[x[f(i+1, n)][f(j+1, m)]]
                matrix[i][j] = count
                if x[i][j] == "*":
                    if not (1 < matrix[i][j] < 4):
                        xx[i][j] = "."
                else:
                    if matrix[i][j] == 3:
                        xx[i][j] = "*"
        x = copy.deepcopy(xx)        

 
    for i in range(n):
        print(*x[i], sep="")

 
if __name__ == "__main__":
    main()