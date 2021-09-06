#include <ansi.h>
inherit NPC;

int ask_job();
int ask_lineup();

void create()
{
        set_name("��Ӣ", ({"cheng ying", "cheng", "ying"}) );
        set("long", "���ǻ�ҩʦ�����յĵ��ӣ�����������\n");
        set("gender", "Ů��" );
        set("age", 20);
        set("attitude", "friendly");
        set("apprentice",1);
        set("str",30);
        set("int",30);
        set("con",28);
        set("dex",30);
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
//        prepare_skill("strike", "luoying-zhang");
        prepare_skill("leg", "xuanfeng-tui");

        set("inquiry", ([
                "�س�": (: ask_job :),
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

int ask_job()
{
       object me = this_player();
       if (!me->query_temp("xy/job"))
       {
               command("say �������������ʾ��");
               return 1;
       }
      if (me->query("family/family_name") != "�һ���")
      {
               command("say ���ȥָ���ĵص�ɣ������ɹű���Ҫ�����ˣ�");
               return 1;
      }
      command("say ��С�İ���");
      command("say �����󷨾�֪ͨ����һ�¡�");
      command("smile");
      me->set_temp("xy/job",2);
      return 1;
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
