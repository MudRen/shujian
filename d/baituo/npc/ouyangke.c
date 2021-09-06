// ouyangke.c

#include <ansi.h>

//inherit F_MASTER;
inherit NPC;

void greeting(object ob);

void create()
{
	seteuid(getuid());
	set_name("ŷ����", ({ "ouyang ke", "ouyang", "ke" }));
	set("long", "��һ��Ʈ�ݵİ�ɫ��������ҡ���ȣ��������š�\n");
	set("title", HIG"ŷ��������ׯ��"NOR);
        set("nickname",HIM"��������"NOR);
	set("gender", "����");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 25);
	set("int", 29);
	set("con", 25);
	set("dex", 26);

	set("qi", 1700);
	set("max_qi", 1700);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);

	set("combat_exp", 300000);

        set_skill("cuff",  180);
	set_skill("dodge", 120);
	set_skill("parry", 140);
	set_skill("force", 130);
	set_skill("staff", 100);
	set_skill("hamagong",200);
	set_skill("lingshe-zhangfa", 130);
        set_skill("lingshe-quanfa", 180);
  set_skill("poison", 180);
  set_skill("hamabu", 100);
  set_skill("hand", 120);
	set_skill("staff", 150);
	set_skill("jingmai-xue", 150);
  set_skill("literate", 150);

	map_skill("force", "hamagong");
	map_skill("dodge", "hamabu");
	map_skill("staff",  "lingshe-zhangfa");
        map_skill("parry", "lingshe-quanfa");
  map_skill("cuff", "lingshe-quanfa");
  prepare_skill("cuff", "lingshe-quanfa");

        create_family("ŷ������", 2, "����");

	set("inquiry", ([
		"ŷ����" : "�������常��",
		"��ʬ��" : "��ֻ��һ�ݻ�ʬ�ۣ����ܸ��㡣������Ҫ�Ǹ���һ��ʬ�壬�ҿ��Ը�����Щ��",
	]));

	set("chat_chance", 2);
	set("chat_msg", ({
		"ŷ���˳�����Ư���������������������Ҷ࿴��һ�ۣ���\n",
		"ŷ����ɫ���Եؿ��Žֱߵ�С���\n",
		"ŷ���˰�ֽ��һչ��ת����ȥ�����������������֪�����ѵã�\n",
	}) );

	set("master_ob",3);
	setup();
	carry_object("/clone/armor/changpao")->wear();
	add_money("gold",10);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) 
        {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	if ((string)ob->query("gender")=="Ů��")
	{
                if (ob->query("per") < 22)
                        return;

                if (ob->query("sex/ŷ����"))
                {
                        command("kiss " + ob->query("id"));
                        command("say ��ô����Ҫ��Ҫ�������ΰ�... ������");
                } else
        	switch(random(3))
        	{
        	case 0: command("rose "+(string)ob->query("id"));break;
        	case 1: command("kiss "+(string)ob->query("id"));break;
        	case 2: command("love "+(string)ob->query("id"));break;
        	}
     
	}
	else
                say("ŷ����̾��һ����˵����λ"+RANK_D->query_respect(ob)+
                        "����Ҫ���ܸ���Ūһ��Ů�����ͺ��ˡ�\n");
	return;
}
/*
void attempt_apprentice(object ob)
{
     if(ob->query_skill("hamagong",1) < 160 ||
      ob->query_skill("shexing-diaoshou",1) < 160 ||
        ob->query_skill("lingshe-zhangfa",1) < 160){
        command("say ������㹦��");
        return 0;
        }
     command("say ���㻹�����𣬾��������,��˵�ҵ�������ŷ�������ѧ���������Ĺ���");
     command("recruit " + ob->query("id"));
          ob->set("title",HIW"����ɽŷ�����Ҽҳ�"NOR);
}
*/
int accept_fight(object ob)
{
	if ((string)ob->query("gender") == "Ů��")
	{
		message_vision("ŷ���˰ڰ���˵������λ"+RANK_D->query_respect(ob)+
		"���������۸�Ů�����أ�\n", ob);
		return 0;
        }

        return ::accept_fight(ob);
}
 


