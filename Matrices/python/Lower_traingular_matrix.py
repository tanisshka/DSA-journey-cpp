class LowerTriangular:
    def __init__(self,n):
        if n<=0:
           raise ValueError("Matrix dimension must be positive")
        self.n=n
        self.A=[0]*(n*(n+1)//2)

    #Row major set
    def set_row_major(self,i,j,x):
        if i>=j:
            index = (i * (i + 1)) // 2 + j
            self.A[index] = x

    def set_col_major(self,i,j,x):
        if i>=j:
            index = self.n * j - ((j - 1) * j) // 2 + (i - j)
            self.A[index] = x

    # Row-major get
    def get_row_major(self, i, j):
        if i >= j:
            index = (i * (i + 1)) // 2 + j
            return self.A[index]
        else:
            return 0

    # Column-major get
    def get_col_major(self, i, j):
        if i >= j:
            index = self.n * j - ((j - 1) * j) // 2 + (i - j)
            return self.A[index]
        else:
            return 0

    # Display matrix
    def display(self, row=True):
        print(f"\nLower Triangular Matrix ({'Row-Major' if row else 'Column-Major'}):")
        for i in range(self.n):
            for j in range(self.n):
                if row:
                    print(self.get_row_major(i, j), end="\t")
                else:
                    print(self.get_col_major(i, j), end="\t")
            print()

# ---------------- MAIN ----------------
if __name__ == "__main__":
    while True:
        try:
            n = int(input("Enter dimension: "))
            if n > 0:
                break
            print("Dimension must be greater than 0.")
        except ValueError:
            print("Invalid input! Please enter a number.")

    lt = LowerTriangular(n)

    print("Enter elements (row-wise):")
    for i in range(n):
        for j in range(n):
            x = int(input(f"Element [{i},{j}]: "))
            lt.set_row_major(i, j, x)  # can change to set_col_major if testing column-major

    lt.display(row=True)
    lt.display(row=False)      
    