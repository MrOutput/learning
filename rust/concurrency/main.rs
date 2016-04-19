use std::thread;

fn main() {
    let child = thread::spawn(move || {
        for i in 1..1000 {
            println!("{}", i);
        }
        println!("Thread finished.");
    });

    let result = child.join();
}
