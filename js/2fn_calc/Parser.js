/* e -> t e'
 * t -> (e)
 *    | num
 * e' -> op e e'
 *    | epsilon
 *
 * Sample Expressions
 * -3 + (5-6)
 * (3+1) + (-3-1)
 */
const Lexer = require("./Lexer");

var l = new Lexer("-23 + 3 - (18 + (-3 - 8))");
var w = next();

if (e() && w.category === null)
    console.log('valid');
else
    console.log("unexpected token '%s'", w.token);

//debug hooks
function next() {
    var c = l.next();
    console.log(c);
    return c;
}

function e() {
    if (t())
        return ep();
}

function t() {
    if (w.token === "(") {
        w = next();
        if (e()) {
            if (w.token === ")") {
                w = next();
                return true;
            }
        }
    } else if (w.category === Lexer.cat.INT) {
        w = next();
        return true;
    }
}

function ep() {
    if (w.category === Lexer.cat.OP) {
        w = next();
        if (e()) {
            return ep();
        }
    } else if (w.token === ")" || w.category === null) {
        return true;
    }
}
