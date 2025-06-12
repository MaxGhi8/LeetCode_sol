impl Solution {
    pub fn max_adjacent_distance(nums: Vec<i32>) -> i32 {
        let mut max_value:i32 = Self::my_abs(nums[0] - nums[nums.len() - 1]);
        
        for i in 0..nums.len()-1 {
            let diff = Self::my_abs(nums[i] - nums[i+1]);
            if diff > max_value {
                max_value = diff;
            }
        }

        max_value

    }
    
    pub fn my_abs(a: i32) -> i32 {
        if a >= 0 { a } else { -a }
    }
}