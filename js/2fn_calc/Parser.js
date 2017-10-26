/* e -> t e'
 * t -> (e)
 *    | num
 * e' -> op e e'
 *    | epsilon
 *
 * Sample Expressions
 * -3 + (5-6)
 * (3+1) + (-3-1)
 * -23 + 3 - (18 + (-3 - 8))
 * 3 + 2 + 3
 * 3 + 2 - 1 + (-3-3)
 */
const Lexer = require("./Lexer");
const stack = [];

var l = new Lexer("-23 + 3 - (18 + (-3 - 8))");
var w = l.next();

if (e() && w.category === null)
    console.log("%s = %s", l.string, stack.pop());
else
    console.log("unexpected token '%s'", w.token);

function e() {
    if (t())
        return ep();
}

function t() {
    if (w.token === "(") {
        w = l.next();
        if (e()) {
            if (w.token === ")") {
                w = l.next();
                return true;
            }
        }
    } else if (w.category === Lexer.cat.INT) {
        stack.push(parseInt(w.token));
        w = l.next();
        return true;
    }
}

function ep() {
    if (w.category === Lexer.cat.OP) {
        var _op = w.token;
        var a = stack.pop();
        w = l.next();
        if (e()) {
            var b = stack.pop();
            stack.push(calc(a, _op, b));
            return ep();
        }
    } else if (w.token === ")" || w.category === null) {
        return true;
    }
}

function calc(a, op, b) {
    var fn = (op === "+") ? sum : diff;
    return fn(a, b);
}

function sum(a, b) {
    return a + b;
}

function diff(a, b) {
    return a - b;
}
