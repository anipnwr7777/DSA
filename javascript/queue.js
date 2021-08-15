function Queue(){
    var q = [];
    this.enqueue = function(element){
        q.push(element);
    }
    this.dequeue = function(){
        q.shift();
    }
    this.size = function(){
        return q.length;
    }
    this.front = function(){
        return q[0];
    }
    this.empty = function(){
        return q.length == 0;
    }
    this.print = function(){
        console.log(q);
    }
}

var myq = new Queue();
myq.enqueue(1);
myq.enqueue(3);
myq.enqueue('name');
myq.enqueue({name:1, name2:2});
myq.print();

myq.dequeue();
myq.print();

console.log(myq.empty());
console.log(myq.front());
console.log(myq.size());




