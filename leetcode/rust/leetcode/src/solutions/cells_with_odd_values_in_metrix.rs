pub struct Solution {}
impl Solution {
    /**
     * ref https://leetcode.cn/problems/cells-with-odd-values-in-a-matrix/
     * 如果 ri 或 ci 出现偶数次，则所在行 or 列偶数点归 0，所以首先找出
     * 所有 ri,ci 为奇数次的行和列。
     * 现在问题变成，所有的这些行和列中，除去交点以外的点的个数：
     * 包括交点在内：
     * 1. 每行点数为 n 个，按行算，总数为 row_num*n
     * 2. 类似的，每列总数为 column_num*m
     * 这里所有的交点算了两次，交点的个数为 column_num*row_num
     * 所以总点数为：row_num*n + column_num*m - 2 * column_num*row_num
     */
    pub fn odd_cells(m: i32, n: i32, indices: Vec<Vec<i32>>) -> i32 {
        let mut columns:Vec<bool> = vec![];
        columns.resize(n as usize,false);
        let mut rows:Vec<bool> = vec![];
        rows.resize(m as usize,false);
        indices.iter().for_each(|cell|{
            let (ri,ci) = (cell[0] as usize,cell[1] as usize);
            rows[ri]=!rows[ri];
            columns[ci]=!columns[ci];
        });
        let (mut r,mut c) = (0,0);
        rows.iter().for_each(|x| if *x==true {r=r+1;});
        columns.iter().for_each(|x| if *x==true{c=c+1;});
        return r*n + c*m - 2*c*r;
    }
}

#[cfg(test)]
mod tests {
    // Import the necessary modules
    use super::Solution;

    // This test writes to a file
    #[test]
    fn test_odd_cells() {
        let test_data = vec![
            // m = 2, n = 3, indices = [[0,1],[1,1]] => 6
           (2,3,vec![vec![0,1],vec![1,1]],6),
           // m = 2, n = 2, indices = [[1,1],[0,0]] => 0
           (2,2,vec![vec![1,1],vec![0,0]],0)
        ];
        for (m,n,indices,expect) in test_data {
            let got = Solution::odd_cells(m,n,indices);
            assert_eq!(got, expect);
        }
    }
}