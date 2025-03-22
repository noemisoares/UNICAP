public class App{
    public static void main (String[] args){
       Endereco endereco = new Endereco("Rua da Vida", 203, "Apartamento", "Coqueiral", "Rapazes Individuais", "Raincife", "12345-678");
       Medico medico = new Medico("12345", "Frank Einstein", "masculino", "Cirurgião Geral", endereco);

       System.out.println("INFORMAÇÕES DO MÉDICO:");
       System.out.println("Código: " + medico.codigo);
       System.out.println("Nome: " + medico.nome);
       System.out.println("Sexo: " + medico.sexo);
       System.out.println("Especialidade: " + medico.especialidade);
       System.out.println("ENDEREÇO ");
       System.out.println("Rua: " + medico.endereco.rua);
       System.out.println("Numero: " + medico.endereco.numero);
       System.out.println("Complemento: " + medico.endereco.complemento);
       System.out.println("Bairro: " + medico.endereco.bairro);
       System.out.println("Cidade: " + medico.endereco.cidade);
       System.out.println("UF: " + medico.endereco.uf);
       System.out.println("CEP: " + medico.endereco.cep);
       
       endereco = new Endereco("Rua da Morte", 302, "Casa", "Mangueiral", "Santa Pauline", "Hellcife", "87654-321");
       medico = new Medico("54321", "Marry Jackson", "feminino", "Pediatria Geral", endereco);

       System.out.println(" ");
       System.out.println("INFORMAÇÕES DO MÉDICO:");
       System.out.println("Código: " + medico.codigo);
       System.out.println("Nome: " + medico.nome);
       System.out.println("Sexo: " + medico.sexo);
       System.out.println("Especialidade: " + medico.especialidade);
       System.out.println("ENDEREÇO ");
       System.out.println("Rua: " + medico.endereco.rua);
       System.out.println("Numero: " + medico.endereco.numero);
       System.out.println("Complemento: " + medico.endereco.complemento);
       System.out.println("Bairro: " + medico.endereco.bairro);
       System.out.println("Cidade: " + medico.endereco.cidade);
       System.out.println("UF: " + medico.endereco.uf);
       System.out.println("CEP: " + medico.endereco.cep);
    }
}