//comparing binary search implemenation to native js indexOf
//conclusion...see for yourself you will be surprised
//Rafael Cepeda 2016-12-17

var states = ["Alabama", "Alaska", "American Samoa", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "District Of Columbia", "Federated States Of Micronesia", "Florida", "Georgia", "Guam", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Marshall Islands", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Northern Mariana Islands", "Ohio", "Oklahoma", "Oregon", "Palau", "Pennsylvania", "Puerto Rico", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virgin Islands", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming"];

var SEARCH_FOR = "Oklahoma";
var SEARCH_IN = states;
console.log("Searching array with %s elements", SEARCH_IN.length);

var i;

console.time("indexOf");
i = SEARCH_IN.indexOf(SEARCH_FOR);
console.timeEnd("indexOf");
console.log("INDEXOF: Found element %s at index %s", SEARCH_IN[i], i);


console.time("binary_search");
var c = 0;
i = binary_search(SEARCH_IN, function (el) {
    c++;
    return strcmp(SEARCH_FOR, el);
});
console.timeEnd("binary_search");
console.log("BINARY SEARCH: Found element %s at index %s in %s iterations", SEARCH_IN[i], i, c);


//for giggles, sequential search because we can :) the results are surprising
console.time("sequential search");
i = sequential_search(SEARCH_IN, SEARCH_FOR);
console.timeEnd("sequential search");
console.log("SEQ SEARCH: Found element %s at index %s", SEARCH_IN[i], i);

function sequential_search(array, el) {
    for (i = 0; i < array.length; i++)
        if (array[i] === el)
            return i;
    return -1;
}

//binary_search: finds index of element in array through custom function; returns index or -1 if not found
function binary_search(array, fn) {
    var low, mid, high;
    low = 0;
    high = array.length - 1;
    while (low <= high) {
        //dividing by shifting increases the search speed by 100ms in this ex.
        //also ~~ rids the decimal also increasing the speed by 200ms in this ex.
        mid = ~~((low + high) >> 1);
        var cmp = fn(array[mid]);
        if (cmp < 0) {
            high = mid - 1;
        } else if (cmp > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

/*
 * strcmp: compares two strings
 * returns -1 if reference string is before comparison string  
 * returns 1 if reference string is after comparison string  
 * returns 0 if equal
 */
function strcmp(ref, cmp) {
    if (ref < cmp) {
        return -1;
    } else if (ref > cmp) {
        return 1;
    } else {
        return 0;
    }
}
