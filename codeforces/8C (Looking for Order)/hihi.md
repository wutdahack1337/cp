# Looking for Order (8C)

## Tóm Tắt Bài Toán
Cho tọa độ của cái túi và n đồ vật. Chỉ có thể mang theo tối đa 2 đồ vật cùng lúc. Tìm thời gian ít nhất để bỏ n đồ vật vào túi.

## Quá Trình 
Ban đầu, do quá gà nên không suy nghĩ ra cách làm trong contest. Nhưng vì sau khi contest kết thúc, chuẩn bị kiếm bài mới cho contest sau, "vô tình" thấy được tag "bitmask", mới lóe ra được ý tưởng áp dụng kĩ thuật dp bitmask. Nhưng vấn đề ở đây là sau 1 ngày suy nghĩ cho có (không thực sự nghiêm túc giải quyết vấn đề) t chỉ suy nghĩ ra được cách làm trong $O(2^n * n * n)$:  
> - Gọi $f(sl, mask)$ là phương án chọn tốt nhất cho mask, với thằng cuối cùng được chọn chỉ có nó (sl == 0) hay bắt cặp với một thằng khác (sl == 1)  
> - $f(sl, mask) = min(f(sl, mask), min(f(0, OffBit(mask, bit1, bit2)), f(1, OffBit(mask, bit1, bit2)) + cost)$ (bit1 và bit2 là giống nhau nếu sl == 0)  

Đúng rồi, đúng rồi đấy, cách nhìn nhìn thực sự rất ngu ngốc =))

T buộc phải mở hint ra xem, đó chính là bảng xếp hạng lúc contest của bài này diễn ra, t thấy bài này được giải ở phút 30, t nghĩ rằng "Chắc nó cũng không khó đến thế". Và tiếp tục 1 ngày sau suy cũng giữ tinh thần giống ngày đầu (không thực sự nghiêm túc giải quyết vấn đề), t đã không nhận ra được 1 điểm mấu chốt quan trọng để giải quyết bài toàn này cho đến khi đọc được lời giải:
> Thứ tự chọn đồ vật không quan trọng

Đây chính là điểm mấu chốt mà t đã bỏ qua, nó thay đổi hoàn toàn cách nhìn nhận của t về một bài toán dp bitmask, từ trước giờ t chỉ nghĩ là chỉ cần làm cách tính $f(mask)$ từ việc duyệt từng bit bật trong mask, từ đó kết quả là $min(f(OffBit(mask, bit)) + cost)$ là đủ rồi. Nhưng với bài toán này, cách làm này là không hiệu quả.
> - Gọi $f(mask)$ là phương án chọn tốt nhất cho mask. Mask ở đây không còn dưới góc nhìn là các đồ vật đã chọn như ý tưởng cũ nữa, mask ở đây phải được xử lý dưới góc nhìn những đồ vật **chưa chọn**.  
> - Vì thứ tự chọn đồ vật không quan trọng, nên thực sự ta chỉ cần chọn đồ vật chưa được chọn đầu tiên trong mask mà thôi (nice!!!)  
> - Gọi bit1 là đồ vật đầu tiên chưa được chọn trong mask. Khi chỉ chọn một mình đồ vật đó thì $f(OnBit(mask, bit1)) = min(f(mask) + cost)$, còn khi đồ vật đó không được chọn một mình, lúc này mình mới cần bắt cặp qua tất cả các đồ vật khác chưa được chọn khác, gọi là bit2, $f(OnBit(mask, bit1, bit2)) = min(f(mask) + cost)$
> - $O(2^n * n)$ (tuyệt vời!!!)

## Bài Học
Vấn đề nằm ở bản thân. Đúng như Um_Nik đã nói:
> Most of the time you don’t need to learn any advanced stuff to solve the problem, you can’t solve it because you are not trying hard enough or not paying attention to details or just being stupid.

## Code
```
fto(mask, 0, (1 << n)-1){
    fto(bit, 0, n-1){
        if (getBit(mask, bit) == 0){
            int xor_mask_bit = getXorMask(mask, bit);
            if (f[xor_mask_bit] > f[mask] + cost[bit+1][bit+1]){
                f[xor_mask_bit] = f[mask] + cost[bit+1][bit+1];
            }

            fto(bit2, bit+1, n-1){
                if (getBit(mask, bit2) == 0){
                    int xor_mask_bit_bit2 = getXorMask(xor_mask_bit, bit2);
                    if (f[xor_mask_bit_bit2] > f[mask] + cost[bit+1][bit2+1]){
                        f[xor_mask_bit_bit2] = f[mask] + cost[bit+1][bit2+1];
                    }
                }
            }
            break;
        }
    }
}
cout << f[(1<<n)-1] << endl;
```
