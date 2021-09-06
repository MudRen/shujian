// tianlang.c ������
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_job();

void create()
{
        set_name("������", ({ "tianlang zi", "tianlang", "zi" }));
        set("nickname", "��������ʦ��");
        set("long", "һ��ò���Һ���ʵʮ�ֽ��������ӡ�\n");
	set("gender", "����");
        set("age", 30);
        set("attitude", "peaceful");
        set("str", 35);
        set("int", 16);
        set("con", 25);
        set("dex", 22);
        set("max_qi", 2500);
        set("max_jing", 2300);
        set("eff_jingli", 1900);
        set("combat_exp", 1100000);
        set("shen", -11000);

    	set_skill("force", 150);
    	set_skill("huagong-dafa", 150);
    	set_skill("dodge", 150);
    	set_skill("zhaixingshu", 150);
    	set_skill("strike", 150);
    	set_skill("chousui-zhang", 150);
    	set_skill("parry", 150);
    	set_skill("staff", 150);
    	set_skill("tianshan-zhang", 150);
    	set_skill("literate", 50);
    	set_skill("poison", 150);
     	map_skill("force", "huagong-dafa");
     	map_skill("dodge", "zhaixingshu");
     	map_skill("strike", "chousui-zhang");
     	map_skill("parry", "tianshan-zhang");
     	map_skill("staff", "tianshan-zhang");
     	prepare_skill("strike", "chousui-zhang");

      	set("chat_chance_combat", 5);
      	set("chat_msg_combat", ({
                (: exert_function, "huagong" :),
                (: perform_action, "strike.yinhuo" :),
                (: perform_action, "strike.biyan" :),
      	}));
      	create_family("������", 2, "����");
      	set("inquiry", ([
                "������" : "������룬�Ͱ���Ϊʦ��",
                "���޺�" : "ȥ���޺���ʲô������Ϊʦ�͹���ѧ���ˡ�",
                "������" : "����������е���û��ûС�ġ��Ժ�����ɣ�",
                "����" : (: ask_job :),
      	]));

        setup();
        UPDATE_D->get_cloth(this_object());
        carry_object("/d/xingxiu/obj/yao3");
        carry_object("/d/xingxiu/obj/yao1");
        carry_object("/d/xingxiu/obj/fire");
        carry_object(BINGQI_D("gangzhang"))->wield();
}

void attempt_apprentice(object ob)
{
   	if(ob->query("family/family_name") != "������"){
        	say("�����Ӷ�"+ob->name()+"������\n");
        	return;
        }
   	if(ob->query_skill("huagong-dafa",1) < 100 || ob->query("shen") > -5000){
       		command("say ����������������ҲŲ��������ء�");
       		return;
       	}
   	command("say �ðɣ�������Ļ������е�����ˣ��Ҿ�������ɡ�");
   	command("recruit " + ob->query("id"));
}

string ask_job()
{
  	object me, ob;
  	mapping fam;
  	int shen, exp;
  	me = this_player();
  	fam = (mapping)me->query("family");
  	shen = me->query("shen");
  	exp=me->query("combat_exp",1);

    	if(!fam) return "���ó��������̬�ȹ������β��������������أ�";
    	if(fam["family_name"] != "������" && !me->query_temp("ding_flatter"))
       		return "������ɵ�̬�ȿ���ȥ��̫��������";
    	if(exp < 400000)
    		return "�����������ټӰ��������ɡ�";
    	if(exp >= 700000)
    		return "�������������Ҳ�̫��������Լ�ȥ���������˼Ұɡ�";
    	if(me->query_condition("wait_xx_task"))
    		return "�ϴθ����ˣ������͵ȵȰɡ�";
	if( me->query("job_name") == "���ɷ���")
		return "�����������黹�ã���������Ϊ���ɷ��ǡ�";
    	if( me->query_temp("xx_job"))
    		return "����ô�������﷢����";
    	if( me->query_condition("wait_xx_task"))
    		return "�����������黹�ã���������Ϊ�����ǡ�";
    	ob = new("/d/xingxiu/obj/di");
    	ob->move(me);
    	ob->set("name", MAG "����̵�" NOR);
    	ob->set("long", MAG"����Ѷ̵ó��棬ֻ�����ߴ�������ͨ���Ϻ죬��Ө�ɰ���\n" NOR);
    	ob->set("xx_user", getuid(me));
    	if(fam["family_name"] != "������")
      		me->set_temp("title", MAG"�������ſ�"NOR);
    	me->set_temp("xx_job", 1);
    	message_vision("\n$N�ó�һֻ���ƶ̵ѣ�����$n��\n", this_object(), me);
    	return "����������鲻�ѣ����Ҫ���Ϊ�����˼ҷ��ǲ��ǣ�\n";
}
