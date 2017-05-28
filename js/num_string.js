/* Exemplifies JavaScript's simplicity and power.
 * 
 * The program takes an input string and finds the valid numbers in the string and sums the distribution.
 */
const input = '0 0 12 1..9 .. . asontehu a  asontehu     a  1.0 .2 001.2230 0 0 .. gg a b 1.9 .9 ..9 18.8 18. 88 12 19 1000 99';

const nums = input.split(/\s/).filter(isnum).map(parseFloat);

function sum(a, b) {
    return a + b;
}

function isnum(str) {
    return /^\d+(\.\d+)?$/.test(str) || /^\.\d+$/.test(str);
}

console.log('Original input is:\n%s.\n\nThe sum of %s is %s.', input, nums, nums.reduce(sum));
