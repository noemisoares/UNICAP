package BPlus;
import Alunos.Aluno;

class BNodePlus {
    private int n;
    private boolean ehFolha;
    private String [] chaves;
    private Aluno [] infos;
    private BNodePlus [] pont;
    private BNodePlus prox;
    
    public BNodePlus(int n, boolean ehFolha, String[] chaves, Aluno[] infos) {
        this.n = n;
        this.ehFolha = ehFolha;
        this.chaves = chaves;
        this.infos = infos;
    }

    int getN() {
        return n;
    }

    void setN(int n) {
        this.n = n;
    }

    boolean isEhFolha() {
        return ehFolha;
    }

    void setEhFolha(boolean ehFolha) {
        this.ehFolha = ehFolha;
    }

    String[] getChaves() {
        return chaves;
    }

    void setChaves(String[] chaves) {
        this.chaves = chaves;
    }

    Aluno[] getInfos() {
        return infos;
    }

    void setInfos(Aluno[] infos) {
        this.infos = infos;
    }

    BNodePlus[] getPont() {
        return pont;
    }

    void setPont(BNodePlus[] pont) {
        this.pont = pont;
    }

    BNodePlus getProx() {
        return prox;
    }

    void setProx(BNodePlus prox) {
        this.prox = prox;
    }
}
