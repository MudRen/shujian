// Npc: /d/tianshan/npc/yupopo.c
// By Linux

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������", ({ "yu popo", "yu", "popo" }));
        set("long",
            "���ǡ����չ�������Ų�����첿������.\n"+
            "������ͯ�Ѷ���, ��������,������˪.\n");
        set("title", "��첿����");
        set("gender", "Ů��");
	set("per",15);
        set("age", 60);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 20);
        set("int", 25);
        set("con", 30);
        set("dex", 30);
        set("unique", 1);

        set("qi", 3500);
        set("max_qi", 3500);
        set("jing", 2900);
        set("max_jing", 2500);
        set("neili", 3500);
        set("max_neili", 3000);
        set("eff_jingli", 4500);
        set("jiali", 100);

        set("combat_exp", 2000000);
        set("score", 5000);

        set_skill("force", 260);
        set_skill("dodge", 260);
        set_skill("parry", 260);
        set_skill("hand",260);
        set_skill("strike", 260);
        set_skill("sword",260);

        set_skill("tianyu-qijian",260);
        set_skill("zhemei-shou",260);
        set_skill("liuyang-zhang",260);
        set_skill("yueying-wubu",260);
        set_skill("bahuang-gong", 260);
        set_skill("literate", 150);

        map_skill("force", "bahuang-gong");
        map_skill("strike","liuyang-zhang");
        map_skill("dodge", "yueying-wubu");
        map_skill("hand", "zhemei-shou");
        map_skill("parry", "liuyang-zhang");
        map_skill("sword", "tianyu-qijian");
        prepare_skill("hand", "zhemei-shou");
        prepare_skill("strike", "liuyang-zhang");

        create_family("���չ�",2,"����");
        setup();
        carry_object(__DIR__"obj/qingyi")->wear();
        if(!random(3)) 
		carry_object(BINGQI_D("changjian"))->wield();
        add_money("silver",20+random(20));
}

#include "npc.h";
