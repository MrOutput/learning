var rows = [
    ["rafael", "nelson"],
    ["torvalds","linus"]
];

// state vars
var ads = document.getElementById("advertisements");
var search_el = document.getElementById("search");
var search_state = false;

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

var list_el = ads.querySelectorAll("ul li");

select(list_el, cur_selected);
console.log(list_el);


// logic
document.onkeydown = function (e) {
    console.log(e.which);
    // j
    if (search_state === true) {
        //esc
        if (e.which === 27) {
            console.log("asonetuasnotehu");
            remove_class(search_el, "show");
            search_state = false;
            return;
        }
        console.log(search_el);
        search_el.innerHTML += String.fromCharCode(e.which);
        console.log(e);
    } else {
        switch (e.which) {
            case 40: // down arrow
            case 74: // j
                cur_selected++;
                select(list_el, cur_selected);
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
                add_class(search_el, "show");
                search_state = true;
                console.log(search_state);
                console.log("search ads");
                break;
        }
    }
};

var cur_selected = 0;
function select(list, index) {
    var el = list[index];
    el.setAttribute("data-selected", true);
    el.className += "selected";
}

function select_next() {
    
}

function add_class(el, classname) {
    el.className += " " + classname;
}

function remove_class(el, classname) {
    el.className = el.className.replace(classname, "");
    el.className = el.className.trim();
}
