// ��ͷ��

inherit F_MASTER;
inherit NPC;

int ask_book();

void create()
{
	set_name("��ͷ��", ({ "pang toutuo","toutuo","pang" }));
	set("long","���ݵó��棬����Ƥ����ͷ��˫�����ݣ�������罩ʬһ�㣬�������磬\nͷ��һ��ͭ����ס���������ϴ������ۣ�������������ǹ����¼���һ�㣬\n���������̵Ļ�����\n");
	set("gender", "����");
	set("title", "�����̻���");	
	set("age", 40);       
	set("str", 40);
	set("int", 12);
	set("con", 22);
	set("dex", 22);
	set("per", 10);
	set("combat_exp", 700000);
	set("shen", -50000);
	set("attitude", "peaceful");
	set("max_qi",2500);
	set("max_jing",2500);
	set("neili",2000);
	set("max_neili",3000);
	set("jingli",2000);
       set("eff_jingli",2000);
	set("jiali",50);
	set("score", 20000);

	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry",120);
	set_skill("strike",120);
	set_skill("leg",150);
	set_skill("hook",180);
	set_skill("shenlong-tuifa",150);
	set_skill("canglang-goufa",180);
	set_skill("huagu-mianzhang", 120);
	set_skill("youlong-shenfa",120);
	set_skill("dulong-dafa",120);
      
	map_skill("force", "dulong-dafa");
	map_skill("dodge", "youlong-shenfa");
       map_skill("strike", "huagu-mianzhang");
       map_skill("hook","canglang-goufa");
	map_skill("leg","shenlong-tuifa");
	map_skill("parry","huagu-mianzhang");

	prepare_skill("leg","shenlong-tuifa");

	set("inquiry", ([
		"��������" : (: ask_book :),
		"book" : (: ask_book :),
	]) );
         set("chat_chance", 3);
        set("chat_msg", ({
                "��ͷ��˵������ϧ����������Ȼ���������Ǹ��ط�������û��˭��ȥ�һ���������\n",
        }) );

      create_family("������",2, "����");
      setup();
      carry_object(__DIR__"obj/bupao")->wear(); 
      carry_object(__DIR__"obj/hook")->wield();    
}

int ask_book()
{
	object book;
	mapping myfam;
	object me=this_player();

	myfam = (mapping)me->query("family");
	if(!myfam || myfam["family_name"] != "������")
		return 0;

	book= unew(__DIR__"obj/hook-book");
	if (!book)  
	{
		command("say ���������Ѿ������������ˣ�");
		return 1;
	}

	command("say �ðɣ��Ȿ������������"+me->query("name")+"�����ȥ�úÿ����ɡ�");
	book->move(me);      
        me->start_busy(2);

	return 1;
}

int prevent_learn(object me, string skill)
{
	return 0;
}

int recognize_apprentice(object ob)
{
	mapping myfam;
	object hw;

	myfam = (mapping)ob->query("family");
	if(myfam && (myfam["family_name"] == "������")&&(ob->query("shen",1) >0))  {
		command("say �ߣ��㾹Ȼ�ҺͰ׵����˸���һ���ǲ��ǲ�����ˣ���ȥ���ݺú÷�ʡ��ʡ�ɣ�");
		if(!objectp(hw=find_object("/d/sld/npc/obj/heiwu")))
			hw=load_object("/d/sld/npc/obj/heiwu");
		ob->set("in_heiwu",time());
		ob->move(hw);        
		return 0;
	}
       if(myfam && (myfam["family_name"] == "������")&&(ob->query("shen",1) < -30000)
          && (ob->query_skill("dulong-dafa",1)>=100) && 
          (ob->query_skill("huagu-mianzhang",1)>=100))
        {
             return 1;
        }
    	return 0;
}
