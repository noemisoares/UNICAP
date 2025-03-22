public class Lutador {
    String nome;
    int energia, forca;

    public Lutador(String nome, int energia, int forca) {
        this.nome = nome;
        this.energia = energia;
        this.forca = forca;
    }

    void reduzirEnergia(Lutador L){
        L.energia = L.energia - forca;
    }

    void aplicarGolpe(Lutador L){
        reduzirEnergia(L);
    }
}
