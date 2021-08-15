class square{
    constructor(height, width){
        this.height = height;
        this.width = width;
    }
    // function keyword throws error here
    calArea(){
        return this.height*this.width;
    }
}

let sq = new square(1,2);
console.log(sq.calArea());