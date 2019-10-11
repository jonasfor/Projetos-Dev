package entidade;

public class Endereco {
    public String logradouro, complemento, bairro, cidade, CEP;
    int numero;
    
    public Endereco(String logradouro, String complemento, String bairro,
            String cidade, String CEP, int numero){
        this.logradouro = logradouro;
        this.complemento = complemento;
        this.bairro = bairro;
        this.cidade = cidade;
        this.CEP = CEP;
        this.numero = numero;
    }
    
    public String getLogradouro(){
        return logradouro;
    }
    public void setLogradouro(String logradouro){
        this.logradouro = logradouro;
    }
    public String getComplemento(){
        return complemento;
    }
    public void setComplemento(String complemento){
        this.complemento = complemento;
    }
    public String getBairro(){
        return bairro;
    }
    public void setBairro(String bairro){
        this.bairro = bairro;
    }
    public String getCidade(){
        return cidade;
    }
    public void setCidade(String cidade){
        this.cidade = cidade;
    }
    public String getCEP (){
        return CEP;
    }
    public void setCEP(String CEP){
        this.CEP = CEP;
    }
    public int getNumero(){
        return numero;
    }
    public void setNumero(int Numero){
        this.numero = numero;
    }

}
