def find_num(exp,m,p):
    for x in range(1000):
        print(eval(exp))
        if eval(exp)%m == p:
            return x

print(find_num("10-x-1",4,3))