var ads = document.getElementById("advertisements");
var search_el = document.getElementById("search");
var search_state = false;

var cur_selected = 0;

function select(list, index) {
    cur_selected = index;

    var el = list[cur_selected];
    el.setAttribute("data-selected", true);
    el.className += "selected";
}
