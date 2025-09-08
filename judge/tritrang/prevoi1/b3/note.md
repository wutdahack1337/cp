- Các cây có độ cao khác nhau từng đôi một

Subtestcase 1:
    Dòng 1: O(n^2)
    Dòng 2:
        Những thằng nào sau h, phải có chiều cao tăng dần hết hoặc là bằng nhau?

        _ _ _ _ h _ _ _ _ _ _ -> sum( (n-h_index)_C_ * ?)

        -> Trong đoạn [l, r], gọi caoIndex là thằng nào có chiều cao lớn nhất, thì những thằng [caoIndex, r] phải xếp bằng hoặc tăng dần
        => Nhìn rộng ra, thì 

Subtestcase 1:
    Dòng 1: O(n)
        Những thằng nào sau h, phải có chiều cao tăng dần hết hoặc là bằng nhau?