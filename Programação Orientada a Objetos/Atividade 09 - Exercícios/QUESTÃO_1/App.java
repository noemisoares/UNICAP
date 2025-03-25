import java.util.ArrayList;
import java.util.Scanner;

public class App{
    public static void main (String[] args){
        Scanner scanner = new Scanner(System.in);
        ArrayList<Funcionario> funcionarios = new ArrayList<Funcionario>();
        int escolha = 0;
        
        do {
            System.out.println("DIGITE: 1 - Sim | 2 - Não ");
            System.out.println("Deseja adicionar um funcionario a lista? ");
            escolha = scanner.nextInt();
            scanner.nextLine();

            if(escolha == 1){
                Funcionario funcionario = new Funcionario(null, 0, 0);
                System.out.println("Digite o Nome do Funcionário: ");
                funcionario.setNome(scanner.nextLine());
                System.out.println("Digite a Idade do Funcionário: ");
                funcionario.setIdade(scanner.nextInt());
                System.out.println("Digite o Salario do Funcionário: ");
                funcionario.setSalarioAnual(scanner.nextDouble());
                funcionarios.add(funcionario);
            } else if(escolha == 2){
                System.out.println("Sua lista de funcionários foi finalizada! ");
                System.out.println("LISTA DE FUNCIONÁRIOS: ");
                for (Funcionario f : funcionarios) {
                    System.out.println(f);
                }
                escolha = 0;
            } else {
                System.out.println("Valor Incorreto! Esta opção não esta disponivel ");
            }
        } while(escolha != 0);

        System.out.println("Os Funcionários que ganham mais de R$50.000 e têm menos de 30 anos: ");
        for(int i = 0; i < funcionarios.size(); i++){
            if(funcionarios.get(i).getIdade() < 30 && funcionarios.get(i).getSalarioAnual() > 50000){
                System.out.println(funcionarios.get(i).getNome());
            }
        }
        scanner.close();
    }
}