// yinliting.c����ͤ
// by ydh

inherit NPC;

int ask_me_1(string);

void create()
{
        set_name("����ͤ", ({ "yin liting", "yin" }));
        set("nickname", "�䵱����");
        set("long", 
                "�����������������������ͤ��\n"
                "����һ���˲ţ��Ҿ����䵱�������������Խ�����\n");
        set("gender", "����");
        set("age", 28);
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
        set_skill("taiji-jian", 90);
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
                "����ܽ" : (: ask_me_1 :),
        ]));

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

int ask_me_1(object who)
{ object me;
  me=this_player();
  command("blush "+(string)me->query("id"));
  command("say ��Ȼ���Ǽ͹��������,�Ǿ͸����и������!\n");
  message_vision("����ͤһ����,��$N�ý���СԺ��\n",me);
  me->move("/d/wudang/xiaoyuan");
  return 1;
}

