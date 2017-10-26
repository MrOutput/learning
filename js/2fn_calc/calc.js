/* Sample Expressions
 * -3 + (5-6)
 * (3+1) + (-3-1)
 * -23 + 3 - (18 + (-3 - 8))
 * 3 + 2 + 3
 * 3 + 2 - 1 + (-3-3)
 */
const Parser = require("./Parser");

var p = new Parser();

try {
    var expr = "-23 + 3 - (18 + (-3 - 8))";
    var ans = p.exec(expr);
    console.log("%s = %s", expr, ans);
} catch (e) {
    console.log("unexpected token '%s'", e);
}
