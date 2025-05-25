package Aplicacao;
import java.util.Scanner;
import B.B;

public class App {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
       B numeros = new B();
        int escolha = 0;
        do{
            System.out.println("Opções:");
            System.out.println("1 - Inserir valor na árvore");
            System.out.println("2 - Exibir as chaves por nível");
            System.out.println("3 - Exibir as chaves pré ordem");
            System.out.println("4 - Remover um valor da árvore");
            System.out.println("0 - Sair ");
            System.out.println("Informe a opção desejada: ");
            escolha = scanner.nextInt();

            switch (escolha) {
                case 1:
                    System.out.println("Digite um número: ");
                    int inserirNum = scanner.nextInt();
                    numeros.insert(inserirNum);
                    break;
                case 2:
                    System.out.println("Passeio Por Nível: ");
                    numeros.porNivel(); 
                    break;
                case 3:
                    System.out.println("Passeio Pré Ordem: ");
                    numeros.preOrdem();
                    break;
                case 4:
                    System.out.println("Passeio Por Nível: ");
                    numeros.porNivel(); 
                    break;
                case 0:
                    System.out.println("Saindo do programa... ");
                    break;
                default:
                    System.out.println("Opção inválida. Tente novamente... ");
                    break;
            }
        } while(escolha != 0);
        scanner.close();
    }
}