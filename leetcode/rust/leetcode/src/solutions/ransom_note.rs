pub struct Solution {}
impl Solution {
    /**
    https://leetcode.cn/problems/ransom-note/
    简单题，不多说。
    */
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut data = vec![0; 26];
        let mut ransom = ransom_note.as_bytes().iter();
        let mut rmatch = if let Some(v) = ransom.next() {
            (v - b'a') as usize
        } else {
            return true;
        };
        for c in magazine.as_bytes() {
            let cur = (c - b'a') as usize;
            data[cur] = data[cur] + 1;
            while data[rmatch] > 0 {
                data[rmatch] = data[rmatch] - 1;
                if let Some(v) = ransom.next() {
                    rmatch = (v - b'a') as usize
                } else {
                    return true;
                }
            }
        }
        return false;
    }

    pub fn can_construct2(ransom_note: String, magazine: String) -> bool {
        let mut data = vec![0; 26];
        let mut r_idx = 0;
        let ransom = ransom_note.as_bytes();
        for c in magazine.as_bytes() {
            let cur = (c - b'a') as usize;
            data[cur] = data[cur] + 1;
            while r_idx < ransom.len() {
                let v = (ransom[r_idx] - b'a') as usize;
                if data[v] == 0 {
                    break;
                }
                data[v] = data[v] - 1;
                r_idx = r_idx + 1;
            }
            if r_idx == ransom.len() {
                return true;
            }
        }
        return false;
    }
}
