class square{
    constructor(height, width){
        this.height = height;
        this.width = width;
    }
    get calArea(){
        return this.height*this.width;
    }
}

let sq = new square(1,2);
console.log(sq.calArea);    // notice the change here when I call the getter here rather than a different function as defined in classes.js, don't use paranthesis while calling getter.