use std::cmp::{Ord, Ordering, PartialEq};
struct Solution {}

#[derive(Eq)]
struct Student {
    id: i32,
    score: i32,
}

impl Student {
    fn new(id: i32, score: i32) -> Self {
        return Self {
            id: id,
            score: score,
        };
    }
}

impl Ord for Student {
    fn cmp(&self, other: &Self) -> Ordering {
        if self.score == other.score {
            if self.id < other.id {
                return Ordering::Less;
            }
            return Ordering::Greater;
        }
        if self.score < other.score {
            return Ordering::Greater;
        }
        return Ordering::Less;
    }
}

impl PartialOrd for Student {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        return Some(self.cmp(other));
    }
}

impl PartialEq for Student {
    fn eq(&self, other: &Self) -> bool {
        return self.score == other.score && self.id == other.id;
    }
}

struct ScoreComputer {
    positive_feedback: std::collections::HashSet<String>,
    negative_feedback: std::collections::HashSet<String>,
}
impl ScoreComputer {
    fn new(positive_feedback: Vec<String>, negative_feedback: Vec<String>) -> Self {
        Self {
            positive_feedback: positive_feedback.into_iter().collect(),
            negative_feedback: negative_feedback.into_iter().collect(),
        }
    }
    fn compute_score(&self, report: &str) -> i32 {
        let mut score = 0;
        let mut iter = report.split_whitespace();
        loop {
            if let Some(word) = iter.next() {
                if self.positive_feedback.contains(word) {
                    score = score + 3;
                } else if self.negative_feedback.contains(word) {
                    score = score - 1;
                }
            } else {
                return score;
            }
        }
    }
}
use std::collections::BinaryHeap;
impl Solution {
    /*
    https://leetcode.cn/problems/reward-top-k-students/description/
     */
    pub fn top_students(
        positive_feedback: Vec<String>,
        negative_feedback: Vec<String>,
        report: Vec<String>,
        student_id: Vec<i32>,
        k: i32,
    ) -> Vec<i32> {
        let computer = ScoreComputer::new(positive_feedback, negative_feedback);
        let heap_size = std::cmp::min(k as usize, report.len());
        let mut students: BinaryHeap<Student> = BinaryHeap::with_capacity(heap_size);

        for id in 0..heap_size {
            let score = computer.compute_score(&report[id]);
            let cur_student = Student::new(student_id[id], score);
            students.push(cur_student);
        }
        for id in heap_size..report.len() {
            let score = computer.compute_score(&report[id]);
            let cur_student = Student::new(student_id[id], score);
            if let Some(mut st) = students.peek_mut() {
                if st.cmp(&cur_student) == Ordering::Greater {
                    st.score = cur_student.score;
                    st.id = cur_student.id;
                }
            }
        }
        return students
            .into_sorted_vec()
            .iter()
            .map(|stu| stu.id)
            .collect();
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    #[test]
    fn test_top_students() {
        let test_cases = vec![
            (
                vec!["smart", "brilliant", "studious"],
                vec!["not"],
                vec!["this student is studious", "the student is smart"],
                vec![1, 2],
                2,
                vec![1, 2],
            ),
            (
                vec!["smart", "brilliant", "studious"],
                vec!["not"],
                vec!["this student is not studious", "the student is smart"],
                vec![1, 2],
                2,
                vec![2, 1],
            ),
        ];

        for (possitive_feedback, negative_feedback, report, student_id, k, expect) in test_cases {
            let got = Solution::top_students(
                possitive_feedback
                    .iter()
                    .map(|s| s.to_string())
                    .collect::<Vec<String>>(),
                negative_feedback
                    .iter()
                    .map(|s| s.to_string())
                    .collect::<Vec<String>>(),
                report
                    .iter()
                    .map(|s| s.to_string())
                    .collect::<Vec<String>>(),
                student_id,
                k,
            );
            assert_eq!(expect, got);
        }
    }
}
