h1 = int(input())
m1 = int(input())

h2 = int(input())
m2 = int(input())

result = 0
def beaut(Z):
    if int(Z[:2]) == int(Z[2:]):
        return True
    elif (int(Z[0])) == (int(Z[1]) - 1) == (int(Z[2]) - 2) == (int(Z[3]) - 3):
        return True
    elif (int(Z[0])) == (int(Z[3])) and (int(Z[1]) == int(Z[2])):
        return True
    else:
        return False

if h2 < h1:
    for i in range(h1, 24):
        if i == h1 and i != h2:
            for minutes in range(m1, 60):
                chasi = (f"{i:02}{minutes:02}")
                if beaut(chasi) == True:
                    result += 1
        elif i != h1 and i != h2:
            for minutes in range(0, 60):
                chasi = (f"{i:02}{minutes:02}")
                if beaut(chasi) == True:
                    result += 1
        elif i != h1 and i == h2:
            for minutes in range(0, m2 + 1):
                chasi = (f"{i:02}{minutes:02}")
                if beaut(chasi) == True:
                    result += 1
        else:
            for minutes in range(m1, m2 + 1):
                chasi = (f"{i:02}{minutes:02}")
                if beaut(chasi) == True:
                    result += 1
    for i in range(0, h2 + 1):
        if i == h1 and i != h2:
            for minutes in range(m1, 60):
                chasi = (f"{i:02}{minutes:02}")
                if beaut(chasi) == True:
                    result += 1
        elif i != h1 and i != h2:
            for minutes in range(0, 60):
                chasi = (f"{i:02}{minutes:02}")
                if beaut(chasi) == True:
                    result += 1
        elif i != h1 and i == h2:
            for minutes in range(0, m2 + 1):
                chasi = (f"{i:02}{minutes:02}")
                if beaut(chasi) == True:
                    result += 1
        else:
            for minutes in range(m1, m2 + 1):
                chasi = (f"{i:02}{minutes:02}")
                if beaut(chasi) == True:
                    result += 1



for i in range(h1, h2 + 1):
    if i == h1 and i != h2:
        for minutes in range(m1, 60):
            chasi = (f"{i:02}{minutes:02}")
            if beaut(chasi) == True:
                result += 1
    elif i != h1 and i != h2:
        for minutes in range(0, 60):
            chasi = (f"{i:02}{minutes:02}")
            if beaut(chasi) == True:
                result += 1
    elif i != h1 and i == h2:
        for minutes in range(0, m2 + 1):
            chasi = (f"{i:02}{minutes:02}")
            if beaut(chasi) == True:
                result += 1
    else:
        for minutes in range(m1, m2 + 1):
            chasi = (f"{i:02}{minutes:02}")
            if beaut(chasi) == True:
                result += 1
print(result)
