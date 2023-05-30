class Set:
    
    def __init__(self,n):
        self._s=[]
        for i in range(n):
            e = int(input("Enter Element %d : "%(i+1)))
            self.add(e)

    def add(self, e):
        if e not in self:
            self._s.append(e)

    def __contains__(self,e):
        return e in self._s

    def __str__(self):
        string = "\n{"
        for i in range(len(self.get_set())):
            string = string + str(self.get_set()[i])
            if i!= len(self.get_set())-1:
                string = string + " , "
        string = string + "}"
        return string

    def __len__(self):
        return len(self._s)

    def get_set(self):
        return self._s

    def remove(self,e):
        if e in self:
            self.get_set().remove(e)

    def intersection(self, setB):
        newSet=Set(0)
        for i in range(len(self.get_set())):
            for j in range(len(setB.get_set())):
                if self.get_set()[i] == setB.get_set()[j]:
                    newSet.add(self.get_set()[i])
        return newSet

    def __eq__(self, setB):
        if(len(self.get_set()) != len(setB.get_set())):
            return False
        else:
            return self.subset(setB)
            
    def subset(self, setB):
        for e in setB.get_set():
            if e not in self.get_set():
                return False
        return True

    def __iter__(self):
        return iter(self._s)

    def union(self, setB):
        newSet = self
        for e in setB:
            if e not in self.get_set():
                newSet.add(e)
        return newSet

    def difference(self, setB):
        newSet = Set(0)
        for e in self.get_set():
            if e not in setB.get_set():
                newSet.add(e)
        return newSet
