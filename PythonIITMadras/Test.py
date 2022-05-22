# Input of 5 lines 
x1 = int(input())
y1 = int(input())
x2 = int(input())
y2 = int(input())
x3 = int(input())

def calc_y3():
    y3 = (slope * (x3 - x1)) + y1
    return y3

if (x2 - x1) == 0:
    print("Vertical Line")

else:
    slope = (y2 - y1) / (x2 - x1)
    print('%.1f' %calc_y3())
    if slope == 0:
        print("Horizontal Line")
    elif slope > 0:
        print("Positive Slope")
    else:
        print("Negative Slope")
