const http = require('http');
const querystring = require('querystring');

const server = new http.createServer();

//method enum
var transition_table = { 'GET': {} };

//register request handler
transition_table['GET']['/'] = getIndex;

server.on('request', function (req, res) {
    let [path, queries] = req.url.split('?');
    queries = querystring.parse(queries);

    req.queries  = queries;

    if (path in transition_table[req.method]) {
        transition_table[req.method][path](req, res);
    } else {
        res.statusCode = 404;
        res.end();
    }
});

function getIndex(req, res) {
    res.end('hello, world');
}

server.listen('3333');
