// Npc: /d/tianshan/npc/wulaoda.c
// By Linux
inherit NPC;
void create()
{
	set_name("���ϴ�", ({ "wu laoda", "wu"}));
	set("long",@LONG
�������������������ϴ�һ�ֱ��̵���ʹ�ó����뻯��
LONG	    
	   );
	set("gender", "����");
	set("age", 40);
	set("shen_type",-1);
	set("attitude", "peaceful");

	set("str", 27);
	set("int", 23);
	set("con", 24);
	set("dex", 30);
	set("no_quest", 1);

	set("max_qi", 100000);
 	set("qi", 100000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 10000);
	set("jiali", 0);

	set("combat_exp", 1000000);
	setup();
	carry_object(BINGQI_D("blade"))->wield();
	carry_object(MISC_D("cloth"))->wear();   
}
