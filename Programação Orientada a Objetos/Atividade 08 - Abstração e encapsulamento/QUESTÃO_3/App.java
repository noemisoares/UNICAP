import java.util.Scanner;

public class App{
    public static void main (String[] args){
        Scanner scanner = new Scanner(System.in);
        CarrinhoDeCompras carrinho = new CarrinhoDeCompras(50);
        
        int escolha = 0;
        do{
            System.out.println("Carrinho de Compras");
            System.out.println("1 - Adicionar");
            System.out.println("2 - Remover");
            System.out.println("3 - Listar");
            System.out.println("0 - Ir para o Caixa");
            System.out.println("Escolha: ");
            escolha = scanner.nextInt();
            scanner.nextLine();
            if(escolha == 1){
                System.out.println("Adicione um item ao carrinho: ");
                carrinho.adicionar(scanner.nextLine());
            } else if(escolha == 2){
                System.out.println("Remova um item do carrinho: ");
                carrinho.remover(scanner.nextLine());
            } else if(escolha == 3){
                System.out.println("Lista de Itens no Carrinho: ");
                carrinho.listar();
                System.out.println("Quantidade de Itens: " + carrinho.getQtdItens());
            } else if(escolha == 0){
                System.out.println("Indo para o Caixa de Pagamento... ");
                escolha = -1;
            }
        } while(escolha != -1);
        scanner.close();
    }
}