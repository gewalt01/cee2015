#include <stdio.h>
#include "system.h"
#include "io.h"
#include "sys/alt_irq.h"
#include "altera_up_avalon_parallel_port_regs.h"

//�v�b�V���{�^���̊��荞�݃n���h��
void button_handler();

//�v�b�V���{�^���̊��荞�ݏ�����
void button_init();

int main(void)
{
	puts("---start---");
	button_init();

	while(1)
	{

	}

	return 0;
}

void button_handler()
{
	//���荞�݂����v�b�V���{�^���̏��
	int button_position;

	//���荞�݂����v�b�V���{�^���̏��𓾂�
	button_position = IORD_ALT_UP_PARALLEL_PORT_EDGE_CAPTURE(PUSHBUTTONS_BASE);

	//���荞�݂����v�b�V���{�^�����ǂꂩ�\��
	printf("interrupted, %x\n", button_position);

	//EDGE���W�X�^��0�ɂ��Ȃ��Ƃ����Ɗ��荞�݂��J��Ԃ��Ė\������
	IOWR_ALT_UP_PARALLEL_PORT_EDGE_CAPTURE(PUSHBUTTONS_BASE, 0x0);
}

void button_init()
{
	volatile alt_irq_context ic;
	//���荞�݉\�ȃX���C�h�X�C�b�`���w�肷��B�Ƃ肠�����S���B
	IOWR_ALT_UP_PARALLEL_PORT_INTERRUPT_MASK(PUSHBUTTONS_BASE, 0xf);

	//���荞�݃|�[�g�̗����オ���������
	IOWR_ALT_UP_PARALLEL_PORT_EDGE_CAPTURE(PUSHBUTTONS_BASE,0x0);

	alt_irq_register(
			PUSHBUTTONS_IRQ,
			NULL,
			(void *)button_handler);
	//�Ȃ��Ă���
    ic = alt_irq_disable_all();//���荞�݋֎~�ɂ���
    alt_irq_enable_all(ic);//���荞�݉\�ɂ���

}
