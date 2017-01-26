export class Queue<T> {
    private queue: Array<T>;

    constructor() {
        this.queue = [];
    }

    enqueue(a: T): void {
        if (this.queue.indexOf(a) >= 0) {
            console.warn("Element %s already on the queue...ignoring request.", a.toString());
            return;
        }
        this.queue.push(a);
    }

    dequeue(): T {
        return this.queue.shift();
    }

    toString(): string  {
        return `[ ${this.queue.join(", ")} ]`;
    }
}
