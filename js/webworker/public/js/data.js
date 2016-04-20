/* data_worker is responsible for all requests to REST API */
onmessage = function (req) {
    req = req.data;

    var http_req = new XMLHttpRequest();
        http_req.responseType = "json";

        http_req.onloadstart = function (e) {
            console.log("getting data...");
        };

        http_req.onloadend = function (e) {
            console.log("data retrieved...");
        };

        http_req.onerror = function (e) {
            console.log("error retrieving data...");
        };

        http_req.onprogress = function (e) {
            console.log("progress made...");
        };

        http_req.onload = function (e) {
            console.log("done", this.status);

            postMessage({req: req, res: this.response});
        };

        http_req.open(req.method, req.uri);
        http_req.send();
}
