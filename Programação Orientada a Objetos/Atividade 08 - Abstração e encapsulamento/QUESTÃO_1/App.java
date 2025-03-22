import java.util.Scanner;

public class App{
    public static void main (String[] args){
        Scanner scanner = new Scanner(System.in);
        ContaBancaria conta = new ContaBancaria(null, null);

        System.out.println("Digite o nome do titular da conta: ");
        conta.setNome(scanner.nextLine());
        System.out.println("Nome do Titular da Conta: " + conta.getNome());

        System.out.println("Digite o número da conta: ");
        conta.setNumero(scanner.nextLine());
        System.out.println("Número da Conta: " + conta.getNumero());

        System.out.println("Digite o saldo da conta: ");
        conta.setSaldo(scanner.nextDouble());
        System.out.println("Saldo da Conta: " + conta.getSaldo());
        scanner.close();
    }
}