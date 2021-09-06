#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("����", ({"ma yu", "ma"}));
        set("gender", "����");
        set("age", 42);
        set("class", "taoist");
        set("nickname",MAG"������"NOR);
        set("long",
                "�������������Ĵ���ӣ�ȫ������֮�ף����������������ˡ�\n"
                "����ü��Ŀ���Ͱ����ף���Ц�ſ����㡣\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 28);
        set("int", 32);
        set("con", 31);
        set("dex", 30);
        set("title","ȫ������֮��");
        set("qi", 4500);
        set("max_qi", 4500);
        set("jing", 2200);
        set("max_jing", 2200);
        set("neili", 4700);
        set("max_neili", 4700);
        set("jiali", 100);
        set("level", 18);
        set("combat_exp", 1400000);

        set_skill("force", 180);
        set_skill("xiantian-gong", 180);
        set_skill("sword", 170);
        set_skill("quanzhen-jianfa",170);
        set_skill("dodge", 180);
        set_skill("jinyan-gong", 180);
        set_skill("parry", 180);
        set_skill("literate",100);
        set_skill("strike", 180);
        set_skill("haotian-zhang", 180);
        set_skill("taoism",150);
	      set_skill("medicine", 200);
        set_skill("tiangang-beidouzhen", 80);
	
        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike","haotian-zhang");

        create_family("ȫ���", 2, "����");

        set("book_count",1);
        set("miji_count",1);
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
                command("say �����ڵ�����֮������Ů�б��㻹��ȥ��ʦ�����￴���ɡ�\n");
                return;
        }
        if ((int)ob->query_skill("xiantian-gong",1) < 100 )
        {
                command("say ��ı����ڹ��ķ������,�������Ը�������书��");
                return;
        }
        if ((int)ob->query("shen") < 500000)
        {
                command("say ���������ұ�ѧ�������������ģ���������Ŀɲ�������\n");
                return;
        }
        command("pat " + ob->query("id"));
        command("say �ðɣ��Ҿ����������ͽ���ˡ�");
        command("recruit " + ob->query("id"));
}
