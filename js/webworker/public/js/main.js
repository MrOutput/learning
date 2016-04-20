var data_worker = new Worker("js/data.js");

/* all data */
var site_data = {advertisements: [], users: []};
//var site_events = [{event: new Event("refreshed_ads"), subscribers: [document]];

/* register events*/
var event_refreshed_ads = new Event("refreshed_ads");

document
    .getElementById("advertisements")
    .addEventListener("refreshed_ads", function (e) {
        console.log("advertisements refreshed, update everything that depends on them");
    });

/* get initial data */
refresh_test();

/* async REST API response handler */
data_worker.onmessage = function (message) {
    switch (message.data.req.sender) {
    case 0: // receiver for fresh ads
        site_data.advertisements = message.data.res.data;
        //document
        //    .getElementById("advertisements")
        //    .dispatchEvent(event_refreshed_ads);
        create_datalist(message.data.res.data, document.getElementById("advertisements"));

        break;
    }

    console.log("finished: %s", message.data.req.message);
};

/*
 * creates a ul from any object
 *
 * @param * data
 * @return Element ul
 */
function create_datalist(data, ul) {
    if (typeof data === "object") {
        var nested_ul = document.createElement("ul");

        if (Array.isArray(data)) {
            for (var i = 0, l = data.length; i < l; ++i) {
                var cur_data = data[i];
                ul.appendChild( create_li_from_data(cur_data, nested_ul) );
            }
        } else {
            for (let value in data) {
                var cur_data = data[value];

                var item = create_li_from_data(cur_data, nested_ul);

                item.innerHTML = value + ": " + item.innerHTML;

                ul.appendChild(item);
            }
        }
    } else {
        throw "data must be an object";
    }
}

/*
 * creates an li element from any data type
 * if the item is iterable (object, or array)
 * the li will contain a ul element w/ li's for
 * each non-iterable element
 *
 * @param * data
 * @return Element li
 */
function create_li_from_data(data, ul) {
    var li = document.createElement("li");

    if (typeof data === "object") {
        li.appendChild( create_datalist(data, ul) );
    } else {
        li.innerHTML = data;
    }

    return li;
}

/* testing data_worker */
function delete_that() {
    data_worker.postMessage({method: "DELETE", uri: "/test", message: "delete test"});
}

/* testing data_worker */
function refresh_test() {
    data_worker.postMessage({method: "GET", uri: "/test", message: "get advertisements", sender: 0});
}
