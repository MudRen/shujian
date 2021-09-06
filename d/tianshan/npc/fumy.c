// Npc: /d/tianshan/npc/fumy.c
// By Linux

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("������", ({ "fu mingyi", "fu"}));
	set("long",
	    "���ǡ����չ�������Ų������첿������.\n"+
	    "���ųơ�����.\n");
	set("title", "���첿����");
	set("gender", "Ů��");
	set("nickname", HIR "����" NOR);
	set("per",25);
        set("age", 30);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 20);
        set("int", 25);
        set("con", 30);
        set("dex", 30);

        set("qi", 2000);
        set("max_qi", 2000);
        set("jing", 1500);
        set("max_jing", 1500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);

        set("combat_exp", 100000);
        set("score", 10000);
        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("hand",100);
        set_skill("strike", 100);
        set_skill("sword",100);

	set_skill("tianyu-qijian",100);
        set_skill("zhemei-shou",100);
        set_skill("liuyang-zhang",100);
        set_skill("yueying-wubu",100);
        set_skill("bahuang-gong", 100);

        map_skill("force", "bahuang-gong");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "yueying-wubu");
        map_skill("unarmed", "liuyang-zhang");
        map_skill("hand", "zhemei-shou");
        map_skill("parry", "liuyang-zhang");
        map_skill("sword", "tianyu-qijian");
        create_family("���չ�",3,"����");
        setup();
        carry_object(__DIR__"obj/qingyi")->wear();
        carry_object(BINGQI_D("changjian"))->wield();
        add_money("silver",20+random(20));
}

#include "npc.h";
