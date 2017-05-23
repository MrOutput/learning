/* get n numbers in fibonacci series starting with 0, 1, 1 */
function fibSeries(n) {
    const PRE_INIT = 3;
    let f = new Array(n);
    f[0] = 0;
    f[1] = f[2] = 1;
    for (let i = 0; i <= n - PRE_INIT; ++i) {
        f[i+2] = f[i] + f[i+1];
    }
    return f;
}

console.log(fibSeries(40));
