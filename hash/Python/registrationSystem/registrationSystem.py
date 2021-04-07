
# python3 registrationSystem.py < registrationSystemTest
# url: https://codeforces.com/problemset/problem/4/C

nameDic={}

def response(name):
    if name not in nameDic:
        nameDic[name]=0
        print("OK")
    else:
        nameDic[name]+=1
        print(name+str(nameDic[name]))

x = input()
for i in range(int(x)):
    name=input()
    response(name)