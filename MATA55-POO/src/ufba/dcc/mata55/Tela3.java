package ufba.dcc.mata55;

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.util.List;

import javax.swing.ButtonGroup;
import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JLabel;
import javax.swing.JRadioButton;
import javax.swing.LayoutStyle.ComponentPlacement;
import javax.swing.JButton;

public class Tela3 extends JFrame {
	/**
	 * 
	 */
	private static final long serialVersionUID = 6096767662030845123L;
	private ButtonGroup bg1 = new ButtonGroup();
	private ButtonGroup bg2 = new ButtonGroup();
	private ButtonGroup bg3 = new ButtonGroup();
	private ButtonGroup bg4 = new ButtonGroup();
	private ButtonGroup bg5 = new ButtonGroup();
	
	public Tela3(Recomendacao recomendacao) {
		
		setTitle("Recomendações");
		setSize(400,300);
		setResizable(false);
		setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
		
		
		// ####### NÃO MEXA ABAIXO DESSA LINHA, PORQUE É APENAS LAYOUT #############
		JPanel panel = new JPanel();
		getContentPane().add(panel, BorderLayout.CENTER);
		
		JLabel lblFilme = new JLabel("Filme 1");
		
		JRadioButton rdbtnGostou = new JRadioButton("Gostou");
		JRadioButton rdbtnNoGostou = new JRadioButton("N\u00E3o Gostou");
		
		bg1.add(rdbtnGostou);
		bg1.add(rdbtnNoGostou);
		
		JLabel lblFilme_1 = new JLabel("Filme 2");
		
		JRadioButton rdbtnGostou_1 = new JRadioButton("Gostou");		
		JRadioButton rdbtnNoGostou_1 = new JRadioButton("N\u00E3o Gostou");
		
		bg2.add(rdbtnGostou_1);
		bg2.add(rdbtnNoGostou_1);
		
		JLabel lblFilme_2 = new JLabel("Filme 3");
		
		JRadioButton rdbtnGostou_2 = new JRadioButton("Gostou");		
		JRadioButton rdbtnNoGostou_2 = new JRadioButton("N\u00E3o Gostou");
		
		bg3.add(rdbtnGostou_2);
		bg3.add(rdbtnNoGostou_2);
		
		JLabel lblFilme_3 = new JLabel("Filme 4");
		
		JRadioButton rdbtnGostou_3 = new JRadioButton("Gostou");		
		JRadioButton rdbtnNoGostou_3 = new JRadioButton("N\u00E3o Gostou");
		
		bg4.add(rdbtnGostou_3);
		bg4.add(rdbtnNoGostou_3);		
		
		JLabel lblFilme_4 = new JLabel("Filme 5");
		
		JRadioButton rdbtnGostou_4 = new JRadioButton("Gostou");
		JRadioButton rdbtnNoGostou_4 = new JRadioButton("N\u00E3o Gostou");
		
		bg5.add(rdbtnGostou_4);
		bg5.add(rdbtnNoGostou_4);
		
		JButton btnSubmit = new JButton("Submit");
		GroupLayout gl_panel = new GroupLayout(panel);
		gl_panel.setHorizontalGroup(
			gl_panel.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_panel.createSequentialGroup()
					.addContainerGap()
					.addGroup(gl_panel.createParallelGroup(Alignment.LEADING)
						.addGroup(gl_panel.createSequentialGroup()
							.addComponent(lblFilme)
							.addGap(34)
							.addComponent(rdbtnGostou)
							.addGap(18)
							.addComponent(rdbtnNoGostou))
						.addGroup(gl_panel.createSequentialGroup()
							.addComponent(lblFilme_1)
							.addGap(34)
							.addComponent(rdbtnGostou_1)
							.addGap(18)
							.addComponent(rdbtnNoGostou_1))
						.addGroup(gl_panel.createSequentialGroup()
							.addGroup(gl_panel.createParallelGroup(Alignment.LEADING)
								.addComponent(lblFilme_2)
								.addComponent(lblFilme_3)
								.addComponent(lblFilme_4))
							.addGap(34)
							.addGroup(gl_panel.createParallelGroup(Alignment.LEADING)
								.addGroup(gl_panel.createSequentialGroup()
									.addComponent(rdbtnGostou_4)
									.addGap(18)
									.addComponent(rdbtnNoGostou_4))
								.addGroup(gl_panel.createSequentialGroup()
									.addComponent(rdbtnGostou_3)
									.addGap(18)
									.addComponent(rdbtnNoGostou_3))
								.addGroup(gl_panel.createSequentialGroup()
									.addComponent(rdbtnGostou_2)
									.addGap(18)
									.addComponent(rdbtnNoGostou_2)))))
					.addContainerGap(149, Short.MAX_VALUE))
				.addGroup(Alignment.TRAILING, gl_panel.createSequentialGroup()
					.addContainerGap(285, Short.MAX_VALUE)
					.addComponent(btnSubmit)
					.addContainerGap())
		);
		gl_panel.setVerticalGroup(
			gl_panel.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_panel.createSequentialGroup()
					.addContainerGap()
					.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblFilme)
						.addComponent(rdbtnGostou)
						.addComponent(rdbtnNoGostou))
					.addGap(18)
					.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblFilme_1)
						.addComponent(rdbtnGostou_1)
						.addComponent(rdbtnNoGostou_1))
					.addGap(18)
					.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblFilme_2)
						.addComponent(rdbtnGostou_2)
						.addComponent(rdbtnNoGostou_2))
					.addGap(18)
					.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblFilme_3)
						.addComponent(rdbtnGostou_3)
						.addComponent(rdbtnNoGostou_3))
					.addGap(18)
					.addGroup(gl_panel.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblFilme_4)
						.addComponent(rdbtnGostou_4)
						.addComponent(rdbtnNoGostou_4))
					.addPreferredGap(ComponentPlacement.RELATED, 33, Short.MAX_VALUE)
					.addComponent(btnSubmit)
					.addContainerGap())
		);
		panel.setLayout(gl_panel);
	}
}