public class App{
    public static void main (String[] args){
        Lutador lutador1 = new Lutador("Ryu", 100, 10);
        Lutador lutador2 = new Lutador("Bison", 100, 12);
        
        lutador1.aplicarGolpe(lutador2);
        lutador1.aplicarGolpe(lutador2);
        lutador1.aplicarGolpe(lutador2);

        System.out.println("Ryu: " + lutador1.energia + " Hp");
        System.out.println("Bison: " + lutador2.energia + " Hp");

        lutador2.aplicarGolpe(lutador1);
        lutador2.aplicarGolpe(lutador1);
        lutador2.aplicarGolpe(lutador1);
        lutador2.aplicarGolpe(lutador1);
        lutador2.aplicarGolpe(lutador1);
        lutador2.aplicarGolpe(lutador1);
        lutador2.aplicarGolpe(lutador1);
        lutador2.aplicarGolpe(lutador1);

        System.out.println("Ryu: " + lutador1.energia + " Hp");
        System.out.println("Bison: " + lutador2.energia + " Hp");
    }
}