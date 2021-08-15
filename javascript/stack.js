var s = 'hello';
var stack = [];

for(var i=0 ; i<s.length ; i++){
    stack.push(s[i]);
}
var nw = '';
for(var i=0 ; i<s.length ; i++){
    nw += stack.pop();
}
console.log(nw);