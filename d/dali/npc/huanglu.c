//baitu.c
inherit NPC;

void create()
{
        set_name("��¹", ({ "huang lu", "lu" }) );
        set("race", "Ұ��");
        set("age", 2);
        set("long", "һֻ��ɫ�Ĵ�Ұ¹��\n");
        set("attitude", "peaceful");
 
        set("str", 15);
        set("cor", 16);

        set("limbs", ({ "ͷ��", "����", "צ��", "β��" }) );
        set("verbs", ({ "bite" }) );
 
        set("combat_exp", 1000+random(1000));

        set_temp("apply/attack", 5);
        set_temp("apply/damage", 3);
	set_temp("apply/defence",5);
	set_temp("apply/armor",2);
      
	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
	}) );

	setup();
}


void die()
{
	object ob;
	message_vision("$N��ҵĺ��˼��������ˡ�\n", this_object());
        if( random(30) >29 )      {
        	ob = new(__DIR__"obj/lurong");
                ob->move(environment(this_object()));
        }
        else    
                message_vision("�����ͻȻ����һֻͺ�գ���$N�����ˡ�\n", this_object());
	destruct(this_object());
}

