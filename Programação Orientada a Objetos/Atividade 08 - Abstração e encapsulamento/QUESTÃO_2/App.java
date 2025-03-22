import java.util.Scanner;

public class App{
    public static void main (String[] args){
        Scanner scanner = new Scanner(System.in);
        Carro carro = new Carro(null, null, 0, 0);

        System.out.println("Digite a marca do Carro: ");
        carro.setMarca(scanner.nextLine());
        System.out.println("Digite o modelo do Carro: ");
        carro.setModelo(scanner.nextLine());
        System.out.println("Digite o ano de fabricação do Carro: ");
        carro.setAnoFabricacao(scanner.nextInt());
        System.out.println("Digite a velocidade atual do Carro: ");
        carro.setVelocidadeAtual(scanner.nextInt());

        int pedais = 0, velocidade = 0;
        do{
            System.out.println("Carro está em movimento...");
            System.out.println("[Digite 0 para parar o carro]");
            System.out.println("Deseja acelerar (1) ou desacelerar (2)? ");
            pedais = scanner.nextInt();
            if(pedais == 1){
                System.out.println("Valor da aceleração: ");
                velocidade = scanner.nextInt();
                carro.acelerar(velocidade);
                System.out.println("Velocidade Atual do Carro: " + carro.getVelocidadeAtual());
            } else if(pedais == 2){
                System.out.println("Valor da desaceleração: ");
                velocidade = scanner.nextInt();
                carro.desacelerar(velocidade);
                System.out.println("Velocidade Atual do Carro: " + carro.getVelocidadeAtual());
                if(carro.getVelocidadeAtual() == 0){
                    System.out.println("O carro foi estacionado...");
                    pedais = -1;
                }
            } else if(pedais == 0){
                System.out.println("O carro foi estacionado...");
                pedais = -1;
            } else {
                System.out.println("Nada mudou.");
            }
        } while(pedais != -1);
        scanner.close();
    }
}