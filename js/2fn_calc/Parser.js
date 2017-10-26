/*
 * TODO add error handling
 *
 * null categories _may_ be empty (e-string) expansions; need to finish lookaheads
 *
 * e -> t e'
 * t -> (e)
 *    | num
 * e' -> op e e'
 *    | epsilon
 *
 * -3 + (5-6)
 * (3+1) + (-3-1)
 */
const Lexer = require("./Lexer");

var l = new Lexer("(3 + 3 - 3 + 2) + 5");
var w = next(true);

if (e() && w.category === null)
    console.log('valid');
else
    console.log('invalid');

//debug hooks
function next(sup) {
    if (!sup)
        console.log(w);
    var c = l.next();
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
