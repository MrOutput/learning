/* TODO support funcs
 * sin, cos, tan, log, sqrt
 * log_<base>, ln
 *
 * support identifiers:
 * ans, e, pi
 */
const Lexer = require("./Lexer");

class Parser {
    constructor() {
        this.stack = [];
        this.w = null;
        this.l = null;
    }

    static calc(a, op, b) {
        return this._chooseFn(op)(a, b);
    }

    static _chooseFn(op) {
        switch (op) {
        case "+": return this.sum;
        case "-": return this.diff;
        case "/": return this.quo;
        case "*": return this.prod;
        case "^": return this.expo;
        }
    }

    static expo(a, b) {
        return Math.pow(a, b);
    }

    static sum(a, b) {
        return a + b;
    }

    static diff(a, b) {
        return a - b;
    }

    static prod(a, b) {
        return a * b;
    }

    static quo(a, b) {
        return a / b;
    }

    _lrecmut(nt, pfn) {
        if (nt.call(this))
            return pfn.call(this);
    }

    _ophit(ops, nt, pfn, follow) {
        if (ops.some(this._istok, this)) {
            var _op = this.w.token;
            var a = this.stack.pop();
            this.w = this.l.next();
            if (nt.call(this)) {
                var b = this.stack.pop();
                this.stack.push(Parser.calc(a, _op, b));
                return pfn.call(this);
            }
        } else if (follow.some(this._istok, this) || this.w.category === null) {
            return true;
        }
    }

    _istok(o) {
        return (o === this.w.token);
    }

    exec(expr) {
        this.l = new Lexer(expr);
        this.w = this.l.next();

        if (!(this.e() || this.w.category === null))
            throw new SyntaxError(this.w.token);

        return this.stack.pop();
    }

    e() {
        return this._lrecmut(this.p, this.ep);
    }

    ep() {
        return this._ophit(["+", "-"], this.p, this.ep, [")"]);
    }

    p() {
        return this._lrecmut(this.x, this.pp);
    }

    pp() {
        return this._ophit(["*", "/"], this.x, this.pp, ["+", "-", ")"]);
    }
    
    x() {
        return this._lrecmut(this.z, this.xp);
    }

    xp() {
        return this._ophit(["^"], this.z, this.xp, ["*", "/", "+", "-", ")"]);
    }

    z() {
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
}
module.exports = Parser;
