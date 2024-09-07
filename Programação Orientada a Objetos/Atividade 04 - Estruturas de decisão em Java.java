//Atividade 04 - Estruturas de Decisão em Java - Programação Orientada a Objeto

//CÓDIGOS DAS RESPOSTAS

//QUESTÃO 1
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scanner = new Scanner(System.in)){
            System.out.println("Digite um numero inteiro: ");
            int num = scanner.nextInt();

            if(num > 0){
                System.out.println("O numero digitado eh positivo");
            } else if(num == 0){
                System.out.println("O numero digitado eh igual a zero");
            } else {
                System.out.println("O numero digitado eh negativo");
            }
        }
    }
}

//QUESTÃO 2
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scanner = new Scanner(System.in)){
            System.out.println("Digite sua idade: ");
            int idade = scanner.nextInt();

            if(idade >= 18){
                System.out.println("Voce eh maior de idade");
            } else {
                System.out.println("Voce eh menor de idade");
            }
        }
    }
}

//QUESTÃO 3
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scanner = new Scanner(System.in)){
            System.out.println("Digite o primeiro numero: ");
            int num1 = scanner.nextInt();

            System.out.println("Digite o segundo numero: ");
            int num2 = scanner.nextInt();

            if(num1 > num2){
                System.out.println("O numero " + num1 + " eh maior que o numero " + num2);
            } else if(num1 == num2) {
                System.out.println("Os dois numeros são iguais");
            } else {
                System.out.println("O numero " + num2 + " eh maior que o numero " + num1);
            }
        }
    }
}

//QUESTÃO 4
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scanner = new Scanner(System.in)){
            System.out.println("Digite o primeiro numero: ");
            int num = scanner.nextInt();

            if(num % 2 == 0){
                System.out.println("O numero " + num + " eh par");
            } else {
                System.out.println("O numero " + num + " eh impar");
            }
        }
    }
}

//QUESTÃO 5
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scanner = new Scanner(System.in)){
            System.out.println("Digite a primeira nota: ");
            float nota1 = scanner.nextFloat();

            System.out.println("Digite a primeira nota: ");
            float nota2 = scanner.nextFloat();

            System.out.println("Digite a primeira nota: ");
            float nota3 = scanner.nextFloat();

            float media = (nota1 + nota2 + nota3)/3;

            if(media >= 7.0){
                System.out.println("O aluno esta aprovado! Com media " + media);
            } else {
                System.out.println("O aluno esta reprovado! Com media " + media);
            }
        }
    }
}

//QUESTÃO 6
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scanner = new Scanner(System.in)){
            System.out.println("Digite o primeiro nome: ");
            String nome1 = scanner.nextLine();

            System.out.println("Digite o primeiro nome: ");
            String nome2 = scanner.nextLine();


            if(nome1.length() > nome2.length()){
                System.out.println("O nome " + nome1 + " possui mais caracteres do que o nome " + nome2);
            } else if(nome1.length() == nome2.length()){
                System.out.println("O nome " + nome1 + " possui a mesma quantidade de caracteres do nome " + nome2);
            } else {
                System.out.println("O nome " + nome2 + " possui mais caracteres do que o nome " + nome1);
            }
        }
    }
}

//QUESTÃO 7
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scanner = new Scanner(System.in)){
            System.out.println("Digite uma letra: ");
            String letra = scanner.nextLine();

            char caracter = letra.charAt(0);

            if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u' ||
                caracter == 'A' || caracter == 'E' || caracter == 'I' || caracter == 'O' || caracter == 'U') {
                System.out.println("A letra " + caracter + " eh uma vogal");
            } else {
                System.out.println("A letra " + caracter + " eh uma consoante");
            }
        }
    }
}

//QUESTÃO 8
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.println("Digite o primeiro numero: ");
            int num1 = scanner.nextInt();

            System.out.println("Digite o segundo numero: ");
            int num2 = scanner.nextInt();

            System.out.println("Digite o terceiro numero: ");
            int num3 = scanner.nextInt();

            int[] numeros = {num1, num2, num3};

            java.util.Arrays.sort(numeros);
            
            System.out.println(numeros[0] + " " + numeros[1] + " " + numeros[2]);
        }
    }
}

