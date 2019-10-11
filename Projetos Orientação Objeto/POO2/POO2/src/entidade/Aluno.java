package entidade;

import util.Data;

public class Aluno {
    private String nome, RG, CPF;
    private Data dataNascimento;
    private char sexo;
    private Endereco endereco;

    public Aluno(String nome, String RG, String CPF, Data dataNascimento,
            char sexo, Endereco endereco){
        this.nome = nome;
        this.RG = RG;
        this.CPF = CPF;
        this.dataNascimento = dataNascimento;
        this.sexo = sexo;
        this.endereco = endereco;
    }
    
    public String getNome(){
        return nome;
    }
    public String getRG(){
        return RG;
    }
    public String getCPF(){
        return CPF;
    }
    public Data getDataNascimento(){
        return dataNascimento;
    }
    public char getSexo(){
        return seexo;
    }
    public Endereco getEndereco(){
        return endereco;
    }
    public void setEndereco(Endereco endereco){
        this.endereco = endereco;
    }

}

