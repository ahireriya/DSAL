max  = int(input("Enter the size of hash table : "))
hash = [-1]*max
hash1 = [-1]*max
keys = []

def LinearProbe(k):
    pos = k % max
    if(hash[pos]==-1):
        hash[pos] = k
    else:
        while(hash[pos]!=-1):
            pos = (pos + 1)%max
        hash[pos] = k

def QuadraticProbe(k):
    pos = k % max
    if(hash1[pos]==-1):
        hash1[pos] = k
    else:
        i=1
        while(True):
            newpos = (pos + (i*i))%max
            if(hash1[newpos]==-1):
                hash1[newpos]=k
                break
            i+=1

def insert():
    print("\nLinear Probing")
    ans = 1
    cnt = 1
    while(ans==1):
        key = int(input("Enter Key : "))
        keys.append(key)
        LinearProbe(key)
        print(hash)
        cnt+=1
        if(cnt>max):
            print("\nHash Table is Full")
            print(hash)
            break
        ans = int(input("Enter more?(1/0) : "))

    print("\nQuadratic Probing")
    print("Keys : ",keys)
    for i in keys:
        QuadraticProbe(i)
        print(hash1)

def Lsearch(k):
    pos = k %max
    global lcmp
    lcmp=0
    lcmp+=1
    if(hash[pos]==k):
        return pos
    else:
        pos = (pos+1)%max
        for i in range(max-1):
            lcmp+=1
            if(hash[pos]==k):
                return pos
            pos = (pos+1)%max
        return -1

def Qsearch(k):
    pos = k %max
    global qcmp
    qcmp=0
    qcmp+=1
    if(hash1[pos]==k):
        return pos
    else:
        i=1
        for j in range(max-1):
            newpos = (pos + (i*i))%max
            qcmp+=1
            if(hash1[newpos]==k):
                return newpos
            i+=1
        return -1


def main():
    while(True):
        print("\n******MENU******")
        print("1 : Insert")
        print("2 : Display")
        print("3 : Search")
        print("4 : Exit")
        n = int(input("\nEnter your Choice : "))
        if(n==4):
            print("\n End of Program")
            break
        elif(n==1):
            insert()
        elif(n==2):
            print("\nUsing Linear Probing : ",hash)
            print("\nUsing Quadratic Probing : ",hash1)
        elif(n==3):
            k = int(input("\nEnter the key to search : "))
            print("\n Linear Search : ")
            location = Lsearch(k)
            if(location==-1):
                print("Element not found")
            else:
                print("\nElement found at location : ",location," with ",lcmp," number of comparisons")
            if(location!=-1):
                location = Qsearch(k)
                print("\nQuadratic Search")
                print("\nElement found at location : ",location," with ",qcmp," number of comparisons")
        else:
            print("\nIncorrect Choice!")
main()
