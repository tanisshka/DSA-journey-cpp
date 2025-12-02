class Diagonal:
    def __init__(self, n=10):
        if n <= 0:
            raise ValueError("Matrix dimension must be positive")
        self.n = n
        self.A = [0] * n  # store only diagonal elements

    def set(self, i, j, x):
        if 0 <= i < self.n and 0 <= j < self.n:
            if i == j:
                self.A[i] = x
        else:
            raise IndexError(f"Invalid index ({i}, {j}) for matrix of size {self.n}")

    def get(self, i, j):
        if 0 <= i < self.n and 0 <= j < self.n:
            return self.A[i] if i == j else 0
        else:
            raise IndexError(f"Invalid index ({i}, {j}) for matrix of size {self.n}")

    def display(self):
        for i in range(self.n):
            for j in range(self.n):
                print(self.get(i, j), end="\t")
            print()

    def get_dimension(self):
        return self.n


if __name__ == "__main__":
    while True:
        try:
            d = int(input("Enter dimension: "))
            if d > 0:
                break
            print("Dimension must be greater than 0")
        except ValueError:
            print("Invalid input! Please enter a number.")

    dm = Diagonal(d)

    for i in range(d):
        while True:
            try:
                x = int(input(f"Enter diagonal element [{i}{i}]: "))
                dm.set(i, i, x)
                break
            except ValueError:
                print("Invalid input! Please enter a number")

    print("Matrix:")
    dm.display()
