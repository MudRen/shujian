#include <ansi.h>
inherit NPC;
int ask_lineup();
void create()
{
        set_name("�����", ({"wu tianfeng", "wu", "tianfeng"}) );
        set("long", "���ǻ�ҩʦ��С���ӣ�����Ϊ�����澭�¼�����ҩʦ����һ�����\n");
        set("gender", "����" );
        set("age", 35);
        set("attitude", "friendly");
        set("apprentice",1);
        set("str",30);
        set("int",30);
        set("con",28);
        set("dex",15);
        set("max_qi", 5000);
        set("max_jing", 5000);
        set("eff_jingli", 5000);
        set("neili", 5400);
        set("max_neili", 5400);
        set("jiali", 80);
        set("combat_exp", 1000000);


        set_skill("force", 180);
        set_skill("bihai-chaosheng", 180);
        set_skill("qimen-baguazhen",200);
        set_skill("dodge", 180);
        set_skill("suibo-zhuliu", 180);
        set_skill("parry", 180);
        set_skill("strike", 180);
        set_skill("luoying-zhang", 180);
        set_skill("leg", 180);
        set_skill("xuanfeng-tui", 180);
        set_skill("sword", 180);
        set_skill("yuxiao-jian", 180);
        set_skill("taoism", 180);
        set_skill("literate", 180);
        set_skill("qimen-bagua", 200);
        set_skill("qimen-baguazhen", 200);

        map_skill("force", "bihai-chaosheng");
        map_skill("dodge", "suibo-zhuliu");
        map_skill("strike", "luoying-zhang");
        map_skill("leg", "xuanfeng-tui");
        map_skill("parry", "yuxiao-jian");
        map_skill("sword", "yuxiao-jian");
        prepare_skill("strike", "luoying-zhang");

        set("inquiry", ([
                "����": (: ask_lineup :),
        ]) );

        set("shen_type", 1);
        set("shen", 100);
        create_family("�һ���", 2, "����");
        set("class", "fighter");
        setup();

        carry_object("/d/city/npc/obj/yuxiao.c")->wield();
        carry_object("/d/thd/obj/grn-cloth.c")->wear();
}

int ask_lineup()
{
      object me = this_player();
      if (me->query_temp("xy/job")!=2)
      {
              command("?");
              return 1;
      }
      command("nod");
      command("lineup with " + me->query("id"));
      return 1;
}

