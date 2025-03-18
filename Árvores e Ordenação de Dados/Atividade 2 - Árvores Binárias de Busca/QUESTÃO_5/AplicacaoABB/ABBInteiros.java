package AplicacaoABB;
import ABBGenerica.ABB;
import java.util.Scanner;

public class ABBInteiros {
    public static void main(String[] args) {
        ABB<Integer> numeros = new ABB<>();
        Scanner scanner = new Scanner(System.in);
        int opcao, valor;

        do {
            System.out.println("\n--- ÁRVORE BINÁRIA ---");
            System.out.println("1 - Inserir valor");
            System.out.println("2 - Buscar valor");
            System.out.println("3 - Percorrer em ordem");
            System.out.println("0 - Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt();

            switch (opcao) {
                case 1:
                    System.out.print("Digite o valor a ser inserido: ");
                    valor = scanner.nextInt();
                    numeros.insert(valor);
                    break;
                case 2:
                    System.out.print("Digite o valor a ser buscado: ");
                    valor = scanner.nextInt();
                    Integer encontrado = numeros.find(valor);
                    if (encontrado != null) {
                        System.out.println("Valor " + encontrado + " encontrado na árvore!");
                    } else {
                        System.out.println("Valor não encontrado.");
                    }
                    break;
                case 3:
                    System.out.println("Passeio em Ordem:");
                    numeros.emOrdem();
                    break;
                case 0:
                    System.out.println("Encerrando o programa...");
                    break;
                default:
                    System.out.println("Opção inválida! Tente novamente.");
            }
        } while (opcao != 0);

        scanner.close();
    }
}
