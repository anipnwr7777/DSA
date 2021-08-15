var newset = new Set();
newset.add(3);
newset.add(1);
newset.add(5);
newset.add(9);
newset.add(3);

console.log(newset);
console.log(newset.has(9));
console.log(newset.has(0));

newset.delete(9);
console.log(newset);

newset.add('hello');
var obj = {
    name: "anirudh",
    age: 21
}
newset.add(obj);
console.log(newset);
