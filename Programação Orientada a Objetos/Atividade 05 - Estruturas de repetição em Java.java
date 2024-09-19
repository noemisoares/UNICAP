//Atividade 05 - Estruturas de Repetição em Java - Programação Orientada a Objeto

//CÓDIGOS DAS RESPOSTAS

//QUESTÃO 1
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            float[] alunos = new float[5];
            int i = 0, aprovados = 0;

            while(i < 5){
                System.out.print("Digite a nota do Aluno " + (i+1) + ": ");
                alunos[i] = scanner.nextFloat();
                if(alunos[i] >= 7.0){
                    aprovados++;
                }
                i++;
            }
            System.out.println(aprovados + " Alunos aprovados");
        }
    }
}

//QUESTÃO 2
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int numero, soma = 0;
            System.out.print("Digite um numero inteiro positivo: ");
            numero = scanner.nextInt();

            while(numero != 0){
                soma += numero % 10;
                numero = numero / 10;
            }

            System.out.println("Soma dos digitos: " + soma);
        }
    }
}

//QUESTÃO 3
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int numero, x = 1;
            System.out.print("Digite um numero inteiro positivo: ");
            numero = scanner.nextInt();

            System.out.println("Divisores do numero " + numero + ":");
            while(numero != 0){
                if(numero % x == 0){
                    System.out.printf(x + " ");
                }
                x++;
            }
        }
    }
}

//QUESTÃO 4
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            float[] pessoas = new float[5];
            int i = 0;
            float soma = 0, media = 0;

            while(i < 5){
                System.out.print("Digite a a altura da pessoa " + (i+1) + ": ");
                pessoas[i] = scanner.nextFloat();
                soma += pessoas[i];
                i++;
            }

            media = soma / 2;
            System.out.println("Media de altura: " + media);
        }
    }
}

//QUESTÃO 5
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int numeros = 1;

            while(numeros <= 100){
                if(numeros % 3 == 0){
                    System.out.print("Fizz ");
                } else if(numeros % 5 == 0){
                    System.out.print("Buzz ");
                } else if(numeros % 3 == 0 && numeros % 5 == 0){
                    System.out.print("FizzBuzz ");
                } else {
                    System.out.print(numeros + " ");
                }
                numeros++;
            }
        }
    }
}

//QUESTÃO 6
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int numero, soma = 0, k;
            System.out.print("Digite um numero inteiro positivo: ");
            numero = scanner.nextInt();

            while(numero != 0){
                k = numero % 10;
                if(k % 2 == 0){
                    soma += k;
                }
                numero = numero / 10;
            }

            System.out.println("Soma dos digitos pares: " + soma);
        }
    }
}

//QUESTÃO 7
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int numero, k;
            System.out.print("Digite um numero inteiro positivo: ");
            numero = scanner.nextInt();

            while(numero != 0){
                k = numero % 10;
                System.out.print(k);
                numero = numero / 10;
            }
        }
    }
}

//QUESTÃO 8
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int numero = 1, soma = 0;

            while(numero <= 100){
                soma += numero;
                numero++;
            }
            System.out.print("Soma dos numeros de 1 a 100: " + soma);
        }
    }
}

//QUESTÃO 9
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int numero = 1, mult = 1;

            while(numero <= 5){
                mult = mult * numero;
                numero++;
            }
            System.out.print("Produto dos numeros de 1 a 5: " + mult);
        }
    }
}

//QUESTÃO 10
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int nove = 0, i = 0;

            while(i < 11){
                nove = i * 9;
                System.out.println(i + " x 9 = " + nove);
                i++;
            }
        }
    }
}

//QUESTÃO 11
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int escolha = 1, maior = 0, menor = 999;

            while(escolha != 0){
                System.out.println("Digite um numero inteiro (0 - sair):");
                escolha = scanner.nextInt();

                if(escolha > maior){
                    maior = escolha;
                } else if (escolha != 0 && escolha < menor){
                    menor = escolha;
                }
            }
            System.out.println("Maior: " + maior);
            System.out.println("Menor: " + menor);
        }
    }
}

//QUESTÃO 12
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int escolha = 1, soma = 0, media = 0;

            while(escolha != -1){
                System.out.println("Digite um numero inteiro (-1 - sair):");
                escolha = scanner.nextInt();
                if(escolha != -1){
                    soma += escolha;
                }
            }
            media = soma / 2;
            System.out.println("Media: " + media);
        }
    }
}

//QUESTÃO 13
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int numero, soma = 0, n = 0;
            
            System.out.println("Digite um numero inteiro:");
            numero = scanner.nextInt();

            while(numero != 0){
                n = numero % 10;
                soma = soma + (n * n);
                numero = numero / 10;
            }
            System.out.println("Soma dos digitos: " + soma);
        }
    }
}

