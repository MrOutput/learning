var express = require('express');
var app = express();

app.use(express.static('public'));

app.get('/', function (req, res) {
    res.send('Hello World!');
});

app.get('/test', function (req, res) {
    var data = {
        data: [
            {name: "rafael cepeda", age: 22, colors: ["orange", "green", "brown"], loves: {name: "ana buracioc", age: 24}},
            {name: "nelson cepeda", age: 24, numbers: [2, 8, 9], location: {state: "new jersey", city: "newark"}},
            {name: "vanessa cepeda", age: 13}
        ]
    };

    res.json(data);
});

app.delete("/test", function (req, res) {
    res.sendStatus(200);
});

app.listen(3000, function () {
    console.log('Example app listening on port 3000!');
});
