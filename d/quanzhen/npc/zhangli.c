#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
        set_name("��������", ({ "zhangli daozhang", "zhangli", "daozhang" }));
        set("long", @LONG
����һλ��ͺ���ĵ��ˣ��������ܸɣ���ȫ
��̵��Ĵ������г���δ�����ǰ������
�Ƿ�����������ȫ�����µ�����
LONG);

        set("gender", "����");
        set("age", 22);
        set("class", "taoist");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 22);
        set("int", 22);
        set("con", 22);
        set("dex", 22);

        set("qi", 600);
        set("max_qi", 600);
        set("jing", 400);
        set("max_jing", 400);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 0);

        set("combat_exp", 30000);
        set("score", 20000);

        set_skill("force", 60);
        set_skill("xiantian-gong", 50);
        set_skill("sword", 60);
        set_skill("quanzhen-jianfa",60);
        set_skill("dodge", 50);
        set_skill("jinyan-gong", 50);
        set_skill("parry", 60);
        set_skill("unarmed",60);
        set_skill("strike",60);
        set_skill("haotian-zhang", 50);
        set_skill("literate",50);
        set_skill("taoism",40);

        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 4, "����");

        set("book_count",1);
        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",
                "���¾�" : (: ask_me :),
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/grayrobe")->wear();

}

string ask_me()
{
        mapping fam;
        object ob;

        if (! (fam = this_player()->query("family"))
           || fam["family_name"] != "ȫ���")
                return "�����뱾�̺��޹ϸ����⻰�ɽ���Ū�������ˡ�";

        if (query("book_count") < 1)
                return "�������ˣ����¾��Ѿ�����ȡ���ˡ�";

        add("book_count", -1);
        ob = new(__DIR__"obj/daodejing-ii");
        ob->move(this_player());
        return "�ðɣ��Ȿ�����¾�������ȥ�ú��ж��������ĵط����������ҡ�";

}