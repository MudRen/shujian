// liang.c ������
// Lklv 2001.9.28

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "bags_up.h"
int ask_xiaofeng();

#define QUESTDIR2 "quest/�����˲�/����Ӫ��ƪ/"
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"

void create()
{
	set_name("������", ({"liang zhanglao", "liang", "zhanglao"}));
	set("title", HIW"ؤ����ϯ����"NOR);
	set("gb/bags", 9);
	set("gender", "����");
	set("age", 55);
	set("long",
		"��������ؤ�������ã��书��ߵĳ��ϣ��������������Ѿá�\n"
		"ؤ���书������ǿ������������һ�����٣������������ϡ�\n");

	set("attitude", "peaceful");

	set("str", 28);
	set("int", 24);
	set("con", 24);
	set("dex", 25);

	set("qi", 4500);
	set("max_qi", 4500);
	set("jing", 4000);
	set("max_jing", 4000);
	set("eff_jingli", 3500);
	set("neili", 6000);
	set("max_neili", 5000);
	set("jiali", 120);

	set("combat_exp", 2500000);

	set_skill("force", 190);
	set_skill("huntian-qigong", 195);
	set_skill("strike", 185);
	set_skill("xianglong-zhang", 190);
	set_skill("dodge", 193);
	set_skill("xiaoyaoyou", 190);
	set_skill("parry", 180);
	set_skill("stick", 180);
	set_skill("dagou-bang", 180);
	set_skill("begging", 180);
	set_skill("checking", 190);

	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("parry", "xianglong-zhang");
	map_skill("stick", "dagou-bang");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("strike", "xianglong-zhang");

    	set("chat_msg_combat", ({
        	(: perform_action, "strike.xiao" :),
        	(: perform_action, "strike.paiyun" :),
        	(: exert_function, "huntian" :),
        }));

        set("inquiry", ([
                "ؤ��" : "����ؤ�������µ�һ��\n",
                "�Ƿ�" : "�����������壬���ǵ�ǰ�ΰ�����\n",
		            "����" : (: ask_xiaofeng :),
		            "���־���" : (: ask_xiaofeng :),
		            "ؤ������" : (: ask_xiaofeng :),
		            "���־��" : (: ask_xiaofeng :),
                "����" : (: ask_me :),
                "����" : (: ask_bag :),

        ]));

	create_family("ؤ��", 18, "��ϯ����");
	setup();

        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
	carry_object(__DIR__"obj/gb_budai9")->wear();
}

void attempt_apprentice(object ob)
{
        if (ob->query("family/family_name")
        && ob->query("family/family_name") != "ؤ��") {
                command("say �㻹��ȥ������ɿ����ɡ�");
                return;
	}
        if ((int)ob->query("gb/bags") >= 2
        && ob->query("family/family_name") != "ؤ��" ) {
                command("say ؤ����ݲ��������ֱ��������С�ˣ�����");
                command("kill "+ob->query("id"));
                return;
        }

        if((int)ob->query_skill("huntian-qigong",1) < 120){
           command("say ����������ؤ�����������Ĺ�����Դ����в�������\n");
           return;
	}
        command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
        "�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");

        command("recruit " + ob->query("id"));
        if (!ob->query("gb/bags")) ob->set("gb/bags", 1);
        ob->set("title",sprintf("ؤ���ܶ�%s������",
                chinese_number(ob->query("gb/bags"))) );
        ob->set("gb/fenduo","�ܶ�");
        ob->set("class","beggar");
}

void init()
{
        add_action("do_kill", "kill");
        add_action("do_kill", "tk");
        add_action("do_kill", "teamkill");
        add_action("do_kill", "hit");
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


        if (userp(ob) && ob->query("family/family_name") == "ؤ��") {
                if (me->query("family/family_name") == "ؤ��") {
	                message_vision(ob2->name()+"��$N�е������Ȼɱ�Լ���ͬ�ţ��������㣡"+ob->name()+"���ߣ�\n", me);
	                kill_ob(me);
                }
                else {
                        message_vision(ob2->name()+"��$N�ȵ����󵨣���Ȼ��������ǰ��Ұ��"+ob->name()+"���ߣ���������\n", me);
                        kill_ob(me);
                }
                return 1;
        }
        return 0;
}
int ask_xiaofeng()
{
	object me = this_player();
	if(me->query(QUESTDIR2+"over") && !me->query(QUESTDIR3+"start"))
	{
		if(!me->query_temp(QUESTDIR3+"ask"))
		{
			command("sigh");
	    message_vision(HIC"$N��Ĭ��һ���ˣ���������ʱ��������ʱ��ؤ���������϶��ڳ�������������������ʰɡ���\n"NOR,this_object());
	    me->set_temp(QUESTDIR3+"ask",1);
			return 1;
		}
		if(!me->query_temp(QUESTDIR3+"ask_chen"))
		{
			command("sigh");
	    message_vision(HIC"$N��Ĭ��һ���ˣ���������ʱ��������ʱ���³���Ҳ�ڣ�������������ʰɡ���\n"NOR,this_object());
			return 1;
		}
		if(!me->query_temp(QUESTDIR3+"ask_song"))
		{
			command("sigh");
	    message_vision(HIC"$N��Ĭ��һ���ˣ���������ʱ��������ʱ���γ��϶��ڳ���������������ʰɡ���\n"NOR,this_object());
			return 1;
		}
		if(!me->query_temp(QUESTDIR3+"ask_liang"))
		{
			command("sigh");
      me->set_temp(QUESTDIR3+"ask_liang",1);
      message_vision(HIC"$Nҡ��ҡͷ�������γ��ϲ����ף����кγ����á������壬��Ȼ�������ˣ�������Щ������ôһ�㼣��Ҳû�а�����\n"NOR,this_object());
      message_vision(HIC"$N���ĵ�������������Թ��ˣ�Ӣ���˵ã�����˭����������ڱ�������ˣ������Ȿ��Խ�󣬴���Խ��Σ�ա���\n"NOR,this_object());
			return 1;
		}
		command("sigh");
    message_vision(HIC"$N����һ�ٵ����������˵����ǣ��̫�࣬���˳�ȥ��ؤ���ڽ�������Ҳ̧����ͷ��������Ҫ�����ǲ���ȥ�ʱ��˰ɡ���\n"NOR,this_object(),me);
		return 1;
	}	
	if(me->query(QUESTDIR3+"start")&&!me->query(QUESTDIR3+"over"))
	{
		message_vision(HIC"$N����¶��һ��ҧ���гݵ����ӡ�\n"NOR,this_object());
    command("say �������������֣��������ú��ˣ���ʱ��δ����������������������²������ĳ��һ���������ˡ���"NOR);
		return 1;
	}	
	if(me->query(QUESTDIR3+"over"))
	{
		command("sigh");
		command("say ������Ҫ�ǻ������ǰ����ö��......"NOR);
		return 1;
	}	
	message_vision(HIC"$N��Ĭ��һ���ˣ�����������������ؤ�����ˡ���\n"NOR,this_object());
	return 1;
}
