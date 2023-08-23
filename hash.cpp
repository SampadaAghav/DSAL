
class Hashtable_Linear:

    hashtable_telenum = []
    hashtable_name = []

    def __init__(self):
        self.m = int(input("Enter the size for Hash Table:"))

        for i in range(self.m):
            self.hashtable_telenum.append(0)
            self.hashtable_name.append(0)

    def hash_function(self, x):
        key = x % self.m
        return key

    def initialize(self, array, names):
        for i in range(len(array)):
            key = self.hash_function(array[i])
            while self.hashtable_telenum[key] != 0:
                key = (key + 1) % self.m
            self.hashtable_telenum[key] = array[i]
            self.hashtable_name[key] = names[i]

    def display(self):
        print("\nKey - Value")
        for i in range(self.m):
            print(i, '-', self.hashtable_telenum[i], ":", self.hashtable_name[i])


class Hashtable_DoubleHashing:
    hashtable_telenum = []
    hashtable_name = []

    def __init__(self):
        self.m = int(input("Enter size of Hash Table:"))
        self.p = self.get_primenumber(self.m - 1)

        for i in range(self.m):
            self.hashtable_telenum.append(0)
            self.hashtable_name.append(0)

    def get_primenumber(self, n):
        while True:
            if self.isprime(n):
                return n
            n -= 1

    def isprime(self, n):
        if n <= 1:
            return False
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                return False
        return True

    def hash_function1(self, x):
        return x % self.m

    def hash_function2(self, x):
        return self.p - (x % self.p)

    def initialize(self, array, names):
        for i in range(len(array)):
            key = self.hash_function1(array[i])
            if self.hashtable_telenum[key] == 0:
                self.hashtable_telenum[key] = array[i]
                self.hashtable_name[key] = names[i]
            else:

                jump = self.hash_function2(array[i])
                while True:

                    next_key = (key + jump) % self.m
                    if self.hashtable_telenum[next_key] == 0:
                        self.hashtable_telenum[next_key] = array[i]
                        self.hashtable_name[next_key] = names[i]
                        break
                    else:
                        jump += self.hash_function2(array[i])

    def display(self):
        print("\nKey - Value")
        for i in range(self.m):
            print(i, '-', self.hashtable_telenum[i], ":", self.hashtable_name[i])

def main():
    n = int(input("Enter number of persons:"))
    s = []
    p = []
    g = 0
    for i in range(n):
        elmt = int(input(f"Enter telephone number({i + 1}):"))
        while (elmt < 1000000000 or elmt > 9999999999):
            print("Wrong Input has been entered : ")
            elmt = int(input(f"Enter telephone number({i + 1}):"))
        s.append(elmt)
        a = (input(f"Enter name of person ({i + 1}):"))
        p.append(a)

    flag = 0
    while (flag == 0):
        g = int(input("Enter your option : 1 for Linear or 2 for Double Hashing : "))
        if g == 1:
            table1 = Hashtable_Linear()
            table1.initialize(s, p)
            table1.display()
        elif g == 2:
            table2 = Hashtable_DoubleHashing()
            table2.initialize(s, p)
            table2.display()
        else:
            flag = 1
main()
