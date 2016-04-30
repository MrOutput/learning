var rows = [
    ["rafael", "nelson"],
    ["torvalds","linus"]
];

var ads = document.getElementById("advertisements");

// make elmts
for (let irows = 0, lrows = rows.length, cols; irows < lrows; irows++) {
    cols = rows[irows];

    let ul = document.createElement("ul");

    for (let icols = 0, lcols = cols.length, col; icols < lcols; icols++) {
        col = cols[icols];

        let li = document.createElement("li");
            li.innerHTML = col;

        ul.appendChild(li);
    }

    ads.appendChild(ul);
}

var fst = ads.querySelector("ul>li:first-of-type");

select(fst);


var searche = document.getElementById("search");
var search = false;
// logic
document.onkeydown = function (e) {
    console.log(e.which);
    // j
    if (search === true) {
        //esc
        if (e.which === 27) {
            console.log("asonetuasnotehu");
            remove_class(searche, "show");
            search = false;
            return;
        }
        console.log(searche);
        searche.innerHTML += e.which.toString();
        console.log(e);
    } else {
        switch (e.which) {
            case 40: // down arrow
            case 74: // j
                console.log("highlight item below");
                break;
            case 38: // up arrow
            case 75: // k
                console.log("highlight item above");
                break;
            case 27: // esc
                console.log("cancel current view or search");
                break;
            case 13: // enter
                console.log("view item");
                break;
            case 78: // n
                console.log("highlight next search item");
                break;
            case 191: // '/'
                add_class(searche, "show");
                search = true;
                console.log(search);
                console.log("search ads");
                break;
        }
    }
};

function select(el) {
    el.setAttribute("data-selected", true);
    el.className += "selected";
}

function add_class(el, classname) {
    el.className += " " + classname;
}

function remove_class(el, classname) {
    el.className = el.className.replace(classname, "");
    el.className = el.className.trim();
}
