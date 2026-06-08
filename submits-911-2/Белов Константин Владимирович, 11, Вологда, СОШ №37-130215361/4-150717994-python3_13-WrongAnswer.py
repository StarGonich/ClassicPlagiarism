n = int(input())
coords = [[int(x) for x in input().split()] for _ in range(n)]

for k in range(1, n, 2):
    c = 0
    for c1 in coords:
        closest_coords = []
        for c2 in coords:
            coords_range = (abs(c1[0] - c2[0]) ** 2 + abs(c1[1] - c2[1]) ** 2) ** 0.5
            ccl = len(closest_coords)

            if c2 != c1 and (c2, coords_range) not in closest_coords:
                if ccl < k:
                    closest_coords.append((c2, coords_range))
                else:
                    for i in range(ccl):
                        mr = max(closest_coords)
                        if mr[1] > coords_range:
                            closest_coords.remove(mr)
                            closest_coords.append((c2, coords_range))

        c_0 = 0
        c_1 = 0

        for i in range(len(closest_coords)):
            if closest_coords[i][0][2] == 0:
                c_0 += 1
            else:
                c_1 += 1

        if c_0 > c_1:
            if 0 == c1[2]:
                c += 1
        else:
            if 1 == c1[2]:
                c += 1

    print(c)
