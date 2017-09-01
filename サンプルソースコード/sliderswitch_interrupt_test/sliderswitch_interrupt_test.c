#include <stdio.h>
#include <sys/unistd.h>
#include "system.h"
#include "io.h"
#include "sys/alt_irq.h"
#include "altera_up_avalon_parallel_port_regs.h"

//�X���C�h�X�C�b�`�̊��荞�݃n���h��
void sliderswitch_handler();

//�X���C�h�X�C�b�`�̊��荞�ݏ�����
void sliderswitch_init();

int main(void)
{
	puts("---sliderswitch_test start---");
	sliderswitch_init();

	while(1)
	{

	}

	return 0;
}

void sliderswitch_handler()
{
	int button_position;
	//���荞�݂����X���C�h�X�C�b�`�̏��𓾂�
	button_position = IORD_ALT_UP_PARALLEL_PORT_EDGE_CAPTURE(SLIDER_SWITCHES_BASE);
	//�X���C�h�X�C�b�`��HIGH,LOW��\��
	printf("interrupted!!, %x\n", *((int*)SLIDER_SWITCHES_BASE));
	//EDGE���W�X�^��0�ɂ��Ȃ��Ƃ����Ɗ��荞�݂��J��Ԃ�
	IOWR_ALT_UP_PARALLEL_PORT_EDGE_CAPTURE(SLIDER_SWITCHES_BASE, 0x0);
}

void sliderswitch_init()
{
	volatile alt_irq_context ic;
	//���荞�݉\�ȃX���C�h�X�C�b�`���w�肷��B�Ƃ肠�����S���B
	IOWR_ALT_UP_PARALLEL_PORT_INTERRUPT_MASK(SLIDER_SWITCHES_BASE, 0xfffff);

	//���荞�݃|�[�g�̗����オ���������
	IOWR_ALT_UP_PARALLEL_PORT_EDGE_CAPTURE(SLIDER_SWITCHES_BASE,0x0);

	//���荞�݃n���h��o�^
	alt_irq_register(
			SLIDER_SWITCHES_IRQ,
			NULL,
			(void *)sliderswitch_handler);
	//������͂Ȃ��Ă������B
    ic = alt_irq_disable_all();//���荞�݋֎~�ɂ���
    alt_irq_enable_all(ic);//���荞�݋��ɂ���

}
