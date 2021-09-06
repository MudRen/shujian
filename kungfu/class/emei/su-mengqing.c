// /kungfu/class/emei/su-mengqing.c
// Lklv 2001.10.18 update

#include "sujia.h"
inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("������", ({"su mengqing", "su", "mengqing"}));
	set("long", "�������ʦ̫�İ˴��׼ҵ���֮һ���ó��ط��������\n");

	set("gender", "Ů��");
	set("attitude", "friendly");
	set("unique", 1);
	set("age", 35);
        set("shen_type", 1);

	set("str", 32);
	set("int", 32);
	set("con", 32);
	set("dex", 32);
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 30);
	set("combat_exp", 500000);
	set("score", 100);

	set_skill("dacheng-fofa", 90);
	set_skill("linji-zhuang", 70);
	set_skill("literate", 90);
	set_skill("huifeng-jian", 80);
	set_skill("sword", 80);
	set_skill("parry", 90);
	set_skill("dodge", 90);
	set_skill("force", 90);
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