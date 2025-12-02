#include <iostream>
using namespace std;

int fib(int n, int look_up_table[]) {
    if(n<=1){
        look_up_table[n]=n;
        return n;
    }else{
        if(look_up_table[n]!=-1){
            return look_up_table[n];
        }else{
            look_up_table[n]=fib(n-1,look_up_table)+fib(n-2,look_up_table);
            return look_up_table[n];
        }
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int *look_up_table = new int[n + 1];
    for (int i = 0; i <= n; i++) {
        look_up_table[i] = -1;
    }

    cout << "Fibonacci(" << n << ") = " << fib(n, look_up_table) << endl;

    delete[] look_up_table; // free heap memory
    return 0;
}

// 🔹 Verdict

// If you’re doing competitive programming (time/memory constraints are strict, you know n in advance, speed matters more than maintainability) → Array is often better.

// If you’re writing real-world software, projects, or want clean, maintainable code → Vector is better.

// The actual difference in performance for fib(n) up to ~10^6 is negligible with modern compilers. But the risk of bugs (like fib(100001) with MAX=100000) is much higher with arrays.

// ✅ My honest answer:

// Use vector by default → safer, cleaner, scales with n.

// Use arrays only if you’re constrained by performance in a competitive environment and know n won’t exceed your MAX.

