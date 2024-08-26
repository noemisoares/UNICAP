//Atividade 03 - Conceitos Básicos de Java - Estruturas de Dados Lineares

//CÓDIGOS DAS RESPOSTAS

//QUESTÃO 1
import java.util.Scanner;
public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite seu nome: ");
            String name = scan.nextLine();

            System.out.println("Bem-vindo " + name);
        }
    }
}

//QUESTÃO 2
import java.util.Scanner;
public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite sua idade: ");
            String idadeString = scan.nextLine();

            //int idadeInt = Integer.parseInt(idadeString);
            int idadeInt = 0;
            for(int i = 0; i < idadeString.length(); i++){
                idadeInt = idadeInt * 10 + (idadeString.charAt(i) - '0');
            }

            System.out.println("Numero em inteiro: " + idadeInt);

        }
    }
}

//QUESTÃO 3
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite um numero inteiro: ");
            int numero= scan.nextInt();

            float numeroFloat = (float) numero;

            System.out.println("Numero em decimal: " + numeroFloat);

        }
    }
}

//QUESTÃO 4
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite o primeiro numero inteiro: ");
            int a = scan.nextInt();

            System.out.print("Digite o segundo numero inteiro: ");
            int b = scan.nextInt();

            int soma = a + b;

            System.out.println("Soma: " + soma);

        }
    }
}

//QUESTÃO 5
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite um numero decimal: ");
            float numero = scan.nextFloat();

            float numeroQuadrado = numero*numero;

            System.out.println("Seu quadrado: " + numeroQuadrado);

        }
    }
}

//QUESTÃO 6
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite seu Ano de Nascimento: ");
            int ano = scan.nextInt();

            int idade = 2024 - ano;

            System.out.println("Voce possui " + idade + " anos");
        }
    }
}

//QUESTÃO 7
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite seu primeiro nome: ");
            String nome = scan.nextLine();

            System.out.print("Digite seu sobrenome: ");
            String sobrenome = scan.nextLine();

            String nomecompleto = nome.concat(" " + sobrenome);

            System.out.println(nomecompleto);
        }
    }
}

//QUESTÃO 8
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite sua sequencia de numeros: ");
            String sequencia = scan.nextLine();

            String[] numeros = sequencia.split(" ");
            int contagem = numeros.length;          

            System.out.println("Voce digitou " + contagem + " numeros");
        }
    }
}

//QUESTÃO 9
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite o nome do animal: ");
            String animal = scan.nextLine();   

            System.out.println("O nome do animal eh " + animal);
        }
    }
}

//QUESTÃO 10
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite seu primeiro nome: ");
            String nome = scan.nextLine();

            System.out.print("Digite seu sobrenome: ");
            String sobrenome = scan.nextLine();

            String nomecompleto = sobrenome.concat(" " + nome);

            System.out.println(nomecompleto);
        }
    }
}

//QUESTÃO 11
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite uma string: ");
            String string = scan.next();

            int tamanho = string.length();

            System.out.println("O tamanho da string: " + tamanho);
        }
    }
}

//QUESTÃO 12
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite um numero: ");
            int numero = scan.nextInt();

            if(numero % 2 == 0){
                System.out.println("O numero " + numero + " eh par");
            } else {
                System.out.println("O numero " + numero + " eh impar");
            }
        }
    }
}

//QUESTÃO 13
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite um numero: ");
            int numero = scan.nextInt();

            if(numero >= 0){
                System.out.println("O numero " + numero + " eh positivo");
            } else {
                System.out.println("O numero " + numero + " eh negativo");
            }
        }
    }
}

//QUESTÃO 14
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite o primeiro numero: ");
            int n1 = scan.nextInt();

            System.out.print("Digite o segundo numero: ");
            int n2 = scan.nextInt();

            if(n1 > n2){
                System.out.println("O numero maior eh " + n1);
            } else {
                System.out.println("O numero maior eh " + n2);
            }
        }
    }
}

