// xiansheng.c ��������
inherit NPC;

void create()
{
	set_name("��������", ({ "xian sheng" ,"xian", "sheng", "teacher" }));
	set("long", "���������Ǻ���һ��������ѧ����\n");
	set("gender", "����");
	set("age", 65);
	set("per", 25);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);

	set("combat_exp", 50000);
	set("shen_type", 1);
	set("chat_chance", 2);
	set("chat_msg", ({
		"��������˵��������֮�£�Ī������������֮����Ī��������\n",
		"��������˵���������ˣ�С�������ɣ����������δ������֮��\n",
		"��������˵������ѧ֮�����������¡���������ֹ�����ơ� \n",
		"��������˵����������֪���������ģ�������ң��ι�ƽ���¡�\n",
	}));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}
