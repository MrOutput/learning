/* 4 function calculator w/ expo
 * -------------------------------------
 * TODO support funcs
 * like sin, cos, tan, log, sqrt
 * log_<base>, ln
 *
 * support identifiers:
 * ans, e, pi
 *
 * e -> s
 * s -> ps'
 * s'-> +ps'
 *    | -ps'
 *    | epsilon
 * p -> xp'
 * p'-> *xp'
 *    | /xp'
 *    | epsilon
 * x -> zx'
 * x'-> ^zx'
 *    | epsilon
 * z -> (e)
 *    | num
 */
const Lexer = require("./Lexer");

class Parser {
    constructor() {
        this.stack = [];
        this.w = null;
        this.l = null;
    }

    static calc(a, op, b) {
        var fn = (op === "+") ? this.sum : this.diff;
        return fn(a, b);
    }

    static sum(a, b) {
        return a + b;
    }

    static diff(a, b) {
        return a - b;
    }

    exec(expr) {
        this.l = new Lexer(expr);
        this.w = this.l.next();

        if (!(this.e() || this.w.category === null))
            throw new SyntaxError(this.w.token);

        return this.stack.pop();
    }

    e() {
        if (this.t())
            return this.ep();
    }

    t() {
        if (this.w.token === "(") {
            this.w = this.l.next();
            if (this.e()) {
                if (this.w.token === ")") {
                    this.w = this.l.next();
                    return true;
                }
            }
        } else if (this.w.category === Lexer.cat.INT) {
            this.stack.push(parseInt(this.w.token));
            this.w = this.l.next();
            return true;
        }
    }

    ep() {
        if (this.w.category === Lexer.cat.OP) {
            var _op = this.w.token;
            var a = this.stack.pop();
            this.w = this.l.next();
            if (this.e()) {
                var b = this.stack.pop();
                this.stack.push(Parser.calc(a, _op, b));
                return this.ep();
            }
        } else if (this.w.token === ")" || this.w.category === null) {
            return true;
        }
    }
}
module.exports = Parser;
