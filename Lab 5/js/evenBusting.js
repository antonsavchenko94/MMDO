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
    while(firstX < b){
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
    console.log("x = " + xMin);
    console.log("f(x) = " + f(xMin));
    console.log("Кількість обрахунків F = "+ f.called);
}