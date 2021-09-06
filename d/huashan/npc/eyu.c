// NPC: /d/huashan/npc/eyu.c
// Date: Look 99/03/25
// Modify by Lklv 2001.10.18

inherit NPC;

void create()
{
        set_name("����", ({ "e yu", "eyu" }));
        set("race", "Ұ��");
        set("age", 10);
        set("long", "һ���Ӵ��ޱȵĴ����㣬�ſ���������������\n");
        set("attitude", "aggressive");
        set("str", 70);
        set("con", 50);
        set("max_qi", 8000);
        set("no_get", "����������̫���ˡ�\n");
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 500000);
        set_temp("apply/attack", 200);
        set_temp("apply/armor", 200);
        setup();
}
void die()
{
        object sword;
        sword = unew("/clone/weapon/sword/bishui-jian");
        if( clonep(sword) ) {
		sword->move(environment(this_object()));
        }
	::die();
}

