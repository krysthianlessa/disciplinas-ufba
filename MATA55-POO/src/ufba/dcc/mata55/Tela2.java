package ufba.dcc.mata55;

import javax.swing.JFrame;
import javax.swing.ButtonGroup;
import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JRadioButton;
import javax.swing.LayoutStyle.ComponentPlacement;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import jxl.Cell;
import jxl.Sheet;
import jxl.Workbook;
import jxl.read.biff.BiffException;
import ufba.dcc.mata55.Tela2;

public class Tela2 extends JFrame {
	/**
	 * 
	 */
	private static final long serialVersionUID = 5027488961795686373L;
	private ButtonGroup bg1 = new ButtonGroup();
	private ButtonGroup bg2 = new ButtonGroup();
	private ButtonGroup bg3 = new ButtonGroup();
	private ButtonGroup bg4 = new ButtonGroup();
	private ButtonGroup bg5 = new ButtonGroup();
	private ButtonGroup bg6 = new ButtonGroup();
	private ButtonGroup bg7 = new ButtonGroup();
	private ButtonGroup bg8 = new ButtonGroup();
	private ButtonGroup bg9 = new ButtonGroup();
	private ButtonGroup bg10 = new ButtonGroup();
	
	public Tela2() throws BiffException, IOException{
		setTitle("Avalia\u00E7\u00E3o");
		setSize(600,600);
		setResizable(false);
		setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
		
		String filme = null;
		String genero = null;
		final Filme filme1 = new Filme();
		final Filme filme2 = new Filme();
		final Filme filme3 = new Filme();
		final Filme filme4 = new Filme();
		final Filme filme5 = new Filme();
		final Filme filme6 = new Filme();
		final Filme filme7 = new Filme();
		final Filme filme8 = new Filme();
		final Filme filme9 = new Filme();
		final Filme filme10 = new Filme();
		
		JPanel panel = new JPanel();
		getContentPane().add(panel, BorderLayout.CENTER);
		
		JLabel lblFilmes = new JLabel("FILMES");
		
		// Abrir a planilha 
		Workbook workbook = Workbook.getWorkbook(new File("filmes.xls"));
		Sheet sheet = workbook.getSheet(0);
						
		// loop de leitura das linhas e atribuições dos 10 objetos filmes 
		Random gerador = new Random();
		int k = 0;
		int chosen1 = 0;
		int chosen2 = 0;
		for (int i = 1; i < 11;) {
			int cont = 0;
			while (cont <= 1){
				if (cont == 0) {
					chosen1 = gerador.nextInt(15);
				} else {
					chosen2 = gerador.nextInt(15);
					while (chosen1 == chosen2){
						chosen2 = gerador.nextInt(15);
					}
				}
				for (int j = 0; j < 2 ; j++) {
					if (cont == 0){
						Cell a1 = sheet.getCell(j, chosen1+k);
						if (j==0) {
							filme = a1.getContents();
							System.out.println(filme);
						} else {
							genero = a1.getContents();
							System.out.println(genero);
						}	
					} else {
						Cell a1 = sheet.getCell(j, chosen2+k);
						if (j==0) {
							filme = a1.getContents();
							System.out.println(filme);
						} else {
							genero = a1.getContents();
							System.out.println(genero);
						}	
					}
				}
				switch (i) {
					case 1:
						filme1.setNome(filme);
						filme1.setGenero(genero);
						break;
					case 2:
						filme2.setNome(filme);
						filme2.setGenero(genero);
						break;
					case 3:
						filme3.setNome(filme);
						filme3.setGenero(genero);
						break;
					case 4:
						filme4.setNome(filme);
						filme4.setGenero(genero);
						break;
					case 5:
						filme5.setNome(filme);
						filme5.setGenero(genero);
						break;
					case 6:
						filme6.setNome(filme);
						filme6.setGenero(genero);
						break;
					case 7:
						filme7.setNome(filme);
						filme7.setGenero(genero);
						break;
					case 8:
						filme8.setNome(filme);
						filme8.setGenero(genero);
						break;
					case 9:
						filme9.setNome(filme);
						filme9.setGenero(genero);
						break;
					case 10:
						filme10.setNome(filme);
						filme10.setGenero(genero);
						break;
					default:
						System.out.println("Numero invalido");					
				}
				if (i % 2 == 0 ) {
					k= k + 15;
				}
				i++;
				cont++;
			}
		}
		//Fecha a planilha
		workbook.close();
		
		JLabel lblFilme = new JLabel(filme1.getNome());
		
		JRadioButton radioButton = new JRadioButton("1");
		JRadioButton radioButton_1 = new JRadioButton("2");
		JRadioButton radioButton_2 = new JRadioButton("3");
		JRadioButton radioButton_3 = new JRadioButton("4");
		JRadioButton radioButton_4 = new JRadioButton("5");
		
		//Define os valores que vão receber ao selecionar um dos JRadioButton
		radioButton.setActionCommand("1");
		radioButton_1.setActionCommand("2");	
		radioButton_2.setActionCommand("3");
		radioButton_3.setActionCommand("4");
		radioButton_4.setActionCommand("5");

		//Cria um grupo de RadioButton para que apenas um JRadioButton seja selecionado
		bg1.add(radioButton);
		bg1.add(radioButton_1);
		bg1.add(radioButton_2);
		bg1.add(radioButton_3);
		bg1.add(radioButton_4);	
		
		JLabel lblFilme_1 = new JLabel(filme2.getNome());
		
		JRadioButton radioButton_5 = new JRadioButton("1");
		JRadioButton radioButton_6 = new JRadioButton("2");
		JRadioButton radioButton_7 = new JRadioButton("3");
		JRadioButton radioButton_8 = new JRadioButton("4");
		JRadioButton radioButton_9 = new JRadioButton("5");
		
		radioButton_5.setActionCommand("1");
		radioButton_6.setActionCommand("2");
		radioButton_7.setActionCommand("3");
		radioButton_8.setActionCommand("4");
		radioButton_9.setActionCommand("5");
		
		bg2.add(radioButton_5);
		bg2.add(radioButton_6);
		bg2.add(radioButton_7);
		bg2.add(radioButton_8);
		bg2.add(radioButton_9);
		
		JLabel lblFilme_2 = new JLabel(filme3.getNome());
		
		JRadioButton radioButton_10 = new JRadioButton("1");
		JRadioButton radioButton_11 = new JRadioButton("2");
		JRadioButton radioButton_12 = new JRadioButton("3");
		JRadioButton radioButton_13 = new JRadioButton("4");
		JRadioButton radioButton_14 = new JRadioButton("5");
		
		radioButton_10.setActionCommand("1");
		radioButton_11.setActionCommand("2");
		radioButton_12.setActionCommand("3");
		radioButton_13.setActionCommand("4");
		radioButton_14.setActionCommand("5");
		
		bg3.add(radioButton_10);
		bg3.add(radioButton_11);
		bg3.add(radioButton_12);
		bg3.add(radioButton_13);
		bg3.add(radioButton_14);
		
		JLabel lblFilme_3 = new JLabel(filme4.getNome());
		
		JRadioButton radioButton_15 = new JRadioButton("1");
		JRadioButton radioButton_16 = new JRadioButton("2");
		JRadioButton radioButton_17 = new JRadioButton("3");
		JRadioButton radioButton_18 = new JRadioButton("4");
		JRadioButton radioButton_19 = new JRadioButton("5");
		
		radioButton_15.setActionCommand("1");
		radioButton_16.setActionCommand("2");
		radioButton_17.setActionCommand("3");
		radioButton_18.setActionCommand("4");
		radioButton_19.setActionCommand("5");
		
		bg4.add(radioButton_15);
		bg4.add(radioButton_16);
		bg4.add(radioButton_17);
		bg4.add(radioButton_18);
		bg4.add(radioButton_19);
		
		JLabel lblFilme_4 = new JLabel(filme5.getNome());
	
		JRadioButton radioButton_20 = new JRadioButton("1");
		JRadioButton radioButton_21 = new JRadioButton("2");
		JRadioButton radioButton_22 = new JRadioButton("3");
		JRadioButton radioButton_23 = new JRadioButton("4");
		JRadioButton radioButton_24 = new JRadioButton("5");
		
		radioButton_20.setActionCommand("1");
		radioButton_21.setActionCommand("2");
		radioButton_22.setActionCommand("3");
		radioButton_23.setActionCommand("4");
		radioButton_24.setActionCommand("5");
		
		bg5.add(radioButton_20);
		bg5.add(radioButton_21);
		bg5.add(radioButton_22);
		bg5.add(radioButton_23);
		bg5.add(radioButton_24);
		
		JLabel lblFilme_5 = new JLabel(filme6.getNome());
		
		JRadioButton radioButton_25 = new JRadioButton("1");
		JRadioButton radioButton_26 = new JRadioButton("2");
		JRadioButton radioButton_27 = new JRadioButton("3");
		JRadioButton radioButton_28 = new JRadioButton("4");
		JRadioButton radioButton_29 = new JRadioButton("5");
		
		radioButton_25.setActionCommand("1");
		radioButton_26.setActionCommand("2");
		radioButton_27.setActionCommand("3");
		radioButton_28.setActionCommand("4");
		radioButton_29.setActionCommand("5");
		
		bg6.add(radioButton_25);
		bg6.add(radioButton_26);
		bg6.add(radioButton_27);
		bg6.add(radioButton_28);
		bg6.add(radioButton_29);				
		
		JLabel lblFilme_6 = new JLabel(filme7.getNome());
		
		JRadioButton radioButton_30 = new JRadioButton("1");
		JRadioButton radioButton_31 = new JRadioButton("2");
		JRadioButton radioButton_32 = new JRadioButton("3");
		JRadioButton radioButton_33 = new JRadioButton("4");
		JRadioButton radioButton_34 = new JRadioButton("5");
		
		radioButton_30.setActionCommand("1");
		radioButton_31.setActionCommand("2");
		radioButton_32.setActionCommand("3");
		radioButton_33.setActionCommand("4");
		radioButton_34.setActionCommand("5");
		
		bg7.add(radioButton_30);
		bg7.add(radioButton_31);
		bg7.add(radioButton_32);
		bg7.add(radioButton_33);
		bg7.add(radioButton_34);
		
		JLabel lblFilme_7 = new JLabel(filme8.getNome());
		
		JRadioButton radioButton_35 = new JRadioButton("1");
		JRadioButton radioButton_36 = new JRadioButton("2");
		JRadioButton radioButton_37 = new JRadioButton("3");
		JRadioButton radioButton_38 = new JRadioButton("4");
		JRadioButton radioButton_39 = new JRadioButton("5");
		
		radioButton_35.setActionCommand("1");
		radioButton_36.setActionCommand("2");
		radioButton_37.setActionCommand("3");
		radioButton_38.setActionCommand("4");
		radioButton_39.setActionCommand("5");
		
		bg8.add(radioButton_35);
		bg8.add(radioButton_36);
		bg8.add(radioButton_37);
		bg8.add(radioButton_38);
		bg8.add(radioButton_39);
		
		JLabel lblFilme_8 = new JLabel(filme9.getNome());
		
		JRadioButton radioButton_40 = new JRadioButton("1");
		JRadioButton radioButton_41 = new JRadioButton("2");
		JRadioButton radioButton_42 = new JRadioButton("3");
		JRadioButton radioButton_43 = new JRadioButton("4");
		JRadioButton radioButton_44 = new JRadioButton("5");
		
		radioButton_40.setActionCommand("1");
		radioButton_41.setActionCommand("2");
		radioButton_42.setActionCommand("3");
		radioButton_43.setActionCommand("4");
		radioButton_44.setActionCommand("5");
		
		bg9.add(radioButton_40);
		bg9.add(radioButton_41);
		bg9.add(radioButton_42);
		bg9.add(radioButton_43);
		bg9.add(radioButton_44);
		
		JLabel lblFilme_9 = new JLabel(filme10.getNome());
		
		JRadioButton radioButton_45 = new JRadioButton("1");
		JRadioButton radioButton_46 = new JRadioButton("2");
		JRadioButton radioButton_47 = new JRadioButton("3");
		JRadioButton radioButton_48 = new JRadioButton("4");
		JRadioButton radioButton_49 = new JRadioButton("5");
		
		radioButton_45.setActionCommand("1");
		radioButton_46.setActionCommand("2");
		radioButton_47.setActionCommand("3");
		radioButton_48.setActionCommand("4");
		radioButton_49.setActionCommand("5");
		
		bg10.add(radioButton_45);
		bg10.add(radioButton_46);
		bg10.add(radioButton_47);
		bg10.add(radioButton_48);
		bg10.add(radioButton_49);
		
		JButton btnAvaliar = new JButton("Avaliar");
		btnAvaliar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
//				System.out.println(filme1.getNome());
//				System.out.println(filme1.getGenero());
//				System.out.println(bg1.getSelection().getActionCommand());
				
				//Criando as 10 avaliações passando no construtor os filmes avaliados e a nota recebida 
				Avaliacao avaliacao1 = new Avaliacao(filme1, (byte)Integer.parseInt(bg1.getSelection().getActionCommand()));
				Avaliacao avaliacao2 = new Avaliacao(filme2, (byte)Integer.parseInt(bg2.getSelection().getActionCommand()));
				Avaliacao avaliacao3 = new Avaliacao(filme3, (byte)Integer.parseInt(bg3.getSelection().getActionCommand()));
				Avaliacao avaliacao4 = new Avaliacao(filme4, (byte)Integer.parseInt(bg4.getSelection().getActionCommand()));
				Avaliacao avaliacao5 = new Avaliacao(filme5, (byte)Integer.parseInt(bg5.getSelection().getActionCommand()));
				Avaliacao avaliacao6 = new Avaliacao(filme6, (byte)Integer.parseInt(bg6.getSelection().getActionCommand()));
				Avaliacao avaliacao7 = new Avaliacao(filme7, (byte)Integer.parseInt(bg7.getSelection().getActionCommand()));
				Avaliacao avaliacao8 = new Avaliacao(filme8, (byte)Integer.parseInt(bg8.getSelection().getActionCommand()));
				Avaliacao avaliacao9 = new Avaliacao(filme9, (byte)Integer.parseInt(bg9.getSelection().getActionCommand()));
				Avaliacao avaliacao10 = new Avaliacao(filme10, (byte)Integer.parseInt(bg10.getSelection().getActionCommand()));
				
				//Cria lista de avaliações 
				List<Avaliacao> avaliacoes = new ArrayList<Avaliacao>();
				
				//Adiciona as 10 avaliações na lista
				avaliacoes.add(avaliacao1);
				avaliacoes.add(avaliacao2);
				avaliacoes.add(avaliacao3);
				avaliacoes.add(avaliacao4);
				avaliacoes.add(avaliacao5);
				avaliacoes.add(avaliacao6);
				avaliacoes.add(avaliacao7);
				avaliacoes.add(avaliacao8);
				avaliacoes.add(avaliacao9);
				avaliacoes.add(avaliacao10);
				
				Recomendacao recomendacao = new Recomendacao(avaliacoes);
				
				//Passa no construtor a lista de avaliações
				Tela3 tela3 = new Tela3(recomendacao);
			
				Tela2.this.setVisible(false);
				tela3.setVisible(true);
			}
		});
		GroupLayout gl_panel = new GroupLayout(panel);
		gl_panel.setHorizontalGroup(
			gl_panel.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_panel.createSequentialGroup()
					.addGroup(gl_panel.createParallelGroup(Alignment.LEADING)
						.addGroup(gl_panel.createSequentialGroup()
							.addContainerGap()
							.addComponent(lblFilmes))
						.addGroup(gl_panel.createSequentialGroup()
							.addGap(64)
							.addGroup(gl_panel.createParallelGroup(Alignment.TRAILING)
								.addComponent(lblFilme_1)
								.addComponent(lblFilme)
								.addComponent(lblFilme_2)
								.addComponent(lblFilme_3)
								.addComponent(lblFilme_4)
								.addComponent(lblFilme_5)
								.addComponent(lblFilme_6)
								.addComponent(lblFilme_7)
								.addComponent(lblFilme_8)
								.addComponent(lblFilme_9))
							.addGap(18)
							.addGroup(gl_panel.createParallelGroup(Alignment.LEADING)
								.addGroup(gl_panel.createSequentialGroup()
									.addComponent(radioButton_45)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_46)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_47)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_48)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_49))
								.addGroup(gl_panel.createSequentialGroup()
									.addComponent(radioButton_40)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_41)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_42)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_43)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_44))
								.addGroup(gl_panel.createSequentialGroup()
									.addComponent(radioButton_35)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_36)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_37)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_38)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_39))
								.addGroup(gl_panel.createSequentialGroup()
									.addComponent(radioButton_30)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_31)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_32)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_33)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_34))
								.addGroup(gl_panel.createSequentialGroup()
									.addComponent(radioButton_25)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_26)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_27)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_28)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_29))
								.addGroup(gl_panel.createSequentialGroup()
									.addComponent(radioButton_20)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_21)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_22)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_23)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_24))
								.addGroup(gl_panel.createSequentialGroup()
									.addComponent(radioButton_15)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_16)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_17)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_18)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_19))
								.addGroup(gl_panel.createSequentialGroup()
									.addComponent(radioButton_10)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_11)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_12)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_13)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_14))
								.addGroup(gl_panel.createSequentialGroup()
									.addComponent(radioButton)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_1)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_2)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_3)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_4))
								.addGroup(gl_panel.createSequentialGroup()
									.addComponent(radioButton_5)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_6)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_7)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_8)
									.addPreferredGap(ComponentPlacement.UNRELATED)
									.addComponent(radioButton_9)))))
					.addContainerGap(454, Short.MAX_VALUE))
				.addGroup(Alignment.TRAILING, gl_panel.createSequentialGroup()
					.addContainerGap(313, Short.MAX_VALUE)
					.addComponent(btnAvaliar)
					.addGap(306))
		);
		gl_panel.setVerticalGroup(
			gl_panel.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_panel.createSequentialGroup()
					.addContainerGap()
					.addComponent(lblFilmes)
					.addGap(18)
					.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblFilme)
						.addComponent(radioButton)
						.addComponent(radioButton_1)
						.addComponent(radioButton_2)
						.addComponent(radioButton_3)
						.addComponent(radioButton_4))
					.addGap(18)
					.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblFilme_1)
						.addComponent(radioButton_5)
						.addComponent(radioButton_6)
						.addComponent(radioButton_7)
						.addComponent(radioButton_8)
						.addComponent(radioButton_9))
					.addGap(18)
					.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblFilme_2)
						.addComponent(radioButton_10)
						.addComponent(radioButton_11)
						.addComponent(radioButton_12)
						.addComponent(radioButton_13)
						.addComponent(radioButton_14))
					.addGap(18)
					.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblFilme_3)
						.addComponent(radioButton_15)
						.addComponent(radioButton_16)
						.addComponent(radioButton_17)
						.addComponent(radioButton_18)
						.addComponent(radioButton_19))
					.addGap(18)
					.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblFilme_4)
						.addComponent(radioButton_20)
						.addComponent(radioButton_21)
						.addComponent(radioButton_22)
						.addComponent(radioButton_23)
						.addComponent(radioButton_24))
					.addGap(18)
					.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblFilme_5)
						.addComponent(radioButton_25)
						.addComponent(radioButton_26)
						.addComponent(radioButton_27)
						.addComponent(radioButton_28)
						.addComponent(radioButton_29))
					.addGap(18)
					.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblFilme_6)
						.addComponent(radioButton_30)
						.addComponent(radioButton_31)
						.addComponent(radioButton_32)
						.addComponent(radioButton_33)
						.addComponent(radioButton_34))
					.addGap(18)
					.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblFilme_7)
						.addComponent(radioButton_35)
						.addComponent(radioButton_36)
						.addComponent(radioButton_37)
						.addComponent(radioButton_38)
						.addComponent(radioButton_39))
					.addGap(18)
					.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblFilme_8)
						.addComponent(radioButton_40)
						.addComponent(radioButton_41)
						.addComponent(radioButton_42)
						.addComponent(radioButton_43)
						.addComponent(radioButton_44))
					.addGap(18)
					.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblFilme_9)
						.addComponent(radioButton_45)
						.addComponent(radioButton_46)
						.addComponent(radioButton_47)
						.addComponent(radioButton_48)
						.addComponent(radioButton_49))
					.addPreferredGap(ComponentPlacement.RELATED, 92, Short.MAX_VALUE)
					.addComponent(btnAvaliar)
					.addContainerGap())
		);
		panel.setLayout(gl_panel);
	}
}
