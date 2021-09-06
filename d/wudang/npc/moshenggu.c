// moshenggu.c
// by ydh

inherit NPC;

string ask_me_1();

void create()
{
        set_name("Ī����", ({ "mo shenggu", "mo" }));
        set("nickname", "�䵱����");
        set("long", 
                "��������������ߵ���Ī���ȡ�\n"
                "��������ᣬ����Ŀ��࣬�����ܸɡ�\n");
        set("gender", "����");
        set("age", 22);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);
        
        set("max_qi", 1200);
        set("max_jing", 800);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);
        set("combat_exp", 100000);
        set("score", 50000);

        set_skill("force", 80);
        set_skill("yinyun-ziqi", 60);
        set_skill("dodge", 80);
        set_skill("tiyunzong", 60);
        set_skill("cuff", 80);
        set_skill("taiji-quan", 60);
        set_skill("parry", 80);
        set_skill("sword", 80);
        set_skill("taiji-jian", 70);
        set_skill("taoism", 80);
        set_skill("literate", 80);

        map_skill("force", "yinyun-ziqi");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");
        create_family("�䵱��", 2, "����");
        set("inquiry", ([
                "��ɽ" : (: ask_me_1 :),
        ]));

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

string ask_me_1()
{
	object me;

  me=this_player();
 if ( (int)me->query_skill("yinyun-ziqi", 1) < 20)
   {
    command("pat "+(string)me->query("id"));
    return "������δ�ɣ����Ǳ���ɽ�ĺã�\n";
   }
  if((int)me->query("wudang_given")) 
    { command("kick "+me->query("id"));
      return "�޵�֮�˵�����������ú÷�ʡ�ɣ�\n";
    }
    command("nod "+(string)me->query("id"));
    add_money("silver",(int)(me->query_skill("yinyun-ziqi", 1)) );
    command("give "+me->query("id")+" "+(int)(me->query_skill("yinyun-ziqi", 1))+" silver");
    me->set("wudang_given",1);
    return "����ɽ��Ҫ���������壬Ҫ��Ϊ���������ұ������Ż���\n";
}

