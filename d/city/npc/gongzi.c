// gongzi.c
// Lklv modify 2001.9.27

inherit NPC;

void create()
{
        set_name("���Ӹ��", ({"gong zi", "gongzi", "man"}) );
        set("gender", "����" );
        set("age", 20);
        set("long", "����һ���������ֺ��еĹ��Ӹ����\n");

        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set("combat_exp", 750);
	set("shen_type", -1);
        set("str", 25);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","heroism");
        setup();

        carry_object(ARMOR_D("changshan"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
	add_money("silver",3);
}