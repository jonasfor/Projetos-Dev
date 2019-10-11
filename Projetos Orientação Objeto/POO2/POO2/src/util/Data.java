package util; 

import java.util.Calendar;
import java.util.GregorianCalendar;

public class Data {
    
    private int dia, mes, ano;
    
    public Data(int dia, int mes, int ano){
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }
    
    public int getDia(){
        return dia;
    }
    public int getMes(){
        return mes;
    }
    public int getAno(){
        return ano;
    }
    
    public int calcularIdade(){
        GregorianCalendar data_atual = new GregorianCalendar();
        int dia_atual = data_atual.get(Calendar.DAY_OF_MONTH);
        int mes_atual = data_atual.get(Calendar.MONTH);
        int ano_atual = data_atual.get(Calendar.YEAR);
        int idade = ano_atual - ano;
        if ((mes_atual < mes)||((mes_atual == mes)&&(dia_atual < dia))){
            idade--;
        }
        return idade;
    }
    
    public int compareTo(Data data){
        if(ano > data.getAno()) return 1;
        if(ano < data.getAno()) return -1;
        if(mes > data.getMes()) return 1;
        if(mes < data.getMes()) return -1;
        if(dia > data.getDia()) return 1;
        if(dia < data.getDia()) return -1;
        return 0;
    }
    
    public String toString(){
        String data;
        if (dia < 10) data = "0" + dia; else data = "" + dia;
        if (mes < 10) data += "/0" + mes; else data += "/" + mes;
        return data += ano;
    }
}





