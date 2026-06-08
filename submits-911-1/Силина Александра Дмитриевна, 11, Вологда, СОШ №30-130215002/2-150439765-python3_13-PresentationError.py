def find_divisors(n):
    divisors=[]
    for i in range(1, int(n**0.5)+1):
        if n%1==0:
            divisors_append(i)
            if i!=n//i:
                ivisors.append(n//i)
                return divisors

def find_number(n):
    for num in range (1,10**6+1):
        divisors=find_divisors(num)
        divisors.sort()
        current_sum=0
        selected_divisors=[]
        for divisor in divisors:
            if current_sum+divisor<=num:
                current_sum+=divisor
                selected_divisors.append(divisor)

            if current_sum==num and len(selected_divisors)==n:
                return num,selected_divisors
            return -1,[]
        n=int(input())
        result,divisors=find_number(n)
        if result !=-1:
            print(resuly)
            print("".join(map(str,divisors)))
        else:
                print(-1)