// zhou.c �ܵ�
// Modify By River@sj 99.06
// Modify by Looklove@sj 2000/9/30



#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_blade();
void create()
{
        object weapon;
        set_name("�ܵ�", ({ "zhou dian","zhou","dian" }) );
        set("title", "������ɢ��");
        
        set("gender", "����");
        set("age",52);
        set("long", "������������ɢ��֮һ���ܵߡ�\n");
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("shen_type",0);
        set("combat_exp", 600000);
        set("unique", 1);

        set_skill("blade",80);
        set_skill("force",80);
        set_skill("dodge",80);
        set_skill("hand", 80);
	set_skill("parry", 80);
        set_skill("piaoyi-shenfa",85);
        set_skill("shenghuo-shengong",85);
        set_skill("lieyan-dao",85);
        set_skill("suohou-shou",85);
        map_skill("hand","suohou-shou");
        map_skill("force","shenghuo-shengong");
        map_skill("dodge","piaoyi-shenfa");
        map_skill("blade","lieyan-dao");
        map_skill("parry","lieyan-dao");
        prepare_skill("hand","suohou-shou");

        create_family("����",36,"ɢ��");

        set("max_qi",1500);
        set("max_jing",1200);
        set("jiali",50);
        set("eff_jingli",1100);
        set("inquiry", ([
                "�赶"     : (: ask_blade :),
                "���浶" : "�����ҵ�������������ã����Խ���㡣\n",
                ]));
        setup();

        carry_object("/d/mingjiao/obj/yel-cloth")->wear();
        if (clonep()){
                weapon = unew(BINGQI_D("blade/qingyan-dao"));
                if(!weapon) weapon=new(BINGQI_D("blade"));
                weapon->move(this_object());
                weapon->wield();
        }
}

void init()
{
	::init();
        add_action("do_kill", "kill");
        add_action("do_kill", "tk");
        add_action("do_kill", "teamkill");
        add_action("do_kill", "hit");
}
string ask_blade()
{ 
        object blade,me,ob;
        me = this_player(); 
        ob = this_object();

        if ( me->query("combat_exp") < 100000 )
        return RANK_D->query_respect(me)+"�Ĺ���̫�����㣬����Ҳ����ס������";
        if ( present("qingyan dao", me)|| me->query_temp("qydao"))
                return RANK_D->query_respect(this_player()) + 
                "��ֻ��һ�ѣ��Ѿ����������";
        if ( blade=present("qingyan dao", ob))
        command("give qingyan dao to "+me->query("id"));
        if(!objectp(blade))   blade = unew(BINGQI_D("blade/qingyan-dao"));
        if(!objectp(blade))   return "��Ǹ��������浶���Ѿ���������ˡ�"; 

        blade->move(me);
        blade = unew(BINGQI_D("blade"));
        blade->move(this_object());
        me->set_temp("qydao",1);
        command("wield dao"); 
        return "��Ҷ��ǽ���ͬ������������,������ȥ�á�";
         
}

int do_kill(string arg)
{
        object ob,ob2; 
        object me = this_player();
        ob2 = this_object();

        if (!arg) return 0;
        ob = present(arg, environment(me));
        if (ob == this_object() || ob == me) return 0;
        if (!ob || !ob->is_character()) return 0;

        
        if (userp(ob) && ob->query("family/family_name") == "����") {
                if (me->query("family/family_name") == "����") { 
        message_vision(ob2->name()+"��$N�ȵ�����Ϊ���̵��ӣ���Ȼɱ�Լ���ͬ�ţ��������㣡\n", me);
                }
                else {
                        message_vision(ob2->name()+"��$N�ȵ����󵨿�ͽ����Ȼ����������Ұ��\n", me);
                        kill_ob(me);
                }
                me->set("vendetta/����", 1);
                return 1;
        }
        return 0;
}


#include "5san_app.h";

