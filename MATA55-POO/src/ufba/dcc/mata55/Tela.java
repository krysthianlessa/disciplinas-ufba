package ufba.dcc.mata55;

import javax.swing.JFrame;
import javax.swing.JPanel;

import java.awt.BorderLayout;

import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.LayoutStyle.ComponentPlacement;

import jxl.read.biff.BiffException;
import jxl.write.WritableSheet;
import jxl.write.WriteException;
import jxl.write.biff.RowsExceededException;

import javax.swing.JButton;

import java.awt.event.ActionListener;
import java.io.IOException;
import java.awt.event.ActionEvent;

public class Tela extends JFrame {
	
	static final Usuario user = new Usuario();
	
	
	/**
	 * 
	 */
	private static final long serialVersionUID = -1309538964427598496L;
	private JTextField nome;
	private JTextField cpf;
	

	public Tela() {
		setTitle("Cadastro");
		setSize(400,160);
		setResizable(false);
		setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		getContentPane().add(panel, BorderLayout.CENTER);
		
		JLabel lblNome = new JLabel("Nome:");
		
		nome = new JTextField();
		nome.setColumns(10);
		
		JLabel lblCpf = new JLabel("CPF:");
		
		cpf = new JTextField();
		cpf.setColumns(10);
		
		JButton btnSubmit = new JButton("Submit");
		btnSubmit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//Clicar botão, atribui valores à Usuario()
				
				
				user.setNome(nome.getText());
				user.setCpf(cpf.getText());
				
//				InsereDados inseredados = new InsereDados();
//-------------------------Joguei isso na Main pra Criar a Planilha-----------------------------------------------------------------------			
//				try {
//					inseredados.insere();
//				} catch (RowsExceededException e2) {
//					// TODO Auto-generated catch block
//					e2.printStackTrace();
//				} catch (WriteException e2) {
//					// TODO Auto-generated catch block
//					e2.printStackTrace();
//				} catch (IOException e2) {
//					// TODO Auto-generated catch block
//					e2.printStackTrace();
//				}
//------------------------------------------------------------------------------------------------------------------------------------
				
//Tá dando erro aqui ele ta pedindo pra passar algo do tipo Writable Sheet que tem no metodo addLabel pra adcinar na celula
//
//				try {
//
//				inseredados.addLabel(,0,0,"hugo");
//				}
//				catch (RowsExceededException e2) {
//						// TODO Auto-generated catch block
//						e2.printStackTrace();
//					} catch (WriteException e2) {
//						// TODO Auto-generated catch block
//						e2.printStackTrace();
//					}
//				
								
				//Tela.this.dispose();
				Tela.this.setVisible(false);
				
				Tela2 tela2 = null;
				try {
					tela2 = new Tela2();
				} catch (BiffException e1) {
					System.out.println("Erro");
					e1.printStackTrace();
				} catch (IOException e1) {
					System.out.println("ERRO");
					e1.printStackTrace();
				}
				tela2.setVisible(true);
				System.out.println(user.getNome());
				System.out.println(user.getCpf());
			}
		});
		GroupLayout gl_panel = new GroupLayout(panel);
		gl_panel.setHorizontalGroup(
			gl_panel.createParallelGroup(Alignment.TRAILING)
				.addGroup(gl_panel.createSequentialGroup()
					.addContainerGap()
					.addGroup(gl_panel.createParallelGroup(Alignment.TRAILING)
						.addComponent(lblCpf)
						.addComponent(lblNome))
					.addGap(20)
					.addGroup(gl_panel.createParallelGroup(Alignment.TRAILING)
						.addComponent(cpf, Alignment.LEADING, GroupLayout.PREFERRED_SIZE, 129, GroupLayout.PREFERRED_SIZE)
						.addComponent(nome, GroupLayout.PREFERRED_SIZE, 294, GroupLayout.PREFERRED_SIZE))
					.addContainerGap(29, Short.MAX_VALUE))
				.addGroup(gl_panel.createSequentialGroup()
					.addContainerGap(309, Short.MAX_VALUE)
					.addComponent(btnSubmit)
					.addContainerGap())
		);
		gl_panel.setVerticalGroup(
			gl_panel.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_panel.createSequentialGroup()
					.addContainerGap()
					.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblNome)
						.addComponent(nome, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE))
					.addPreferredGap(ComponentPlacement.UNRELATED)
					.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblCpf)
						.addComponent(cpf, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE))
					.addGap(27)
					.addComponent(btnSubmit)
					.addGap(149))
		);
		panel.setLayout(gl_panel);
	}
}
