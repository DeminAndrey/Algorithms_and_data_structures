def draw():
    for x in range(0, 25):
        for y in range(0, 25):
            if (x < y):
                print('#', end =" ")
            else:
                print('.', end = " ")
        print()
    
draw()