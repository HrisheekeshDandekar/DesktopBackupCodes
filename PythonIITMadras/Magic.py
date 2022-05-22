words = []

for i in range(5):
    words.append(input())

sequence_broken = False

for i in range(len(words) - 1):
    if words[i] not in words[i + 1]:
        sequence_broken = True 
        break

if sequence_broken == True:
    print("non-magical")
elif sequence_broken == False:
    print("magical")

lettercord = "ABCDEFGH"
numbercord = "12345678"
c1=input()
c2=input()
if (abs(lettercord.index(c1[0]) - lettercord.index(c2[0])) == abs(numbercord.index(c1[1]) - numbercord.index(c2[1]))):
    print("YES")
elif (abs(lettercord.index(c1[0]) - lettercord.index(c2[0])) != abs(numbercord.index(c1[1]) - numbercord.index(c2[1]))):
    print("NO")
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    