//https://stackoverflow.com/questions/46536862/check-to-see-if-all-objects-in-an-array-has-a-common-property/46537234#46537234

function recurse_obj(obj, cb, _stack = []) {
    for (var k in obj) {
        cb(k, obj[k], _stack);
        if (obj.hasOwnProperty(k) && (obj[k] instanceof Object)) {
            _stack.push(k);
            recurse_obj(obj[k], cb, _stack);
            _stack.pop();
        }
    }
}

function obj_all_keys(obj) {
    var tmp = [];

    recurse_obj(obj, (k, v, stack) => {
        var ext = (stack.length) ? "." : ""; 
        tmp.push(stack.join(".").concat(ext, k));
    }); 

    return tmp;
}

function key_intersection(...objs) {
    var lookup = {};

    objs.forEach(o => {
        obj_all_keys(o).forEach(k => {
            if (k in lookup === false)
                lookup[k] = 0;
            lookup[k]++;
        });
    });

    for (var k in lookup)
        if (lookup[k] !== objs.length)
            delete lookup[k];

    return lookup;
}
