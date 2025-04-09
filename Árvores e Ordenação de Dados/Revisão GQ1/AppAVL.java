import AVLTree.AVL;
import java.util.Scanner;

public class AppAVL {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        AVL<Integer> arv1 = new AVL<Integer>();
        AVL<Integer> arv2 = new AVL<Integer>();
        int escolha = 0;
        do{
            System.out.println("Árvore AVL");
            System.out.println("1 - Inserir valor");
            System.out.println("2 - Por nivel");
            System.out.println("3 - Criar copia");
            System.out.println("4 - Proximos de Desbalancear");
            System.out.println("5 - comparar arvores");
            System.out.println("6 - Altura da Arvore e apartir de um Nó");
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
                    System.out.println("Por Nivel:");
                    arv1.porNivel();
                    break;
                case 3:
                    arv2 = arv1.copiarArvore();
                    System.out.println("Cópia realizada! Por Nivel da cópia:");
                    arv2.porNivel();
                    break;
                case 4:
                    System.out.println("Proximos de Desbalancear: " );
                    arv1.desbalanceados();
                    break;
                case 5:
                    boolean comparar = arv1.compararArvores(arv2);
                    if(comparar == true){
                        System.out.println("Arvores sao iguais ");
                    } else {
                        System.out.println("Arvores sao diferentes ");
                    }
                    break;
                case 6:
                    System.out.println("Digite um número: ");
                    int no = scanner.nextInt();
                    System.out.println("Altura do nó " + no + ": " + arv1.alturaNo(no));
                    System.out.println("Altura da Arvore: " + arv1.alturaArvore());
                    break;
                case 7:
                    arv2.esvaziarArvore();
                    arv2.porNivel();
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