#include <ansi.h>
inherit NPC;
//inherit F_MASTER;

void create()
{
        set_name("������", ({"liu chuxuan", "liu"}));
        set("gender", "����");
        set("age", 38);
        set("class", "taoist");
        set("nickname",WHT"������"NOR);
        set("long",
                "������ȫ����ͽ�����������ˣ��������С�������μ�����һ\n"
                "���������š�\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 30);
        set("int", 30);
        set("con", 28);
        set("dex", 30);

        set("title","ȫ������֮��");


        set("qi", 4400);
        set("max_qi", 4400);
        set("jing", 2200);
        set("max_jing", 2200);
        set("neili", 4600);
        set("max_neili", 4600);
        set("jiali", 100);
        set("level", 15);
        set("combat_exp", 850000);

        set_skill("force", 160);
        set_skill("xiantian-gong", 160);
        set_skill("sword", 160);
        set_skill("quanzhen-jianfa",160);
        set_skill("dodge", 140);
        set_skill("jinyan-gong", 140);
        set_skill("parry", 150);
        set_skill("literate", 100);
        set_skill("strike", 150);
        set_skill("haotian-zhang", 150);
        set_skill("tiangang-beidouzhen", 80);
	      set_skill("taoism",120);

        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike","haotian-zhang");

        create_family("ȫ���", 2, "����");

        set("inquiry", ([

        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}
/*
void attempt_apprentice(object ob)
{

        if ((int)ob->query_skill("xiantian-gong",1) < 70 )
        {
                command("say ��ı����ڹ��ķ������,�������Ը�������书��");
                return;
        }
        if ((int)ob->query("shen") < 6000)
        {
                command("say ����һЩ���������������˵�ɣ���\n");
                return;
        }
        command("say �ðɣ��Ҿ����������ͽ���ˡ�");
        command("recruit " + ob->query("id"));
}
*/

