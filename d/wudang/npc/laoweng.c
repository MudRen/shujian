// /u/dubei/wudang/npc/laoweng
 
inherit NPC;
int ask_me();
int ask_me1();

void create()
{
	set_name("��������", ({ "lao weng", "lao" }));
	set("long", "��λ���ߴ��ż��ӣ���ͷ��������ɫ����\n");
	set("gender", "����");
	set("age", 70);

	set("eff_jingli", 1300);
	set("max_qi", 1400);
	set("max_jing", 1000);

	set_skill("medicine", 130);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 100);

	set_skill("unarmed", 150);
	set_skill("parry", 150);
	set_skill("dodge", 150);

	set("combat_exp", 1000000);
	set("shen", 4000);
	set("inquiry", ([
                "��ҩ����" : (: ask_me :),
                "���" : (: ask_me1 :),
	]));
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}

int ask_me()
{
	command("say ���䵱�Ĳ�ҩ������ż���ܿ���������ɽ��ҩ��\n");
	return 1;
}

int ask_me1()
{
	object me, ob;

	ob = this_player();
	me = this_object();
       
	command("say ����һλ�䵱��ҩ����ʧ��׹���ɽ���£������ò�ҩ·�����Լ�\n"
		"ҽ�Ρ�����֮�ͣ����������£���������");
	ob->set_temp("marks/jieguo",1);
	return 1;
}
