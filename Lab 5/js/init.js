var a = -3.0;
var b = 3.0;
var epsilon = 0.0001;

function point(x1, x2, L) {
    return 0.5 * (x1 + x2 + (f(x1) - f(x2)) / L);
}
function pointDeriv(x1, x2, L) {
    var d1 = fDeriv(x1);
    var d2 = fDeriv(x2);
    var f1 = f(x1);
    var f2 = f(x2);
    var a1 = (2 / L) * (f2 - f1 + 2 * (Math.pow(d2, 2) - Math.pow(d1, 2)) / L);
    var a2 = x1 + d1 / L - x2 - d2 / L;
    return (a1 / a2 + x1 + d1 / L + x2 + d2 / L) / 2;
}
function g_f(p, x0, L) {
    return f(x0) - L * Math.abs(p - x0);
}
function g_fDeriv(p, x0, L) {
    return f(x0) + Math.pow(fDeriv(x0), 2) / (2 * L) - L * Math.pow(p - x0 - fDeriv(x0) / L, 2) / 2;
}
function f(x) {
    f.called++;
    return x * Math.sin(x) - 2 * Math.cos(3 * x);
}

function fDeriv(x) {
    return Math.sin(x) + 6 * Math.sin(3 * x) + x * Math.cos(x);
}