//QUESTÃO 14
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int numero = 1;

            System.out.println("Numeros Impares de 1 a 100: ");
            while(numero <= 100){
                if (numero % 2 != 0){
                    System.out.print(numero + " ");
                }
                numero++;
            }  
        }
    }
}

//QUESTÃO 15
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int numero = 1;

            System.out.println("Multiplos de 3 de 1 a 50: ");
            while(numero <= 50){
                if (numero % 3 == 0){
                    System.out.print(numero + " ");
                }
                numero++;
            }  
        }
    }
}

//QUESTÃO 16
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            float[] alunos = new float[5];
            int i = 0, aprovados = 0;

            while(i < 5){
                System.out.print("Digite a nota do Aluno " + (i+1) + ": ");
                alunos[i] = scanner.nextFloat();
                if(alunos[i] >= 7.0){
                    aprovados++;
                }
                i++;
            }
            System.out.println(aprovados + " Alunos aprovados");
        }
    }
}

//QUESTÃO 17
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int numero = 1, contadorPares = 0;

            while(numero != 0) {
                System.out.println("Digite um número inteiro (0 - sair):");
                numero = scanner.nextInt();

                if (numero % 2 == 0) {
                    contadorPares++; 
                } else {
                    break;
                }
            }
        System.out.println("Quantidade de números pares antes do primeiro ímpar: " + contadorPares);
        }
    }
}

//QUESTÃO 18
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int numero = 1, contadorPares = 0, contadorImpares = 0;
    
            while (numero != 0) {
                System.out.println("Digite um número inteiro (0 - sair):");
                numero = scanner.nextInt();
    
                if (numero % 2 == 0) {
                    contadorPares++;
                } else {
                    contadorImpares++;
                }
            }
    
            System.out.println("Quantidade de números pares: " + contadorPares);
            System.out.println("Quantidade de números ímpares: " + contadorImpares);
        }
    }
}

//QUESTÃO 19
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int numero = 1, Div2 = 0, Div3 = 0, Div5 = 0;
    
            while (numero != 0) {
                System.out.println("Digite um número inteiro (0 - sair):");
                numero = scanner.nextInt();
    
                if (numero % 2 == 0) {
                    Div2++; 
                }
                if (numero % 3 == 0) {
                    Div3++;
                }
                if (numero % 5 == 0) {
                    Div5++;
                }
            }
            
            System.out.println("Quantidade de números divisíveis por 2: " + Div2);
            System.out.println("Quantidade de números divisíveis por 3: " + Div3);
            System.out.println("Quantidade de números divisíveis por 5: " + Div5);
        }
    }
}

//QUESTÃO 20
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int numero = 1, soma = 0, Div3 = 0;
    
            while (numero != 0) {
                System.out.println("Digite um número inteiro (0 - sair):");
                numero = scanner.nextInt();
    
                if (numero % 3 == 0) {
                    soma += numero;
                    Div3++;
                }
            }
            if (Div3 > 0) {
                double media = (double) soma / Div3;
                System.out.println("Media dos numeros divisiveis por 3: " + media);
            } else {
                System.out.println("Nenhum numero divisivel por 3 foi inserido.");
            }
        }
    }
}

//QUESTÃO 21
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int numero = 1, Maior3 = 0;
    
            while (numero != 0) {
                System.out.println("Digite um número inteiro (0 - sair):");
                numero = scanner.nextInt();
    
                if (numero >= 100) {
                    Maior3++;
                }
            }
            if (Maior3 > 0) {
                System.out.println("Numeros q possuem mais de três digitos: " + Maior3);
            } else {
                System.out.println("Nenhum numero divisivel por 3 foi inserido.");
            }
        }
    }
}

//QUESTÃO 22
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int numero = 1, soma = 0;
    
            while (numero != 0) {
                System.out.println("Digite um número inteiro (0 - sair):");
                numero = scanner.nextInt();
    
                if (numero >= 50 && numero <= 100) {
                    soma += numero;
                }
            }
            double media = (double) soma / 2;
            System.out.println("Media dos numeros entre 50 e 100: " + media);
        }
    }
}

//QUESTÃO 23
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int numero = 1, menor = 999;
    
            while (numero != 0) {
                System.out.println("Digite um número inteiro (0 - sair):");
                numero = scanner.nextInt();
    
                if (numero > 0 && numero % 2 != 0) {
                    if(numero < menor){
                        menor = numero;
                    }
                    
                }
            }
            System.out.println("O menor valor digitado positivo e impar: " + menor);       
        }
    }
}

//QUESTÃO 24
import java.util.Scanner;

public class Index {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int numero = 1, impar = 0, par = 0;
    
            while (numero != 0) {
                System.out.println("Digite um número inteiro (0 - sair):");
                numero = scanner.nextInt();
    
                if (numero % 2 != 0) {
                    impar++;
                } else if (numero % 2 == 0 && numero != 0) {
                    par++;
                }
            }
            System.out.println("Numeros pares: " + par);       
            System.out.println("Numeros impares: " + impar);       
        }
    }
}