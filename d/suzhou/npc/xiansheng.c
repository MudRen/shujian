// xiansheng.c ��������
inherit NPC;

void create()
{
	set_name("��������", ({ "xian sheng" , "xiansheng", "teacher" }));
	set("long", "��������������һ��������ѧ����\n");
	set("gender", "����");
	set("age", 65);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);

	set("combat_exp", 120000);
	set("shen_type", 1);
	setup();

	set("chat_chance", 3);
	set("chat_msg", ({
		"��������˵��������֮�£�Ī������������֮����Ī��������\n",
		"��������˵���������ˣ�С�������ɣ����������δ������֮��\n",
		"��������˵������ѧ֮�����������¡���������ֹ�����ơ� \n",
		"��������˵����������֪���������ģ�������ң��ι�ƽ���¡�\n",
	}) );
}
