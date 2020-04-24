a = float(input("Insert the value of a(ax2 + bx + c): "))
b = float(input("Insert the value of b(ax2 + bx + c): "))
c = float(input("Insert the value of c(ax2 + bx + c): "))

d = b ** 2 - (4 * a * c)

print("Delta =",d)

if d == 0:
    print("X =",-b / (2 * a))
elif d > 0:
    print("X1 =",(-b + d ** 0.5) / ( 2 * a),"\nX2 =",(-b - d ** 0.5) / (2 * a))
else:
    print("No real roots")
    
print("Xv =",-b / (2 * a),"\nYv =",-d / (4 * a))