
# python3 winner.py < winnerTest
# url: https://codeforces.com/problemset/problem/2/A


# i didnt like making this code so i wont comment c:

scoreTable={}

def addScore(name,score,date):
    if name not in scoreTable:
        auxDic={}
        auxDic[date]=score
        scoreTable[name]=[auxDic[date],auxDic]
    else:
        scoreTable[name][0]+=score
        scoreTable[name][1][date]=scoreTable[name][0]
            

x = input()
for i in range(int(x)):
    name, score= (var for var in input().split(" "))
    addScore(name,int(score),i)



maxScore=0
for key in scoreTable.keys():
    maxScore=scoreTable[key][0]
    break


for key in scoreTable.keys():
    if maxScore<scoreTable[key][0]:
        maxScore=scoreTable[key][0]




finalist=[]
dates=[]

for key in scoreTable.keys():
    if scoreTable[key][0]==maxScore:
        finalist.append(key)
        dates.append(1001)


for i in range(len(finalist)):
    for date in scoreTable[finalist[i]][1]:
        if scoreTable[finalist[i]][1][date]>=maxScore:
            dates[i]=date
            break


minDate=dates[0]
datei=0
for i in range(len(dates)):
    if dates[i]<minDate:
        minDate=dates[i]
        datei=i

print(finalist[datei])