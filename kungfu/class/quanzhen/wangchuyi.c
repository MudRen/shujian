#include <ansi.h>
inherit NPC;
//inherit F_MASTER;

void create()
{
        set_name("����һ", ({"wang chuyi", "wang"}));
        set("gender", "����");
        set("age", 35);
        set("class", "taoist");
        set("nickname",RED"������"NOR);
        set("long",
                "������ȫ������֮������һ�����ˡ�������޳����������࣬\n"
                "��縺���Ʈ����ǰ����̬������\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 32);
        set("int", 30);
        set("con", 32);
        set("dex", 30);

        set("title","ȫ������֮��");

        set("qi", 4200);
        set("max_qi", 4200);
        set("jing", 2100);
        set("max_jing", 2100);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 100);

        set("combat_exp", 1200000);

        set_skill("force", 170);
        set_skill("xiantian-gong", 170);
        set_skill("sword", 160);
        set_skill("quanzhen-jianfa",160);
        set_skill("dodge", 150);
        set_skill("jinyan-gong", 150);
        set_skill("parry", 170);
        set_skill("strike", 170);
        set_skill("haotian-zhang", 170);
        set_skill("literate",100);
        set_skill("taoism",100);
	      set_skill("medicine", 180);
	      set_skill("cuff",150);
        set_skill("tiangang-beidouzhen",150);

	
        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("finger", "zhongnan-zhi");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 2, "����");

        set("book_count",1);
        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}
/*
void attempt_apprentice(object ob)
{     
	    if ((int)ob->query_skill("xiantian-gong",1) < 100 )
        {
                command("say ��ı����ڹ��ķ�����㣬�������Ը�������书��");
                return;
        }
        if ((int)ob->query("shen") < 50000)
        {
                command("say �ҿ��㻹�Ƕ���һЩ����֮�°ɡ�\n");
                return;
        }
     command("say �ðɣ��Ҿ����������ͽ���ˡ�");
     command("recruit " + ob->query("id"));
}
*/


