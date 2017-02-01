//Rafael Cepeda 2016-12-17
function binary_search(array, fn) {
    var low, mid, high;
    low ^= low;
    high = array.length - 1;
    while (low <= high) {
        mid = (low + high) >> 1;
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
