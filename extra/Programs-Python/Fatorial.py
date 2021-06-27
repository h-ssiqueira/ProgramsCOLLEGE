x = int(input("Insert the number: "))
r = 1
if x == 1 | x == 0:
    print(1)
else:
    while x != 1:
        r *= x
        x -= 1
    print(r)