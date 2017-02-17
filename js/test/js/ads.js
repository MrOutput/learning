var ads = document.getElementById("advertisements");
var search_el = document.getElementById("search");
var search_state = false;

var cur_selected = 0;
var list_el;

function select_ad(index) {
    cur_selected = index;

    var el = list_el[cur_selected];
    el.setAttribute("data-selected", true);
    el.className += "selected";
}

function deselect_ad(index) {
    var el = list_el[index];

    el.setAttribute("data-selected", false);
    remove_class(el, "selected");

    cur_selected = 0;
}

function select_next_ad() {
    deselect_ad(cur_selected);
    cur_selected++;
    select_ad(cur_selected);
}

function select_prev_ad() {
    deselect_ad(cur_selected);
    cur_selected--;
    select_ad(cur_selected);
}
