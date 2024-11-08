# Binary Search on real values

```
db l = L, r = R;
while (r - l > eps){
    db m = (l+r)/2;
    if (Check(m)){
        l = m;
    } else {
        r = m;
    }
}
cout << (l+r)/2 << endl;
```
