// wolf��by xiaoyao
#include <ansi.h>

inherit NPC;
void create()
{
        set_name(WHT"����"NOR, ({ "hui lang", "wolf", "lang" }));
        set("race", "Ұ��");
        set("age", 5);
        set("long","����һͷ��ɫ���ǣ����ú�ɫ���۾������㣬��ʱ�������˵�ս��������\n");
        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 200000);
        set("str", 80);
        set("con", 80);
        set("chat_chance", 6);
        set("chat_msg", ({
              (: this_object(), "random_move" :),
        }) );
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 50);
        setup();
}

void unconcious()
{    
       object ob;
       message_vision("$N�ó�޵��۹⿴���㣬��Ѫ�Ӽ��������������������ˣ�\n", this_object());
        ob = new(__DIR__"obj/langya");
       ob->move(environment(this_object()));
       destruct(this_object());     
}
void die(){ unconcious(); }

