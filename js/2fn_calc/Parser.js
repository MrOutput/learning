/* current
 * -------
 * e -> t e'
 * e'-> op t e'
 *    | epsilon
 * t -> (e)
 *    | num
 *
 * planned: 4 function calculator w/ expo
 * --------------------------------------
 * TODO support funcs
 * like sin, cos, tan, log, sqrt
 * log_<base>, ln
 *
 * support identifiers:
 * ans, e, pi
 *
 * e -> p e'
 * e'-> + p e'
 *    | - p e'
 *    | epsilon
 * p -> x p'
 * p'-> * x p'
 *    | / x p'
 *    | epsilon
 * x -> z x'
 * x'-> ^ z x'
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

    exec(expr) {
        this.l = new Lexer(expr);
        this.w = this.next();

        if (!(this.e() || this.w.category === null))
            throw new SyntaxError(this.token);

        return this.stack.pop();
    }

    e() {
        if (this.p())
            return this.ep();
    }

    ep() {
        if (this.token === "+" || this.token === "-") {
            var _op = this.token;
            var a = this.stack.pop();
            //
            this.w = this.next();
            if (this.p()) {
                var b = this.stack.pop();
                this.stack.push(Parser.calc(a, _op, b));
                //
                return this.ep();
            }
        } else if (this.token === ")" || this.w.category === null) {
            return true;
        }
    }

    p() {
        if (this.x())
            return this.pp();
    }

    pp() {
        if (this.token === "*" || this.token === "/") {
            var _op = this.token;
            var a = this.stack.pop();
            //
            this.w = this.next();
            if (this.x()) {
                var b = this.stack.pop();
                this.stack.push(Parser.calc(a, _op, b));
                //
                return this.pp();
            }
        } else if (this.token === "+" || this.token === "-" ||
                   this.token === ")" || this.w.category === null) {
            return true;
        }
    }
    
    x() {
        if (this.z())
            return this.xp();
    }

    xp() {
        if (this.token === "^") {
            var _op = this.token;
            var a = this.stack.pop();
            //
            this.w = this.next();
            if (this.z()) {
                var b = this.stack.pop();
                this.stack.push(Parser.calc(a, _op, b));
                //
                return this.xp();
            }
        } else if (this.token === "*" || this.token === "/" ||
                   this.token === "+" || this.token === "-" ||
                   this.token === ")" || this.w.category === null) {
            return true;
        }
    }

    z() {
        if (this.token === "(") {
            this.w = this.next();
            if (this.e()) {
                if (this.token === ")") {
                    this.w = this.next();
                    return true;
                }
            }
        } else if (this.w.category === Lexer.cat.INT) {
            this.stack.push(parseInt(this.token));
            this.w = this.next();
            return true;
        }
    }

    get token() {
        return this.w.token;
    }
    
    next() {
        var w = this.l.next();
        //console.log(w);
        return w;
    }
}
module.exports = Parser;
