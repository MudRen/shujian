// aqing.c ԽŮ����
#include <ansi.h>

inherit NPC;
void create()
{

         set_name("����", ({ "a qing", "aqing", "qing" }) );
	set("gender", "Ů��" );
        set("age", 14);
        set("long", "һ��ʮ�������С���Ƥ����������ò��������������������������ˡ�\n");
        set("attitude", "peaceful");
        set("beauty", "28");
        set("title", "��Ů");
        set("attitude", "friendly");
        set("combat_exp", 20000000);
        set("str", 10);
        set("dex", 50);
        set("int", 50);
        set("con", 30);
        set("max_neili", 45000);
        set("neili", 90000);
        set("eff_jingli", 8000);
        set("jingli", 8000);
        set("max_jing", 5000);
        set("jing", 5000);
        set("jiali", 100);
        set("max_qi", 60000);
        set("qi", 60000);
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "sword.liujian" :)
        }));

        set_skill("sword", 600);
        set_skill("dodge",600);
        set_skill("force",  400);
        set_skill("parry",  600);
        set_skill("literate",200);
        set_skill("yunu-xinjing", 400);
        set_skill("yuenu-jian", 600);
        set_skill("yunu-shenfa",600);

        map_skill("force", "yunu-xinjing");
        map_skill("dodge", "yunu-shenfa");
        map_skill("sword","yuenu-jian");
        map_skill("parry","yuenu-jian");
        set_temp("apply/attack", 150); 
        set_temp("apply/defense", 150); 
        set_temp("apply/armor", 150); 
        set_temp("apply/damage", 150); 

        setup();

        carry_object("/d/suzhou/npc/obj/shoe")->wear();
        carry_object("/d/suzhou/npc/obj/skirt")->wear();
        carry_object("/d/suzhou/npc/obj/greensilk")->wear();
        carry_object("/d/suzhou/npc/obj/zhujian")->wield();
}



void die()
{
	object me = query_temp("last_damage_from");

		if(me->query_temp("quest/wuzhao/over")&&!me->query("quest/pass/dugu-jiujian/wuzhao")){
			
message_vision(MAG"\n$Nһ����ս��������$nԽŮ��������Ѹ���ޱȣ�����������׺䣬�������ް�����ף�ίʵ���\n"NOR,me,this_object());
	message_vision(MAG"ֻ��$n�����²������������У������ް�����������Լ���ѧ���գ��Զ��¾Ž��ľ�΢������������\n\n",me,this_object());
	me->add_temp("quest/wuzhao/over",1);		
	//������1�������1������˭������������������+1��
		
			}

	::die();

}

void unconcious()
{
	die();
}
            