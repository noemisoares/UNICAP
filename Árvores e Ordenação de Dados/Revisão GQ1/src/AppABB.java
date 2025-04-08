import ABBTree.ABB;
import java.util.Scanner;

public class AppABB {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        ABB<Integer> arv1 = new ABB<Integer>();
        ABB<Integer> arv2 = new ABB<Integer>();
        int escolha = 0;
        do{
            System.out.println("Árvore Binária");
            System.out.println("1 - Inserir valor");
            System.out.println("2 - Em Ordem");
            System.out.println("3 - Criar copia");
            System.out.println("4 - Contar nós");
            System.out.println("5 - Soma e Multiplicação");
            System.out.println("6 - Quantidade de repetidos");
            System.out.println("7 - Esvaziar");
            System.out.println("Digite: ");
            escolha = scanner.nextInt();

            switch (escolha) {
                case 1:
                    System.out.println("Digite um número: ");
                    int numero = scanner.nextInt();
                    arv1.insert(numero);
                    break;
                case 2:
                    System.out.println("Em Ordem:");
                    arv1.emOrdem();
                    break;
                case 3:
                    arv2 = arv1.copiarArvore();
                    System.out.println("Cópia realizada! Em ordem da cópia:");
                    arv2.emOrdem();
                    break;
                case 4:
                    System.out.println("Nós: " + arv1.nos());
                    System.out.println("Folhas: " + arv1.folhas());
                    System.out.println("Não Terminais: " + arv1.naoTerminais());
                    System.out.println("Altura: " + arv1.alturaArvore());
                    break;
                case 5:
                    System.out.println("Soma: " + arv1.soma());
                    System.out.println("Multiplicação: " + arv1.multiplica());
                    break;
                case 6:
                    System.out.println("Digite um número: ");
                    int encontrar = scanner.nextInt();
                    System.out.println("Tem: " + arv1.encontrarRepetidos(encontrar));
                    break;
                case 7:
                    arv2.esvaziarArvore();
                    arv2.emOrdem();
                    break;
                case 0:
                    arv1.esvaziarArvore();
                    break;
                default:
                    System.out.println("Opção incorreta! Tente novamente...");
                    break;
            }
        } while(escolha != 0);
        scanner.close();
    }   
}