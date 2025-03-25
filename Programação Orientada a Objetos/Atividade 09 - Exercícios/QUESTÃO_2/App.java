import java.util.ArrayList;
import java.util.Scanner;

public class App{
    public static void main (String[] args){
        Scanner scanner = new Scanner(System.in);
        ArrayList<Pedido> pedido = new ArrayList<Pedido>();
        int opcao = 0, numero = 1;
        
        do {
            System.out.println("MENU DE PEDIDOS");
            System.out.println("DIGITE: 1 - Sim | 2 - Não ");
            System.out.println("Deseja fazer um novo pedido? ");
            opcao = scanner.nextInt();
            scanner.nextLine();

            if(opcao == 1){
                Pedido pedir = new Pedido(numero);
                double total = 0.0;
                int escolha = 1;

                while(escolha != 0){
                    System.out.println("DIGITE: 1 - Sim | 2 - Não ");
                    System.out.println("Deseja adicionar um item ao carrinho? ");
                    escolha = scanner.nextInt();
                    scanner.nextLine();

                    if(escolha == 1){
                        ItemPedido item = new ItemPedido(null, 0);
                        System.out.println("Digite o Nome do Produto: ");
                        item.setNome(scanner.nextLine());
                        System.out.println("Digite o Preço do Produto: ");
                        item.setPreco(scanner.nextDouble());
                        scanner.nextLine();
                        
                        total = total + item.getPreco();
                        pedir.getItens().add(item);
                        
                    } else if(escolha == 2){
                        System.out.println("Sua compra foi finalizada! ");
                        System.out.println("LISTA DE COMPRAS: ");
                        for (ItemPedido ip : pedir.getItens()) {
                            System.out.println(ip);
                        }
                        escolha = 0;
                    } else {
                        System.out.println("Valor Incorreto! Esta opção não esta disponivel ");
                    }
                }
                pedir.setTotal(total);
                pedido.add(pedir);
                numero++;
            } else if (opcao == 2){
                System.out.println("LISTA DE PEDIDOS: ");
                for (Pedido p : pedido) {
                    System.out.println(p);
                }
                opcao = 0;
            } else {
                System.out.println("Valor Incorreto! Esta opção não esta disponivel ");
            }
        } while(opcao != 0);

        System.out.println("Os pedidos que têm um valor total superior a R$500: ");
        for(int i = 0; i < pedido.size(); i++){
            if(pedido.get(i).getTotal() > 500){
                System.out.println(pedido.get(i));
            }
        }
        scanner.close();
    }
}