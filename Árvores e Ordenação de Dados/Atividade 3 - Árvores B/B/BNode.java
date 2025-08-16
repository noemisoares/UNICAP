package B;

class NodeB {
    private int n;
    private int[] chaves;
    private NodeB[] filhos;
    boolean folha;

    NodeB(int m) {
        chaves = new int[m];
        filhos = new NodeB[m];
        folha = true;
        n = 0;
    }

    int getN() {
        return n;
    }

    void setN(int n) {
        this.n = n;
    }

    int[] getChaves() {
        return chaves;
    }

    void setChaves(int[] chaves) {
        this.chaves = chaves;
    }

    NodeB[] getFilhos() {
        return filhos;
    }

    void setFilhos(NodeB[] filhos) {
        this.filhos = filhos;
    }

    boolean isFolha() {
        return folha;
    }

    void setFolha(boolean folha) {
        this.folha = folha;
    }
}