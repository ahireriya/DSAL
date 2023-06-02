from adt_set_operations import Set

def create_set():
    n = int(input("\nEnter the Number of Elements in set : "))
    s = Set(n)
    return s

print("\nSet A : ")
s1 = create_set()
print(str(s1))

while(True):
    print("\n******MENU******")
    print("1 : Add")
    print("2 : Remove")
    print("3 : Contains")
    print("4 : Size")
    print("5 : Intersection")
    print("6 : Union")
    print("7 : Difference")
    print("8 : Subset")
    print("9 : Exit")
    ch=int(input("Enter your choice : "))
    if(ch==9):
        print("\nEnd of Program")
        break
    elif(ch==1):
        e=int(input("Enter the element to add : "))
        s1.add(e)
        print(str(s1))
    elif(ch==2):
        e=int(input("Enter the element to remove : "))
        s1.remove(e)
        print(str(s1))
    elif(ch==3):
        e=int(input("Enter the element to search : "))
        if e in s1:
            print("Number is present in Set")
        else:
            print("Number is not present in Set")
    elif(ch==4):
        print("Size of Set : ",len(s1))
    elif(ch==5):
        s2=create_set()
        s3=s1.intersection(s2)
        print("Set A : ",str(s1))
        print("Set B : ",str(s2))
        print("Set c : ",str(s3))
    elif(ch==6):
        s2=create_set()
        s3=s1.union(s2)
        print("Set A : ",str(s1))
        print("Set B : ",str(s2))
        print("Set c : ",str(s3))
    elif(ch==7):
        s2=create_set()
        s3=s1.difference(s2)
        print("Set A : ",str(s1))
        print("Set B : ",str(s2))
        print("Set c : ",str(s3))
    elif(ch==8):
        s2=create_set()
        isSubset = s1.subset(s2)
        print("Set A : ",str(s1))
        print("Set B : ",str(s2))
        if isSubset:
            print("Set B is Subset of Set A")
        else:
            print("Set B is not Subset of Set A")
    else:
        print("Incorrect Choice")    
