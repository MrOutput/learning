fn main() {
    num(3);
}

fn num(x: i32) {
    println!("hello, num: {}", inc(x));
}

fn inc(x: i32) -> i32 {
    return x + 1
}
