package ufba.dcc.mata55;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import jxl.Cell;
import jxl.Sheet;
import jxl.Workbook;
import jxl.read.biff.BiffException;

public class Recomendacao {

	List<Avaliacao> avaliacoes = new ArrayList<Avaliacao>();
	List<Filme> filmes = new ArrayList<Filme>();

	public Recomendacao(List<Avaliacao> avaliacoes) {
		this.avaliacoes = avaliacoes;
		//Pegando a media de cada genero
		float  mediaGenero1 = ((float)(avaliacoes.get(0).getNota()+avaliacoes.get(1).getNota())/2);
		float  mediaGenero2 = ((float)(avaliacoes.get(2).getNota()+avaliacoes.get(3).getNota())/2);
		float  mediaGenero3 = ((float)(avaliacoes.get(4).getNota()+avaliacoes.get(5).getNota())/2);
		float  mediaGenero4 = ((float)(avaliacoes.get(6).getNota()+avaliacoes.get(7).getNota())/2);
		float  mediaGenero5 = ((float)(avaliacoes.get(8).getNota()+avaliacoes.get(9).getNota())/2);

		
		
		float[] odr = {mediaGenero1, mediaGenero2, mediaGenero3, mediaGenero4, mediaGenero5} ;
		float aux = 0;        

		//System.out.println(" ");
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 4; j++) {
				if (odr[j] < odr[j + 1]) {
					aux = odr[j];
					odr[j] = odr[j + 1];
					odr[j + 1] = aux;
				}
			}
		}
		System.out.println("Vetor organizado:");
		for (int i = 0; i < 5; i++) {
			System.out.println(" " + odr[i]);
		}

		int mediaMaior = 0; 
		int segundaMedia = 0;       

		for (int i = 0; i <= 0; i++) {

			if(odr[i] == mediaGenero1){
				mediaMaior = 1;
				System.out.println("Recomenda 3 de Ação");
				break;
				//recomenda 3 de Ação
			}

			if(odr[i] == mediaGenero2){
				mediaMaior = 2;
				System.out.println("Recomenda 3 de Comédia");
				break;
				//recomenda 3 de Comédia	
			}

			if(odr[i] == mediaGenero3){
				mediaMaior = 3;
				System.out.println("Recomenda 3 de Drama");
				break;
				//recomenda 3 de Drama
			}

			if(odr[i] == mediaGenero4){
				mediaMaior = 4;
				System.out.println("Recomenda 3 de Ficção");
				break;
				//recomenda 3 de Ficção Científica 
			}

			if(odr[i] == mediaGenero5){
				mediaMaior = 5;
				System.out.println("Recomenda 3 de Infantil");
				break;
				//recomenda 3 Infantil
			}
		}

		// medMen

		for (int i = 1; i<=1; i++) {

			if(odr[i] == mediaGenero1){
				segundaMedia = 1;
				System.out.println("Recomenda 2 de Ação");
				break;
				//recomenda 2 de Ação
			}

			if(odr[i] == mediaGenero2){
				segundaMedia = 2;
				System.out.println("Recomenda 2 de Comédia");
				break;
				//recomenda 2 de Comédia	
			}

			if(odr[i] == mediaGenero3){
				segundaMedia = 3;
				System.out.println("Recomenda 2 de Drama");
				break;
				//recomenda 2 de Drama
			}

			if(odr[i] == mediaGenero4){
				segundaMedia = 4;
				System.out.println("Recomenda 2 de Ficção");
				break;
				//recomenda 2 de Ficção Científica 
			}

			if(odr[i] == mediaGenero5){
				segundaMedia = 5;
				System.out.println("Recomenda 2 de Infantil");
				break;
				//recomenda 2 Infantil
			}
		}
		
		try {
			this.recomenda(mediaMaior, segundaMedia);
		} catch (BiffException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public void recomenda(int mediaMaior, int segundaMedia) throws BiffException, IOException {
		Workbook workbook = Workbook.getWorkbook(new File("filmes.xls"));
		Sheet sheet = workbook.getSheet(0);
		Random gerador = new Random();
		List<String> filmesRecomendados = new ArrayList<String>();
		int escolha1 = 0;
		int escolha2 = 0;
		int escolha3 = 0;
				
		switch (mediaMaior) {
		case 1:
			String acao1 = avaliacoes.get(0).getFilme().getNome();
			String acao2 = avaliacoes.get(1).getFilme().getNome();	
			
			do {
				do {
					escolha1 = gerador.nextInt(15);
					escolha2 = gerador.nextInt(15);
					escolha3 = gerador.nextInt(15);
				} while ((escolha1 == escolha2) || (escolha1 == escolha3) || (escolha2 == escolha3));

				Cell a1 = sheet.getCell(0, escolha1);
				filmesRecomendados.add(0, a1.getContents());
				a1 = sheet.getCell(0, escolha2);
				filmesRecomendados.add(1, a1.getContents());
				a1 = sheet.getCell(0, escolha3);
				filmesRecomendados.add(2, a1.getContents());
				
			} while ((filmesRecomendados.get(0) == acao1) || (filmesRecomendados.get(1) == acao1) || (filmesRecomendados.get(2) == acao1) || 
					(filmesRecomendados.get(0) == acao2) || (filmesRecomendados.get(1) == acao2) || (filmesRecomendados.get(2) == acao2));
			
			System.out.println(filmesRecomendados.get(0));
			System.out.println(filmesRecomendados.get(1));
			System.out.println(filmesRecomendados.get(2));
			break;
		case 2:

			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		
		}
		
		
	}
}
