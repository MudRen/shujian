// hao.c �´�ͨ
#include <ansi.h>
inherit NPC;
//inherit F_MASTER;

void create()
{
        set_name("�´�ͨ", ({"hao datong", "hao"}));
        set("gender", "����");
        set("age", 34);
        set("class", "taoist");
        set("nickname",HIG"������"NOR);
        set("long",
                "������ȫ�������еĺ´�ͨ�����ˡ������΢�֣��������ģ\n"
                "�������ϴ��ĵ���˫����ޡ�\n" );
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 30);
        set("int", 29);
        set("con", 29);
        set("dex", 29);

        set("title","ȫ������֮��");

        set("qi", 4200);
        set("max_qi", 4200);
        set("jing", 2100);
        set("max_jing", 2100);
        set("neili", 4400);
        set("max_neili", 4400);
        set("jiali", 100);
        set("level", 12);
        set("combat_exp", 680000);

        set_skill("force", 150);
        set_skill("xiantian-gong", 150);
        set_skill("sword", 130);
        set_skill("quanzhen-jianfa",130);
        set_skill("dodge", 110);
        set_skill("jinyan-gong", 120);
        set_skill("parry", 140);
        set_skill("literate",100);
        set_skill("strike", 150);
        set_skill("haotian-zhang", 150);
        set_skill("taoism",100);
        set_skill("tiangang-beidouzhen", 120);
	
        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike","haotian-zhang");

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
        if ((int)ob->query_skill("xiantian-gong",1) < 50 )
        {
                command("say ��ı����ڹ��ķ������,�������Ը�������书��");
                return;
        }
        if ((int)ob->query("shen") < 5000)
        {
                command("say �����������������������̫�٣�\n");
                return;
        }
        command("say �ðɣ��Ҿ����������ͽ���ˡ�");
        command("recruit " + ob->query("id"));
}
*/