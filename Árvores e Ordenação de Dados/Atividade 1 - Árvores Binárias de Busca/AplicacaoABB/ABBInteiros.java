package AplicacaoABB;
import ABBGenerica.ABB;
import java.util.Scanner;

public class ABBInteiros {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        ABB<Integer> numeros = new ABB<Integer>();
        int escolha = 0;
        do{
            System.out.println("Árvore Binária");
            System.out.println("1 - Inserir valor");
            System.out.println("2 - Buscar valor");
            System.out.println("Digite: ");
            escolha = scanner.nextInt();

            switch (escolha) {
                case 1:
                    System.out.println("Digite um número: ");
                    int numero = scanner.nextInt();
                    numeros.insert(numero);
                    break;
                case 2:
                    System.out.println("Digite o número: ");
                    int buscar = scanner.nextInt();
                    Integer encontrado = numeros.find(buscar);
                    if (encontrado != null) {
                        System.out.println("Valor " + encontrado + " encontrado na árvore!");
                    } else {
                        System.out.println("Valor não encontrado.");
                    }
                    break;
                default:
                    System.out.println("Opção incorreta! Tente novamente...");
                    break;
            }
        } while(escolha != 0);
        scanner.close();
    }   
}