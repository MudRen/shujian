//baitu.c
// Modify By River 98/12
inherit NPC;

void create()
{
        set_name("Ұ��", ({ "ye tu", "tu" }) );
        set("race", "Ұ��");
        set("age", 2);
        set("long", "һֻ��ɫ��Ұ�á�\n");
        set("attitude", "peaceful");
 
        set("str", 15);
        set("cor", 16);

        set("limbs", ({ "ͷ��", "����", "צ��", "β��" }) );
        set("verbs", ({ "bite" }) );
 
        set("combat_exp", 500);

        set_temp("apply/attack", 5);
        set_temp("apply/damage", 3);
	set_temp("apply/defence",5);
	set_temp("apply/armor",2);

	setup();
}

void die()
{
	object ob;
	message_vision("$N��ҵĺ��˼��������ˡ�\n", this_object());
        if( random(3) >1 ) {            
            ob = new(__DIR__"turou");
            ob->move(environment(this_object()));
        }
        else    
            message_vision("�����ͻȻ����һֻͺ�գ���$N�����ˡ�\n", this_object());
	destruct(this_object());
}
