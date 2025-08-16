public class Calculadora {

    public static double calcular(double a, char simb, double b) {
        return operacao(a, simb, b);
    }

    public static double calcular(double a, char simb, double b, char simb2, double c) {
        double valor = operacao(a, simb, b);
        return operacao(valor, simb2, c);
    }

    private static double operacao(double x, char simb, double y) {
        if (simb == '+') {
            return x + y;
        } else if (simb == '-') {
            return x - y;
        } else if (simb == '*') {
            return x * y;
        } else if (simb == '/') {
            if (y == 0) {
                System.out.println("Erro: divisão por zero não é permitida!");
                return 0;
            }
            return x / y;
        } else {
            System.out.println("Erro: operador inválido (" + simb + ")");
            return 0;
        }
    }
}
