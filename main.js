

function partition(arr, start, end) {
    let cursor = start;
    let pivot = arr[end - 1]
    for (let i = start; i < end - 1; i++) {
        if (arr[i] <= pivot) {
            let temp = arr[cursor];
            arr[cursor] = arr[i];
            arr[i] = temp;
            cursor++;
        }
    }

    let temp = arr[cursor];
    arr[cursor] = arr[end - 1];
    arr[end - 1] = temp;
    return cursor;

}

function dumbqsort(arr, start, end) {
    if (start >= end) return;

    let index = partition(arr, start, end);

    dumbqsort(arr, start, index);
    dumbqsort(arr, index + 1, end);
}

function debugDump(arr,  len) {
    let line = ""
    for (let i = 0; i < len; i++) {
        line += (arr[i].toFixed(4))+" ";
    }
    console.log(line)
}

function main() {
    let arrLength = 10000000;

    let arr = new Float32Array(arrLength)

    for (let i = 0; i < arrLength; ++i) {
        arr[i] = Math.random();
    }
   // debugDump(arr, arrLength);
    let start = Date.now()
    dumbqsort(arr, 0, arrLength);
    let stop = Date.now()
    document.getElementById("result").innerHTML = `Time: ${(stop-start).toFixed(1)} ms`
   // debugDump(arr, arrLength);
    return 0;
}
