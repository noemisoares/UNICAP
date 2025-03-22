public class App{
    public static void main (String[] args){
        Livro livro = new Livro("Percy Jackson e Os Olimpianos: O Ladrão de Raios", "Rick Riordan", 2005);
        
        System.out.println("Informações do Livro");
        System.out.println("Título: " + livro.getTítulo());
        System.out.println("Autor(a): " + livro.getAutor());
        System.out.println("Ano de Publicação: " + livro.getAnoPublicacao());

        livro.setAnoPublicacao(-2005);
        System.out.println("Ano de Publicação: " + livro.getAnoPublicacao());
    }
}