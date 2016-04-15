var x = [88, 59, 67, 92, 1000, 2, 8, 19, 20];

console.log(x);

console.time("sort");
x.sort(function (a, b) {
    return a - b;
});
console.timeEnd("sort");

console.log(x);
