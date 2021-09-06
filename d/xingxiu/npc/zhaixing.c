// zhaixing.c ժ����
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_job();

void create()
{
	set_name("ժ����", ({ "zhaixing zi", "zhaixing", "zi" }));
	set("nickname", "�����ɴ�ʦ��");
	set("long", "һ����ʮ�߰���İ��������ˡ�����ĸ��ݣ���ɫ���з��ƣ���Ŀȴ��Ӣ����\n");
	set("gender", "����");
	set("age", 27);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 24);
        set("con", 23);
        set("dex", 30);
        set("per", 24);

        set("max_qi", 3500);
        set("max_jing", 3000);
        set("eff_jingli", 2500);
        set("combat_exp", 1800000);
        set("shen", -18000);

    	set_skill("force", 190);
    	set_skill("huagong-dafa", 190);
    	set_skill("dodge", 190);
    	set_skill("zhaixingshu", 200);
    	set_skill("strike", 190);
    	set_skill("chousui-zhang", 190);
    	set_skill("poison", 190);
    	set_skill("parry", 190);
    	set_skill("staff", 190);
    	set_skill("tianshan-zhang", 170);
    	set_skill("literate", 120);
    	set_skill("claw", 190);
    	set_skill("sanyin-zhua", 190);

    	map_skill("force", "huagong-dafa");
    	map_skill("dodge", "zhaixingshu");
    	map_skill("strike", "chousui-zhang");
    	map_skill("parry", "chousui-zhang");
    	map_skill("staff", "tianshan-zhang");
    	map_skill("claw", "sanyin-zhua");
    	prepare_skill("claw", "sanyin-zhua");
    	prepare_skill("strike", "chousui-zhang");

    	set("chat_chance_combat", 15);
    	set("chat_msg_combat", ({
                (: exert_function, "huagong" :),
                (: perform_action, "strike.huoqiu" :),
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
    	carry_object("/d/xingxiu/obj/yao");
    	carry_object("/d/xingxiu/obj/yao1");
    	carry_object("/d/xingxiu/obj/yao3");
    	add_money("silver", 60);
}
void attempt_apprentice(object ob)
{
	if(ob->query("family/family_name") != "������"){
        	say("ժ���Ӷ�"+ob->name()+"������\n");
        	return;
        }
     	if(ob->query_skill("huagong-dafa",1) < 145 || ob->query("shen") > -50000){
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
    	if(exp < 700000)
    		return "�����������ټӰ��������ɡ�";
        if(exp >= 1000000 )
    		return "�������������Ҳ�̫��������Լ�ȥ���������˼Ұɡ�";
	if( me->query("job_name") == "���ɷ���")
		return "�����������黹�ã���������Ϊ���ɷ��ǡ�";
    	if(me->query_condition("wait_xx_task"))
    		return "�ϴθ����ˣ������͵ȵȰɡ�";
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
