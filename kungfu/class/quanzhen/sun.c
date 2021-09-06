// sun.c �ﲻ��

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�ﲻ��", ({"sun buer", "sun"}));
        set("gender", "Ů��");
        set("age", 33);
        set("class", "taoist");
        set("nickname",CYN"�徻ɢ��"NOR);
        set("long",
                "������ȫ��̶���������Ψһ��Ů�����ﲻ�������ˡ�������\n"
                "�������ǰ�����ӣ�����������һ������ͷ��\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 30);
        set("int", 29);
        set("con", 29);
        set("dex", 29);

        set("title","ȫ������֮ĩ");

        set("qi", 3700);
        set("max_qi", 3700);
        set("jing", 1800);
        set("max_jing", 1800);
        set("neili", 4100);
        set("max_neili", 4100);
        set("jiali", 100);

        set("combat_exp", 660000);

        set_skill("force", 280);
        set_skill("xiantian-gong", 220);
        set_skill("sword", 220);
        set_skill("quanzhen-jianfa",220);
        set_skill("dodge", 250);
        set_skill("jinyan-gong", 250);
        set_skill("parry", 250);
        set_skill("strike", 250);
        set_skill("haotian-zhang", 250);
        set_skill("literate",200);
        set_skill("taoism",200);
	      set_skill("tiangang-beidouzhen", 250);
	
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

void attempt_apprentice(object ob)
{

        if (ob->query("gender")=="����") {
                command("say �Ҳ�����ͽ���㻹��ȥ���Ҽ�λʦ��Ϊʦ�ɡ�\n");
                return;
        }
        if ((int)ob->query_skill("xiantian-gong",1) < 50 )
        {
                command("say ��ı����ڹ��ķ������,�������Ը�������书��");
                return;
        }
        if ((int)ob->query("shen") < 6000)
        {
                command("say �ҿ��㻹�Ƕ���һЩ����֮�°ɡ�\n");
                return;
        }
        command("say �ðɣ��Ҿ����������ͽ���ˡ�");
        command("recruit " + ob->query("id"));
}

