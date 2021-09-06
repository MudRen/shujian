// zhao.c ��־��
// By Lgg,1998.10

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��־��", ({"zhao zhijing", "zhao"}));
        set("gender", "����");
        set("age", 26);
        set("class", "taoist");
        set("long",
                "������ȫ��̵����������еĺ��֣�����һ�Ĵ������־���� \n"
                "����ò��������ü����ƺ�������һ˿�ƻ�����ɫ��\n"
		"����һ��������ˣ�������ȴ��Щɷ����\n");
        set("attitude", "friendly");
        set("shen_type",-1);
        set("str", 25);
        set("int", 26);
        set("con", 26);
        set("dex", 25);

        set("qi", 1500);
        set("max_qi", 1500);
        set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 60);

        set("combat_exp", 160000);

        set_skill("force", 100);
        set_skill("xiantian-gong", 100);
        set_skill("sword", 100);
        set_skill("quanzhen-jianfa",100);
        set_skill("dodge", 70);
        set_skill("jinyan-gong", 70);
        set_skill("parry", 100);
        set_skill("strike",100);
        set_skill("haotian-zhang", 100);
        set_skill("literate", 60);
        set_skill("taoism", 60);      
        set_skill("tiangang-beidouzhen", 40);

        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 3, "����");

        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",          
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{     
        if (ob->query("gender")=="Ů��") {
                command("say �����ڵ�����֮������Ů�б��Ҷ���������һ����֪��ʵ����������ʦ����\n");
                return;
        }
     command("say �ðɣ��Ҿ����������ͽ���ˡ�");
     command("recruit " + ob->query("id"));
}