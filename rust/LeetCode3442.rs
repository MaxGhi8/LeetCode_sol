use std::collections::HashMap;

impl Solution {
    pub fn max_difference(s: String) -> i32 {
        let mut ds = HashMap::new();
        
        // Count frequency of each character
        for c in s.chars() {
            *ds.entry(c).or_insert(0) += 1;
        }
        
        let mut min_val = 100;
        let mut max_val = 0;
        
        // Find max odd frequency and min even frequency
        for (_, count) in ds {
            if count % 2 == 1 && count > max_val {
                max_val = count;
            }
            if count % 2 == 0 && count < min_val {
                min_val = count;
            }
        }
        
        max_val - min_val
    }
}