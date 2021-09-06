#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("��־ƽ", ({"yin zhiping", "yin"}));
        set("gender", "����");
        set("class", "taoist");
        set("nickname", HIM"�������"NOR);
        set("age", 24);
        set("long",
                "�����𴦻��ĵ���������־ƽ������ü���ۣ�������ЩӢ����\n"
                "�ţ���ȫ��̵����������������������Ϊ����Ĳ��ߣ�ü���\n"
		"�ƺ���һ������֮ɫ�����ĵ��ǳ�ü��Ŀ����ò���ţ�������룬\n"
		"��ϧ��ȸ���������в��͡�\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 28);
        set("int", 25);
        set("con", 25);
        set("dex", 25);


        set("qi", 1500);
        set("max_qi", 1500);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 60);

        set("combat_exp", 220000);

        set_skill("force", 110);
        set_skill("xiantian-gong", 110);
        set_skill("sword", 100);
        set_skill("quanzhen-jianfa", 100);
        set_skill("dodge", 90);
        set_skill("jinyan-gong", 90);
        set_skill("parry", 110);
        set_skill("strike", 100);
        set_skill("haotian-zhang", 100);
        set_skill("literate",60);
        set_skill("taoism",100);
        set_skill("tiangang-beidouzhen",60);
        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 3, "����");

        set("inquiry", ([
                "ȫ���"   :  "��ȫ��������µ����������ڡ�\n",
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
     command("say ��ȫ����������������ڣ����µ��Ӷ����Ͻ����أ��в���������;��");
}

