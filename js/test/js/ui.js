function add_class(el, classname) {
    el.className += " " + classname;
}

function remove_class(el, classname) {
    el.className = el.className.replace(classname, "");
    el.className = el.className.trim();
}
