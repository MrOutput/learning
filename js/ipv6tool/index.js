function* Scanner(addr) {
    var i = 0;
    while (getchar() !== Scanner.EOL) {
        var lexeme = { str: "", cat: null };
        if (ishex(getchar())) {
            var j = 0;
            do {
                lexeme.str += getchar();
                i++, j++;
            } while (j<4 && ishex(getchar()));
            lexeme.cat = Scanner.H16;
        } else if (getchar() === ":") {
            lexeme.str = getchar();
            lexeme.cat = Scanner.SEP;
            i++;
        } else {
            throw new SyntaxError("Unexpected token: " + getchar());
        }
        yield lexeme;
    }
    function getchar() {
        return addr[i];
    }
}
Scanner.ERR = 0;
Scanner.H16 = 1;
Scanner.SEP = 2;
Scanner.EOL = undefined;

function ishex(c) {
    return (c>="0" && c<="9" ||
            c>="a" && c<="f" ||
            c>="A" && c<="F");
}
/*
RFC 3986
========
A 128-bit IPv6 address is divided into eight 16-bit pieces.  Each
piece is represented numerically in case-insensitive hexadecimal,
using one to four hexadecimal digits (leading zeroes are permitted).
The eight encoded pieces are given most-significant first, separated
by colon characters.  Optionally, the least-significant two pieces
may instead be represented in IPv4 address textual format.  A
sequence of one or more consecutive zero-valued 16-bit pieces within
the address may be elided, omitting all their digits and leaving
exactly two consecutive colons in their place to mark the elision.

   IPv6address =                            6( h16 ":" ) ls32
               /                       "::" 5( h16 ":" ) ls32
               / [               h16 ] "::" 4( h16 ":" ) ls32
               / [ *1( h16 ":" ) h16 ] "::" 3( h16 ":" ) ls32
               / [ *2( h16 ":" ) h16 ] "::" 2( h16 ":" ) ls32
               / [ *3( h16 ":" ) h16 ] "::"    h16 ":"   ls32
               / [ *4( h16 ":" ) h16 ] "::"              ls32
               / [ *5( h16 ":" ) h16 ] "::"              h16
               / [ *6( h16 ":" ) h16 ] "::"

   ls32        = ( h16 ":" h16 ) / IPv4address
               ; least-significant 32 bits of address

   h16         = 1*4HEXDIG
               ; 16 bits of address represented in hexadecimal
*/
function parse(scanner) {
    var buf = new ArrayBuffer(16);
    var addr = new Uint16Array(buf);
    var bufi = 0;

    var w = next();

    if (ipv6()) {
        return addr;
    } else {
        throw new SyntaxError("Unexpected token: " + w.str);
    }

    function ipv6() {
        var flag = true;
        for (var i = 0; flag && i<6; ++i)
            if (sect())
                w = next();
            else
                flag = false;
        if (flag && ls32()) {
            w = next();
            if (w === scanner.EOL) {
                return true;
            }
        }
    }

    function sect() {
        if (h16()) {
            w = next();
            if (w.cat === Scanner.SEP) {
                return true;
            }
        }
    }

    function h16() {
        addr[bufi++] = parseInt(w.str.toLowerCase(), 16);
        return (w.cat === Scanner.H16);
    }

    function ls32() {
        if (sect()) {
            w = next();
            if (h16()) {
                return true;
            }
        }
    }

    function next() {
        var x = scanner.next().value;
        //console.log(x);
        return x;
    }
}

var cidr = "ABCD:EF01:2345:6789:ABCD:EF01:2345:6789/63";
/*
for (let lexeme of Scanner(cidr)) {
    console.log(lexeme);
}
*/

var [ addr, prefix_len ] = cidr.split('/');
prefix_len = parseInt(prefix_len);

var rawip = parse(Scanner(addr));

ipv6_mask(prefix_len);

function ipv6_prefix(addr_uint16_arr, prefix_len) {
    const SIZE = 8;

    var mask = new Uint16Array(SIZE);
    var prefix = new Uint16Array(SIZE);

    for (var i = 0; i < SIZE; ++i) {
        prefix[i] = k;
    }

    return prefix;
}

function ipv6_mask(p) {
    if (p > 128 || p < 0)
        throw new Error();

    const SIZE = 8;
    const BASE = 16;
    var mask = new Uint16Array(SIZE);

    var bits = (mask.BYTES_PER_ELEMENT*8);
    var len = parseInt(p / bits);
    var extra = p%bits - 1;

    for (var i = 0; i < len; ++i) {
        mask[i] = 0xFFFF;
    }

    if (extra) {
        console.log(extra, extra.toString(BASE));
        mask[i+1] = parseInt(extra.toString(BASE), BASE);
    }

    console.log(mask);

    return mask;
}
