// sun.c ������
// By River@SJ 2001.02.28

#include <ansi.h>
inherit NPC;
string ask_job();
void create()
{
	set_name("������", ({ "sun popo", "sun", "popo" }));
	set("long","��λ�ϸ�����һ��������Ƥ���ĳ����������������㡣\n");
	set("gender", "Ů��");
	set("age", 60);
	set("attitude", "friendly");
	set("no_bark",1);
	set("per", 10);
	set("str", 30);
	set("dex", 30);
	set("con", 25);
	set("int", 40);
	set("shen", 1000);

	set("combat_exp", 1700000);
	set("max_qi", 3500);
	set("max_jing", 3600);
	set("eff_jingli",2000);
	set("max_neili", 5000);
	set("neili", 5000);
	set("jiali",30);
	set("unique", 1);

	set_skill("parry", 200);
	set_skill("force", 160);
	set_skill("dodge", 200);
	set_skill("sword", 200);
	set_skill("throwing", 200);
	set_skill("whip", 200);
	set_skill("meinu-quanfa", 200);
	set_skill("cuff", 200);
	set_skill("yunu-shenfa", 200);
	set_skill("yinsuo-jinling", 200);
	set_skill("yunu-jianfa", 200);
	set_skill("yunu-xinjing", 170);
	set_skill("literate", 140);

	map_skill("force", "yunu-xinjing");
	map_skill("dodge", "yunu-shenfa");
	map_skill("cuff", "meinu-quanfa");
	map_skill("sword", "yunu-jianfa");
	map_skill("whip", "yinsuo-jinling");
	map_skill("parry","yinsuo-jinling");
	prepare_skill("cuff", "meinu-quanfa");

	set("inquiry", ([
//		"���" : (: ask_job :),
	]));
      
	setup();
	carry_object("/d/gumu/obj/buxue1")->wear();
	carry_object(ARMOR_D("cloth"))->wear(); 
}
