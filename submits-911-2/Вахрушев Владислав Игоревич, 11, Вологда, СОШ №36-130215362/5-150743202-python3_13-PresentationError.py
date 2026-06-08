N = int(input())
p_list = [int(x) for x in input().split()]
FR_count = int(input())
FR_index = [int(x)-1 for x in input().split()]


for p in p_list:
    if p_list.index(p) in FR_index:
        p_list[p_list.index(p)] = [p,True]
    else:
        p_list[p_list.index(p)] = [p,False]

max_F = 0
save_T = 0
for p in p_list:
    for i in range(-1,2,1):
        T = int(p[0])+i
        TP = 0
        FP = 0
        TN = 0
        FN = 0
        for p in p_list:
            if p[0]>=T and p[1]==False:
                FP +=1
            if p[0]>=T and p[1]==True:
                TP +=1
            if p[0]<T and p[1]==True:
                FN +=1
            if p[0]<T and p[1]==False:
                TN +=1
        if TP+FP > 0:
            PR = TP/(TP+FP)
        else:
            PR = 0

        if TP+FN > 0:
            RC = TP/(TP+FN)
        else:
            RC = 0
        if RC+PR==0:
            F = 0
        else:
            F = 2*PR*RC/(PR+RC)

        if F>max_F:
            max_F=F
            save_T=T
        print("i=",i,"F=",F,"T=",T)
print("----------",save_T)







            

                                                                                                                     
    
    
