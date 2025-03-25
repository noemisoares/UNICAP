import java.util.ArrayList;
import java.util.Scanner;

public class App{
    public static void main (String[] args){
        Scanner scanner = new Scanner(System.in);
        ArrayList<Aluno> alunos = new ArrayList<Aluno>();
        int opcao = 0;
        
        do {
            System.out.println("CADASTRO DE ALUNOS");
            System.out.println("DIGITE: 1 - Sim | 2 - Não ");
            System.out.println("Deseja adicionar um novo aluno? ");
            opcao = scanner.nextInt();
            scanner.nextLine();

            if(opcao == 1){
                Aluno aluno = new Aluno(null, 0);
                
                System.out.println("Digite o Nome do Aluno: ");
                aluno.setNome(scanner.nextLine());
                System.out.println("Digite a Matricula do Aluno: ");
                aluno.setMatricula(scanner.nextInt());
                    
                Notas nota = new Notas();

                System.out.println("Digite a Nota 1: ");
                nota.setNota1(scanner.nextDouble());
                System.out.println("Digite a Nota 2: ");
                nota.setNota2(scanner.nextDouble());
                System.out.println("Digite a Nota 3: ");
                nota.setNota3(scanner.nextDouble());
                System.out.println("Digite a Nota 4: ");
                nota.setNota4(scanner.nextDouble());
                scanner.nextLine();

                aluno.getNota().add(nota);
                alunos.add(aluno);
                System.out.println("Aluno foi cadastrado! ");
            } else if (opcao == 2){
                System.out.println("LISTA DE ALUNOS: ");
                for (Aluno a : alunos) {
                    System.out.println(a);
                }
                opcao = 0;
            } else {
                System.out.println("Valor Incorreto! Esta opção não esta disponivel ");
            }
        } while(opcao != 0);

        System.out.println("Alunos Aprovados: ");
        for(int i = 0; i < alunos.size(); i++){
            if(alunos.get(i).calcularMedia() >= 7){
                System.out.println(alunos.get(i));
            }
        }

        System.out.println("Alunos Reprovados: ");
        for(int i = 0; i < alunos.size(); i++){
            if(alunos.get(i).calcularMedia() < 7){
                System.out.println(alunos.get(i));
            }
        }
        scanner.close();
    }
}