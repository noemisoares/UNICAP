import java.util.Scanner;

public class App{
    public static void main (String[] args){
        Scanner scanner = new Scanner(System.in);
        BancoDeDados banco = new BancoDeDados(50);
        
        int escolha = 0;
        do{
            System.out.println("Banco de Dados");
            System.out.println("1 - Adicionar");
            System.out.println("2 - Remover");
            System.out.println("3 - Atualizar");
            System.out.println("4 - Listar");
            System.out.println("0 - Sair");
            System.out.println("Escolha: ");
            escolha = scanner.nextInt();
            scanner.nextLine();
            if(escolha == 1){
                System.out.println("Adicione um dado: ");
                banco.adicionar(scanner.nextInt());
            } else if(escolha == 2){
                System.out.println("Remova um dado: ");
                banco.remover(scanner.nextInt());
            } else if(escolha == 3){
                System.out.println("Atualizar um dado: ");
                int dado = scanner.nextInt();
                System.out.println("Valor Novo: ");
                int atualizar = scanner.nextInt();
                banco.atualizar(dado, atualizar);
            } else if(escolha == 4){
                System.out.println("Lista dos Dados: ");
                banco.listar();
                System.out.println("Quantidade de Dados: " + banco.getQtdDados());
            } else if(escolha == 0){
                System.out.println("Saindo... ");
                escolha = -1;
            }
        } while(escolha != -1);
        scanner.close();
    }
}