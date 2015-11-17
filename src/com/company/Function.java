package com.company;

/**
 * Created by mozli on 14.11.2015.
 */
public class Function {
    public static double vectorNorm(double[] x) {
        double sum = 0;
        for (double aX : x) sum += Math.pow(aX, 2);
        return Math.sqrt(sum);
    }

    public static double[] massiveMinus(double[] x1, double[] x2) {
        double[] res = new double[x1.length];
        for (int i = 0; i < x1.length; i++) {
            res[i] = x1[i] - x2[i];
        }
        return res;
    }

    public static double[][] jordanGauss(double[][] inp) {
        double[][] input = new double[inp.length][inp[0].length];
        for (int i = 0; i < inp.length; i++) {
            input[i] = massiveCopy(inp[i]);
        }
        double[][] res = new double[input.length][input[0].length];
        for (int i = 0; i < res.length; i++) {
            for (int j = 0; j < res[0].length; j++) {
                res[i][j] = (i == j) ? 1 : 0;
            }
        }

        for (int i = 0; i < res[0].length - 1; i++) {
            double div = input[i][i];
            //утворенн€ 1 на д≥агонал≥
            for (int j = 0; j < res[0].length; j++) {
                res[i][j] /= div;
                input[i][j] /= div;
            }
            //”творюЇмо 0 у стовпц€х
            for (int j = i + 1; j < res.length; j++) {

                div = input[j][i];
                for (int k = 0; k < res[0].length; k++) {
                    res[j][k] -= res[i][k] * div;
                    input[j][k] -= input[i][k] * div;
                }
            }
        }

        double div = input[input.length - 1][input[0].length - 1];
        //утворенн€ 1 на останн≥й д≥агонал≥
        for (int j = 0; j < res[0].length; j++) {
            res[input.length - 1][j] /= div;
            input[input.length - 1][j] /= div;
        }

        //ќбернений х≥д алгоритму(зм≥нюЇмо числа над д≥агоналлю)
        for (int i = res.length - 1; i > 0; i--) {

            for (int j = i - 1; j >= 0; j--) {

                div = input[j][i];
                for (int k = 0; k < res[0].length; k++) {
                    res[j][k] -= res[i][k] * div;
                    input[j][k] -= input[i][k] * div;
                }
            }
        }
        return res;
    }

    public static double[] massiveCopy(double[] doubles) {
        double [] x = new double[doubles.length];
        for(int i = 0; i<doubles.length; i++){
            x[i] = doubles[i];
        }
        return x;
    }

    public static double f1(double[] x) {
        return Math.pow((x[0]-2),2) + Math.pow((x[1]+5),2) + Math.pow((x[2]-4),2) + Math.pow((x[3]+8),2);
//        return Math.pow((x[0]-5),2) + Math.pow((x[1]+2),2) + Math.pow((x[2]+4),2) + Math.pow((x[3]-8),2) + Math.pow((x[4]+4),2);
//        return 5 * Math.pow(x[0], 2) + x[0] * x[1] + 25 * Math.pow(x[1], 2) - 4 * x[0] + 6 * x[1];
    }
    public static double f2(double[] x) {
        return Math.pow(x[0], 2) + Math.exp(2 * Math.pow(x[0],2)+ Math.pow(x[1],2)) + x[0] - x[1];
    }

    public static double[] gradient(double[] x) {
        return new double[]{2*(x[0]-2), 2*(5 + x[1]), 2*( x[2]-4), 2*( x[3]+8)};
//        return new double[]{10 * x[0] + x[1] - 4, x[0] + 50 * x[1] + 6};
    }
    public static double[] gradient2(double[] x) {
        return new double[]{ 4 * x[0] * Math.exp(2 * x[0] * x[0] + x[1] * x[1]) + 2 * x[0] + 1,  2 * x[1] * Math.exp(2 * x[0] * x[0] + x[1] * x[1]) - 1};
    }