//QUESTÃO 9
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.println("Digite seu peso: ");
            float peso = scanner.nextFloat();

            System.out.println("Digite seu altura: ");
            float altura = scanner.nextFloat();

            float IMC = peso / (altura * altura);

            if (IMC < 18.5) {
                System.out.println("Categoria: Abaixo do peso\n");
            } else if (IMC >= 18.5 && IMC < 25) {
                System.out.println("Categoria: Peso normal\n");
            } else if (IMC >= 25 && IMC < 30) {
                System.out.println("Categoria: Sobrepeso\n");
            } else if (IMC >= 30 && IMC < 35) {
                System.out.println("Categoria: Obeso\n");
            } else {
                System.out.println("Categoria: Muito obeso\n");
            }
        }
    }
}

//QUESTÃO 10
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.println("Digite um numero de mes: ");
            int mes = scanner.nextInt();

            switch (mes) {
                case 1:
                    System.out.println("Janeiro");
                    break;
                case 2:
                    System.out.println("Fevereiro");
                    break;
                case 3:
                    System.out.println("Março");
                    break;
                case 4:
                    System.out.println("Abril");
                    break;
                case 5:
                    System.out.println("Maio");
                    break;
                case 6:
                    System.out.println("Junho");
                    break;
                case 7:
                    System.out.println("Julho");
                    break;
                case 8:
                    System.out.println("Agosto");
                    break;
                case 9:
                    System.out.println("Setembro");
                    break;
                case 10:
                    System.out.println("Outubro");
                    break;
                case 11:
                    System.out.println("Novembro");
                    break;
                case 12:
                    System.out.println("Dezembro");
                    break;
                default:
                    System.out.println("Esse numero não eh um mes valido.");
                    break;
            }
        }
    }
}

//QUESTÃO 11
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.println("Digite seu salario: ");
            float salario = scanner.nextFloat();
            float aumento, novoSalario;

            if(salario >= 1500.0){
                aumento = (salario * 10)/100;
                novoSalario = salario + aumento;
            } else {
                aumento = (salario * 15)/100;
                novoSalario = salario + aumento;
            }
            System.out.println("Novo salario: " + novoSalario);
            
        }
    }
}

//QUESTÃO 12
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.println("Digite um numero: ");
            int num = scanner.nextInt();
            
            if(num % 3 == 0 && num % 5 == 0){
                System.out.println("O numero eh divisivel por 3 e por 5");
            } else {
                System.out.println("O numero NAO eh divisivel por 3 e por 5");
            }
        }
    }
}

//QUESTÃO 13
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.println("Digite o dia da semana (EX: segunda-feira):");
            String dia = scanner.nextLine();

            switch (dia) {
                case "segunda-feira":
                case "terça-feira":
                case "quarta-feira":
                case "quinta-feira":
                case "sexta-feira":
                    System.out.println(dia + " é um dia útil.");
                    break;
                case "sábado":
                case "domingo":
                    System.out.println(dia + " é um fim de semana.");
                    break;
                default:
                    System.out.println("Dia da semana inválido.");
                    break;
            }
        }
    }
}

//QUESTÃO 14
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.println("Digite uma nota de 1-5: ");
            int nota = scanner.nextInt();

            switch (nota) {
                case 1:
                    System.out.println("Muito insuficiente");
                    break;
                case 2:
                    System.out.println("Insuficiente");
                    break;
                case 3:
                    System.out.println("Regular");
                    break;
                case 4:
                    System.out.println("Bom");
                    break;
                case 5:
                    System.out.println("Muito bom");
                    break;
                default:
                    System.out.println("Nota inválida.");
                    break;
            }
        }
    }
}

//QUESTÃO 15
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.println("Digite um numero de dia 1-7: ");
            int dia = scanner.nextInt();

            switch (dia) {
                case 1:
                    System.out.println("Domingo");
                    break;
                case 2:
                    System.out.println("Segunda-feira");
                    break;
                case 3:
                    System.out.println("Terça-feira");
                    break;
                case 4:
                    System.out.println("Quarta-feira");
                    break;
                case 5:
                    System.out.println("Quinta-feira");
                    break;
                case 6:
                    System.out.println("Sexta-feira");
                    break;
                case 7:
                    System.out.println("Sábado");
                    break;
                default:
                    System.out.println("Esse numero não eh um dia valido.");
                    break;
            }
        }
    }
}

