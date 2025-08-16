public class TesteCalc {
    public static void main(String[] args) {
        System.out.println("Testando com 2 Numeros: ");
        System.out.println("5 + 3 = " + Calculadora.calcular(5, '+', 3));
        System.out.println("10 - 4 = " + Calculadora.calcular(10, '-', 4));
        System.out.println("6 * 2 = " + Calculadora.calcular(6, '*', 2));
        System.out.println("8 / 2 = " + Calculadora.calcular(8, '/', 2));

        System.out.println("Testando com 3 Numeros: ");
        System.out.println("5 + 3 * 2 = " + Calculadora.calcular(5, '+', 3, '*', 2));
        System.out.println("10 - 4 / 2 = " + Calculadora.calcular(10, '-', 4, '/', 2));
    }
}