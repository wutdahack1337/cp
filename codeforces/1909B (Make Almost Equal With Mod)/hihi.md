# Make Almost Equal With Mod (1909B)

T với tinh thần làm xong nhanh chóng 3 bài A, B, C rồi đi ngủ sớm. Contest này đã làm t tắt điện với [bài B](https://codeforces.com/problemset/problem/1909/B), t dành ra 2 tiếng chỉ để ngồi suy nghĩ và giải bài B, nhưng kết quả cũng chỉ là acp bài A, và 5 lần spam bài B =)).  
  
Sáng hôm sau, t quá bí, t chỉ có thể đọc [solutions](https://codeforces.com/blog/entry/123584), nó nói là:
- Mọi số nguyên không âm a_i đều có thể biểu diễn như thế này:
    
  ![](https://codeforces.com/predownloaded/04/d4/04d40ed602b2fa79759cb44fa5c66a3c954fa123.png)

  Ở đây a = [1005, 2005, 7005, 11005, 16005] và k = 16 = 2^4. Có thể nhận ra, a_i % k thì chỉ còn giữ lại 4 bit đầu tiên
- Khái quát thành với a_i % 2^j thì chỉ còn giữ lại j bit đầu tiên.
- Vậy chỉ cần tìm thằng j, sao cho thỏa điều kiện là được.

Sau một hồi ngẫm nghĩ, thì t mới nhận ra quả thực là như vậy, lý do tại sao giải bằng cách này lại đúng và tại sao chắc chắn có đáp án:
- a_i cũng có thể được biểu diễn như thế này, 1005 = 2^9 + 2^8 + 2^7 + 2^6 + 2^5 + 2^3 + 2^2 + 2^0
- Mod cho 2^j chỉ có thể giữ lại j bit đầu tiên tại vì: từ bit thứ j+1 trở đi (2^j, 2 * 2^j, 2 * 2 * 2^j,...) % 2^j đều bằng 0. 
- Vậy chỉ cần cho j chạy từ bit thứ 0 đến bit thứ log2(max(a_i)), với mỗi bit thứ j, ta chỉ có 2 trường hợp là 0 và 1, nếu a_i có bit thứ j toàn bộ là 0 hết hoặc 1 hết thì xét tiếp (a_i % 2^j đều bằng nhau); còn nếu chia ra một bên 0, một bên 1 (a_i % 2^j có sự khác biệt) thì 2^(j+1) chính là đáp án của bài toán.
- Nếu t của tương lai có thắc mắc là tại sao đáp án lại là 2^(j+1) chứ không phải là 2^j, thì hãy nhớ j là số thứ tự của bit; còn đáp án phải là bao nhiêu bit đầu tiên, do j bắt đầu từ 0 nên đáp án sẽ là 2^(j+1).

Một góc nhìn mới về phép mod quá hay ho ~~
