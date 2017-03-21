var x = {
    a: [1, 32, 2, 8, 9],
    i: 0,
    current: function () {
        return x.a[x.i];
    },
    next: function () {
        if (x.a[x.i] === undefined) {
            x.i = 0;
            return x.a[x.i];
        } else {
            x.i++;
            return x.a[x.i];
        }
    },
    prev: function () {
        if (x.a[x.i] === undefined) {
            x.i = x.a.length - 1;
            if (x.a[x.i] === x.current()) {
                x.i--;
            }
            return x.a[x.i];
        } else {
            x.i--;
            return x.a[x.i];
        }
    },
    rewind: function () {
        x.i = 0;
    },
    fastForward: function () {
        x.i = x.a.length - 1;
    },
    save: function () {},
    delete: function () {},

    //static
    get(i) {
        return x.a[i];
    }
};

do {
    //console.log(x.i);
    console.log(x.current());
} while (x.next());

while (x.prev()) {
    //console.log(x.i);
    console.log(x.current());
}

x.rewind();
console.log(x.current());
x.fastForward();
console.log(x.current());

console.log(x.get(3));
