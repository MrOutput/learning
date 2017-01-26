import { Queue } from "./Queue"
import { Payload } from "./Payload"
import { Person } from "./Person";
import { Student } from "./Student";

let c = new Queue<Payload>();

[ 1, 1, 3 ].forEach(n => {
    let p = new Payload(n); 
    c.enqueue(p);
});

let p = new Payload(11); 
c.enqueue(p);
c.enqueue(p);

console.log(c.toString());

let d = c.dequeue();
console.log(c.toString());
console.log("Removed element is: %s", d.toString());


enum Priority {
    HIGHEST,
    LOWEST
}

var store: Array<Queue<Payload>> = [];
let hqueue = store[Priority.HIGHEST] = new Queue<Payload>();
let lqueue = store[Priority.LOWEST] = new Queue<Payload>();

let h = new Payload(7);

hqueue.enqueue(h);
hqueue.enqueue(new Payload(15));
lqueue.enqueue(h);

let a = hqueue.dequeue();

console.log("STORE IS: %s", store);

let s = new Student(new Person("rafael", "cepeda", 23), "970331904");
console.log(s.toString());
