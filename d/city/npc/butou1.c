// butou

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��ͷ", ({"bu tou","bu"}));
        set("long",
                "һλ�������ݵĲ�ͷ����Ĳ��ߣ�������������\n"
                "��˵��������Ĳݿܶ��������֡�\n"
        );
        set("nickname", "������");
        set("gender", "����");
        set("attitude", "peaceful");
        
        set("age", 35);
        set("shen", 2000);
          set("str", 45);
        set("int", 20);
        set("con", 30);
        set("dex", 35);
        set("max_qi", 1500);
        set("max_jing", 1600);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 120);
          set("combat_exp", 450000);
 
        set_skill("force", 140);
	set_skill("blade",140);
	set_skill("cuff",140);
	set_skill("taizu-quan",140);
        set_skill("shenghuo-shengong", 140);
        set_skill("dodge", 140);
        set_skill("tiyunzong", 140);
        set_skill("parry", 140);
        
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("parry", "taizu-quan");
        map_skill("cuff", "taizu-quan");
       prepare_skill("cuff", "taizu-quan");

        setup();
        carry_object("/clone/armor/armor")->wear();
}

void init()
{
        object me, ob;
        ::init();

        ob = this_player();
        me = this_object();
        
        if (interactive(ob) 
        && !environment(ob)->query("no_fight")
          && (int)ob->query("PKS",1) >40 )
        {
 
         command("say ��˵��������˲��ٰ��ӣ�����ײ�����٣��ͺ�����һ�˰ɡ�\n");
         ob->start_busy(2);
         me->set_leader(ob);
         remove_call_out("kill_ob");
         call_out("kill_ob", 1, ob); 

		 
        }       
}
 
int accept_fight(object me)
{
       command("say  ���ٹ�������ûʱ�������档");
       return 0;
}

