//zangao.c ����

inherit NPC;

void create()
{
       set_name("����", ({ "zang ao", "zangao" ,"dog" }) );
 	set("race", "Ұ��");
	set("age", 10);
       set("long", "��ͷ����ͨ����ڣ�������ɢ�ų�������ë���Ե��������ͣ����з������˵صͺ�\n");
       set("attitude", "aggressive");	
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "ǰצ" }) );
	set("verbs", ({ "bite", "claw" }) );
       set("max_qi", 750);
       set("max_jing", 300);
       set("eff_jingli", 300);
	set("combat_exp", 300000);
 
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 25);        
	setup();
}
 
	
