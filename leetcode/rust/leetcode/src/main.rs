mod solutions;
use solutions::zigconversion;
fn main() {
    let guess = "fff".to_string();
    println!(
        "Hello, world:{}",
        zigconversion::Solution::convert(guess, 2)
    );
}
