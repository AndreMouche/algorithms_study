struct Solution {}
impl Solution {
    pub fn box_delivering(
        boxes: Vec<Vec<i32>>,
        ports_count: i32,
        max_boxes: i32,
        max_weight: i32,
    ) -> i32 {
        let mut num = boxes.len();
        let mut weight_prefix = vec![0; num + 1];
        let mut diff_prefix = vec![0; num + 1];
        weight_prefix[1] = boxes[0][1];
        for id in 2..num + 1 {
            diff_prefix[id] = if boxes[id - 1][0] == boxes[id - 2][0] {
                diff_prefix[id - 1]
            } else {
                diff_prefix[id - 1] + 1
            };

            weight_prefix[id] = weight_prefix[id - 1] + boxes[id - 1][1];
        }
        let mut opt = std::collections::VecDeque::new();
        opt.push_back(0);
        let mut min_steps = 0;
        let mut g = vec![0; num + 1];
        for id in 1..num + 1 {
            loop {
                let front = *opt.front().unwrap();
                if id as i32 - (front as i32) > max_boxes
                    || weight_prefix[id] - weight_prefix[front] > max_weight
                {
                    opt.pop_front();
                } else {
                    break;
                }
            }
            min_steps = g[*opt.front().unwrap()] + diff_prefix[id] + 2;
            if (id != num) {
                g[id] = min_steps - diff_prefix[id + 1];
                while opt.is_empty() == false {
                    let back = *opt.back().unwrap();
                    if g[id] <= g[back] {
                        opt.pop_back();
                    } else {
                        break;
                    }
                }
                opt.push_back(id);
            }
        }
        return min_steps;
    }
    pub fn box_delivering1(
        boxes: Vec<Vec<i32>>,
        ports_count: i32,
        max_boxes: i32,
        max_weight: i32,
    ) -> i32 {
        let mut weight_prefix = vec![0; boxes.len() + 1];
        let mut diff_prefix = vec![0; boxes.len() + 1];
        for id in 1..boxes.len() + 1 {
            let (b, w) = (boxes[id - 1][0], boxes[id - 1][1]);
            if id > 1 {
                diff_prefix[id] = if b == boxes[id - 2][0] {
                    diff_prefix[id - 1]
                } else {
                    diff_prefix[id - 1] + 1
                };
            }
            weight_prefix[id] = weight_prefix[id - 1] + w;
        }
        let mut opt = std::collections::VecDeque::new();
        opt.push_back(0);
        let mut f = vec![0; boxes.len() + 1];
        let mut g = vec![0; boxes.len() + 1];
        for id in 1..boxes.len() + 1 {
            loop {
                let front = *opt.front().unwrap();
                if id as i32 - (front as i32) > max_boxes
                    || weight_prefix[id] - weight_prefix[front] > max_weight
                {
                    opt.pop_front();
                } else {
                    break;
                }
            }
            f[id] = g[*opt.front().unwrap()] + diff_prefix[id] + 2;
            if (id != boxes.len()) {
                g[id] = f[id] - diff_prefix[id + 1];
                while opt.is_empty() == false {
                    let back = *opt.back().unwrap();
                    if g[id] <= g[back] {
                        opt.pop_back();
                    } else {
                        break;
                    }
                }
                opt.push_back(id);
            }
        }
        return f[boxes.len()];
    }

    pub fn box_delivering2(
        boxes: Vec<Vec<i32>>,
        ports_count: i32,
        max_boxes: i32,
        max_weight: i32,
    ) -> i32 {
        let mut min_trips = vec![0; boxes.len()];
        for id in 0..boxes.len() {
            //println!("id {},port {},w {}",id,boxes[id][0],boxes[id][1]);
            if id == 0 {
                min_trips[0] = 2;
                continue;
            }
            min_trips[id] = min_trips[id - 1] + 2;
            let mut diff_steps = 0;
            let mut cur_id = id - 1;
            let min_togeter_id = if id >= max_boxes as usize {
                id + 1 - max_boxes as usize
            } else {
                0
            };
            let mut cur_weight = boxes[id][1];
            while cur_id >= min_togeter_id {
                //the different steps between (id-box_num)..id
                if boxes[cur_id][0] != boxes[cur_id + 1][0] {
                    diff_steps = diff_steps + 1;
                }
                cur_weight = cur_weight + boxes[cur_id][1];
                if cur_weight > max_weight {
                    break;
                }

                let cur_trips = if cur_id == 0 {
                    0 + diff_steps + 2
                } else {
                    min_trips[cur_id - 1] + diff_steps + 2
                };
                if cur_trips < min_trips[id] {
                    //println!("cur_to_id {},trips:{}",cur_id,cur_trips);
                    min_trips[id] = cur_trips;
                }
                if cur_id == 0 {
                    break;
                }
                cur_id = cur_id - 1;
            }
        }
        *min_trips.last().unwrap()
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    fn ttt() -> Result<(), reqwest::Error> {
        let mut response = reqwest::get("https://www.rust-lang.org").unwrap();
        assert!(response.status().is_success());
    
        let mut response_text = String::new();
        response.read_to_string(&mut response_text)?;
    
        println!("Response text: {}", response_text);
        Ok(())
    }
    #[test]
    fn test_aaa() {
        ttt().unwrap()
    }

    #[test]
    fn test_delivering_boxes() {
        let test_cases = vec![
            (vec![vec![1, 1], vec![2, 1], vec![1, 1]], 2, 3, 3, 4),
            (
                vec![vec![1, 2], vec![3, 3], vec![3, 1], vec![3, 1], vec![2, 4]],
                3,
                3,
                6,
                6,
            ),
            (
                vec![
                    vec![1, 4],
                    vec![1, 2],
                    vec![2, 1],
                    vec![2, 1],
                    vec![3, 2],
                    vec![3, 4],
                ],
                3,
                6,
                7,
                6,
            ),
            (
                vec![
                    vec![2, 4],
                    vec![2, 5],
                    vec![3, 1],
                    vec![3, 2],
                    vec![3, 7],
                    vec![3, 1],
                    vec![4, 4],
                    vec![1, 3],
                    vec![5, 2],
                ],
                5,
                5,
                7,
                14,
            ),
        ];
        for (boxes, ports_count, max_boxes, max_weight, expect) in test_cases {
            let got = Solution::box_delivering(boxes, ports_count, max_boxes, max_weight);
            assert_eq!(got, expect);
        }
    }
}
