struct Point {
    x: f32,
    y: f32
}

struct Line {
    p1: Point
}

fn main() {
    let l = Line;
    l.p1.x = 32;

    println!("x is {}, y is {}", l.p1.x, l.p1.y);
}
