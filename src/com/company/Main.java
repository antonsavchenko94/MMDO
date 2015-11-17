package com.company;

public class Main {
    static double  [] x0 = {0,-1,2,-5};
    static double  [] x0_2 = {1,-1};
    static double e = 0.0001;
    static double h0 = 1;
    public static void main(String[] args) {

        execute();
        System.out.println("Гауса-Зейдуля");
        jordan_Gauss();
//        newTon();
//        System.out.println("--------------------");
//        newTonMod();

    }


    public static void execute() {
        double[] g = Function.gradient(x0);
        double[] x;

        if(Function.vectorNorm(g) > e) {
            do{
                x = x0;
                double h = Function.findH(x, g, h0, e,1);

                x0 = new double[x0.length];
                for(int i = 0; i < x0.length; i++) {
                    x0[i] = x[i] - h*g[i];
                }

                g = Function.gradient(x0);

            }while(Function.vectorNorm(Function.massiveMinus(x, x0)) >= e && Function.vectorNorm(g) >= e);
        }

        System.out.println("x = " + Function.massiveToString(x0));
        System.out.println("f1(x) = " + Function.f1(x0));
//        System.out.println("x1 = " + "0.25, 0.75");
//        System.out.println("f1(x1) = " + Function.f1(new double[]{0.25, 0.75}));
    }

    public static void jordan_Gauss() {
        double[] h = new double[x0.length];
        for(int i = 0; i < h.length; i++) {
            h[i] = h0;
        }

        double[] x_int = x0;
        double[] x_ext;
        do{
            x_ext = Function.massiveCopy(x_int);

            for(int i = 0; i < x_int.length; i++) {
                double[] x = Function.massiveCopy(x_int);

                double[] y1 = Function.massiveCopy(x);
                y1[i] += 3*e;
                double[] y2 = Function.massiveCopy(x);
                y2[i] -= 3*e;
                double f1 = Function.f1(y1);
                double f2 = Function.f1(y2);
                double z = Math.signum(f2 - f1);

                h[i] = Function.findHCWD(x_int, z, i, h[i], e);

                x_int[i] = x[i] + h[i]*z;
            }
        }while(Function.vectorNorm(Function.massiveMinus(x_int, x_ext)) >= e);

        System.out.println("x = " + Function.massiveToString(x_int));
        System.out.println("f1(x) = " + Function.f1(x_int));
    }

    public static void newTon() {
        double[] g = Function.gradient(x0_2);

        if(Function.vectorNorm(g) > e) {
            do{
                double[] x = x0_2;
                double[][] g2 = Function.gess_f(x0_2);//gess_f
                double[][] g2_1 = Function.jordanGauss(g2);//inverse(g2);

                x0_2 = new double[x0_2.length];
                double[] w = new double[x0_2.length];

                for(int i = 0; i < x0_2.length; i++) {
                    w[i] = 0;
                    for(int j= 0; j < x0_2.length; j++) {
                        w[i] += g2_1[i][j]*g[j];
                    }
                }
                x0_2 = Function.massiveMinus(x,w);
                g = Function.gradient2(x0_2);
            }while(Function.vectorNorm(g) >= e);
        }

        System.out.println("x = " + Function.massiveToString(x0_2));
        System.out.println("f1(x) = " + Function.f2(x0_2));
    }

    public static void newTonMod() {
        double[] g = Function.gradient2(x0);

        if(Function.vectorNorm(g) > e) {
            do{
                double[] x = x0_2;
                double[][] g2 = Function.gess_f(x0);
                double[][] g2_1 = Function.jordanGauss(g2);

                x0_2 = new double[x0_2.length];
                double[] w = new double[x0_2.length];
                for(int i = 0; i < x0_2.length; i++) {
                    w[i] = 0;

                    for(int j= 0; j < x0_2.length; j++) {
                        w[i] += g2_1[i][j]*g[j];
                    }
                }

                double h = Function.findH(x, w, h0, e, 2);
                for(int i = 0; i < x.length; i++) {
                    x0_2[i] = x[i] - h*w[i];
                }

                g = Function.gradient2(x0_2);
            }while(Function.vectorNorm(g) >= e);
        }

        System.out.println("x = " + Function.massiveToString(x0_2));
        System.out.println("f1(x) = " + Function.f2(x0_2));
    }



}