//QUESTÃO 15
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite sua altura: ");
            float altura = scan.nextFloat();

            System.out.print("Digite seu peso: ");
            float peso = scan.nextFloat();

            float IMC = peso / (altura * altura);

            System.out.println("O IMC: " + IMC);
        }
    }
}

//QUESTÃO 16
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite seu nome: ");
            String nome = scan.next();

            if(nome.length() > 5){
                System.out.println("Seu nome possui mais de 5 caracteres");
            } else {
                System.out.println("Seu nome possui 5 ou menos de 5 caracteres");
            }
        }
    }
}

//QUESTÃO 17
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite seu estado civil: ");
            String estado = scan.next();

            System.out.println("Você é " + estado);
        }
    }
}

//QUESTÃO 18
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite o valor da base: ");
            float base = scan.nextFloat();

            System.out.print("Digite o valor da altura: ");
            float altura = scan.nextFloat();

            float area = base * altura;

            System.out.println("A area do retangulo eh: " + area);
        }
    }
}

//QUESTÃO 19
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite o nome da sua cidade: ");
            String cidade = scan.nextLine();

            if(cidade.charAt(0) == 's' || cidade.charAt(0) == 'S'){
                System.out.println("O nome da sua cidade começa com a letra S");
            } else {
                System.out.println("O nome da sua cidade nao começa com a letra S");
            }
        }
    }
}

//QUESTÃO 20
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite o primeiro numero: ");
            float n1 = scan.nextFloat();

            System.out.print("Digite o segundo numero: ");
            float n2 = scan.nextFloat();

            float resto = n1 % n2;

            System.out.println("O resto da divisao: " + resto);  
        }
    }
}

//QUESTÃO 21
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite um numero: ");
            float numFloat = scan.nextFloat();

            int numInt = (int) numFloat;

            System.out.println("Em numero inteiro: " + numInt);  
        }
    }
}

//QUESTÃO 22
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite um numero como string: ");
            String numero = scan.next();

            int numInt = Integer.parseInt(numero);
            int soma = numInt + 10;
            numero = Integer.toString(soma);

            System.out.println("Em numero inteiro: " + numero);  
        }
    }
}

//QUESTÃO 23
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite uma data (dd/mm/aaaa): ");
            String data = scan.nextLine();

            String[] dataSep = data.split("/");
            int dia = Integer.parseInt(dataSep[0]);
            int mes = Integer.parseInt(dataSep[1]);            
            int ano = Integer.parseInt(dataSep[2]);

            System.out.println("dia: " + dia);
            System.out.println("mes: " + mes);  
            System.out.println("ano: " + ano);  
        }
    }
}

//QUESTÃO 24
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite o nome de uma cidade: ");
            String cidade = scan.nextLine();

            System.out.print("Digite o nome de um estado: ");
            String estado = scan.nextLine();

            String cidade_estado = cidade.concat(", " + estado);

            System.out.println("Você mora em " + cidade_estado);
        }
    }
}

//QUESTÃO 25
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite seu ano de nascimento: ");
            String ano = scan.nextLine();

            System.out.println("Bem-vindo ao nosso programa, nascido em " + ano);
        }
    }
}

//QUESTÃO 26
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite um numero: ");
            int numero = scan.nextInt();

            System.out.print("Digite uma string: ");
            String str = scan.next();

            String num = Integer.toString(numero);

            String concatenar = str.concat(" " + num);

            System.out.println(concatenar);
        }
    }
}

//QUESTÃO 27
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite o nome do produto: ");
            String produto = scan.nextLine();

            System.out.print("Digite o preco do produto: ");
            float p = scan.nextFloat();

            String preco = String.valueOf(p);

            String produtoPreco = produto.concat(" - R$ " + preco);

            System.out.println(produtoPreco);
        }
    }
}

