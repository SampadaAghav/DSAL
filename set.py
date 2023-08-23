'''
NAME : AGHAV SAMPADA RAMKRISHNA
CLASS : SE COMP 1
ROLL NO : 056
PRN NO : F21111061
'''
class Python:
    def input(self):
        self.set1 = []
        n = int(input("Enter the size of set 1 : "))
        for i in range(n):
            m = input("Enter the elements : ")
            if (m not in self.set1):
                self.set1.append(m)
        print("set  elements are : ")
        print("{", end="")
        for i in range(n - 1):
            print(self.set1[i], end=",")
        print(self.set1[n - 1], end="")
        print("}")

    def remove(self):
        x = input("Enter element to remove : ")
        self.set1.remove(x)
        print("New set elements are : ")
        print("{", end="")
        for i in range(len(self.set1) - 1):
            print(self.set1[i], end=",")
        print(self.set1[len(self.set1) - 1], end="")
        print("}")

    def search(self):
        b = input("Enter the element to search ")
        if b in self.set1:
            print("Element present at index : ", self.set1.index(b))
        else:
            print("Element not present")

    def size(self):
        count=0
        iterator=iter(self.set)
        while True:
            try:
                next(iterator)
                count=count+1
            except StopIteration:
                break
        print("Size of set is : ", len(self.set1))

    def intersect(self):
        self.set2 = []
        s3 = []
        n = int(input("Enter the size of set 2 : "))
        for i in range(n):
            m = input("Enter the elements : ")
            if (m not in self.set2):
                self.set2.append(m)
        print("set  elements are : ")
        print("{", end="")
        for i in range(len(self.set2) - 1):
            print(self.set2[i], end=",")
        print(self.set2[n - 1], end="")
        print("}")
        print("Intersection of two sets is : ")
        print("{", end="")
        for i in self.set1:
            if (i in self.set2):
                s3.append(i)
        for i in range(len(s3) - 1):
            print(s3[i], end=",")
        print(s3[len(s3) - 1], end="")
        print("}")

    def union(self):
        s3 = self.set1 + self.set2
        for i in self.set1:
            if i in self.set2:
                s3.remove(i)
        print("Union of two sets is : ")
        print("{", end="")
        for i in range(len(s3) - 1):
            print(s3[i], end=",")
        print(s3[len(s3) - 1], end="")
        print("}")

    def diff(self):
        s3 = []
        for i in self.set1:
            if i not in self.set2:
                s3.append(i)
        print("Difference of two sets is : ")
        print("{", end="")
        for i in range(len(s3) - 1):
            print(s3[i], end=",")
        print(s3[len(s3) - 1], end="")
        print("}")

    def sub(self):
        if (all(i in self.set1 for i in self.set2)):
            print("s1 is a subset of s2")
        else:
            print("s1 is not a subset of s2")


a = Python()
while (True):
    g= int(input("Enter your choice : \n1. Input the elements \n2. Remove element\n3. Search an element \n4. Size of set "
                   "\n5. Intersection of two sets\n6. Union of two sets \n7. Difference of two sets\n8. Subset of a set\n9. Exit the process\n"))
    if (g == 1):
        a.input()
    elif (g == 2):
        a.remove()
    elif (g == 3):
        a.search()
    elif (g == 4):
        a.size()
    elif (g == 5):
        a.intersect()
    elif (g == 6):
        a.union()
    elif (g == 7):
        a.diff()
    elif (g == 8):
        a.sub()
    else:
        break
