public class App{
    public static void main (String[] args){
        Post post = new Post("Bis é gostoso", "www.bis.com.br");

        post.curtir();
        post.curtir();
        post.curtir();

        System.out.println("Número de Curtidas: " + post.numeroCurtidas);

        post.compartilhar();
        post.compartilhar();

        System.out.println("Número de Compartilhamentos: " + post.numeroCompartilhamentos);
    }
}