//QUESTÃO 28
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite um numero: ");
            int num = scan.nextInt();

            int dobro = 2*num;
            String dobroStr = String.valueOf(dobro);

            System.out.println("O dobro do numero eh " + dobroStr);
        }
    }
}

//QUESTÃO 29
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite um e-mail: ");
            String email = scan.next();

            System.out.println("Obrigada por usar nossos serviços!  " + email);
        }
    }
}

//QUESTÃO 30
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.println("Escolha um numero para N1: ");
            int num1 = scan.nextInt();
            
            System.out.println("Escolha um numero para N2: ");
            int num2 = scan.nextInt();
            
            int r1 = num1 + num2;
            int r2 = num1 - num2;
            int r3 = num1 / num2;
            int r4 = num1 * num2;
            
            System.out.println("O resultado soma eh: " + r1);
            System.out.println("O resultado subtracao eh: " + r2);
            System.out.println("O resultado divisao eh: " + r3);
            System.out.println("O resultado multiplicacao eh: " + r4);
        }
    }
}

//QUESTÃO 31
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite o valor da base: ");
            float base = scan.nextFloat();

            System.out.print("Digite o valor da altura: ");
            float altura = scan.nextFloat();

            float area = (base * altura)/2;

            System.out.println("A area do triangulo eh: " + area);
        }
    }
}

//QUESTÃO 32
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite o valor do raio: ");
            float raio = scan.nextFloat();

            float pi = 3.14f;
            float perimetro = 2*pi*raio;

            System.out.println("O perimetro da circunferencia eh: " + perimetro);
        }
    }
}

//QUESTÃO 33
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite o valor da base: ");
            float base = scan.nextFloat();

            System.out.print("Digite o valor da altura: ");
            float altura = scan.nextFloat();

            float perimetro = (2*base) + (2*altura);

            System.out.println("A perimetro do retangulo eh: " + perimetro);
        }
    }
}

//QUESTÃO 34
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite o primeiro numero decimal: ");
            float n1 = scan.nextFloat();

            System.out.print("Digite o segundo numero decimal: ");
            float n2 = scan.nextFloat();

            System.out.print("Digite o terceiro numero decimal: ");
            float n3 = scan.nextFloat();

            float mediaAritmetica = (n1+n2+n3)/3;

            System.out.println("A media aritmetica eh: " + mediaAritmetica);
        }
    }
}

//QUESTÃO 35
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite sua idade: ");
            int idade = scan.nextInt();

            int meses = idade * 12;
            int dias = idade * 365;

            System.out.println("Viveu " + meses + " meses | " + dias + " dias");
        }
    }
}

//QUESTÃO 36
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite o valor em real: ");
            float real = scan.nextFloat();

            System.out.print("Digite a cotaçao do dolar: ");
            float dolar = scan.nextFloat();

            float dolarCot = real * dolar;

            System.out.println("Valor em dolar eh $" + dolarCot);
        }
    }
}

//QUESTÃO 37
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite o valor em decinal: ");
            float real = scan.nextFloat();

            int numero = Math.round(real);
            System.out.println("Valor arredondado: " + numero);
        }
    }
}

//QUESTÃO 38
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite o primeiro numero: ");
            int n1 = scan.nextInt();

            System.out.print("Digite o segundo numero: ");
            int n2 = scan.nextInt();

            System.out.print("Digite o terceiro numero: ");
            int n3 = scan.nextInt();

            float formula = (n1 + n2) * n3;

            System.out.println("Resultado: " + formula);  
        }
    }
}

//QUESTÃO 39
import java.util.Scanner;

public class Index{
    public static void main(String[] args){
        try(Scanner scan = new Scanner(System.in)){
            System.out.print("Digite o valor de graus em celsius: ");
            float celsius = scan.nextFloat();

            float fahrenheit = (celsius * 9/5) + 32;

            System.out.println("Resultado: " + fahrenheit);  
        }
    }
}
