var PIYAVSKYY_TYPE = {
    PARABOL: "параболічна міноранта",
    LINE: "кусково-лінійна міноранта"
};

function Piyavskyy(type) {
    f.called = 0;
    var L = 20;
    var x = [a, b];
    var countX = 2;
    var p = 0;
    var g = 0;
    if (PIYAVSKYY_TYPE.LINE == type) {
        p = [point(x[0], x[1], L)];
        g = [g_f(p[0], x[0], L)];
        console.log(PIYAVSKYY_TYPE.LINE);
    }else if(PIYAVSKYY_TYPE.PARABOL == type){
        p = [pointDeriv(x[0], x[1], L)];
        g = [g_fDeriv(p[0], x[0], L)];
        console.log(PIYAVSKYY_TYPE.PARABOL);
    }

    var min = 0;
    do {
        min = g[0];
        var minI = 0;
        for (var j = 1; j < g.length; j++) {
            if (g[j] < min) {
                min = g[j];
                minI = j;
            }
        }
        var i = 0;
        while (x[i] < p[minI]) {
            i++;
        }
        x.splice(i, 0, p[minI]);
        p[minI] = point(x[i - 1], x[i], L);
        g[minI] = g_f(p[minI], x[i - 1], L);
        p.push(point(x[i], x[i + 1], L));
        g.push(g_f(p[countX - 1], x[i], L));
        countX++;
    } while (f(x[i]) - min > epsilon);
    console.log("x = " + x[i].toFixed(4));
    console.log("f(x) = " + f(x[i]).toFixed(4));
    console.log("Кількість обрахунків F = "+ f.called);
}
