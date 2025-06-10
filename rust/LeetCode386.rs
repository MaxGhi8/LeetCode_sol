impl Solution {
    pub fn lexical_order(n: i32) -> Vec<i32> {
        // Compute number of digits
        let mut ans = vec![1];
        let mut num = 1;
        let mut n_digits = 1;
        
        for i in 1..6 {
            if n / (10_i32.pow(i)) >= 1 {
                n_digits += 1;
                num *= 10;
                ans.push(num);
            } else {
                break;
            }
        }
        
        let mut flag = 0;
        
        // at every iteration I add a number
        for _ in 0..(n - n_digits) {
            if flag > 0 {
                flag -= 1;
                num *= 10;
            } else {
                num += 1;
                if num > n {
                    if num % 10 == 0 {
                        num = num / 10;
                    } else {
                        num = num / 10 + 1;
                    }
                }
                while num % 10 == 0 {
                    flag += 1;
                    num = num / 10;
                }
            }
            ans.push(num);
        }
        
        ans
    }
}