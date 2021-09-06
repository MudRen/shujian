#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����ʹ��", ({ "shi zhe", "zhe",}));
        set("long", "����ͷ�����ź�ɫͷ�֣�������������ò��\n"+
        	    "���ɽ������ֵ��̳����ĸ��֣������Ž�̳��������\n");
        set("title",HIY"�������  "HIM"����"NOR);
        set("gender", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
        set("max_qi", 3000);
        set("eff_qi", 3000);
        set("qi", 3000);
        set("max_jing", 2000);
        set("jing", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 50);
        set("combat_exp", 1500000);

        set_skill("parry",200);
        set_skill("dodge",200);
        set_skill("force",200);
        set_skill("strike",200);
        set_skill("literate", 120);
        set_skill("blade",200);
        set_skill("tianmo-dao",200);
        set_skill("tianmo-zhang",200);
        set_skill("tianmo-jian",200);
        set_skill("tianmo-dao",200);
        set_skill("ding-dodge",200);
        set_skill("tianmo-gong",200);

        map_skill("strike", "tianmo-zhang");
        map_skill("sword", "tianmo-jian");
        map_skill("parry", "tianmo-jian");
        map_skill("blade", "tianmo-dao");
        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmo-gong");
        prepare_skill("strike", "tianmo-zhang");
        create_family("�������",10,"����");
        setup();

	set("chat_chance", 2);
        set("chat_msg", ({
              "����ʹ�߸���˵������������ּӢ���������Ųߡ���\n",
              "����ʹ��˵����������ǧ�����أ�һͳ��������\n",
              "����ʹ�߸߽е����������ĳ���£�����Ӣ��������ʥ�̣��󱻲�������\n",
        }));
        if (random(2))
        	carry_object(BINGQI_D("sword"))->wield();
        else
        	carry_object(BINGQI_D("blade"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
	object me, ob;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& !present("heimu ling", ob)){
		if( !ob->query_temp("warned") ) {
			command("say ����˭��  ��ô����������������ˣ���");
			command("say ����������뿪���´ο����������ģ�");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
			command("say �󵨿�ͽ�����Ҵ����������������Ұ������\n");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       
}
