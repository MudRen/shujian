inherit F_MASTER;
inherit NPC;
string ask_me();
void create()
{
        set_name("������ʦ", ({ "liaoxiu chanshi","liaoxiu","chanshi"}) );
        set("nickname", "��������");
        set("long", "������ʦ�Ǳ����ɵĵ���λ���ӣ�����ĸߴ�
��֫�޳������ա���ѧ��ʮ���˵á�\n");
        set("gender", "����" );
        set("attitude", "friendly");
        set("class", "bonze");
        set("age", 40);
        set("shen_type", 1);
        set("str", 23);
        set("int", 22);
        set("con", 24);
        set("dex", 24);
        create_family("������", 14, "����");
        set("inquiry",([
                "ָ����Ҫ" : (: ask_me :),
        ]));

        set("qi", 1800);
        set("max_qi", 1800);
        set("jing", 1500);
        set("eff_jingli", 1500);
        set("max_jing", 1500);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 50);
        set("combat_exp", 1000000);
        set("score", 10000);
        set_skill("strike", 120);
        set_skill("force", 120);
        set_skill("qiantian-yiyang", 120);
        set_skill("dodge", 120);
        set_skill("qingyan-zhang", 120);
        set_skill("tianlong-xiang", 120);
        set_skill("parry", 120);
        set_skill("finger", 120);
        set_skill("sword", 120);
        set_skill("yiyang-zhi", 120);
        set_skill("buddhism", 120);
        set_skill("literate", 100);
        map_skill("strike", "qingyan-zhang");
        map_skill("force", "qiantian-yiyang");
        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "yiyang-zhi");
        map_skill("sword", "yiyang-zhi");
        map_skill("finger", "yiyang-zhi");
        prepare_skill("finger","yiyang-zhi");
        set("book_count", 1);   
        setup();
        carry_object("/d/tls/obj/jiasha1")->wear();
        carry_object("/d/tls/obj/sengxie")->wear();
}
string ask_me()
{
        mapping fam = this_player()->query("family");
        object ob;
        
        if(!fam || fam["family_name"] != "������")
           return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";
         if(this_player()->query_skill("finger",1) > 30)
           return "���ָ���Ѿ���һ�������ˣ��Ȿ�����ûʲô�ã�����������ĵ��Ӱ�";
		if(query("book_count") < 1)
           return "�������ˣ����ɵġ�ָ����Ҫ�����ڴ˴���";
        add("book_count", -1);
        ob = new("/d/tls/obj/zhifa");
        ob->move(this_player());
        return "�ðɣ��Ȿ��ָ����Ҫ�����û�ȥ�ú����С�";
}
#include "liao.h";
