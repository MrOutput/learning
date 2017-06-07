const http = require('http');
const querystring = require('querystring');

const server = new http.createServer();

//method enum
var transition_table = { 'GET': {} };

//register request handler
transition_table['GET']['/user'] = getUser;

server.on('request', function (request, response) {
    let [path, queries] = request.url.split('?');
    queries = querystring.parse(queries);

    request.queries  = queries;

    if (path in transition_table[request.method]) {
        transition_table[request.method][path](request, response);
    } else {
        res.statusCode = 404;
        res.end();
    }
});

function getUser(req, res) {
    let { queries } = req;
    if ('name' in queries) {
        res.end('hello, world : '.concat(queries.name), 'utf8');
    } else {
        res.statusCode = 400;
        res.end();
    }
}

server.listen('3333');
