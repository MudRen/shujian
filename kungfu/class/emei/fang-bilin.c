// /kungfu/class/emei/fang-bilin.c
// Make by Jackie 98.2

#include "sujia.h"
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������", ({
                "fang bilin",
                "fang",
                }));
        set("long",
                "�������ʦ̫�İ˴��׼ҵ���֮һ��\n"
        );


        set("gender", "Ů��");
        set("attitude", "friendly");
         set("unique", 1);
        set("age", 25);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 8);
set("combat_exp", 200000);
        set("score", 100);

	set_skill("dacheng-fofa", 80);
	set_skill("linji-zhuang", 70);
	set_skill("huifeng-jian", 70);
	set_skill("sword", 90);
	set_skill("literate", 90);
	set_skill("parry", 90);
	set_skill("dodge", 80);
	set_skill("force", 100);
	set_skill("anying-fuxiang", 90);

	map_skill("force", "linji-zhuang");
	map_skill("sword", "huifeng-jian");
	map_skill("parry", "huifeng-jian");
	map_skill("dodge", "anying-fuxiang");
        create_family("������", 4, "����");

        setup();

	carry_object("/d/emei/obj/changjian")->wield();
	carry_object("/d/emei/obj/shoes")->wear();
	carry_object("/d/emei/obj/cloth")->wear();

}



