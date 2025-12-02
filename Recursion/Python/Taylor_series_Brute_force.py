def e(x, n):
    # Define static variables (only once)
    if not hasattr(e, "p"):
        e.p = 1  # power of x
        e.f = 1  # factorial of n

    # Base case
    if n == 0:
        return 1

    # Recursive call
    r = e(x, n - 1)

    # Update static variables
    e.p *= x
    e.f *= n

    # Return the Taylor series term + previous sum
    return r + e.p / e.f


# ---------------------------
# Driver code
# ---------------------------

# Reset static variables before each new call
e.p = 1
e.f = 1

x = 2   # you can change this value
n = 10  # number of terms in Taylor expansion
result = e(x, n)

print(f"Approximation of e^{x} using {n} terms = {result}")

