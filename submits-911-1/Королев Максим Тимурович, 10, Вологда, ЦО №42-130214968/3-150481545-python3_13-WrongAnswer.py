z, maximum, time, intervalu_nach, intervalu_konch, reclama_intervalov, vrema_mezdu, q = int(input()), int(input()), 0, [], [], [], [], 0    
for i in range(z):
    t1, t2 = map(int, input().split())
    intervalu_nach.append(t1)
    intervalu_konch.append(t2)
    reclama_intervalov.append(t2 - t1)
    time += t2 - t1
for i in range(z - 1):
    vrema_mezdu.append(intervalu_konch[i] - intervalu_nach[i + 1])
if time > maximum:
    if t2 < 3601:
        print(1)
    else:
        for i in range(z - 1):
            if reclama_intervalov[i] + reclama_intervalov[i + 1] > maximum:
                if reclama_intervalov[i] + reclama_intervalov[i + 1] + vrema_mezdu[i] < 3600:
                  print(-(reclama_intervalov[i] + reclama_intervalov[i + 1]) + maximum - 3600 + intervalu_konch[i+1] + 1)
else:
  print('-1')