    public static double findH(double[] x0, double[] g, double h0, double e, int m) {
        double h = 0;
        double ha;
        double hb;
        double f1;
        if(m == 2){
            f1= Function.f2(x0);
        }else {
            f1 = Function.f1(x0);
        }
        double[] x1 = new double[x0.length];
        double[] x2 = new double[x0.length];
        double f2;
        do {
            h0 = h0 / 2;

            for (int i = 0; i < x0.length; i++) {
                x2[i] = x0[i] - h0 * g[i];
            }
            if(m == 2){
                f2 = Function.f2(x2);;
            }else {
                f2 = Function.f1(x2);;
            }
        } while (f1 <= f2 && h0 >= e);
        if (h0 > e) {
            int secondCycle = 0;
            do {
                x1 = x2;
                x2 = new double[x0.length];
                f1 = f2;
                h += h0;
                for (int i = 0; i < x0.length; i++) {
                    x2[i] = x1[i] - h * g[i];
                }

                if(m == 2){
                    f2 = Function.f2(x2);;
                }else {
                    f2 = Function.f2(x2);;
                }
                secondCycle++;
            } while (f1 >= f2);
            ha = h - 2 * h0;
            hb = h;
            double sigma = e / 3;
            do {
                double h1 = (ha + hb - sigma) / 2;
                double h2 = (ha + hb + sigma) / 2;
                for (int i = 0; i < x0.length; i++) {
                    x1[i] = x0[i] - h1 * g[i];
                    x2[i] = x0[i] - h2 * g[i];
                }
                f1 = Function.f1(x1);
                f2 = Function.f1(x2);
                if (f1 <= f2) {
                    hb = h2;
                } else {
                    ha = h1;
                }
            } while (hb - ha >= e);

            h = (ha + hb) / 2;
        }

        return h;
    }

    public static double findHCWD(double[] x0, double z, int num, double h0, double e) {
        double h = 0;
        double ha;
        double hb;
        double f1 = Function.f1(x0);
        double[] x1;
        double[] x2 = massiveCopy(x0);
        double f2;
        do {
            h0 = h0 / 2;
            x2[num] = x0[num] + h0 * z;//here
            f2 = Function.f1(x2);
        } while (f1 <= f2 && h0 >= e);

        if (h0 > e) {
            int secondCycle = 0;
            do {
                x1 = massiveCopy(x2);
                f1 = f2;
                h += h0;

                x2[num] = x1[num] + h * z;//here

                f2 = Function.f1(x2);
                secondCycle++;
            } while (f1 >= f2);

            ha = h - 2 * h0;
            hb = h;
            double sigma = e / 3;

            do {
                double h1 = (ha + hb - sigma) / 2;
                double h2 = (ha + hb + sigma) / 2;

                x1[num] = x0[num] + h1 * z;//here
                x2[num] = x0[num] + h2 * z;//here

                f1 = Function.f1(x1);
                f2 = Function.f1(x2);

                if (f1 <= f2) {
                    hb = h2;
                } else {
                    ha = h1;
                }
            } while (hb - ha >= e);

            h = (ha + hb) / 2;
        }
        return h;
    }

    public static String massiveToString(double[] x0) {
        StringBuilder str = new StringBuilder();
        for(double inX: x0){
            str.append(inX+" ");
        }
        return str.toString();
    }

    public static double[][] gess_f(double[] x) {
        return new double [][]{
                {(16*x[0]*x[0] + 4)*Math.exp(2*x[0]*x[0] + x[1]*x[1]),8*x[0]*x[1]*Math.exp(2*x[0]*x[0] + x[1]*x[1])},
                {8*x[0]*x[1]*Math.exp(2*x[0]*x[0] + x[1]*x[1]),(4*x[1]*x[1]+2)*Math.exp(2*x[0]*x[0] + x[1]*x[1])}};

    }
}