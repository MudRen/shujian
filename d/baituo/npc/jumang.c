inherit NPC;
void create()
{
    set_name("����", ({ "ju mang", "mang" }) );
	set("race", "Ұ��");
	set("age", 70);
    	set("long", "һ��������������������\n");
    	set("attitude", "aggressive");
	set("limbs", ({ "ͷ��", "����", "β��", "����" }) );
	set("verbs", ({ "sweep", "twist", "bite" }) );
        set("str", 190);
        set("max_qi", 20000);
        set("con", 190);
	set("combat_exp", 600000);
	set_temp("apply/attack", 300);
	set_temp("apply/defense", 400);
	set_temp("apply/damage", 400);
	set_temp("apply/armor", 500);
	setup();
}

void die()
{
	object ob;
    	message_vision("$N���������˼��¾Ͳ����ˡ�\n", this_object());
	ob = new("/d/baituo/obj/shepi");
	ob->move(environment(this_object()));
	destruct(this_object());
}
	