//QUESTÃO 16
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Digite um número decimal: ");
            float numero = scanner.nextFloat();

            int arredondado = (int) Math.round(numero);

            System.out.println("Número arredondado: " + arredondado);
        } catch(NumberFormatException e){
            System.out.println("Erro de valor invalido.");
        }
    }
}

//QUESTÃO 17
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Digite uma idade: ");
            int idade = scanner.nextInt();

            if(idade <= 1 && idade >= 0){
                System.out.println("Idade de um Bebê");
            } else if(idade > 1 && idade <= 12){
                System.out.println("Idade de uma Criança");
            } else if(idade >= 13 && idade <= 18){
                System.out.println("Idade de um Adolescente");
            } else if(idade > 18){
                System.out.println("Idade de um Adulto");
            }
        }
    }
}

//QUESTÃO 18
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Digite seu estado civil: ");
            String estadoCivil  = scanner.nextLine();

            switch (estadoCivil) {
                case "solteiro":
                    System.out.println("Voce eh Solteiro.");
                    break;
                case "casado":
                    System.out.println("Voce eh Casado.");
                    break;
                case "divorciado":
                    System.out.println("Voce eh Divorciado.");
                    break;
                case "viuvo":
                    System.out.println("Voce eh Viuvo.");
                    break;
                default:
                    System.out.println("Estado civil incorreto ou nao disponivel.");
                    break;
            }
        }
    }
}

//QUESTÃO 19
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Digite o primeiro número: ");
            int num1 = scanner.nextInt();

            System.out.print("Digite o segundo número: ");
            int num2 = scanner.nextInt();

            System.out.println("Escolha a operação:");
            System.out.println("1 - Soma");
            System.out.println("2 - Subtração");
            System.out.println("3 - Multiplicação");
            System.out.println("4 - Divisão");
            System.out.print("Digite o número da operação desejada: ");
            int escolha = scanner.nextInt();

            switch (escolha) {
                case 1:
                    System.out.println("Resultado da soma: " + (num1 + num2));
                    break;
                case 2:
                    System.out.println("Resultado da subtração: " + (num1 - num2));
                    break;
                case 3:
                    System.out.println("Resultado da multiplicação: " + (num1 * num2));
                    break;
                case 4:
                    if (num2 != 0) {
                        System.out.println("Resultado da divisão: " + ((double) num1 / num2));
                    } else {
                        System.out.println("Erro: Divisão por zero não é permitida.");
                    }
                    break;
                default:
                    System.out.println("Opção inválida. Escolha um número de 1 a 4.");
                    break;
            }
        }
    }
}

//QUESTÃO 20
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Digite o seu nome: ");
            String nome = scanner.nextLine();
            
            int idade = 0;
            boolean idadeValida = false;

            while (!idadeValida) {
                try {
                    System.out.print("Digite a sua idade: ");
                    idade = Integer.parseInt(scanner.nextLine());
                    idadeValida = true;  
                } catch (NumberFormatException e) {
                    System.out.println("Idade inválida.");
                }
            }

            System.out.println("Nome: " + nome);
            System.out.println("Idade: " + idade);
        }
    }
}

//QUESTÃO 21
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            double metros = 0;
            boolean valorValido = false;

            while (!valorValido) {
                try {
                    System.out.print("Digite um valor em metros: ");
                    metros = Double.parseDouble(scanner.nextLine());
                    valorValido = true;
                } catch (NumberFormatException e) {
                    System.out.println("Valor inválido.");
                }
            }

            double centimetros = metros * 100;
            double milimetros = metros * 1000;
            double quilometros = metros / 1000;

            System.out.println("Valor em metros: " + metros);
            System.out.println("Valor em centímetros: " + centimetros);
            System.out.println("Valor em milímetros: " + milimetros);
            System.out.println("Valor em quilômetros: " + quilometros);
        }
    }
}