package Aplicacao;
import java.util.Scanner;
import B.B;

public class App {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        B arvore = new B();
        int escolha = 0;
        
        do {
            System.out.println("\n--- ÁRVORE B ---");
            System.out.println("1 - Exibir maior valor");
            System.out.println("2 - Exibir menor valor");
            System.out.println("3 - Exibir altura da árvore");
            System.out.println("4 - Procurar valor");
            System.out.println("0 - Sair");
            System.out.print("Escolha: ");
            escolha = scanner.nextInt();

            switch (escolha) {                    
                case 1:
                    arvore.exibirMaior();
                    break;
                case 2:
                    arvore.exibirMenor();
                    break;
                case 3:
                    System.out.println("Altura da árvore: " + arvore.calcularAltura());
                    break;
                case 4:
                    System.out.print("Digite o valor a procurar: ");
                    int valorProcurar = scanner.nextInt();
                    arvore.procurar(valorProcurar);
                    break;
                case 0:
                    System.out.println("Saindo do programa...");
                    break;
                default:
                    System.out.println("Opção inválida. Tente novamente...");
                    break;
            }
        } while(escolha != 0);
        
        scanner.close();
    }
}