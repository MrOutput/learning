//https://stackoverflow.com/questions/46701209/node-js-working-with-an-api-limit-of-5-requests-per-second/46701466#46701466

class Queue {
    constructor() {
        this.queue = [];
    }

    enqueue(obj) {
        return this.queue.push(obj);
    }

    dequeue() {
        return this.queue.shift();
    }

    hasWork() {
        return (this.queue.length > 0);
    }
}

function t_o(delay) {
    return new Promise(function (resolve, reject) {
        setTimeout(function () {
            resolve();
        }, delay);
    });
}

class TimedQueue extends Queue {
    constructor(delay) {
        super();
        this.delay = delay;
    }

    dequeue() {
        return t_o(this.delay).then(() => {
            return super.dequeue();
        });
    }
    
    process(cb) {
        return this.dequeue().then(data => {
            cb(data);
            if (this.hasWork())
                return this.process(cb);
        });
    }
}


var q = new TimedQueue(500);

for (var request = 0; request < 10; ++request)
    q.enqueue(request);

q.process(console.log).then(function () {
    console.log('done');
});
