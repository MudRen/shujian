// NPC : /d/wudang/npc/yezhu.c Ұ��

inherit NPC;
void create()
{
        set_name("Ұ��", ({ "ye zhu","zhu" }) );
        set("race", "Ұ��");
        set("age", 6);
        set("con", 100);
        set("str", 100);
        set("long", "һֻ�۾�Ѫ���Ұ��\n");
        set("attitude", "aggressive");
        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 250000);
	 set_temp("apply/attack", 30);
	 set_temp("apply/defense", 50);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        setup();
}

void die()
{
	object ob;
	message_vision("$N��ҵĺ��˼��������ˡ�\n", this_object());
        ob = new(FOOD_D("yzhurou"));
	ob->move(environment(this_object()));
	destruct(this_object());
}
	
