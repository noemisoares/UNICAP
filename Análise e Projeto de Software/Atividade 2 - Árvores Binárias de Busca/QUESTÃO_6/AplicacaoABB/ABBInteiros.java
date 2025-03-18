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
            System.out.println("3 - Contar número de nós (recursivo)");
            System.out.println("4 - Contar número de nós (não recursivo)");
            System.out.println("5 - Contar número de folhas (recursivo)");
            System.out.println("6 - Contar número de folhas (não recursivo)");
            System.out.println("7 - Contar número de nós não-terminais (recursivo)");
            System.out.println("8 - Contar número de nós não-terminais (não recursivo)");
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
                    System.out.println("Total de nós: " + numeros.NosRecursivo());
                    break;
                case 4:
                    System.out.println("Total de nós (não recursivo): " + numeros.NosNaoRecursivo());
                    break;
                case 5:
                    System.out.println("Total de folhas: " + numeros.FolhasRecursivo());
                    break;
                case 6:
                    System.out.println("Total de folhas (não recursivo): " + numeros.FolhasNaoRecursivo());
                    break;
                case 7:
                    System.out.println("Total de nós não-terminais: " + numeros.NaoTerminaisRecursiva());
                    break;
                case 8:
                    System.out.println("Total de nós não-terminais (não recursivo): " + numeros.NaoTerminaisNaoRecursiva());
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
