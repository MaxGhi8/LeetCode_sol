impl Solution {
    pub fn answer_string(word: String, num_friends: i32) -> String {
        if num_friends == 1 {
            return word;
        }
        
        let max_len = word.len() - num_friends as usize + 1;
        let mut max_subword = String::new();
        
        // Check all the word with the maximum len
        for i in 0..num_friends as usize {
            let end_pos = std::cmp::min(i + max_len, word.len());
            let w = &word[i..end_pos];
            if w > max_subword.as_str() {
                max_subword = w.to_string();
            }
        }
        
        // Check words with not maximum len that are at the end of the string
        for i in 1..max_len {
            if i <= word.len() {
                let w = &word[word.len() - i..];
                if w > max_subword.as_str() {
                    max_subword = w.to_string();
                }
            }
        }
        
        max_subword
    }
}