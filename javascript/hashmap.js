// returns an index at which given key value pair should be inserted based on the hash value calculated for the given key
var hash = (string, max) => {
    var hash = 0;
    for(var i=0 ; i<string.length ; i++){
        hash += string.charCodeAt(i);
    }
    return hash%max;
}

let HashTable = function(){
    let storage = [];   // this is the hashmap
    const storageLimit = 4;     // size of hashmap needed

    this.print = function() {
        console.log(storage);
    }

    this.add = function(key, value) {
        var index = hash(key, storageLimit);
        if(storage[index] == undefined) {       // given place is empty
            storage[index] = [[key, value]];    // directly insert
        }
        else{
            var inserted = false;
            for(var i=0 ; i<storage[index].length ; i++){
                if(storage[index][i][0] == key) {       // if at that bucket any other value is already present with key same as this key then update that key with the new vlaue for that key and mark inserted as true
                    storage[index][i][1] = value;
                    inserted = true;
                }
            }
            if(inserted == false){
                // if this key is not present and some other key was present at this bucket then just push this key vlaue pair at the end of this bucket (is becomes sort of vector<vector<int>> )
                storage[index].push([key, value]);
            }
        }
    }

    this.remove = function(key) {
        var index = hash(key, storageLimit);
        if(storage[index].length == 1 && storage[index][0][0] == key){
            delete storage[index];
        }
        else{
            for(var i=0 ; i<storage[index].length ; i++){
                if(storage[index][i][0] == key){
                    delete storage[index][i];
                }
            }
        }
    }

    this.lookup = function(key) {
        var index = hash(key, storageLimit);
        if(storage[index] == undefined){
            return undefined;
        }
        else{
            for(var i=0 ; i<storage[index].length ; i++){
                if(storage[index][i][0] == key){
                    return storage[index][i][1];
                }
            }
        }
    }
}

let ht = new HashTable();
ht.add(1, 'anirudh');
ht.add(10, 'nice');
ht.add(111, 123);
ht.print();
console.log(ht.lookup(17));     // undefined
console.log(ht.lookup(111));

ht.remove(1);
ht.print();

