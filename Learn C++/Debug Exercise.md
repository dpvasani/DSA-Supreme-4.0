## ✅ **1. Capital, Small or Other Character**

**🔧 Bug**: Used `||` instead of `&&`. Also, conditions should be ordered correctly.

```cpp
#include<iostream>
using namespace std;

int main() {
    char c;
    cin >> c;
    if ('A' <= c && c <= 'Z') {
        cout << 1;
    } else if ('a' <= c && c <= 'z') {
        cout << 0;
    } else {
        cout << -1;
    }
    return 0;
}
```

#### ✅ Output (Sample):

```
Input: G → Output: 1
Input: m → Output: 0
Input: 8 → Output: -1
```

---

### ✅ **2. Number Pattern**

```cpp
/*
Pattern for n = 5:
1
23
345
4567
*/
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int i = 1;
    while(i <= n){
        int j = i, count = 1;
        while(count <= i){
            cout << j;
            j = j + 1;
            count = count + 1;
        }
        cout << "\n";
        i = i + 1;
    }
    return 0;
}
```

---

### ✅ **3. Pyramid Star Pattern**

```cpp
/*
Pattern for n = 4:
   *
  ***
 *****
*******
*/
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int i = 1;
    while(i <= n){
        int spaces = n - i;
        int stars = 2*i - 1;

        for(int k = 1; k <= spaces; k++)
            cout << " ";
        for(int m = 1; m <= stars; m++)
            cout << "*";
        cout << "\n";
        i++;
    }
    return 0;
}
```

---

### ✅ **4. Repeating Digits Pattern**

```cpp
/*
Pattern for n = 5:
1
22
333
4444
*/
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << i;
        }
        cout << endl;
    }
    return 0;
}
```

---

### ✅ **5. Reverse Number Triangle**

```cpp
/*
Pattern for n = 4:
1
21
321
4321
*/
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int p = i;
        for(int j = 1; j <= i; j++){
            cout << p;
            p--;
        }
        cout << endl;
    }
    return 0;
}
```

---

### ✅ **6. Alphabet Pyramid**

```cpp
/*
Pattern for n = 5:
E
DE
CDE
BCDE
ABCDE
*/
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        char p = 'A' + n - i;
        for(int j = 1; j <= i; j++){
            cout << p;
            p++;
        }
        cout << endl;
    }
    return 0;
}
```

---

### ✅ **7. Number Diamond**

```cpp
/*
Pattern for n = 4:
   1
  232
 34543
4567654
*/
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        int spaces = n - i;
        for(int j = 1; j <= spaces; j++)
            cout << " ";

        int val = i;
        for(int j = 1; j <= i; j++)
            cout << val++;

        val -= 2;
        for(int j = 1; j < i; j++)
            cout << val--;

        cout << endl;
    }
    return 0;
}
```

---

### ✅ **8. Diamond Star Pattern**

```cpp
/*
Pattern for n = 5:
  *
 ***
*****
 ***
  *
*/
#include<iostream>
using namespace std;

void printPatt(int n){
    int i = 1;
    while(i <= n){
        int stars = (i <= n/2) ? (2*i - 1) : (2*(n - i) + 1);
        int spaces = (n - stars) / 2;
        
        for(int k = 1; k <= spaces; k++)
            cout << " ";
        for(int j = 1; j <= stars; j++)
            cout << "*";
        for(int k = 1; k <= spaces; k++)
            cout << " ";
        cout << "\n";
        i++;
    }
}

int main(){
    int n;
    cin >> n;
    if(n % 2 == 0) n++;  // Ensure odd for symmetry
    printPatt(n);
    return 0;
}
```

---

