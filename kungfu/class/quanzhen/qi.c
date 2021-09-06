// qi.c ��־��

inherit NPC;
string ask_me();

void create()
{
        set_name("��־��", ({"qi zhicheng", "qi"}));
        set("gender", "����");
        set("age", 24);
        set("class", "taoist");
        set("long",
                "������ȫ��̵����������еĺ��֣�̷���˵Ĵ������־�ϡ�\n"
                "����òӢ���������ܸɣ����ܳ��������Σ���ǲ��ȥ�ƹܽ���\n"
                "�ľ���伮��\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 25);
        set("int", 25);
        set("con", 24);
        set("dex", 24);

        set("qi", 1500);
        set("max_qi", 1500);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 60);

        set("combat_exp", 160000);

        set_skill("force", 80);
        set_skill("xiantian-gong", 80);
        set_skill("sword", 80);
        set_skill("quanzhen-jianfa",80);
        set_skill("dodge", 70);
        set_skill("jinyan-gong", 70);
        set_skill("parry", 80);
        set_skill("strike",80);
        set_skill("haotian-zhang", 60);
        set_skill("literate",60);
        set_skill("taoism",60);

        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 3, "����");

        set("book_count",1);
        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",
                "���¾�" : (: ask_me :),
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "ȫ���")
                return RANK_D->query_respect(this_player()) +
                "�뱾�̺��޹ϸ����⻰�ɽ���Ū�������ˡ�";
        if (query("book_count") < 1)
                return "�������ˣ����¾��Ѿ�����ȡ���ˡ�";
        add("book_count", -1);
        ob = new("/d/quanzhen/npc/obj/daodejing-ii");
        ob->move(this_player());
        return "�ðɣ��Ȿ�����¾������û�ȥ�ú��ж���";
}

void reset()
{
	set("book_count", 1);
}

