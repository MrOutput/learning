/* tests */
var x = [8, 8, {hello: "rafael", colors: ["orange", "green", "brown", {welcome: "Hi my name is Rafael", night: "hello", day: [3, 3]}]}];

var y = deep_copy(x);

y[2].hello = "";

console.log(x);
console.log(JSON.stringify(y));


/* @param Array or Object 
 * @return Array or Object
 */
//function deep_copy(container) {
//    if (arg is a container) {
//        buffer = (if container is an array then create an array else create an object)
//
//        for (every item in the container) {
//            if (current item is a container) {
//                current buffer = deep_copy (current container)
//            } else {
//                current buffer is = static current container value;
//            }
//        }
//
//        return buffer;
//    } else {
//        throw an error
//    }
//}

function deep_copy(data) {
    var IS_CONTAINER = function (datatype) {
        return ( Array.isArray(datatype) || typeof datatype === "object" );
    };

    if ( IS_CONTAINER(data) ) {
        var IS_ARRAY = Array.isArray(data);

        var buffer = (IS_ARRAY) ?  [] : {};

        if (IS_ARRAY) {
            for (var i = 0, l = data.length, cur_data = null; i < l; i++) {
                cur_data = data[i];

                if ( IS_CONTAINER(cur_data) ) {
                    buffer[i] = deep_copy(cur_data);
                } else {
                    buffer[i] = cur_data;
                }
            }
        } else {
            for (var prop in data) {
                cur_data = data[prop];

                if ( IS_CONTAINER(cur_data) ) {
                    buffer[prop] = deep_copy(cur_data);
                } else {
                    buffer[prop] = cur_data;
                }
            }
        }

        return buffer;
    } else {
        throw "Argument must be a container data type.";
    }
}
