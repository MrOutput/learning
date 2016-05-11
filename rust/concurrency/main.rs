fn main() {
    let mut threads = Vec::new();

    for i in 0..10 {
        let t = std::thread::spawn(move || {
            for j in 0..10 {
                if j % 2 == 0 {
                    println!("From {}: {}", i, j);
                }
            }
        });

        threads.push(t);
    }

    for t in threads {
        t.join().unwrap();
    }
}
