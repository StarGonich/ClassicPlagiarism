h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())

start = h1 * 60 + m1
end = h2 * 60 + m2 

count = 0

for total_minutes in range(start, end +1):
   h = total_minutes//60
   m = total_minutes % 60

   hh = f"{h:02d}"
   mm = f"{m:02d}"

   digits_h = [int(d) for d in hh]
   digits_h = [int(d) for d in mm]

   if hh == mm:
       count += 1
       continue 

   if digits_m =  digits_h[::-1]:
       count += 1
       continue

  all_digits = digits_h + digits_m
  if (all_digits[1] - all_digits[0] = 1 and
      all_digits[2] - all_digits[1] = 1 and
      all_digits[3] - all_digits[2] = 1):
       count += 1

print(count)