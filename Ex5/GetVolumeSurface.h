#pragma once

struct BOX {	//���̒�`
	double x;	//��
	double y;	//����
	double z;	//���s
	double volume;	//�̐�
	double surface; //�\�ʐ�
	double packSize;  //������}�ւ̃T�C�Y
};

void GetVolumeSurface(BOX* box);
bool isSendable(BOX* box);
