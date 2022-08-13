use std::iter::empty;

pub struct Solution {}
impl Solution {
    /**
     * https://leetcode.cn/problems/intersection-of-two-arrays-ii/
     * 使用 map 把较短的那个数组存下来，然后拿长的那个数组去更新 map.
     * 当前方法适用于原题中两个进阶思考：
     * - 如果 nums1 的大小比 nums2 小，哪种方法更优？
     * - 如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
     */
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut ans = vec![];
        let (iters, iterl) = if nums1.len() < nums2.len() {
            (nums1.iter(), nums2.iter())
        } else {
            (nums2.iter(), nums1.iter())
        };
        let mut datas = std::collections::BTreeMap::new();
        iters.for_each(|x| {
            if let Some(count) = datas.get_mut(x) {
                *count = *count + 1;
            } else {
                datas.insert(*x, 1);
            }
        });

        iterl.for_each(|y| {
            let mut need_remove = false;
            if let Some(count) = datas.get_mut(y) {
                *count = *count - 1;
                ans.push(*y);
                if *count == 0 {
                    need_remove = true;
                }
            }
            if need_remove {
                datas.remove(y);
            }
        });

        ans
    }

    fn skip_smaller(iter: &mut core::slice::Iter<i32>, v: i32) -> Option<i32> {
        while let Some(a) = iter.next() {
            if *a >= v {
                return Some(*a);
            }
        }
        return None;
    }

    /**
     * 简单的排序，然后从前往后比对
     */
    pub fn intersect3(mut nums1: Vec<i32>, mut nums2: Vec<i32>) -> Vec<i32> {
        nums1.sort();
        nums2.sort();
        let mut iter2 = nums2.iter();
        let mut iter1 = nums1.iter();
        let mut ans = vec![];
        let mut cur2 = None;
        while let Some(v) = iter1.next() {
            if let Some(leftv2) = cur2.take() {
                if leftv2 > *v {
                    cur2 = Some(leftv2);
                    continue;
                }
                if leftv2 == *v {
                    ans.push(leftv2);
                    continue;
                }
            }

            match Solution::skip_smaller(&mut iter2, *v) {
                None => return ans,
                Some(v2) => {
                    if v2 == *v {
                        ans.push(*v);
                    } else {
                        cur2 = Some(v2);
                    }
                }
            }
        }
        ans
    }

    pub fn intersect2(mut nums1: Vec<i32>, mut nums2: Vec<i32>) -> Vec<i32> {
        nums1.sort();
        nums2.sort();
        let mut ans = vec![];
        let (mut i, mut j) = (0, 0);
        while i < nums1.len() && j < nums2.len() {
            while i < nums1.len() && nums1[i] < nums2[j] {
                i = i + 1;
            }
            if i == nums1.len() {
                return ans;
            }
            while j < nums2.len() && nums1[i] > nums2[j] {
                j = j + 1;
            }
            if j == nums2.len() {
                return ans;
            }
            if nums1[i] == nums2[j] {
                ans.push(nums1[i]);
                i = i + 1;
                j = j + 1;
            }
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn test_intersect() {
        let test_data = vec![
            (vec![1, 2, 2, 1], vec![2, 2], vec![2, 2]),
            (vec![4, 9, 5], vec![9, 4, 9, 8, 4], vec![4, 9]),
            (vec![3, 1, 2], vec![1, 3], vec![1, 3]),
        ];
        for (a, b, expect) in test_data {
            let mut got = Solution::intersect(a, b);
            got.sort();
            assert_eq!(got, expect);
        }
    }
}
