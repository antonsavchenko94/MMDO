function evenBusting (){
    f.called = 0;
    console.log("рівномірного перебору");
    var L = 20;
    var h = (2* epsilon) /L;
    var x1 = a  - h /2;
    var firstX = x1;
    var firstF = f(x1);
    var xMin = firstX;
    var fMin = firstF;
    var iteration = 0
    while(firstX < b){
        iteration++;
        firstX += h;
        if (firstX > b){
            firstX = b;
        }
        firstF = f(firstX);
        if (firstF < fMin) {
            fMin =firstF;
            xMin = firstX;
        }
    }
    if(epsilon==0.01){
        return {num:1, name:"Рівномірного перебору", itr: iteration,Nf: f.called ,x:xMin, f:f(xMin)};
    }else if(epsilon==0.0001){
        return {itr: iteration,Nf: f.called ,x:xMin, f:f(xMin)};
    }
    //console.log("x = " + xMin);
    //console.log("f(x) = " + f(xMin));
    //console.log("Кількість обрахунків F = "+ f.called);
}