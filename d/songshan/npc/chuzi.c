//chuzi.c ����
inherit NPC;
#include <ansi.h>
string ask_water();
string ask_food();
void create()
{
        set_name("����",({"chu zi", "chuzi"}));
        set("long","����ǰ�ǻʼҵ����������Ͻ����͵���ɽ�ƹ���ɽ�ɵ��ӵ���ʳ��\n");
        set("gender", "����");
        set("age", 36);
        set("attitude", "friendly");
        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 100);
        set("max_neili", 100);
        set("jiali", 1);
        set("combat_exp", 3500);
        set_skill("unarmed",20);
        set_skill("parry",20);
        set_skill("dodge",20);
        set_skill("force", 20);
        set_skill("sword", 20);
        set("inquiry", ([
              "ˮ" : (: ask_water :),
              "ʳ��" : (:ask_food:),
        ]));
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        say(CYN"����Ц��˵������λ" + RANK_D->query_respect(ob)
             + "�����������ҵ����ա�\n"NOR);
}

string ask_water()
{
        object ob;
        object me;
        ob=this_object();
        me=this_player();
        if ((me->query("water")*10/me->max_water_capacity())>8)
                return "����ô�ȱ��˻���Ҫ��";
        if ( present("suanmei tang", this_player()))
                return "�Ⱥ������Ҹ������˵�ɡ�";
        if ( present("suanmei tang",  environment(me)) )
                return "�ǲ��������Ⱥ�������˵��";
        ob=new(FOOD_D("tang"));
        ob->move(environment(this_object()));
        return "�Ɑ�������ȵ���÷������ɣ��������Ӵ��";
}

string ask_food()
{
        object ob;
        object me;
        ob=this_object();
        me=this_player();
        if ((me->query("food")*10/me->max_water_capacity())>8)
                return "����ô�Ա��˻���Ҫ��";
        if ( present("zongzi", this_player()))
                return "�ȳ������Ҹ������˵�ɡ�";
        if ( present("zongzi",  environment(me)) )
                return "�ǲ��������ȳ�������˵��";
        ob=new(random(2)==1?FOOD_D("liji"):FOOD_D("mantou"));
        ob->move(environment(this_object()));
        return "���������ɣ����ҵ�������Σ�";
}
