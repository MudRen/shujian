// /d/village/npc/girl.c

inherit NPC;

void create()
{
	set_name("Ů��",({ "nv hai", "girl" }) );
        set("gender", "Ů��" );
        set("age", 12+random(3));
        set("long", "���Ǹ�ũ����Ů����Ȼֻ��ʮ�������꣬����Ѿ���ʼ������\n");
        set_temp("apply/defense", 5);
	set("combat_exp", 70);
	set("shen_type", 1);
        set("str", 14);
        set("dex", 15);
        set("con", 16);
        set("int", 15);
        set("attitude", "friendly");
        setup();
       	carry_object(ARMOR_D("armor/cloth"))->wear();
	add_money("coin", random(30));
}
