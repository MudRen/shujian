
#include <ansi.h>
inherit NPC;
mapping *names =({
              ({"��ɰ�ﳤ��","�޾��ﳤ��","�����ﳤ��",
                "��ȭ�ų���","���½̳���",
               }),
               });

void create()
{
      string weapon,t_name;
        t_name=names[0][random(sizeof(names[0]))];
        set_name(t_name, ({ "zhanglao"}));
        set("gender", "����");
        set("age", random(10) + 45);
        set("str", 28);
        set("con", 23);
        set("int", 15);
        set("dex", 20);
        set("long", "а�̵ĳ��ϡ�\n");
        set("combat_exp", 60000 + random(25000));
        set("attitude", "friendly");

        set_skill("force", 40);
        set_skill("sword", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("cuff", 40);
        set_skill("blade", 40);
        set_skill("taizu-quan", 50);
        set_skill("qingmang-jianfa", 50);
        map_skill("dodge", "qingmang-jianfa");
        map_skill("sword", "qingmang-jianfa");
        map_skill("parry", "qingmang-jianfa");
        map_skill("cuff", "taizu-quan");
        prepare_skill("cuff", "taizu-quan");

        set("max_qi", 300);
        set("eff_jingli", 300);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);

        weapon = random(2)?"/clone/weapon/changjian":"/clone/weapon/blade";
        setup();
        carry_object(weapon)->wield();
        carry_object("/d/city/obj/junfu")->wear();
}

void init()
{
        int a;
        object ob, me;
        ob = this_object();
        me = this_player();
      if(me->query_temp("gb_rob")){
        a = me->query_temp("j")-1;
        if(a < 2) a=2;
        message_vision(HIR"ͻȻ��·�ߴܳ�һ��$N��ŭ��һ��������������\n"NOR, ob, me);
        me->add_temp("xietu", 1);
        ob->set("combat_exp", ob->query("combat_exp")*a);
        ob->set_skill("force", 40+(10*a));
        ob->set_skill("sword", 40+(10*a));
        ob->set_skill("blade", 40+(10*a));
        ob->set_skill("dodge", 40+(10*a));
        ob->set_skill("parry", 40+(10*a));
        ob->set_skill("qingmang-jian", 40+(10*a));
        ob->set_skill("taizu-quan", 40+(10*a));
        if(present("blade", ob))
          ob->map_skill("blade", "qingmang-jian");
        ob->set("max_qi", 300+(50*a));
        ob->set("eff_jingli", 300+(50*a));
        ob->set("neili", 300+(50*a));
        ob->set("max_neili", 300+(50*a));
        ob->set("jiali", 20);
        ob->reincarnate();
        ob->kill_ob(me);
        call_out("checking", 3, me);
        }
        remove_call_out("do_back");
        call_out("do_back", 300,  me);
}
int checking(object me)
{
        if (me->is_fighting())
 	{
	call_out("checking", 2, me);
        return 1;
	}
        remove_call_out("do_back");
  	call_out("do_back", 5, me);
	return 1;
}
void do_back(object me)
{
  tell_room(environment(me), me->query("name")+"ת��������Ͳ����ˡ�\n", ({me}));
  destruct(me);
  return;
}
void unconcious()
{
      command("escape");
      do_back(this_object());
}
void die(){ do_back(this_object()); }