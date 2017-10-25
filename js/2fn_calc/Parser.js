/*
 * TODO add error handling
 *
 * null categories _may_ be empty (e-string) expansions; need to finish lookaheads
 *
 * e -> s e'
 * e'-> T | epsilon
 * T -> op e
 * s -> num | s'
 * s'-> (se')s' | epsilon
 *
 * -3 + (5-6)
 * (3+1) + (-3-1)
 */
const Lexer = require("./Lexer");
const epsilon = -1;

var l = new Lexer("-3 + (5-6)");
var w = next();

if (e() && (w.category === null || w.category === epsilon))
    console.log('valid');
else
    console.log('invalid');
console.log(w);

//debug hooks
function next() {
    var w = l.next();
    console.log(w);
    return w;
}

function e() {
    if (s())
        return ep();
}

function s() {
    if (w.category === Lexer.cat.INT) {
        w = next();
        return true;
    }
    return sp();
}

function sp() {
    if (w.category === Lexer.cat.LP) {
        w = next();
        if (s()) {
            if (ep()) {
                if (w.category === Lexer.cat.RP) {
                    w = next();
                    return sp();
                }
            }
        }
    } else if (w.category === Lexer.cat.LP) {//TODO finish lookahead
        w = next();
        w.category = epsilon;
        return true;
    }
}

function ep() {
    if (t()) {
        return ep();
    } else {//TODO lookahead
        w = next();
        w.category = epsilon;
        return true;
    }
}

function t() {
    if (w.category === Lexer.cat.OP) {
        w = next();
        return e();
    }
}
